#include<REGX51.H>
sfr LCD=0xA0;
sbit RS=P3^0;
sbit RW=P3^1;
sbit EN=P3^2;
void delay(unsigned int t)   //delay program
{	
	unsigned int i;
	while(t--)
	for(i=0;i<1257;i++);
}
void lcd_cmd(unsigned char ch)
{
	LCD=ch;
	RS=0;
	RW=0;
	EN=1;
	delay(2);
	EN=0;
}
void lcd_data(unsigned char ch)
{
	LCD=ch;
	RS=1;
	RW=0;
	EN=1;
	delay(2);
	EN=0;
}

void lcd_init()
{
lcd_cmd(0x38);
lcd_cmd(0x06);
lcd_cmd(0x0C);
lcd_cmd(0x01);
lcd_cmd(0x80);
}

void lcd_print(unsigned char *str)
{
	while(*str)
{
	lcd_data(*str);
	str++;
}
}

void main()
{
	while(1)
	{
		P0_0=1;
		P0_1=1;
		P0_2=1;
		delay(100);
		
		P0_0=0;
		P0_1=0;
		P0_2=0;
		delay(100);
		
		P0_0=1;
		delay(50);
		P0_0=0;
		delay(50);
		P0_1=1;
		delay(50);
		P0_1=0;
		delay(50);
		P0_2=1;
		delay(50);
		P0_2=0;
		delay(100);
		
	}
}