#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct worker
{
	char depa[30];
	char name[30];
	char ID[10];
	int salary1;
	int salary2;
	int salary3;
	int salary4;
}; //职工信息 
int  dq(struct worker wo[]);
void bc(struct worker wo[]);
void show();       //主界面 
void add();        //添加信息 
void see();        //查看信息 
void search();     //查询信息 
void ghcz();       //按工号查找 
void xmcz();       //按姓名查找 
void bmcz();       //按部门查找 
void del();        //删除信息 
void xmsc() ;      //按姓名删除 
void ghsc();       //按工号删除 
void statistics(); //个人工资统计 
void statistic();  //总计职工工资 
void statistic1(); //统计职工工资
void average();    //职工工资求平均 
void gzdtj();      //按工资段统计 
void bmtj();       //按部门统计 
void modify();     //修改职工信息 
void ghxg();       //按工号修改 
void xmxg();       //按姓名修改 
void sort();       //职工工资排序 
void reserve();    //保存 
void back();       //返回 
 struct worker wo[100];  //保存所有的职工信息
 int Number=0;           //记录总的职工人数 
 int main()
{  
 int choose=0; 
 while (1)
{
show();
 printf ("\t\t====>请选择:");
 scanf ("%d",&choose); 
 system ("cls");
 switch (choose)
{
 case 0:exit(0);  //退出 
 break ;
 case 1:add();
 back();   //添加职工信息 
 break ;
 case 2:see();
 back() ;  //查看职工信息 
 break ;
 case 3:search();
 back();   //查找职工信息 
 break ;
 case 4:del() ;
 back();   //删除职工信息 
 break ;
 case 5:statistics(); 
 back( );  //个人工资统计 
 break ;
 case 6:statistic(); 
 back();   //总记职工工资 
 break ;
 case 7:sort();
 back();   //排序职工信息 
 break ;
 case 8:modify();
 back();   //修改职工信息 
 break ;
 case 9:reserve(); 
 back();   //保存数据 
 break ;
 default:
 break;
}
 fflush(stdin);
 system ("cls");
 system("pause");
}
}
 int dq(struct worker wo[])
{
 FILE*fp=NULL;
 int i=0;
 fp=fopen("C://worker.dat","rb");
 while(fread(&wo[i],sizeof(struct worker),1,fp))
 i++;
 fclose (fp); 
 return i;
 } 
 
 void bc(struct worker *wo)
{
	FILE*fp=NULL;
 fp=fopen("C://worker.dat","ab+");
 fwrite(wo,sizeof(struct worker),1,fp); 
 fclose(fp);
 system("pause");
}
 void show ()
 {
 
 printf ("\n");
 printf ("\t——欢迎进入职工工资管理系统！您可以进行以下操作！——\n");
 printf ("\t——————————————————————————————————————————————\n");
 printf ("\t——             职工工资管理系统              ——\n");
 printf ("\t——————————————————————————————————————————————\n");
 printf ("\t///No.1—————[1]添加职工信息                  ——\n");
 printf ("\t///No.2—————[2]查看职工信息                  ——\n");
 printf ("\t///No.3—————[3]查找职工信息                  ——\n");
 printf ("\t///No.4—————[4]删除职工信息                  ——\n");
 printf ("\t///No.5—————[5]个人工资统计                  ——\n");
 printf ("\t///No.6—————[6]总记职工工资                  ——\n");
 printf ("\t///No.7—————[7]排序职工工资                  ——\n");
 printf ("\t///No.8—————[8]修改职工信息                  ——\n");
 printf ("\t///No.9—————[9]保 存 数 据                  ——\n"); 
 printf ("\t///No.0—————[0]退 出 系 统                  ——\n");  
 printf ("\t——————————————————————————————————————————————\n");
 printf ("\t——————————————————————————————————————————————\n");
}
 
 
 void add()  //添加职工信息 
{
 int numberTemp=0; 
 int i=0;
 struct worker temp;
 printf("请输入要添加职工个数:"); 
 scanf ("%d",&numberTemp);
 for (i=0;i<numberTemp;i++)
{
 printf ("输入第%d个职工信息\n",i+1); 
 printf ("姓名:");
 scanf ("%s",temp.name); 
 printf ("工号:");
 scanf ("%s",temp.ID);
 printf ("所属部门:"); 
 scanf ("%s",temp.depa); 
 printf ("基本工资:");
 scanf ("%d",&temp.salary1); 
 printf ("奖励工资:");
 scanf ("%d",&temp.salary2); 
 printf ("补贴项目即金额:");
 scanf ("%d",&temp.salary3);
 printf ("扣除项目即金额:");
 scanf ("%d",&temp.salary4);
 wo[Number++]=temp;   //写入到数组 
 bc(&temp);           //写入到文件
 system("pause");
}
 printf ("添加成功!\n");
}
void see() //查看职工信息 
{
 int i=0;
 printf ("以下是全部职工\n");
 printf ("姓名    工号         所属部门    基本工资     奖励工资     补贴项目及金额     扣款项目及金额    总工资\n"); 
 while (i<Number)
{
 printf ("%s  %s    %s      %d        %d            %d               %d         %d\n",wo[i].name,wo[i].ID,wo[i].depa,wo[i].salary1,wo[i].salary2,wo[i].salary3,wo[i].salary4,wo[i].salary1+wo[i].salary2+wo[i].salary3-wo[i].salary4);
 i++;
}system("pause");
}
void search()  //查找职工信息
{
 int n=0;
 printf("1 按姓名查找\n"); 
 printf("2 按工号查找\n"); 
 printf("3 按部门查找\n"); 
 scanf ("%d",&n);
 switch (n) 
{
 case 1:xmcz(); 
 break ;
 case 2:ghcz(); 
 break ;
 case 3:bmcz(); 
 break ;
 default: printf ("输入错误!\n"); 
 break ;
}system("pause");
}
void xmcz()  //按姓名查找
{
 char name[30]; 
 int i=0;
 printf ("请输入要查找职工姓名:"); 
 scanf ("%s",name);
 system ("cls");
 printf ("姓名    工号         所属部门    基本工资     奖励工资     补贴项目及金额     扣款项目及金额    总工资\n");
 for (i=0;i<Number;i++)
{
  if (strcmp(name,wo[i].name)==0)
{
	printf("%s  %s    %s      %d        %d            %d               %d         %d\n",wo[i].name,wo[i].ID,wo[i].depa,wo[i].salary1,wo[i].salary2,wo[i].salary3,wo[i].salary4,wo[i].salary1+wo[i].salary2+wo[i].salary3-wo[i].salary4);
}
}system("pause");
}
void ghcz()  //按工号查找
{
  char id[10];
  int i=0;
  printf("请输入要查找工号:");
  scanf("%s",id);
  system("cls");
  printf ("姓名    工号         所属部门    基本工资     奖励工资     补贴项目及金额     扣款项目及金额    总工资\n");
 for(i=0;i<Number;i++){
 	if(strcmp(id,wo[i].ID)==0)
 {
 	printf("%s  %s    %s      %d        %d            %d               %d         %d\n",wo[i].name,wo[i].ID,wo[i].depa,wo[i].salary1,wo[i].salary2,wo[i].salary3,wo[i].salary4,wo[i].salary1+wo[i].salary2+wo[i].salary3-wo[i].salary4);
}
}system("pause");
}
void bmcz()  //按部门查找
{
  char depa[30];
  int i=0;
  printf("请输入要查找部门名称:");
  scanf("%s",depa);
  system("cls");
  printf ("姓名    工号         所属部门    基本工资     奖励工资     补贴项目及金额     扣款项目及金额    总工资\n");
 for(i=0;i<Number;i++){
 	if(strcmp(depa,wo[i].depa)==0)
 {
 	printf("%s  %s    %s      %d        %d            %d               %d         %d\n",wo[i].name,wo[i].ID,wo[i].depa,wo[i].salary1,wo[i].salary2,wo[i].salary3,wo[i].salary4,wo[i].salary1+wo[i].salary2+wo[i].salary3-wo[i].salary4);
}
}system("pause");
}
void del()  //删除职工信息 
{
 int n=0;
 printf ("1 按姓名删除\n"); 
 printf ("2 按工号删除\n"); 
 scanf ("%d",&n);
 switch (n)
{
	case 1: xmsc(); 
	break ;
    case 2: ghsc(); 
	break ;
}system("pause");
}
 void xmsc ()//按姓名删除
{
 FILE*fp=NULL;
 char name[30]; 
 int i=0;
 int j=0;
 printf ("请输入要删除的职工姓名:"); 
 scanf ("%s",name);
 for (i=0;i<Number;i++)
 { 
   if (strcmp(name,wo[i].name)==0)
 {
   for (j=i;j<Number-1;j++)
   {
    wo[j]=wo[j+1];
	}
 
 Number --;
 }system("pause");
}
 
//将剩余数据写入文件擦除以前的数据
 fp = fopen ("C://worker.dat","wb"); 
 for (i=0;i<Number;i++)
 {
 	fwrite(&wo[i],sizeof(struct worker),1,fp);
 }
 fclose (fp); 
 printf ("删除成功!\n");
}
 void ghsc()  //按工号删除 
{
 FILE*fp=NULL;
 char id[60]; 
 int i=0;
 int j=0;
 printf ("请输入要删除的职工工号:"); 
 scanf ("%s",id);
 for (i=0;i<Number;i++)
 {
   if (strcmp(id,wo[i].ID)==0)
{
 for(j=i;j<Number-1;j++)
{
 wo[j]=wo[j+1];
 }
Number--;
 }system("pause");
}
 
//将剩余数据写入文件擦除以前的数据 
 fp=fopen("C://worker.dat","wb");
 for (i=0;i<Number;i++)
{
fwrite(&wo[i],sizeof(struct worker),1,fp);
 }
fclose (fp);
 printf ("删除成功!\n");
}
 void statistics() //个人工资统计  
{
 int i=0;
 double sum[100]; 
 for (i=0;i<Number;i++)
 {
 sum[i]=wo[i].salary1+wo[i].salary2+wo[i].salary3-wo[i].salary4;
 printf ("%s的总工资为:%f\n",wo[i].name,sum[i]);
}system("pause");
}
void statistic()   //总计职工工资 
{
   int n=0;
 printf ("1 统计职工工资\n"); 
 printf ("2 职工工资求平均\n"); 
 scanf ("%d",&n);
 switch (n){
 case 1:statistic1(); 
 break ;
 case 2:average();
 break ;
 default:printf("输入错误!\n");
 break;
 }system("pause");
}
 void statistic1()  //统计职工工资
{
 int n=0;
 printf ("1 按工资段统计\n"); 
 printf ("2 按部门统计\n"); 
 scanf ("%d",&n);
 switch (n){
 case 1:gzdtj(); 
 break ;
 case 2:bmtj();
 break ;
 default:printf("输入错误!\n");
 break;
}system("pause");
}
void gzdtj()  //按工资段统计
{ 
 int sa1,sa2;
 int i=0;
 int n,m;
 int sl[20]={0,0}; 
 double sum [100];
 printf ("请输入要查询的工资段:"); 
 scanf ("%d,%d",&sa1,&sa2);
 system ("cls");
 for (i=0;i<Number;i++)
{
 sum[i]=wo[i].salary1+wo[i].salary2+wo[i].salary3-wo[i].salary4;
 }
 for (i=0;i<Number;i++)
 { n=sum[i]/1000;
 if (n>9) 
 n=10;
 switch(n)
{ case 0:sl[0]++; 
  break ; 
  case 1:sl[1]++; 
  break ; 
  case 2:sl[2]++; 
  break ; 
  case 3:sl[3]++; 
  break ; 
  case 4:sl[4]++; 
  break ; 
  case 5:sl[5]++; 
  break ;
  case 6:sl[6]++; 
  break ; 
  case 7:sl[7]++; 
  break ; 
  case 8:sl[8]++; 
  break ; 
  case 9:sl[9]++; 
  break ; 
  case 10:sl[10]++; 
  break ;
  }
}
 m=sa1/1000; 
 switch(m)
{case 0:printf ("工资在1000以下的人数为%d\n",sl[0]); break ;
 case 1:printf("工资在1000到2000之间的人数为%d\n",sl[1]); break ;
 case 2:printf("工资在2000到3000之间的人数为%d\n",sl[2]); break ;
 case 3:printf("工资在3000到4000之间的人数为%d\n",sl[3]); break ; 
 case 4:printf("工资在4000到5000之间的人数为%d\n",sl[4]); break ;
 case 5:printf("工资在5000到6000之间的人数为%d\n",sl[5]); break ;
 case 6:printf("工资在6000到7000之间的人数为%d\n",sl[6]); break ;
 case 7:printf("工资在7000到8000之间的人数为%d\n",sl[7]); break ;
 case 8:printf("工资在8000到9000之间的人数为%d\n",sl[8]); break ;
 case 9:printf("工资在9000到10000之间的人数为%d\n",sl[9]);break ;
 case 10:printf("工资在10000以上的人数为%d\n",sl[10]);    break ;
 }system("pause");
}
void bmtj()   //按部门统计
{
 char depa[30]; 
 float sum=0;
 int i=0;
 printf("请输入要查询的部门名称:"); 
 scanf ("%s",depa);
 system ("cls");
 printf ("姓名    工号         所属部门    基本工资     奖励工资     补贴项目及金额     扣款项目及金额    总工资\n");
 for(i=0;i<Number;i++){
  if (strcmp(depa,wo[i].depa)==0)
{ 
   printf("%s  %s    %s      %d        %d            %d               %d         %d\n",wo[i].name,wo[i].ID,wo[i].depa,wo[i].salary1,wo[i].salary2,wo[i].salary3,wo[i].salary4,wo[i].salary1+wo[i].salary2+wo[i].salary3-wo[i].salary4);
 sum=sum+wo[i].salary1+wo[i].salary2+wo[i].salary3-wo[i].salary4;
}
}
printf("该部门的总工资为:%f\n",sum);
system("pause");
}
 void average()   //职工工资求平均   
{   double all=0;
    double sum[100];
    int cnt=0;
	int i=0;
	printf("职工工资平均值如下:\n");
	for (i=0;i<Number;i++)
{
 sum[i]=wo[i].salary1+wo[i].salary2+wo[i].salary3-wo[i].salary4;
 all+=sum[i];
 cnt++;
 }
 all/=cnt;
 printf("%f\n",all);
 system("pause");
}
 void sort()  //职工工资排序
{
 int i=0;
 int m,n;
 double sum[100];
 double t;
 struct worker p;
 for (i=0;i<Number;i++)
 sum[i]=wo[i].salary1+wo[i].salary2+wo[i].salary3-wo[i].salary4;
 for(m=1;m<Number;m++){
   	for(n=1;n<Number;n++){
   		if(sum[n]>sum[n-1]){
   			t=sum[n];
   			sum[n]=sum[n-1];
   			sum[n-1]=t;
   		    p=wo[n];
   		    wo[n]=wo[n-1];
   		    wo[n-1]=p;
		   }
	   }
   } 
  for (i=0;i<Number;i++)
    printf ("%s的总工资为:%lf\n",wo[i].name,sum[i]);
system("pause");
}
void modify()  //修改职工信息
{
 int mode=0; 
printf ("请选择修改查找方式\n"); 
printf ("1 按姓名查找修改\n"); 
printf ("2 按工号查找修改\n"); 
scanf ("%d",&mode);
 switch (mode){
 case 1: xmxg() ; 
 break ;
 case 2:ghxg(); 
 break ;
 default : printf ("输入错误!\n"); 
 break ;
}system("pause");
}
void xmxg()  //按姓名修改
{
 FILE*fp=NULL ; 
 char name[30]; 
 int i=0;
 printf ("请输入要修改的职工姓名:");
 scanf ("%s",name); 
 for (i=0;i<Number;i++)
{
 if (strcmp(name,wo[i].name));
 else 
 break;}
 printf ("姓名    工号         所属部门    基本工资     奖励工资     补贴项目及金额     扣款项目及金额    总工资\n"); 
 printf ("%s  %s    %s      %d        %d            %d               %d         %d\n",wo[i].name,wo[i].ID,wo[i].depa,wo[i].salary1,wo[i].salary2,wo[i].salary3,wo[i].salary4,wo[i].salary1+wo[i].salary2+wo[i].salary3-wo[i].salary4);
 printf ("请重新输入该职工信息\n"); 
 printf ("姓名:");
 scanf ("%s",wo[i].name); 
 printf ("工号:");
 scanf ("%s",wo[i].ID);
 printf ("所属部门:"); 
 scanf ("%s",wo[i].depa); 
 printf ("基本工资:");
 scanf ("%d",&wo[i].salary1); 
 printf ("奖励工资:");
 scanf ("%d",&wo[i].salary2); 
 printf ("补贴项目即金额:");
 scanf ("%d",&wo[i].salary3);
 printf ("扣除项目即金额:");
 scanf ("%d",&wo[i].salary4);
//将剩余数据写入文件擦除以前的数据
 fp = fopen ("C://worker.dat","wb"); 
 for (i=0;i<Number;i++)
 {
 	fwrite(&wo[i],sizeof(struct worker),1,fp);
 }
 fclose ( fp ); 
 printf("\t=======>修改成功!\n");
 system("pause");
}
void ghxg()  //按工号修改
{
 FILE*fp=NULL ; 
 char id[30]; 
 int i=0;
 printf ("请输入要修改的职工工号:");
 scanf ("%s",id); 
 for (i=0;i<Number;i++)
{
 if (strcmp(id,wo[i].ID));
 else 
 break ;}
 printf ("姓名    工号         所属部门    基本工资     奖励工资     补贴项目及金额     扣款项目及金额    总工资\n"); 
 printf ("%s  %s    %s      %d        %d            %d               %d         %d\n",wo[i].name,wo[i].ID,wo[i].depa,wo[i].salary1,wo[i].salary2,wo[i].salary3,wo[i].salary4,wo[i].salary1+wo[i].salary2+wo[i].salary3-wo[i].salary4);
 printf ("请重新输入该职工信息\n"); 
 printf ("姓名:");
 scanf ("%s",wo[i].name); 
 printf ("工号:");
 scanf ("%s",wo[i].ID);
 printf ("所属部门:"); 
 scanf ("%s",wo[i].depa); 
 printf ("基本工资:");
 scanf ("%d",&wo[i].salary1); 
 printf ("奖励工资:");
 scanf ("%d",&wo[i].salary2); 
 printf ("补贴项目即金额:");
 scanf ("%d",&wo[i].salary3);
 printf ("扣除项目即金额:");
 scanf ("%d",&wo[i].salary4);
//将剩余数据写入文件擦除以前的数据
 fp = fopen ("C://worker.dat","wb"); 
 for (i=0;i<Number;i++)
 {
 	fwrite(&wo[i],sizeof(struct worker),1,fp);
 }
 fclose ( fp ); 
 printf("\t=======>修改成功!\n");
 system("pause");
}
 
void reserve()  //保存数据
{
  printf("\t=====>程序在运行时已自动保存....\n");
  system("pause");
 } 
void back()
{
	printf("\t=====>按Enter键返回主菜单\n");
	system("pause");
}