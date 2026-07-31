ZCC ?= zcc
ZCC_TARGET ?= +cpm
ZCC_SUBTYPE ?= default
ZCCFLAGS ?= -create-app

all: FSRV.COM

FSRV.COM: fsrv.c
	$(ZCC) $(ZCC_TARGET) -subtype=$(ZCC_SUBTYPE) $(ZCCFLAGS) -o FSRV fsrv.c
	@if [ -f FSRV.com ]; then mv FSRV.com FSRV.COM; fi
	@rm -f FSRV

clean:
	rm -f FSRV FSRV.COM FSRV.bin FSRV.com FSRV.map FSRV.sym FSRV_CODE.bin FSRV_DATA.bin zcc_opt.def *.lis *.lst

.PHONY: all clean
