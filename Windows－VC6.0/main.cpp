#include"source.h"
void menu(){
   f();
   q();p(8);printf("�û���Ϣ����ϵͳ");p(9);e();
   q();p(7);stu();printf("~~~~~~~~~~~~~~~");stu();p(7);e();
   q();p(1);printf("1.��Ϣ��ѯ");p(22);e();
   q();p(1);printf("2.�û����");p(22);e();
   q();p(1);printf("3.�������");p(22);e();
   q();p(1);printf("0.�˳�");p(16);ku();e();
   q();printf("��ѡ����������һ��,���س�����.");p(3);e();
}//Ŀ¼
int linking(char a){
   switch(a){
     case '1':return search();
     case '2':return user();
     case '3':return manage();
     default:q();printf("����!\n");return 1;
   }
}//��������
int main(){
   char type='0',rt=1,rb=0,i=1;
   char enter='0';
   while(rt!=0){
     menu();
    while(1){
     q();type=getchar();if(type=='\n')type='9';else qn();
     if(type>'3' || type<'0'){
       q();printf("�������!");j();i++;if(i==4)goto Loop1;}
       else break;
     }
     if(type<'1')break;
     rb=linking(type);
     if(rb==3)break;
     q();printf("���Ƿ�Ҫ�������г���Y/N");j();
     if(rb!=2){q();enter=getchar();if(enter=='\n')enter='Y';else qn();
     if(enter=='N' || enter=='n')break;}
  }
Loop1:q();printf("��л����sammi��֧��!");j();
  sleep(2);return 0;
}//���������
