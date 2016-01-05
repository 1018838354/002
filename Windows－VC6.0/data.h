struct da *create(char dat[]){//创建链表块
   mk++;
   news=(struct da *)malloc(sizeof(struct da));
   if(mk==1)head=tail=news;else {tail->next=news;tail=news;}
   strcpy(news->dat,dat);tail->next=NULL;
   return head;
}
int dawrite(){
 struct da *a=head;
 int i;
 FILE *data=fopen("data.txt","w");
  for(i=0;i<mk;i++){fputs(a->dat,data);a=a->next;}
  fclose(data);
  q();printf("成功写入数据!\n");sleep(1);
  return 2;
}

int dadelete(int nu){
   if(mk==0 ||head==NULL)return 1;//链表为空
   if(nu>4 &&nu<=mk){
     int i=0;
     struct da *a=head,*b=head;
     if(nu!=1){
		 for(i=0;i<nu-2;i++){a=a->next;}
     b=a->next;a->next=b->next;}else head=NULL;
     free(b);mk--;return 0;
   }q();printf("范围错误\n");return 1;//错误范围
}
int sort(){
   daload();
   if(mk==0 ||head==NULL)return 2;//链表为空
     int i=0,y=0,nu=0,ad=0;
     char us1[U]={0},us2[U]={0};
     struct da *a=head,*b=head,*c=head,*start=head;
     for(i=1;i<4;i++){start=start->next;}//初始化,此时start指向第4个链表块
        for(i=mk-1;i>4;i--){//采用冒泡法排序
          a=start;b=a->next;c=b->next;
          for(y=4;y<i;y++){
            for(ad=1;ad<U;ad++){
               us1[ad-1]=b->dat[ad];
               us2[ad-1]=c->dat[ad];}
            us1[ad]='\0';us2[ad]='\0';
            if(strcmp(us1,us2)>0){
               a->next=c;b->next=c->next;c->next=b;}
               a=a->next;b=a->next;c=b->next;}
        }q();printf("数据整理完成.\n");sleep(1);return dawrite();
}
void datahead(int a){
   FILE *data;
 char c1[5*H]="№--------------------------------------------℡\n";
   char c2[H]="|                  用户信息表                  |\n";
   char c3[H]="|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
   char c4[H]="| 编号  |  KEY |  姓名  |    QQ    |  电话号码 |\n";
   char c5[H]="|0154076|000000|  彭雪锋|1433473816|18470353419|\n";
   char c6[H]="|0154077|000000|  谢作辰| 979290167|15779660687|\n";
   char c7[H]="|0154078|000000|  曹利坚|1018838354|13316959801|\n";
   char c8[H]="|0154080|000000|  椰汁伟|1059654342|15170100866|\n";
   if(a==2){
     create(c1);create(c2);create(c3);create(c4);create(c5);
     create(c6);create(c7);create(c8);//存入链表
     //data=fopen("data.txt","w");
     dawrite();//存入文件
     q();printf("自动生成文件成功.\n");sleep(1);}
   if(a==1){strcat(c1,c2);strcat(c1,c3);strcat(c1,c4);printf("%s",c1);}
}
int daediu(char u[],int po){//通过用户编号编辑数据
     int i,y,nu=1;
   char us[U]={0};
     struct da *a=head,*b=head;
     for(y=1;y<=mk;y++){
       for(i=1;i<U;i++)us[i-1]=a->dat[i];us[i]='\0';
       a=a->next;
       if(strcmp(us,u)==0){return daedin(nu,po);}else nu++;
     }printf("%s,%s,%d,%d",us,u,po,nu);return 1;//未找到数据
}
int daedin(int nu,int po){//通过序号编辑数据
   int i,cname=0;
   char us[U],ke[K],na[Y],qq[Q],te[T];
   if(nu>4 &&nu<=mk){
     struct da *a=head,*b=head;
     char t[H];
     for(i=0;i<nu-1;i++){a=a->next;}
     for(i=0;i<U-1;i++)us[i]=a->dat[i+1];us[i]='\0';
     for(i=0;i<K-1;i++)ke[i]=a->dat[i+U+1];ke[i]='\0';
     for(i=1;i<Y;i++){
       na[i-1]=a->dat[i+U+K];if(na[i-1]=='|')break;}
     na[i-1]='\0';cname=i;
     for(i=1;i<Q;i++)qq[i-1]=a->dat[i+U+K+cname];qq[i-1]='\0';
     for(i=1;i<T;i++)te[i-1]=a->dat[i+U+K+cname+Q];te[i-1]='\0';
//----------menu
  while(1){
   i=1;
  {f();
   if(po==1){q();p(4);printf("管理用户界面,你好 %s.","管理员");p(4);e();}
   else {q();p(3);printf("用户管理界面,你好%s.",na);p(4);e();}
   q();p(2);stu();printf("~~~~~~~~~~~~~~~~~~~~~~~~");stu();p(3);e();
   q();p(1);printf("1.修改编号:%s",us);p(14);e();
   q();p(1);printf("2.修改密码:%s",ke);p(15);e();
   q();p(1);printf("3.修改姓名:%s",na);p(13);e();
   q();p(1);printf("4.修改QQ号:%s",qq);p(11);e();
   q();p(1);printf("5.修改手机号码:%s",te);p(6);e();
   if(po==1){q();p(1);printf("6.删除该用户");p(20);e();}
   else {q();p(1);printf("6.取消该帐号");p(20);e();}
   q();p(1);printf("0.退出");p(16);ku();e();
   q();printf("请选择输入其中一个,按回车进入.");p(3);e();
  }
//---------------
   char enter='0',type='0';
   while(1){
     q();type=getchar();if(type=='\n')type='9';else qn();
     if(type>'6' || type<'0'){q();printf("输入错误!");j();
       i++;if(i==4)return 2;}
     else break;
   }
   if(type<'1')break;
  if(daedimenu(type,t,0)==2)return 2;
   else switch(type){
       case '1':strcpy(us,t);break;
       case '2':strcpy(ke,t);break;
       case '3':strcpy(na,t);break;
       case '4':strcpy(qq,t);break;
       case '5':strcpy(te,t);break;
       case '6':dadelete(nu);sleep(1);dawrite();return 2;//正常删除
       default:q();printf("发生错误!\n");return 1;}
  }
   {t[0]='|';t[1]='\0';
    strcat(t,us);strcat(t,"|");
    strcat(t,ke);strcat(t,"|");
    strcat(t,na);strcat(t,"|");
    strcat(t,qq);strcat(t,"|");
    strcat(t,te);strcat(t,"|\n");
    strcpy(a->dat,t);//存入链表
   }
} 
  return dawrite();
}
int daedimenu(int ch,char t[],int z){
   int rb=1,rt=0;
  char enter='N';
       q();
       switch(ch){
       case '1':printf("请输入%d位数编号:\n",U-1);rt=getinf(U-1,t,z);break;
       case '2':printf("请输入%d位数密码:\n",K-1);rt=getinf(K-1,t,z);break;
       case '3':printf("请输入4个汉字内姓名:\n");rt=getinf(Y-1,t,z);break;
       case '4':printf("请输入%d位数内QQ号:\n",Q-1);rt=getinf(Q-1,t,z);break;
       case '5':printf("请输入%d位数电话号码:\n",T-1);rt=getinf(T-1,t,z);break;
       default:q();printf("发生错误!\n");return 1;} 
       if(rt==2){q();printf("你输入错误次数过多!\n");
                 q();printf("自动返回!\n");sleep(1);return 2;}
	   return 0;
 }
int tui(int *y,int k,char c3[]){
  int m;c3[*y]='\0';
  char su[H]={0};strcpy(su,c3);
  if(k==2){c3[(*y)-7]=' ';c3[(*y)-6]=' ';
      for(m=(*y)-5;m<(*y)+2;m++)
          c3[m]=su[m-2];(*y)+=2;}
  if(k==4){for(m=(*y)-5;m<(*y)-1;m++)c3[m]=' ';
      for(m=(*y)-1;m<(*y)+4;m++)
         c3[m]=su[m-4];(*y)+=4;}
  return 0;
}
int loading(){
   int i=0,y=0,ad=0,z,h=0,lk=1;
   char c[H]={0},c2[H]={0},t[2*H]={0},o[10]={0};
   FILE *data,*loadt;
   if ((data=fopen("data.txt","r"))==NULL){datahead(2);}
   else{daload();fclose(data);}
   if ((loadt=fopen("load.txt","r"))==NULL){return 1;}
   while(1){char c3[H]={0};z=0;
     fgets(c,H,loadt);
       if(ad!=0 &&strcmp(c2,c)==0){fclose(loadt);break;}
       else{ad++;strcpy(c2,c);//puts(c);//拷贝到c2,为检测读取相同
//     }fclose(data);q();printf("数据加载成功\n");sleep(0.03);return
   int rt=0,rb=1,rn=(int)strlen(c);
   if(rn<33)rt=1;//判断数据长度
     c3[0]='|';c3[1]='\0';int l2,l3,d3,d4,ui;
   for(i=0,y=1;i<=rn;){
   //j();sleep(0.03);printf("%d,%d,%d,%d,%d,%d,%s\n",z,rt,rb,i,rn,y,c3);
    //一行数据扫描检测
     if(i==rn){++z;break;}
     if(c[0]==' ' &&i==0)i++;if(c[1]==' ' &&i==1)i++;
     if(y==9){c3[9]='\0';strcat(c3,"000000|");y+=7;}
     if(c[i]==' ' ||c[i]=='\t'){if(c[i]==' ' &&c[i+1]==' ')i++;
                   else{c3[y]='|';z++;
                       if(z==1 &&y!=8)rt=1;
                       if(z==3 ){l3=y;d3=l3-l2;//printf("\n%d,%d",l2,l3);
                         if(d3<=11 &&d3>=6){
                         for(ui=l2+12;ui>l2;ui--)c3[ui]=c3[ui-11+d3];
                         for(ui=l2+1;ui<=l2+11-d3;ui++)c3[ui]=' ';
                         y+=(11-d3);l3=y;}else rt=1;}
                       i++;y++;}  }
     else{if(rb==1 &&c3[24]=='|'){if(z==2)l2=y-1;rb=0;}
          if(rb==1 &&c3[22]=='|'){tui(&y,2,c3);if(z==2)l2=y-1;rb=0;}
          if(rb==1 &&c3[20]=='|'){tui(&y,4,c3);if(z==2)l2=y-1;rb=0;}
          c3[y]=c[i];i++;y++;}
         }d4=y-l3;if(z==4 &&d4!=13)rt=1;//printf("%d%d%d%d\n",z,rt,rb,d4);
       if(z!=4 ||rt!=0 ||rb!=0){
            if(lk==1){lk++;q();printf("错误数据:\n");}
            q();printf("%s",c);sleep(1);}
      else{c3[y-1]='|';c3[y]='\n';c3[y+1]='\0';
           create(c3);h++;}  }}//一行处理完成
   if(h!=0){dawrite();q();printf("添加成功的数据:\n");
     sleep(1);//---------------
     struct da *a=head;
     for(i=0;i<(mk-h);i++){a=a->next;}
     datahead(1);
     while(1){printf("%s",a->dat);sleep((float)0.8);
     if(a->next==NULL)break;
     else {a=a->next;}}sleep(4);}return 0;
}
int daload(){
  if(mk!=0)return 0;
  int ad=0;
  char c[H]={0},c2[H]={0};
  //char su[G][H]={0};//建立2维数组
   FILE *data;
   if((data=fopen("data.txt","r"))==NULL){
     q();printf("数据不存在,请先添加数据\n");sleep(1);return 2;}
   else{
     while(1){
     fgets(c,H,data);
       if(ad!=0 &&strcmp(c2,c)==0)break;
       else{ad++;
         strcpy(c2,c);//拷贝到c2,为检测读取相同
         create(c);//创建并存到链表
         //strcpy(su[ad],c);//存到数组
         //bp();printf("%s",c);//依次显示
       }
     }fclose(data);q();printf("数据加载成功\n");sleep(1);return 0;
   }
}
int datasearch(char u[],char bk[]){
  int i,ad=0;
  char c[H]={0},c2[H]={0},u1[U]={0};
   FILE *data=fopen("data.txt","r");
   while(1){
     fgets(c,H,data);
       if(ad!=0 &&strcmp(c2,c)==0){fclose(data);return 2;}
       else{for(i=1;i<=U-1;i++)u1[i-1]=c[i];u1[U-1]='\0';
            strcpy(c2,c);ad++;}
     //puts(u);puts(u1);sleep(1);//显示输入编号和返回编号
     if(strcmp(u,u1)==0){
        strcpy(bk,c);for(i=0;i<U-2;i++)bk[i+U+1]='*';
        fclose(data);return 0;}
     }return 0;
}

int userkeydata(char u[],char bk[]){
  int i,ad=0;
  char c[H]={0},c2[H]={0},u1[U]={0};
   FILE *data;
   if ((data=fopen("data.txt","r"))==NULL)return 2;
   else{
   while(1){
     fgets(c,H,data);
       if(ad!=0 &&strcmp(c2,c)==0){fclose(data);return 2;}
       else{for(i=1;i<U;i++)u1[i-1]=c[i];u1[U-1]='\0';
            for(i=1;i<K;i++)bk[i-1]=c[i+8];bk[K-1]='\0';
            strcpy(c2,c);ad++;}
    if(strcmp(u,u1)==0){fclose(data);return 0;}
   }}
}
int datalook(){
  int ch=0,nu,i=1,rb=1;
  char enter;
  if(daload()!=0)return 2;//载入数据
 while(1){nu=1;
//显示数据-----------------------
     struct da *a=head;
     while(1){printf("%3d→%s",nu++,a->dat);
     if(a->next==NULL)break;
     else {a=a->next;}}nu--;
//--------------------完成显示
   while(1){
     q();printf("请输入你要修改的'5~%d'序号,返回请输入'0'.\n",nu);
     while(1){
     q();scanf("%d",&ch);qn();
     if(ch==0)return 2;
     if(ch>nu || ch<=4){q();printf("输入错误!");j();
        i++;if(i==4)return 3;}
       else break;
     }
     rb=daedin(ch,1);if(rb==1)break;
     q();printf("您是否要继续留在该界面？Y/N");j();
     if(rb!=2){q();enter=getchar();if(enter=='\n')enter='Y';else qn();
       if(enter=='N' || enter=='n'){
       q();printf("自动返回上一界面.");j();sleep(1);return 2;}
     }break;
  }
 }
}
int getinf(int a,char t[],int z){
   int i,rt,y,f=1;
   char en,tt[Y]="      ";//空置对齐
   while(1){
      q();
      for(i=0;i<a;i++){
        if((en=getchar())!='\n'){t[i]=en;rt=6;}//rt=6为正常返回
        else{
         if(a==Y-1 ||a==Q-1)//判断是否为可未满项
           {if(a==Y-1 && i%2==0)//判断为姓名输入,字符数规则
             {t[i]='\0';//puts(t);//显示输入姓名
              if(i==(Y-1)/2){tt[4]='\0';strcat(tt,t);i+=4;}
              if(i==(Y-1)*3/4){tt[2]='\0';strcat(tt,t);i+=2;}
              strcpy(t,tt);rt=0;break;}
         if(a==Q-1 &&i>=Q/2)//判断为QQ输入,位数规则
           {for(y=i-1;y>=0;y--){t[y+a-i]=t[y];t[y]=' ';}i=a;rt=0;break;}}
         {q();printf("输入错误,请重新输入:\n");rt=1;f++;if(f==4)return 2;}
         //判断为非未满项错误
        break;}}//强制退出for循环
     if(z==1){t[i]='|';t[i+1]='\0';}else t[i]='\0';
     if(rt==6){qn();break;}else{if(rt==0)break;}
     //判断为正确返回rt,否则需重新输入
   }return 0;
}
int adduser(){
   int i,rb=1,rt=0;
  char c[H]={0},t[20],ch='N';
  char enter='N';
   FILE *data;
   if ((data=fopen("data.txt","r"))==NULL){datahead(2);}
   else {daload();fclose(data);}
   while(1){
     c[0]='|';c[1]='\0';
     for(i=1;i<=5;i++){
       q();
       switch(i){
       case 1:printf("请输入7位数编号:\n");rt=getinf(U-1,t,1);break;
       case 2:printf("请输入6位数密码:\n");rt=getinf(K-1,t,1);break;
       case 3:printf("请输入4个汉字内姓名:\n");rt=getinf(Y-1,t,1);break;
       case 4:printf("请输入10位数内QQ号:\n");rt=getinf(Q-1,t,1);break;
       case 5:printf("请输入11位数电话号码:\n");rt=getinf(T-1,t,1);t[T]='\n';t[T+1]='\0';break;
       }strcat(c,t);
     if(rt==2){q();printf("你输入错误次数过多!\n");
               q();printf("自动返回!\n");sleep(1);return 2;}}
      create(c);//存入链表
      data=fopen("data.txt","a+");fputs(c,data);fclose(data);//存入数据
      datahead(1);puts(c);//显示添加数据
     q();printf("添加成功.\n");sleep(1);
     q();printf("是否继续添加?Y/N\n");
    if(rb!=2){q();enter=getchar();if(enter=='\n')enter='Y';else qn();
     if(enter=='N' || enter=='n'){
       q();printf("自动返回上一界面.");j();sleep(1);return 2;}     
   }}return 0;
}

