int usermenu(char u[]){
   int rt=1,i=1;
   daload();
   return daediu(u,0);
}
int user(){
   char u[U]={0};
     FILE *data;
     if ((data=fopen("data.txt","r"))==NULL){
        q();printf("文件不存在,请先添加数据\n");sleep(1);return 2;}
     else fclose(data);
   int rt=keyuser(u);//验证用户管理密码
   if(rt!=0){sleep(1);return rt;}//验证错误1
   else { return usermenu(u);}//验证成功0
}
