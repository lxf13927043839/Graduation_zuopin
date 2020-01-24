NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   008C   00BD =    189. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       008C  __idata_start
       0149  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   014A   095C =   2396. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       00A5  __text_start
       00A5  __start
       00C7  _exit
       00C8  _delay
       00ED  _port_init
       0102  _timer3_init
       0129  _timer3_ovf_isr
       014C  _init_devices
       0163  _clearNum
       0176  _E8266inittotlink
       0301  _main
       0326  _uart0_init
       0333  _uart1_init
       0344  _uart0_rx_isr
       03F5  _uart1_rx_isr
       04FA  _mcutopcSendByte0
       04FE  _mcutopc_str
       050E  _mcuto8266SendByte
       0515  _mcuto8266_str
       0525  _strstr
       053B  push_xgset300C
       0540  pop_xgset300C
       0545  push_xgsetF00C
       054C  pop_xgsetF00C
       0553  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0100   00BD =    189. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0100  __data_start
       0100  _flag
       0101  _time1sflag
       0102  _timensflag
       0103  _linkokflag
       0104  _time
       0105  main.c:E8266state
       0106  main.c:time
       01A0  _pctomcu_num
       01A2  _e8266tomcu_num
       01A4  uart.c:pctowifidatastate
       01A5  uart.c:wifitomcudatastate
       01BD  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   01BD   0C00 =   3072. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       01BD  _Txto8266Buf
       01BD  __bss_start
       05BD  _e8266tomcu_str
       09BD  _pctomcu_str
       0DBD  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   007C =    124. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

C:\iccv7avr\lib\crtatmega.o	[ crtatmega.s ]
main.o	[ main.c ]
uart.o	[ uart.c ]
<library>	[ strstr.s, gpushx.s, gpushz.s ]

User Global Definitions

ram_end = 0x10ff
hwstk_size = 0x1e

User Base Address Definitions

func_lit = 0x8c
data = 0x100
eeprom:0.2048

