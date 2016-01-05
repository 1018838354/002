#include"source.h"
void menu(){
   f();
   q();p(8);printf("用户信息管理系统");p(9);e();
   q();p(7);stu();printf(" ~~~~~~~~~~~~~~~");stu();p(8);e();
   q();p(1);printf("1.信息查询");p(22);e();
   q();p(1);printf("2.用户入口");p(22);e();
   q();p(1);printf("3.管理入口");p(22);e();
   q();p(1);printf("0.退出");p(16);ku();e();
   q();printf("请选择输入其中一个,按回车进入.");p(3);e();
}//目录
int linking(char a){
   switch(a){
     case '1':return search();
     case '2':return user();
     case '3':return manage();
     default:q();printf("错误!\n");return 1;
   }
}//功能链接
int main(){
   char type='0',rt=1,rb=0,i=1;
   char enter='0';
   while(rt!=0){
     menu();
    while(1){
     q();type=getchar();if(type=='\n')type='9';else qn();
     if(type>'3' || type<'0'){
       q();printf("输入错误!");j();i++;if(i==4)goto Loop1;}
       else break;
     }
     if(type<'1')break;
     rb=linking(type);
     if(rb==3)break;
     q();printf("您是否要继续运行程序？Y/N");j();
     if(rb!=2){q();enter=getchar();if(enter=='\n')enter='Y';else qn();
     if(enter=='N' || enter=='n')break;}
  }
Loop1:q();printf("感谢您对sammi的支持!");j();
  sleep(2);return 0;
}//主程序入口
