int loaddata(){
   while(1){
   f();
   q();p(10);printf("�������ݴ���");p(11);e();
   q();p(8);stu();printf("~~~~~~~~~~~~~");stu();p(8);e();
   q();p(1);printf("���������ļ���load.txt����ģ��:");p(1);e();
   f();
   q();printf(" ���   ����    QQ     �绰����  ");e();
   q();printf("0158001 ���� 10188080 18893868540");e();
   q();printf("\b~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");e();
   q();p(4);printf("ע��ÿ����Ϣ֮�䱣�ֿո�.");p(4);e();
   q();p(4);printf("Ĭ���û���½����Ϊ000000.");p(4);e();
   q();p(8);printf("������ֻ�ǲ��԰�,");p(8);e();
   q();p(4);printf("��ʹ��ʱ���水������ģ��.");p(4);e();
   q();printf("ֱ�����س�ȷ�ϵ���.����'N'�˳���");p(1);e();
   q();if(getchar()=='\n'){if(loading()!=0){q();printf("��������!\n");}}
       else {qn();q();printf("�Զ�������һ����.\n");sleep(1);return 2;}}
}

int managedi(){
   if(daload()!=0)return 2;
   char t[20]={0};
   q();printf("��������Ҫ�༭���û����:\n");
   if(getinf(U-1,t,0)==0)daediu(t,1);
   else {q();printf("����������!\n");sleep(1);return 2;}
   return 0;
}
int managelinking(char a){
   switch(a){
     case '1':return datalook();
     case '2':return adduser();
     case '3':return managedi();
     case '4':return sort();
     case '5':return keymanage(5);//5Ϊ�޸�����
     case '6':return loaddata();//�����ļ���Ϣ����
     default:q();printf("��������!\n");return 1;
   }
}//��������


int managemenu(){
   int rt=1,rb=1,i=1;
   char enter,type='0';
   while(rt!=0){
{  f();
   q();p(10);printf("�����������");p(11);e();
   q();p(8);stu();printf("~~~~~~~~~~~~~");stu();p(8);e();
   q();p(1);printf("1.��Ϣ�鿴");p(22);e();
   q();p(1);printf("2.����û�");p(22);e();
   q();p(1);printf("3.�༭�û�");p(22);e();
   q();p(1);printf("4.��������");p(22);e();
   q();p(1);printf("5.�޸Ĺ�������");p(18);e();
   q();p(1);printf("6.��������(���԰�)");p(14);e();
   q();p(1);printf("0.�˳�");p(16);ku();e();
   q();printf("��ѡ����������һ��,���س�����.");p(3);e();
}
   
    while(1){
     q();type=getchar();if(type=='\n')type='9';else qn();
     if(type>'6' || type<'0'){q();printf("�������!");j();
        i++;if(i==4)return 3;}
       else break;}
     if(type<'1')break;
     rb=managelinking(type);if(rb==1)break;
     q();printf("���Ƿ�Ҫ�������ڹ�����棿Y/N");j();
     if(rb!=2){q();enter=getchar();if(enter=='\n')enter='Y';else qn();
       if(enter=='N' || enter=='n'){
       q();printf("�Զ�������һ����.");j();sleep(1);return 2;}
     }
   }return 0;
}
int manage(){
   int rt=1;
   rt=keymanage(1);//��֤��������
   if(rt!=0){sleep(2);return rt;}//��֤����
   else { return managemenu();}//��֤�ɹ�
}
