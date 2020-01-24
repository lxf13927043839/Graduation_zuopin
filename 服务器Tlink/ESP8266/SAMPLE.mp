NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   000A =     10. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       0096  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0096   0436 =   1078. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       004B  __text_start
       004B  __start
       006D  _exit
       006E  _espdelay
       0087  _ESPSendByte
       0092  _ESPSendString
       00A2  _delay
       00C7  _port_init
       00DC  _timer3_init
       0103  _timer3_ovf_isr
       011A  _init_devices
       012D  _main
       013C  _uart0_init
       0149  _uart0_rx_isr
       01B4  _uart1_init
       01C5  _uart1_rx_isr
       0231  _UartSendByte
       0235  _PrintString
       0245  _UartSendByte1
       024C  _PrintString1
       025C  push_xgset300C
       0261  pop_xgset300C
       0266  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   000A =     10. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  _time1sflag
       0100  __data_start
       0101  _espbufcount
       0105  _esplineflag
       0106  _j
       0108  _q
       010A  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   010A   0C00 =   3072. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       010A  __bss_start
       010A  _buf
       050A  _str1
       090A  _str
       0D0A  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   007C =    124. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
ESP8266.o	[ ESP8266.c ]
main.o	[ main.c ]
uart.o	[ uart.c ]
<library>	[ gpushx.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.2048

