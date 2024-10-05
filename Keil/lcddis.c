#include <regx51.h>
void delay(unsigned int);
void cmd(unsigned char);
void lcd_wrt(unsigned char);
void string(unsigned char *str);
void main()
{
while(1)
{
cmd(0X38);
cmd(0X01);
cmd(0X06);
cmd(0X0C);
cmd(0X80);	
string("HELLO TVM");
while(1);
}
}
void cmd(unsigned char b)
{
P2=0X04;
P3=b;
P2=0X00;
delay(10);
}
void lcd_wrt(unsigned char s)
{
P2=0X05;
P3=s;
P2=0X01;
delay(10);
}
void string(unsigned char *str)
{
int k=0;
while(str[k]!= '\0' )
{
lcd_wrt(str[k]);
k++;
}
}
void delay(unsigned int a)
{
unsigned char i;
for(;a>0;a--)
{
for(i=250;i>0;i--);
}
}
