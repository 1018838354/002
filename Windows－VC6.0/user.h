int usermenu(char u[]){
   int rt=1,i=1;
   daload();
   return daediu(u,0);
}
int user(){
   char u[U]={0};
     FILE *data;
     if ((data=fopen("data.txt","r"))==NULL){
        q();printf("�ļ�������,�����������\n");sleep(1);return 2;}
     else fclose(data);
   int rt=keyuser(u);//��֤�û���������
   if(rt!=0){sleep(1);return rt;}//��֤����1
   else { return usermenu(u);}//��֤�ɹ�0
}
