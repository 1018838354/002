int search(){
   int i=1;
   char enter;
   char u[U]={0},bk[H]={0};
  while(1){
   while(1){ FILE *data;
             if ((data=fopen("data.txt","r"))==NULL){
                q();printf("�ļ�������!\n");sleep(1);return 2;}
             else fclose(data);
     q();printf("��������Ҫ��ѯ�ı��:");j();
     if(getinf(U-1,u,0)==2)return 2;
   int f=datasearch(u,bk);
   if(f==2){q();printf("���ݲ�����!");j();i++;if(i==4)return 2;}
   else {q();printf("������ѯ���%s��Ϣ����:\n",u);datahead(1);
   puts(bk);break;}   }
//------------------------------------------------------------------
     q();printf("���Ƿ�Ҫ������ѯ��Y/N");j();
     q();enter=getchar();if(enter=='\n')enter='Y';else qn();
     if(enter=='N' || enter=='n'){
       q();printf("�Զ�������һ����.");j();sleep(1);return 2;}
  }
}
