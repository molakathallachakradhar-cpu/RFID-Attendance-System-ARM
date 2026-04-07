#include <LPC21xx.H>
#include "header.h"
extern s8 arr[13],flag;
  void uart0_handler(void) __irq{
	 u32 u;
	 static int i;
	 u=U0IIR;
	 u=u&0X0E;
	 if(u==4){
	  arr[i]=U0RBR;
	   if(i==11){
	   arr[12]='\0';
	   flag=1;
	   i=-1;
	   }
	   i++;
	}
	VICVectAddr=0;
	 }
	 void uart_intr(void){
	 VICVectCntl0=6|1<<5;
	 VICVectAddr0=(u32)uart0_handler;
	 VICIntEnable=1<<6;
	 U0IER=3;
	 }



