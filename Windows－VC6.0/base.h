void p(int a){
   int i;
   for(i=1;i<=a;i++)printf(" ");
}//�ո�
void l(){
   int a=1;
   int i;
   for(i=1;i<=a;i++)printf("��");
}//'|'
void j(){
   int a=1;
   int i;
   for(i=1;i<=a;i++)printf("\n");
}//����
void q(){
   p(20);l();p(1);
}//��������
void e(){
   l();j();
}//β����
void f(){
   p(20);printf("��һһһһһһһһ����һһһ���������Y");j();
}
void qn(){
   while(getchar()!='\n');
}//getcharȥ�����뻺��
int err(float a){
   q();printf("�д�����,�������޸��ı�����\n");sleep(a);return 0;
}
int ku(){
	if(mk>=4){
		printf("store:%3d ",mk-4);}
	else {printf("store:%3d ",0);}
	return 0;
}//�������ʾ
int stu(){
   if(mk>0){printf("��");return 0;}
   else {printf("��");return 1;}
}
