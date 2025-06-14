#include <lpc21xx.h>    
#include "types.h"    
#include "can.h"   
#include "delay.h" 
#include "external_interrupt.h"
#include "pin_function_defines.h"
#include "defines.h"
#include "lcd.h"
#include "ds18b20.h"

char flag =0;
u32 fg=0;
 
int main(void)    
{
	int temp;
	unsigned char tp,tpd;  
    struct CAN_Frame txFrame,rxFrame; //i=sizeof(txFrame);    
    txFrame.ID=0;
	txFrame.vbf.RTR=0; //data frame   
    txFrame.Data2=0X00;
	

    
	Init_CAN1();
	initLCD();//LCD initialization
   	cmdLCD(0x0c);
	
    temp=ReadTemp();  //READING TEMPERATURE FROM DS18B20 USING 1-WIRE PROTOCOL
	tp  = temp>>4;	  //GETTING INTEGER PART
	tpd=temp&0x08?0x35:0x30;//GETTING FRACTIONAL PART
	
	cmdLCD(0x80);
	strLCD("Temp =");
	s32LCD(tp);
	charLCD('.');
	s32LCD(tpd);
	strLCD(" C  ");
   
    
   	Enable_EINT0();
	Enable_EINT1();
	Enable_EINT2();

  
	while(1)    
  {    
  
		 txFrame.ID=fg;  
         txFrame.vbf.DLC=1;  
	     txFrame.Data1=flag;  
		 CAN1_Tx(txFrame);  
		 delay_s(1);  
		 if(txFrame.ID==3){
		 	CAN1_Rx(&rxFrame);
			 cmdLCD(0xc0); 
			charLCD('A'); 
			if(rxFrame.ID==5){
			  			u32LCD(rxFrame.Data1);			
			}								  		 
		 }
		     
  }
      
}

