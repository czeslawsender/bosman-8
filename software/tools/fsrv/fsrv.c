#include <cpm.h>
#include <stdint.h>

#define C_WRITE 2
#define C_WRITESTR 9
#define RECORD_SIZE 128
#define FCB_SIZE 36

unsigned char baud_divisor;

static unsigned char fcb[FCB_SIZE];
static unsigned char dma[RECORD_SIZE];
static unsigned char sio_byte;
static unsigned char name_buf[16];
static unsigned char print_buf[80];
static const unsigned char baud_divisors[] = {0, 0x52, 0x29, 0x15, 0x0e, 0x07};

static void print(const char *c)
{
    unsigned int i=0;

    while (c[i]) {
        print_buf[i] = c[i];
        i++;
    }
    print_buf[i++] = '$';
    print_buf[i] = 0;

    bdos(C_WRITESTR, (int)c);
}

static void printc(const unsigned char c)
{
    bdos(C_WRITE, (int)c);
}

/* ponytail: minimal dec printer, no printf dependency */
static void print_dec(uint16_t n)
{
    char buf[6];
    unsigned char pos = 0;
    if (n >= 10000) { buf[pos++] = '0' + n / 10000; n %= 10000; }
    buf[pos++] = '0' + n / 1000; n %= 1000;
    buf[pos++] = '0' + n / 100; n %= 100;
    buf[pos++] = '0' + n / 10; n %= 10;
    buf[pos++] = '0' + n;
    buf[pos] = 0;
    print(buf);
}

static int reader_asm(void)
{
#asm
.reader_wait
    in a,(0x83)      ; SIO-B cmd/status (RR0)
    and 0x01          ; Rx char available?
    jr z,reader_wait
    in a,(0x81)      ; SIO-B data
    ld l,a
    ld h,0
#endasm
}

static unsigned char reader(void)
{
    unsigned char c;
    c = (unsigned char)reader_asm();
    return c;
}

static void punch(unsigned char c)
{
    sio_byte = c;
#asm
.punch_wait
    ld a,0x01
    out (0x83),a      ; SIO-B WR0: select RR1
    in a,(0x83)       ; SIO-B RR1
    and 0x01           ; All Sent?
    jr z,punch_wait
    ld a,(_sio_byte)
    out (0x81),a      ; SIO-B data
#endasm
}

static int reader_ready(void)
{
#asm
    in a,(0x83)      ; SIO-B cmd/status (RR0)
    and 0x01          ; Rx char available?
    ld l,a
    ld h,0
#endasm
}


static int console_ready(void)
{
    return bios(BIOS_CONST, 0, 0) & 0xff;
}

static int console_in(void)
{
    return bios(BIOS_CONIN, 0, 0) & 0xff;
}

static void apply_baud_divisor(void)
{
#asm
    ld a,(_baud_divisor)
    call 0x0df7
#endasm
}

static unsigned char upper(unsigned char c)
{
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

static void short_delay(void)
{
    uint16_t i;

    for (i = 0; i < 10000; ++i) {
    }
}

static void send_error(void)
{
    punch('E');
    print(" ERR\r\n$");
}

static void send_ok(void)
{
    punch('K');
    print(" OK\r\n$");
}

static void recv_name(void)
{
    unsigned char i = 0;
    char c;

    do {
        c = reader();
        if (i < sizeof(name_buf) - 1) {
            name_buf[i++] = c;
        }
    } while (c != 0);

    name_buf[sizeof(name_buf) - 1] = 0;
}

static void clear_fcb(void)
{
    unsigned char i;

    for (i = 0; i < FCB_SIZE; ++i) {
        fcb[i] = 0;
    }
}

static void fill_range(unsigned char start, unsigned char count, unsigned char value)
{
    unsigned char i;

    for (i = 0; i < count; ++i) {
        fcb[start + i] = value;
    }
}

static void build_fcb(unsigned char wildcard)
{
    char *p = name_buf;
    unsigned char pos = 1;
    unsigned char ext = 0;

    (void)wildcard;
    clear_fcb();
    fill_range(1, 11, ' ');

    if (p[0] && p[1] == ':') {
        unsigned char d = upper((unsigned char)p[0]);
        if (d >= 'A' && d <= 'P') {
            fcb[0] = d - 'A' + 1;
        }
        p += 2;
    }

    while (*p) {
        unsigned char c = upper((unsigned char)*p++);

        if (c == '.') {
            ext = 1;
            pos = 9;
            continue;
        }

        if (c == '*') {
            if (ext) {
                while (pos < 12) {
                    fcb[pos++] = '?';
                }
            } else {
                while (pos < 9) {
                    fcb[pos++] = '?';
                }
            }
            continue;
        }

        if (c == '?') {
            c = '?';
        }

        if ((!ext && pos < 9) || (ext && pos < 12)) {
            fcb[pos++] = c;
        }
    }
}

static void set_dma(void)
{
    bdos(CPM_SDMA, (int)dma);
}

static void send_dir_entry(unsigned char slot)
{
    unsigned char *entry = dma + ((unsigned int)slot * 32) + 1;
    unsigned char i;
    unsigned char buff[13];

    for (i = 0; i < 11; ++i) {
        punch(entry[i] & 0x7f);
        buff[i] = entry[i] & 0x7f;
    }
    buff[12] = '$';
    print(buff);
    print("\r\n$");
}

static void send_dir_end(void)
{
    unsigned char i;

    for (i = 0; i < 11; ++i) {
        punch(0);
    }
}

static void command_dir(void)
{
    int result;

    recv_name();
    build_fcb(1);
    set_dma();

    result = bdos(CPM_FFST, (int)fcb) & 0xff;
    while (result != 0xff) {
        send_dir_entry((unsigned char)result);
        set_dma();
        result = bdos(CPM_FNXT, (int)fcb) & 0xff;
    }
    send_dir_end();
    print(" OK\r\n$");
}

static uint16_t record_count_from_fcb(void)
{
    return (uint16_t)fcb[33] | ((uint16_t)fcb[34] << 8);
}

static void command_get(void)
{
    uint16_t records;
    uint16_t i;
    unsigned char j;
    unsigned char crc;

    recv_name();
    build_fcb(0);

    bdos(CPM_CFS, (int)fcb);
    records = record_count_from_fcb();
    build_fcb(0);

    if ((bdos(CPM_OPN, (int)fcb) & 0xff) == 0xff) {
        send_error();
        return;
    }

    set_dma();
    punch('K');
    punch(records & 0xff);
    punch(records >> 8);

//    print("GET ($");
//    print_dec(records);
//    print(" rec): $");
//    print(name_buf);
//    print("\r\n$");

    for (i = 0; i < records; ++i) {
        if ((bdos(CPM_READ, (int)fcb) & 0xff) != 0) {
            bdos(CPM_CLS, (int)fcb);
            send_error();
            return;
        }

        /* send record + per-record CRC */
        crc = 0;
        for (j = 0; j < RECORD_SIZE; ++j) {
            crc ^= dma[j];
            punch(dma[j]);
        }
        punch(crc);

        /* wait for PC ACK */
        if ((unsigned char)reader() != 'K') {
            bdos(CPM_CLS, (int)fcb);
            print(" ack err\r\n$");
            return;
        }
    }

    bdos(CPM_CLS, (int)fcb);
    punch('K');  /* final ACK */
    print(" OK\r\n$");
}

/* ponytail: reads one 128B record from SIO into dma, no echo */
static void recv_record(void)
{
    unsigned char i;

    for (i = 0; i < RECORD_SIZE; ++i) {
        dma[i] = (unsigned char)reader();
    }
}

/* ponytail: XOR CRC8 over dma buffer */
static unsigned char crc8_record(void)
{
    unsigned char i, crc = 0;

    for (i = 0; i < RECORD_SIZE; ++i) {
        crc ^= dma[i];
    }
    return crc;
}

static void delete_partial(void)
{
    bdos(CPM_CLS, (int)fcb);
    bdos(CPM_DEL, (int)fcb);
}

static void command_put(void)
{
    uint16_t records;
    uint16_t i;
    unsigned char remote_crc, local_crc;

    recv_name();
    records = (uint16_t)reader();
    records |= (uint16_t)reader() << 8;

    build_fcb(0);
    bdos(CPM_DEL, (int)fcb);
    build_fcb(0);

    if ((bdos(CPM_MAKE, (int)fcb) & 0xff) == 0xff) {
        send_error();
        return;
    }

    set_dma();
    punch('K');  /* initial ACK: ready to receive records */

    for (i = 0; i < records; ++i) {
        recv_record();
        remote_crc = (unsigned char)reader();

        local_crc = crc8_record();
        if (remote_crc != local_crc) {
            delete_partial();
            send_error();
            return;
        }

        if ((bdos(CPM_WRIT, (int)fcb) & 0xff) != 0) {
            delete_partial();
            send_error();
            return;
        }

        punch('K');  /* per-record ACK */
    }

    if ((bdos(CPM_CLS, (int)fcb) & 0xff) == 0xff) {
        bdos(CPM_DEL, (int)fcb);
        send_error();
        return;
    }
    punch('K');  /* final ACK */
    print(" OK\r\n$");
}

int main(void)
{
    unsigned char command;

    print("\r\nCP/M File Server v2.4\r\nLocal Q exits\r\n$");
    for (;;) {
        if (console_ready()) {
            command = upper((unsigned char)console_in());
            if (command == 'Q') {
                break;
            }
        }

        if (reader_ready()) {
            command = reader();
//            printc(command);

            if (command == 'D') {
                command_dir();
            } else if (command == 'G') {
                command_get();
            } else if (command == 'P') {
                command_put();
            } else if (command == 'Q') {
                send_ok();
                break;
            } else {
                send_error();
            }

        }
    }

    print("\r\nFSRV exit\r\n$");
    return 0;
}
