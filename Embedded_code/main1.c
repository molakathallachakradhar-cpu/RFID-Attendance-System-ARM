#include <LPC21xx.H>
#include <string.h>
#include "header.h"
s8 arr[13],flag,temp[50];
int main(){
	u8 h,m,s,i,date,month,year,h1,day;
	s8 arr1[][4]={"","SUN","MON","TUE","WED","THU","FRI","SAT"};
lcd_init();
uart0_init(9600);
uart_intr();
i2c_init();
	i2c_send(0xD0,0x2,0x51);//11am 
	i2c_send(0xD0,0x1,0x59);//59min
	i2c_send(0xD0,0x0,0x55);//55secs
	i2c_send(0xD0,0x3,0x6);//set fri
	i2c_send(0xD0,0x4,0x03);//03th day
	i2c_send(0xD0,0x5,0x10);//10th month
	i2c_send(0xD0,0x6,0x24);//24 year
   while(1){
   h=i2c_read(0xD1,0x02); // hrs
   	m=i2c_read(0xD1,0x1);//read mins
	s=i2c_read(0xD1,0x0);//read secs
	date=i2c_read(0xD1,0x4);//read day
	month=i2c_read(0xD1,0x5);//read month
	year=i2c_read(0xD1,0x6);//read year
	day=i2c_read(0xD1,0X3);//READ DAY
   h1=h;
   h=h&0x1F;
   		lcd_cmd(0x80);
		lcd_string("Scan Your ID");
		lcd_cmd(0xc0);
   		lcd_data((h/0x10)+48);
		lcd_data((h%0x10)+48);
		lcd_data(':');
		lcd_data((m/0x10)+48);
		lcd_data((m%0x10)+48);
		lcd_data(':');
		lcd_data((s/0x10)+48);
		lcd_data((s%0x10)+48);
	lcd_cmd(0xc9);	 
   if((h1>>5)&1)
   lcd_string("pm");
   else
   lcd_string("am");
   lcd_cmd(0xcd);
	 lcd_string(arr1[day]);
		
   if(flag==1){
		strcpy(temp,arr);
		i=12;
		temp[i++]=' ';
		temp[i++]=(date/0x10)+48;
		temp[i++]=(date%0x10)+48;
		temp[i++]=':';
		temp[i++]=(month/0x10)+48;
		temp[i++]=(month%0x10)+48;
		temp[i++]=':';
		temp[i++]=(year/0x10)+48;
		temp[i++]=(year%0x10)+48;
		temp[i++]=' ';
		temp[i++]=(h/0x10)+48;
		temp[i++]=(h%0x10)+48;
		temp[i++]=':';
		temp[i++]=(m/0x10)+48;
		temp[i++]=(m%0x10)+48;
		temp[i++]=':';
		temp[i++]=(s/0x10)+48;
		temp[i++]=(s%0x10)+48;
		temp[i++]=' ';
		if((h1>>5)&1)
		{
		temp[i++]='P';
		temp[i++]='M';
		}
		else
		{
		temp[i++]='A';
		temp[i++]='M';
		}
		temp[i]='\0';	
		uart0_string(temp);
		uart0_string("\r\n");	
   flag=0;
   }
   }
   }


