int loaddata(){
   while(1){
   f();
   q();p(10);printf("导入数据窗口");p(11);e();
   q();p(8);stu();printf(" ~~~~~~~~~~~~~");stu();p(9);e();
   q();p(1);printf("导入数据文件名load.txt导入模板:");p(1);e();
   f();
   q();printf(" 编号   姓名    QQ     电话号码  ");e();
   q();printf("0158001 张三 10188080 18893868540");e();
   q();printf("\b~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");e();
   q();p(4);printf("注意每项信息之间保持空格.");p(4);e();
   q();p(4);printf("默认用户登陆密码为000000.");p(4);e();
   q();p(8);printf("本功能只是测试版,");p(8);e();
   q();p(4);printf("请使用时认真按照以上模板.");p(4);e();
   q();printf("直接摁回车确认导入.输入'N'退出。");p(1);e();
   q();if(getchar()=='\n'){if(loading()!=0){q();printf("发生错误!\n");}}
       else {qn();q();printf("自动返回上一界面.\n");sleep(1);return 2;}}
}

int managedi(){
   if(daload()!=0)return 2;
   char t[20]={0};
   q();printf("请输入您要编辑的用户编号:\n");
   if(getinf(U-1,t,0)==0)daediu(t,1);
   else {q();printf("不存在数据!\n");sleep(1);return 2;}
}
int managelinking(char a){
   switch(a){
     case '1':return datalook();
     case '2':return adduser();
     case '3':return managedi();
     case '4':return sort();
     case '5':return keymanage(5);//5为修改密码
     case '6':return loaddata();//外联文件信息导入
     default:q();printf("发生错误!\n");return 1;
   }
}//功能链接


int managemenu(){
   int rt=1,rb=1,i=1;
   char enter,type='0';
   while(rt!=0){
{  f();
   q();p(10);printf("超级管理界面");p(11);e();
   q();p(8);stu();printf(" ~~~~~~~~~~~~~");stu();p(9);e();
   q();p(1);printf("1.信息查看");p(22);e();
   q();p(1);printf("2.添加用户");p(22);e();
   q();p(1);printf("3.编辑用户");p(22);e();
   q();p(1);printf("4.整理数据");p(22);e();
   q();p(1);printf("5.修改管理密码");p(18);e();
   q();p(1);printf("6.导入数据(测试版)");p(14);e();
   q();p(1);printf("0.退出");p(16);ku();e();
   q();printf("请选择输入其中一个,按回车进入.");p(3);e();
}
   
    while(1){
     q();type=getchar();if(type=='\n')type='9';else qn();
     if(type>'6' || type<'0'){q();printf("输入错误!");j();
        i++;if(i==4)return 3;}
       else break;}
     if(type<'1')break;
     rb=managelinking(type);if(rb==1)break;
     q();printf("您是否要继续留在管理界面？Y/N");j();
     if(rb!=2){q();enter=getchar();if(enter=='\n')enter='Y';else qn();
       if(enter=='N' || enter=='n'){
       q();printf("自动返回上一界面.");j();sleep(1);return 2;}
     }
   }return 0;
}
int manage(){
   int rt=1;
   rt=keymanage(1);//验证管理密码
   if(rt!=0){sleep(2);return rt;}//验证错误
   else { return managemenu();}//验证成功
}
