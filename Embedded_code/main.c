#include"header.h"
	unsigned char h,m,s,t;
	unsigned char date,month,year;
	char empl[40];	
	 extern int i;
	 //int k=0;						   
	 unsigned char temp[100];
		
		int main()
		{

		
		int flag1=0,j;
		//char arr[2];
		int index;
		//unsigned char sum;
		int flag,k;
	
		
	
	
		i2c_init();
		lcd_init();
		uart0_init(9600);
		config_vic();
	    en_uart0_intr();
		uart0_tx_string("DS1307 RTC	\r\n");
		

	
			i2c_byte_write_frame(0XD0,0X2,0X49);
			i2c_byte_write_frame(0XD0,0X1,0X10);
			i2c_byte_write_frame(0XD0,0X0,0X0);
			i2c_byte_write_frame(0XD0,0X4,0X06);
			i2c_byte_write_frame(0XD0,0X5,0X05);
			i2c_byte_write_frame(0XD0,0X6,0X24);
	
		index=2;// day 	  
		while(1)
		{
		 lcd_cmd(0x80);
		 h=i2c_byte_read_frame(0XD0,0X02);
		 m=i2c_byte_read_frame(0XD0,0X01);
		 s=i2c_byte_read_frame(0XD0,0X00);
		 date=i2c_byte_read_frame(0XD0,0X04);	  
		 month=i2c_byte_read_frame(0XD0,0X05);
		 year=i2c_byte_read_frame(0XD0,0X06);
	     
	     t=(h & 0x1f);
	
	
		 if((h>>5)&1)
		   {
	        flag=1;
	   	   }	
	      else
		   {
			 flag=0;
		    }      
	
		lcd_data(t/16+48);
		lcd_data(t%16+48);
		lcd_data(':');
		
		
		lcd_data(m/16+48);
		lcd_data(m%16+48);
		lcd_data(':');
		
		
		lcd_data(s/16+48);
		lcd_data(s%16+48);
		 if(flag==1)
		    lcd_string(" PM");
		 else
		     lcd_string(" AM");
	
	    
		lcd_cmd(0xC0);
		   
	    lcd_data(date/16+48);
		lcd_data(date%16+48);
		lcd_data('/');
	
		lcd_data(month/16+48);
		lcd_data(month%16+48);
		lcd_data('/');
	
		lcd_data(year/16+48);
		lcd_data(year%16+48);
	
		 lcd_cmd(0xcf-5);
		 if(index==1)
		    lcd_string("SUN");
		 if(index==2)
		    lcd_string("MON");
		 if(index==3)
		    lcd_string("TUE");
		 if(index==4)
		    lcd_string("WED");
		 if(index==5)
		    lcd_string("THU");
		 if(index==6)
		    lcd_string("FRI");
		 if(index==7)
		    lcd_string("SAT");

		 
		 if(i==12)
		 {
		 flag1=1;
//		 uart0_tx_string(temp);
//		 uart0_tx_string("\r\n");
//		 
//		
		 i=0;
		  }

           if(flag1==1)
		     {
			   for(j=0,k=0;j<12;k++)
               empl[j++]=temp[k];           
			   empl[j++]=' ';

			   empl[j++]=t/16+48;
			   empl[j++]=t%16+48;
			   empl[j++]=':';
			   empl[j++]=m/16+48;
			   empl[j++]=m%16+48;
			   empl[j++]=':';
			   empl[j++]=s/16+48;
			   empl[j++]=s%16+48;
			   empl[j++]=' ';
			   if(flag==1)
			   
		    empl[j++]='P';
			
		 else
		     empl[j++]='A';
			 empl[j++]='M';

			 empl[j++]=' ';

			
			   empl[j++]=date/16+48;
			   empl[j++]=date%16+48;
			   empl[j++]='/';
			   empl[j++]=month/16+48;
			   empl[j++]=month%16+48;
			   empl[j++]='/';
			   empl[j++]=year/16+48;
			   empl[j++]=year%16+48;

			     empl[j++]=' ';

			   
			   if(index==1)
		    { empl[j++]='S';
			empl[j++]='U';
			empl[j++]='N';
			}
		 if(index==2)
		  {  empl[j++]='M';
			empl[j++]='O';
			empl[j++]='N';}
		 if(index==3)
		    {empl[j++]='T';
			empl[j++]='U';
			empl[j++]='s';}
		 if(index==4)
		   { empl[j++]='W';
			empl[j++]='E';
			empl[j++]='D';}
		 if(index==5)
		    {empl[j++]='T';
			empl[j++]='H';
			empl[j++]='R';}
		 if(index==6)
		   { empl[j++]='F';
			empl[j++]='R';
			empl[j++]='I'; }
		 if(index==7)
		    {empl[j++]='S';
			empl[j++]='A';
			empl[j++]='T';}

	
			   
			   
			   //empl[j]='\0';
			  
			   uart0_tx_string(empl);
				uart0_tx('\0');
			  //uart0_tx_string("4900C8EC1F72");
			   uart0_tx_string("\r\n");
			  flag1=0;
			 }          

		                            }
           

		 
		  
		}
		
		
		
		
		
