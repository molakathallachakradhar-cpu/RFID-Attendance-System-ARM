#include<lpc21xx.h>
#include"header.h"
void lcd_data(u8 data)
{
IOCLR1=0XFE<<16;
IOSET1=(data&0xF0)<<16;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19; 

IOCLR1=0XFE<<16;
IOSET1=(data&0x0F)<<20;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;  
}
void lcd_cmd(u8 cmd)
{
IOCLR1=0XFE<<16;
IOSET1=(cmd&0xF0)<<16;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19; 

IOCLR1=0XFE<<16;
IOSET1=(cmd&0x0F)<<20;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;  
}
void lcd_init()
{
IODIR1=0xFE<<16;
PINSEL2=0X0;
IOCLR0=1<<19;   
lcd_cmd(0x02);
lcd_cmd(0x28) ;
lcd_cmd(0x0e);
lcd_cmd(0x01);
}
void lcd_string(u8 *ptr)
{
while(*ptr!=0)
{
lcd_data(*ptr);
ptr++;         
}
}


