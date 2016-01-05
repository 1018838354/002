//这是个源文件管理目录source.h
//选择当期环境Gcc or Vc
#define Gcc
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>//-lm
#include<stdlib.h>//加密位运算
//---Gcc or Vc配置环境
#ifdef Gcc
#include<time.h>//Gcc使用sleep
#include<unistd.h>//Gcc使用getpass
#else
//Windows VC 兼容转化
#include<conio.h>//Vc使用getch
#include<process.h>//Vc文件处理
#include<windows.h>//Vc使用Sleep
//函数声明
int daload();
int daedin(int nu,int po);
int daedimenu(int ch,char t[],int z);
int getinf(int a,char t[],int z);
char kky[K]={0};
char *getpass(char a[]){
	int i=0;
	q();printf("请输入密码:");
	for(i=1;i<3*K;i++){
		getp[i-1]=getch();printf("*");if(getp[i-1]==' '){getp[i-1]='\r';j();break;}}
	getp[i]='\0';return getp;
}
void sleep(int a){
   Sleep(a*1500);
}
#endif
//定义类---------------------
#define H (99+1)//数据每行长度
#define U (7+1)//用户编号长度
#define K (6+1)//用户密码位数,管理密码最多为其3倍多
#define Y (12+1)//用户姓名最大字节数
#define Q (10+1)//QQ最大位数
#define T (11+1)//电话号码位数
//定义结构体-----------------
struct da{
   char dat[H];
   struct da *next;
};
//全局变量-------------------
int mk=0;
struct da *head=NULL,*tail=NULL,*news=NULL;
//其他函数-------------------
#include"base.h"//基础
#include"data.h"//数据
#include"key.h"//加密
#include"user.h"//用户
#include"manage.h"//管理
#include"search.h"//查询
