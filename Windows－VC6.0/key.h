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
   char *t;t=getpass("  ?����������:");
   strcpy(b,t);keych(b,a);//��ȡ��������,������.
//   puts(b);//��ʾ��������
   if(p==1){
     fgets(c,K*3,key);
     if(!strcmp(b,c)){return 0;}
     else {i++;q();printf("����!\n");if(i==4)return 3;}  }//��Ϊ��֤����
   else{
     fputs(b,key);fclose(key);return 0;}//��Ϊ��������
  }
}
int userkey(char u[]){
   int i=0;
   char k[K]={0},bk[K]={0};
  while(1){
   while(1){
     FILE *data=fopen("data.txt","r");
     q();printf("��������:");j();
     if(getinf(U-1,u,0)==2)return 2;
   int f=userkeydata(u,bk);
   if(f==2){
      q();printf("���ݲ�����");j();
      i++;if(i==5)return 3;sleep(1);fclose(data);}
   else {q();printf("�������%s\n",bk);fclose(data);break;}}//��ʾ����
   char *t;t=getpass("  ?����������:");
   strcpy(k,t);
   if(!strcmp(k,bk)){return 0;}
   else {q();printf("�������!\n");i++;if(i==5)return 3;}  }
}

int keyuser(char u[]){
   int rt=1;
   rt=userkey(u);
   if(rt==0){q();printf("��½�ɹ�");j();return rt;}
   else{q();printf("��½ʧ��");j();return rt;}
}

int keymanage(int a){
   FILE *rkey;
   if (a==5)goto Loop;//a=5�޸Ĺ�������
   if ((rkey=fopen("key.txt","r"))!=NULL){
   q();p(9);printf("����Ա��֤");j();
      if(passkey(1)==0){q();printf("������ȷloading...");j();sleep(1);return 0;}
           //1.��֤��������2.���¹�������.
      else {q();printf("�������������,�����Զ��ر�.");j();return 3;}
   }else{q();printf("�����ļ�������,����������.\n");sleep(1);
Loop:
   q();p(2);printf("�����ù�������:");j();
      if(passkey(2)==0){
      q();printf("�������óɹ�!");j();sleep(1);return 0;}
      else {q();printf("������Ȥ.");j();return 3;}
   }
}
