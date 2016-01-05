int search(){
   int i=1;
   char enter;
   char u[U]={0},bk[H]={0};
  while(1){
   while(1){ FILE *data;
             if ((data=fopen("data.txt","r"))==NULL){
                q();printf("文件不存在!\n");sleep(1);return 2;}
             else fclose(data);
     q();printf("请输入您要查询的编号:");j();
     if(getinf(U-1,u,0)==2)return 2;
   int f=datasearch(u,bk);
   if(f==2){q();printf("数据不存在!");j();i++;if(i==4)return 2;}
   else {q();printf("你所查询编号%s信息如下:\n",u);datahead(1);
   puts(bk);break;}   }
//------------------------------------------------------------------
     q();printf("您是否要继续查询？Y/N");j();
     q();enter=getchar();if(enter=='\n')enter='Y';else qn();
     if(enter=='N' || enter=='n'){
       q();printf("自动返回上一界面.");j();sleep(1);return 2;}
  }
}
