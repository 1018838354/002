void keych(char *m1,char *m2){
   int i;
   int len=strlen(m2);
   while(*m1){
      for(i=0;i<len;i++){
	*m1=*m1^(int)m2[i];}
      m1++;
   }
}
int passkey(int p){
   int i=1;
   char a[20]="key",b[K*3]={0},c[K*3]={0};
   FILE *key;
  while(1){
   if (p==1)
   key=fopen("key.txt","r");
   else key=fopen("key.txt","w");
   char *t;t=getpass("  ⎪请输入密码:");
   strcpy(b,t);keych(b,a);//读取输入密码,并加密.
//   puts(b);//显示输入密码
   if(p==1){
     fgets(c,K*3,key);
     if(!strcmp(b,c)){return 0;}
     else {i++;q();printf("错误!\n");if(i==4)return 3;}  }//此为验证密码
   else{
     fputs(b,key);fclose(key);return 0;}//此为更新密码
  }
}
int userkey(char u[]){
   int i=0;
   char k[K]={0},bk[K]={0};
  while(1){
   while(1){
     FILE *data=fopen("data.txt","r");
     q();printf("请输入编号:");j();
     if(getinf(U-1,u,0)==2)return 2;
   int f=userkeydata(u,bk);
   if(f==2){
      q();printf("数据不存在");j();
      i++;if(i==5)return 3;sleep(1);fclose(data);}
   else {q();printf("密码带回%s\n",bk);fclose(data);break;}}//显示密码
   char *t;t=getpass("  ⎪请输入密码:");
   strcpy(k,t);
   if(!strcmp(k,bk)){return 0;}
   else {q();printf("密码错误!\n");i++;if(i==5)return 3;}  }
}

int keyuser(char u[]){
   int rt=1;
   rt=userkey(u);
   if(rt==0){q();printf("登陆成功");j();return rt;}
   else{q();printf("登陆失败");j();return rt;}
}

int keymanage(int a){
   FILE *rkey;
   if (a==5)goto Loop;//a=5修改管理密码
   if ((rkey=fopen("key.txt","r"))!=NULL){
   q();p(9);printf("管理员验证");j();
      if(passkey(1)==0){q();printf("密码正确loading...");j();sleep(1);return 0;}
           //1.验证管理密码2.更新管理密码.
      else {q();printf("你输入次数过多,程序将自动关闭.");j();return 3;}
   }else{q();printf("加密文件不存在,请重新设置.\n");sleep(1);
Loop:
   q();p(2);printf("请设置管理密码:");j();
      if(passkey(2)==0){
      q();printf("密码设置成功!");j();sleep(1);return 0;}
      else {q();printf("你真有趣.");j();return 3;}
   }
}
