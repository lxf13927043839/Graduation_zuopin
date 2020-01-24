//ICC-AVR application builder : 2015/8/10 13:48:34
// Target : M64
// Crystal: 16.000Mhz

#include <iom64v.h>
#include <macros.h>
#include <string.h>  
#include "uart.h"

//#include "ESP8266.h"

extern unsigned char e8266tomcu_str[1024];
extern unsigned int e8266tomcu_num;
unsigned char Txto8266Buf[1024];
unsigned char flag=0;

unsigned char time1sflag = 0;
unsigned char timensflag = 0;
unsigned char linkokflag = 0;

unsigned char time=0;
#define   timens   5     //修改发送时间间隔   5秒

void delay(int ms)
{
  int i;
  while(ms--)
  {
    for(i=0;i<1000;i++)
	{
	 NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
	 NOP();NOP();NOP();NOP();NOP();NOP();NOP();NOP();
	}
  }
}

void port_init(void)
{
 PORTA = 0x00;
 DDRA  = 0x00;
 PORTB = 0x00;
 DDRB  = 0x00;
 PORTC = 0x00; //m103 output only
 DDRC  = 0x00;
 PORTD = 0x00;
 DDRD  = 0x00;
 PORTE = 0x00;
 DDRE  = 0x00;
 PORTF = 0x00;
 DDRF  = 0x00;
 PORTG = 0x00;
 DDRG  = 0x1F;
}

//TIMER3 initialize - prescale:256
// WGM: 0) Normal, TOP=0xFFFF
// desired value: 1Sec
// actual value:  1.000Sec (0.0%)
void timer3_init(void)
{
 TCCR3B = 0x00; //stop
 TCNT3H = 0x0B; //setup
 TCNT3L = 0xDC;
 OCR3AH = 0xF4;
 OCR3AL = 0x24;
 OCR3BH = 0xF4;
 OCR3BL = 0x24;
 OCR3CH = 0xF4;
 OCR3CL = 0x24;
 ICR3H  = 0xF4;
 ICR3L  = 0x24;
 TCCR3A = 0x00;
 TCCR3B = 0x04; //start Timer
}

#pragma interrupt_handler timer3_ovf_isr:iv_TIM3_OVF
void timer3_ovf_isr(void)
{
 //static unsigned char i;
 //TIMER3 has overflowed
 TCNT3H = 0x0B; //reload counter high value
 TCNT3L = 0xDC; //reload counter low value
 time1sflag = 1;
 if(++time>timens){timensflag = 1;time=0;}
 
}

//call this routine to initialize all peripherals
void init_devices(void)
{
 //stop errant interrupts until set up
 CLI(); //disable all interrupts
 XDIV  = 0x00; //xtal divider
 XMCRA = 0x00; //external memory
 port_init();
 
 uart0_init();
 uart1_init();
 timer3_init();
 MCUCR = 0x00;
 EICRA = 0x00; //extended ext ints
 EICRB = 0x00; //extended ext ints
 EIMSK = 0x00;
 TIMSK = 0x00; //timer interrupt sources
 ETIMSK = 0x04; //extended timer interrupt sources
 SEI(); //re-enable interrupts
 //all peripherals are now initialized
}
void clearNum(unsigned char *p){
    unsigned int i;
    for(i=0;i<1020;i++)
    {
  	    p[i]=0;   //清空数据缓存
    }
}
unsigned char E8266inittotlink(void){
    static unsigned char E8266state = 0,time = 0;
	switch(E8266state){
	  case 0:
	  time++;
	  if(strstr(e8266tomcu_str,"ready")!=0)
	  {
	     mcutopc_str(e8266tomcu_str);
	     clearNum(e8266tomcu_str);
		 time = 0;
		 e8266tomcu_num = 0;
	     mcuto8266_str("AT+CWMODE=1\r\n");
		 E8266state = 1;
	  }
	  break;
	  case 1:
	  time++;
	  if(strstr(e8266tomcu_str,"OK")!=0){
	     mcutopc_str(e8266tomcu_str);
		 clearNum(e8266tomcu_str);
		 time = 0;
		 e8266tomcu_num = 0;
		 //mcuto8266_str("AT+CWJAP=\"zsc\",\"13631103\"\r\n");
		 mcuto8266_str("AT+CWJAP=\"zsc888\",\"13631103\"\r\n");
		 E8266state = 2;
	  }
	  break;
	  case 2:
	  time++;
	  if(strstr(e8266tomcu_str,"OK")!=0){
	     mcutopc_str(e8266tomcu_str);
		 clearNum(e8266tomcu_str);
		 time = 0;
		 e8266tomcu_num = 0;
		 mcuto8266_str("AT+CIPSTART=\"TCP\",\"tcp.tlink.io\",8647\r\n");
		 E8266state = 3;
	  }
	  break;
	  case 3:
	  time++;
	  if(strstr(e8266tomcu_str,"OK")!=0){
	     mcutopc_str(e8266tomcu_str);
		 clearNum(e8266tomcu_str);
		 time = 0;
		 e8266tomcu_num = 0;
		 mcuto8266_str("AT+CIPMODE=1\r\n");
		 E8266state = 4;
	  }
	  break;
	  case 4:
	  time++;
	  if(strstr(e8266tomcu_str,"OK")!=0){
	     mcutopc_str(e8266tomcu_str);
		 clearNum(e8266tomcu_str);
		 time = 0;
		 e8266tomcu_num = 0;
		 mcuto8266_str("AT+CIPSEND\r\n");
		 E8266state = 5;
	  }
	  break;
	  case 5:
	  time++;
	  if(strstr(e8266tomcu_str,">")!=0){
	     mcutopc_str(e8266tomcu_str);
		 clearNum(e8266tomcu_str);
		 time = 0;
		 e8266tomcu_num = 0;
		 mcuto8266_str("XXXXXXXXXXXXXXXXXXXXXXXX");  //发送设备序列号
		 E8266state = 6;
		 linkokflag = 1;
		 timensflag = 0;//必须重新开始计时，否则程序不正常
	  }
	  break;
	  case 6:
	  time++;
	  if(strstr(e8266tomcu_str,"ok")!=0){
	     //PORTG ^= 0X01;//接受到服务器心跳包就闪烁灯
	     mcutopc_str(e8266tomcu_str);
		 clearNum(e8266tomcu_str);
		 time = 0;
		 e8266tomcu_num = 0; 
		 //mcuto8266_str("#50,30,70,50,1,1#");
		 //mcuto8266_str(Txto8266Buf);
		 //PORTG ^= 0X01;//接受到服务器心跳包就闪烁灯 
	  }
	  if(time>30){
	     E8266state = 7; //如果超时没有接收到心跳包则进入异常处理
		 linkokflag = 0; //连接失效
		 time = 0;
	  }	 
	  break;
	  case 7:
	  	 clearNum(e8266tomcu_str);
		 e8266tomcu_num = 0; 
		 mcuto8266_str("+++");//异常处理
		 delay(2000);
		 //mcutopc_str("\r\n");//异常处理
		 mcuto8266_str("AT\r\n");//异常处理
		 E8266state = 8;
	  break;
	  case 8:
	  	 if(strstr(e8266tomcu_str,"OK")!=0){
	       mcutopc_str(e8266tomcu_str);
	       clearNum(e8266tomcu_str);
		   time = 0;
		   e8266tomcu_num = 0;
		   mcuto8266_str("AT+CWMODE=1\r\n");
	       E8266state = 1;
	     }
		 else
		   E8266state = 7;
	  break;
	  
    }
	return 1;
}

int main(void)
{
    unsigned char i,Num;
	init_devices();
	while(1)
    {
       if(time1sflag == 1){   //上电初始化8266连接服务器，然后每1秒检测有无心跳包
	      E8266inittotlink();
		  if(linkokflag == 1)PORTG ^= 0X01;//接受到服务器心跳包就闪烁灯
		  time1sflag = 0;
		  //////////////////////每1秒更新数据，测试用//////////////////////////
		  /*
		  if((PING&(1<<2))== 0) i = 0+48;
		  else i = 1+48;
	      //if(timensflag == 1){  
		    Num++;
		    if(Num==99) Num = 1;
		  	Txto8266Buf[0] = '#';
		  	Txto8266Buf[1] = Num/10+48;
		  	Txto8266Buf[2] = Num%10+48;
		  	Txto8266Buf[3] = ',';
		  	//Txto8266Buf[4] = Num/10+48;
		  	//Txto8266Buf[5] = Num%10+48;
		  	Txto8266Buf[6] = ',';
		  	//Txto8266Buf[7] = Num/10+48;
		  	//Txto8266Buf[8] = Num%10+48;
		  	Txto8266Buf[9] = ',';
		  	//Txto8266Buf[10] = Num/10+48;
		  	//Txto8266Buf[11] = Num%10+48;
		  	Txto8266Buf[12] = ',';
		  	Txto8266Buf[13] = i;
		  	Txto8266Buf[14] = ',';
			
			if((PING&(1<<3))== 0) i = 0+48;
		    else i = 1+48;
			
		  	Txto8266Buf[15] = i;
		  	//Txto8266Buf[16] = '#';
		  	//Txto8266Buf[17] = '\0';*/
	      ////////////////////////////测试代码结束///////////////////////	   
	   }
	   if((timensflag == 1)&&(linkokflag == 1)){
	      mcuto8266_str(Txto8266Buf);  //每n秒上传一次数据
	      timensflag = 0;
	   }      
    }
    return 0;
}

