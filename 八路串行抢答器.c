#include <reg51.h>
#include <stdio.h>
#define uchar unsigned char
#define uint unsigned int
#define shuxuan P1  //数字接口
#define weixuan P0     //位数接口

unsigned char code wxcode[4]={0x01,0x02,0x04,0x08};
unsigned char code sxcode[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int fenshu[8]={0,0,0,0,0,0,0,0};

sbit speaker = P2^0; //喇叭端口
sbit function = P2^2; //功能键端口
sbit jiafen = P2^4; // 加分键
sbit jianfen = P2^6;//减分键
sbit SPL = P3^2;//165的控制端


///////////////延时函数 1000/1s  /////////////////
void delay(uint t)
{
 uint j;
 for(;t>0;t--)
 for(j=120;j>0;j--);
}

/////////////////加分函数////////////////
void jia(uint team)
{
fenshu[team - 1] = fenshu[team - 1] + 1;
}


////////////////////减分函数////////////////////
void jian(uint team)
{
	if (fenshu[team - 1] > 0)
	{
	fenshu[team - 1] = fenshu[team - 1] - 1;
	}
}


////////////显示函数 先是位数 后是数字///////////////
void display(uint wx,uint sx)
	{
	weixuan = wxcode[wx];
	shuxuan = sxcode[sx];
	}


//////////////////喇叭开启函数///////////////
void speakerON()
{
while(function == 1)
	{
	speaker = 1;
	delay(500);
	speaker = 0;
	delay(500);
	}
}


///////////////////倒计时函数//////////////////
void countdown()
{

uint t;
uint j;
while(1)
{
	if(function == 0)
	{
		for(t=20;t>0;t--)
		{
			for(j=100;j>0;j--)
			{
			display(1,9);
			display(2,0);
			}
		}
	  break;
	  }
}
		delay(20);
		display(0,3);
		delay(1500);
		display(1,2);
		delay(1000);
		display(2,1);
		delay(1000);
		display(3,0);
}

////////////////核心函数//////////////////
void key()reentrant  //可以回调
{
uchar n;
countdown();
SCON = 0x10;
while(1)
{
SPL = 0;
delay(20);
SPL = 1;
while(RI == 0);
RI = 0;

//一号选手//
	if (SBUF == 0x80)
		{
		while(1)
		{
		display(0,1);
		speakerON();
		break;
		}
		while(1)
		{
		if(jiafen == 0){jia(1);break;}
		if(jianfen == 0){jian(1);break;}
		}
		while(1)
		{
		display(0,1);
		delay(30);
		display(2,fenshu[0]);
		delay(30);
		if(function == 0){weixuan = 0x00;break;}
		}
		delay(1000);
		key();
		}
//二号选手//
	else if (SBUF == 0x40)
		{
		while(1)
		{
		display(0,2);
		speakerON();
		break;
		}
		while(1)
		{
		if(jiafen == 0){jia(2);break;}
		if(jianfen == 0){jian(2);break;}
		}
		while(1)
		{
		display(0,2);
		delay(30);
		display(2,fenshu[1]);
		delay(30);
		if(function == 0){weixuan = 0x00;break;}
		}
		delay(1000);
		key();
		}
//三号选手//
	else if (SBUF == 0x20)
		{
		while(1)
		{
		display(0,3);
		speakerON();
		break;
		}
		while(1)
		{
		if(jiafen == 0){jia(3);break;}
		if(jianfen == 0){jian(3);break;}
		}
		while(1)
		{
		display(0,3);
		delay(30);
		display(2,fenshu[2]);
		delay(30);
		if(function == 0){weixuan = 0x00;break;}
		}
		delay(1000);
		key();
		}
//四号选手//
	else if (SBUF == 0x10)
		{
		while(1)
		{
		display(0,4);
		speakerON();
		break;
		}
		while(1)
		{
		if(jiafen == 0){jia(4);break;}
		if(jianfen == 0){jian(4);break;}
		}
		while(1)
		{
		display(0,4);
		delay(30);
		display(2,fenshu[3]);
		delay(30);
		if(function == 0){weixuan = 0x00;break;}
		}
		delay(1000);
		key();
		}
//五号选手//
	else if (SBUF == 0x08)
		{
		while(1)
		{
		display(0,5);
		speakerON();
		break;
		}
		while(1)
		{
		if(jiafen == 0){jia(5);break;}
		if(jianfen == 0){jian(5);break;}
		}
		while(1)
		{
		display(0,5);
		delay(30);
		display(2,fenshu[4]);
		delay(30);
		if(function == 0){weixuan = 0x00;break;}
		}
		delay(1000);
		key();
		}
//六号选手//
	else if (SBUF == 0x04)
		{
		while(1)
		{
		display(0,6);
		speakerON();
		break;
		}
		while(1)
		{
		if(jiafen == 0){jia(6);break;}
		if(jianfen == 0){jian(6);break;}
		}
		while(1)
		{
		display(0,6);
		delay(30);
		display(2,fenshu[5]);
		delay(30);
		if(function == 0){weixuan = 0x00;break;}
		}
		delay(1000);
		key();
		}

//七号选手//
	else if (SBUF == 0x02)
		{
		while(1)
		{
		display(0,7);
		speakerON();
		break;
		}
		while(1)
		{
		if(jiafen == 0){jia(7);break;}
		if(jianfen == 0){jian(7);break;}
		}
		while(1)
		{
		display(0,7);
		delay(30);
		display(2,fenshu[6]);
		delay(30);
		if(function == 0){weixuan = 0x00;break;}
		}
		delay(1000);
		key();
		}

//八号选手//
	else if (SBUF == 0x01)
		{
		while(1)
		{
		display(0,8);
		speakerON();
		break;
		}
		while(1)
		{
		if(jiafen == 0){jia(8);break;}
		if(jianfen == 0){jian(8);break;}
		}
		while(1)
		{
		display(0,8);
		delay(30);
		display(2,fenshu[7]);
		delay(30);
		if(function == 0){weixuan = 0x00;break;}
		}
		delay(1000);
		key();
		}
//其余情况//
	else
		{
		display(2,0);
		}
//复位//
	if(function == 0)
	{
	delay(2000);
	key();
	}
}
}



void main()
{
   while(1)
   {
   	key();
   }
}

