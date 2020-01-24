CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega64  -l -g -MLongJump -MHasMul -MEnhanced -Wf-use_elpm -Wf-const_is_flash -DCONST="" 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x10000 -ucrtatmega.o -bfunc_lit:0x8c.0x10000 -dram_end:0x10ff -bdata:0x100.0x10ff -dhwstk_size:30 -beeprom:0.2048 -fihx_coff -S2
FILES = main.o uart.o 

SAMPLE:	$(FILES)
	$(CC) -o SAMPLE $(LFLAGS) @SAMPLE.lk   -lcatmega
main.o: C:\iccv7avr\include\iom64v.h C:\iccv7avr\include\macros.h C:\iccv7avr\include\AVRdef.h C:\iccv7avr\include\string.h C:\iccv7avr\include\_const.h .\..\..\5ESP82~1\ESP8266\source\uart.h
main.o:	..\..\5ESP82~1\ESP8266\source\main.c
	$(CC) -c $(CFLAGS) ..\..\5ESP82~1\ESP8266\source\main.c
uart.o: C:\iccv7avr\include\iom64v.h C:\iccv7avr\include\macros.h C:\iccv7avr\include\AVRdef.h C:\iccv7avr\include\string.h C:\iccv7avr\include\_const.h .\..\..\5ESP82~1\ESP8266\source\uart.h
uart.o:	..\..\5ESP82~1\ESP8266\source\uart.c
	$(CC) -c $(CFLAGS) ..\..\5ESP82~1\ESP8266\source\uart.c
