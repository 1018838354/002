//这是个源文件管理目录source.c
//选择当期环境Windows VC
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<malloc.h>
#include<math.h>//-lm
#include<stdlib.h>//加密位运算
#include<process.h>
#include<windows.h>
#include<conio.h>
//定义类---------------------
#define H (99+1)//数据每行长度
#define U (7+1)//用户编号长度
#define K (6+1)//用户密码位数,管理密码最多为其3倍多
#define Y (8+1)//用户姓名最大字节数
#define Q (10+1)//QQ最大位数
#define T (11+1)//电话号码位数
//定义结构体-----------------------------------
struct da{
   char dat[H];
   struct da *next;
};
//全局变量-------------------------------------
int mk=0;
struct da *head=NULL,*tail=NULL,*news=NULL;
char getp[3*K]={0};
//函数声明-------------------------------------
int daload();
int daedin(int nu,int po);
int daedimenu(int ch,char t[],int z);
int getinf(int a,char t[],int z);
//其他函数-------------------------------------
void sleep(double a){
   Sleep(a*1200);
}
#include"base.h"//基础
//---------------------------------------------
char *getpass(char a[]){
	int i=0;
	q();printf("请输入密码:");
	for(i=0;i<3*K;){if(i<0)i=0;
		getp[i]=getch();if(getp[i]=='\r' ||getp[i]==' '){j();break;}
		if(getp[i]==8){if(i>0){printf("\b \b");sleep(0.5);i-=1;}}
		else {i++;printf("*");}}
	getp[i]='\0';return getp;
}
#include"data.h"//数据
#include"key.h"//加密
#include"user.h"//用户
#include"manage.h"//管理
#include"search.h"//查询
