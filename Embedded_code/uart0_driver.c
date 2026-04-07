#include<stdio.h>
#include <LPC21xx.H>
#include "header.h"
void uart0_init(unsigned int baud)
{
unsigned result,pclk;
int a[]={15,60,30,15,15};
pclk=a[VPBDIV]*1000000;
result=pclk/(16*baud);
PINSEL0|=5;
U0LCR=0X83;
U0DLL=result&0xff;
U0DLM=((result>>8)&0xff);
U0LCR=3;
}
#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
U0THR=data;
while(THRE==0);
}
#define RDR (U0LSR&1)
unsigned char uart0_rx(void)
{
while(RDR==0);
return U0RBR;
} 
#define THRE ((U0LSR>>5)&1)
void uart0_string(s8 *p)
{
while(*p)
{
 U0THR=*p;
 while(THRE==0);
 p++;
 }
}
void uart0_integer(u8 data){
s8 arr[10];
sprintf(arr,"%d",data);
uart0_string(arr);
}
