CC = iccavr
LIB = ilibw
CFLAGS =  -e -D__ICC_VERSION=722 -DATMega64  -l -g -MLongJump -MHasMul -MEnhanced -Wf-use_elpm 
ASFLAGS = $(CFLAGS) 
LFLAGS =  -g -e:0x10000 -ucrtatmega.o -bfunc_lit:0x8c.0x10000 -dram_end:0x10ff -bdata:0x100.0x10ff -dhwstk_size:30 -beeprom:0.2048 -fihx_coff -S2
FILES = ESP8266.o main.o uart.o 

SAMPLE:	$(FILES)
	$(CC) -o SAMPLE $(LFLAGS) @SAMPLE.lk   -lcatmega
ESP8266.o: C:\iccv7avr\include\iom64v.h C:\iccv7avr\include\macros.h C:\iccv7avr\include\AVRdef.h .\..\..\..\..\7无线~1\2ESP82~1\5ESP82~1\ESP8266\source\ESP8266.h
ESP8266.o:	..\..\..\..\7无线~1\2ESP82~1\5ESP82~1\ESP8266\source\ESP8266.c
	$(CC) -c $(CFLAGS) ..\..\..\..\7无线~1\2ESP82~1\5ESP82~1\ESP8266\source\ESP8266.c
main.o: C:\iccv7avr\include\iom64v.h C:\iccv7avr\include\macros.h C:\iccv7avr\include\AVRdef.h .\..\..\..\..\7无线~1\2ESP82~1\5ESP82~1\ESP8266\source\uart.h .\..\..\..\..\7无线~1\2ESP82~1\5ESP82~1\ESP8266\source\ESP8266.h
main.o:	..\..\..\..\7无线~1\2ESP82~1\5ESP82~1\ESP8266\source\main.c
	$(CC) -c $(CFLAGS) ..\..\..\..\7无线~1\2ESP82~1\5ESP82~1\ESP8266\source\main.c
uart.o: C:\iccv7avr\include\iom64v.h C:\iccv7avr\include\macros.h C:\iccv7avr\include\AVRdef.h C:\iccv7avr\include\string.h C:\iccv7avr\include\_const.h .\..\..\..\..\7无线~1\2ESP82~1\5ESP82~1\ESP8266\source\uart.h
uart.o:	..\..\..\..\7无线~1\2ESP82~1\5ESP82~1\ESP8266\source\uart.c
	$(CC) -c $(CFLAGS) ..\..\..\..\7无线~1\2ESP82~1\5ESP82~1\ESP8266\source\uart.c
