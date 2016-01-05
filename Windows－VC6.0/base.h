void p(int a){
   int i;
   for(i=1;i<=a;i++)printf(" ");
}//空格
void l(){
   int a=1;
   int i;
   for(i=1;i<=a;i++)printf("｜");
}//'|'
void j(){
   int a=1;
   int i;
   for(i=1;i<=a;i++)printf("\n");
}//换行
void q(){
   p(20);l();p(1);
}//首行缩进
void e(){
   l();j();
}//尾行收
void f(){
   p(20);printf("№一一一一一一一一——一一一————℡");j();
}
void qn(){
   while(getchar()!='\n');
}//getchar去除输入缓存
int err(float a){
   q();printf("有待开发,请自行修改文本数据\n");sleep(a);return 0;
}
int ku(){
	if(mk>=4){
		printf("store:%3d ",mk-4);}
	else {printf("store:%3d ",0);}
	return 0;
}//库存数显示
int stu(){
   if(mk>0){printf("★");return 0;}
   else {printf("☆");return 1;}
}
