//���Ǹ�Դ�ļ�����Ŀ¼source.c
//ѡ���ڻ���Windows VC
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<malloc.h>
#include<math.h>//-lm
#include<stdlib.h>//����λ����
#include<process.h>
#include<windows.h>
#include<conio.h>
//������---------------------
#define H (99+1)//����ÿ�г���
#define U (7+1)//�û���ų���
#define K (6+1)//�û�����λ��,�����������Ϊ��3����
#define Y (8+1)//�û���������ֽ���
#define Q (10+1)//QQ���λ��
#define T (11+1)//�绰����λ��
//����ṹ��-----------------------------------
struct da{
   char dat[H];
   struct da *next;
};
//ȫ�ֱ���-------------------------------------
int mk=0;
struct da *head=NULL,*tail=NULL,*news=NULL;
char getp[3*K]={0};
//��������-------------------------------------
int daload();
int daedin(int nu,int po);
int daedimenu(int ch,char t[],int z);
int getinf(int a,char t[],int z);
//��������-------------------------------------
void sleep(double a){
   Sleep(a*1200);
}
#include"base.h"//����
//---------------------------------------------
char *getpass(char a[]){
	int i=0;
	q();printf("����������:");
	for(i=0;i<3*K;){if(i<0)i=0;
		getp[i]=getch();if(getp[i]=='\r' ||getp[i]==' '){j();break;}
		if(getp[i]==8){if(i>0){printf("\b \b");sleep(0.5);i-=1;}}
		else {i++;printf("*");}}
	getp[i]='\0';return getp;
}
#include"data.h"//����
#include"key.h"//����
#include"user.h"//�û�
#include"manage.h"//����
#include"search.h"//��ѯ
