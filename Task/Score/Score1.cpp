#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
struct Student{   //每个学生对应一个结构体 
	char ID[20];//学号 
	char Name[10];//姓名 
	float Mark1;//语文成绩 
	float Mark2;//数学成绩 
	float Mark3;//英语成绩 
	float Mark4;//品德成绩 
	float Mark5;//老师评价 
	float Mark6; //学生评价 
	float All; //总分 
	float Average;//平均成绩 
}students[1000];
int num=0; //计数器
void Copy(struct Student *arr,int i,int j)
{
	strcpy(arr[i].ID,arr[j].ID);
	strcpy(arr[i].Name,arr[j].Name);
	arr[i].Mark1 = arr[j].Mark1;
	arr[i].Mark2 = arr[j].Mark2;
	arr[i].Mark3 = arr[j].Mark3;
	arr[i].Mark4 = arr[j].Mark4;
	arr[i].Mark5 = arr[j].Mark5;
	arr[i].Mark6 = arr[j].Mark6;
	arr[i].All = arr[j].All;
	arr[i].Average = arr[j].Average;
}
int Student_SearchByName(char name[])//通过姓名来检索学生
{
     int i;
     for (i=0;i<num;i++)
     {
         if (strcmp(students[i].Name,name)==0)  //通过strcmp函数来对比学生姓名，找到返回在数组的位置 
         {
              return i;
       }
     }
     return -1;    //未找到返回 -1 
}
int Student_SearchByIndex(char id[])//通过学号来检索学生信息
{
     int i;
     for (i=0;i<num;i++)
     {
         if (strcmp(students[i].ID,id)==0)  //通过strcmp函数来对比学生id，找到返回位置 
         {
              return i;
         }  
     }
     return -1;   //未找到返回 -1 
}
void Student_DisplaySingle(int index)//输出表头
{
     printf("%10s%10s%8s%8s%8s%10s%8s%10s\n","学号","姓名","语文","数学","英语","品德","老师评价","学生评价","平均成绩");
     printf("-------------------------------------------------------------\n");
     printf("%10s%10s%8.2f%8.2f%8.2f%8.2f%10.2f%10.2f%10.2f\n",students[index].ID,students[index].Name,
              students[index].Mark1,students[index].Mark2,students[index].Mark3,students[index].Mark4,students[index].Mark5,students[index].Mark6,students[index].Average);
}
void inputt()//利用循环录入学生信息
{
     while(1)
     {
         printf("请输入学号:");
         scanf("%s",&students[num].ID);
         getchar();
         printf("请输入姓名:");
         scanf("%s",&students[num].Name);
         getchar();
         printf("请输入语文成绩:");
         scanf("%f",&students[num].Mark1);
         getchar();
         printf("请输入数学成绩:");
         scanf("%f",&students[num].Mark2);
         getchar();
         printf("请输入英语成绩:");
         scanf("%f",&students[num].Mark3);
         getchar();
         printf("请输入品德成绩:");
         scanf("%f",&students[num].Mark4);   //依次输入各项数据 
         getchar();
           printf("请输入老师评价:");
         scanf("%f",&students[num].Mark5);   //依次输入各项数据 
         getchar();
           printf("请输入学生评价:");
         scanf("%f",&students[num].Mark6);   //依次输入各项数据 
         getchar();
         students[num].All=students[num].Mark1+students[num].Mark2+students[num].Mark3+students[num].Mark4;    //输完数据后自动计算总成绩与平均成绩 
         students[num].Average=(students[num].Mark1+students[num].Mark2+students[num].Mark3)*0.18+ students[num].Mark4*0.1+students[num].Mark5*0.2+students[num].Mark6*0.1;
         if(Student_SearchByIndex(students[num].ID) == -1)
         {
         	num++;  //移向下一个位置 
		 }
		 else
		 {
		 	printf("学号重复，输入数据无效 !!!\n");
		 }
		 
 		 printf("是否继续?(y/n)");
         if (getchar()=='n')
         {
              break;
         }
     }
}
void modify()//修改成绩
{
	  while(1)
     {
         char id[20];
         int index;
         printf("请输入要修改的学生的学号:");
         scanf("%s",&id);
         getchar();
         index=Student_SearchByIndex(id);  //调用搜查id函数，根据其返回值确定位置 
         if (index==-1)
         {
              printf("学生不存在!\n");
         }
         else
         {
              printf("你要修改的学生信息为:\n");
              Student_DisplaySingle(index);
              printf("-- 请输入新值--\n");
              printf("请输入学号:");
              scanf("%s",&students[index].ID);
              getchar();
              printf("请输入姓名:");
              scanf("%s",&students[index].Name);
              getchar();
              printf("请输入语文成绩:");
              scanf("%f",&students[index].Mark1);
 			  getchar();
              printf("请输入数学成绩:");
              scanf("%f",&students[index].Mark2);
              getchar();
              printf("请输入英语成绩:");
              scanf("%f",&students[index].Mark3);
              getchar();
                printf("请输入品德成绩:");
               scanf("%f",&students[index].Mark4);   //依次输入各项数据 
              getchar();
             printf("请输入老师评价:");
         scanf("%f",&students[index].Mark5);   //依次输入各项数据 
         getchar();
           printf("请输入学生评价:");
         scanf("%f",&students[index].Mark6);   //依次输入各项数据 
         getchar();
         students[index].All=students[index].Mark1+students[index].Mark2+students[index].Mark3+students[index].Mark4;    //输完数据后自动计算总成绩与平均成绩 
         students[index].Average=(students[index].Mark1+students[index].Mark2+students[index].Mark3)*0.18+ students[index].Mark4*0.1+students[index].Mark5*0.2+students[index].Mark6*0.1;
         }
         printf("是否继续?(y/n)");
         if (getchar()=='n')
         {
              break;
         }
     }
}
void deletee()//删除学生信息
{
	  int i;
     while(1)
     {
         char id[20];
         int index;
         printf("请输入要删除的学生的学号:");
         scanf("%s",&id);
         getchar();
         index=Student_SearchByIndex(id);   //调用搜查id函数，根据其返回值确定位置 
         if (index==-1)
         {
              printf("学生不存在!\n");
         }
         else
         {
              printf("你要删除的学生信息为:\n");
              Student_DisplaySingle(index);
              printf("是否真的要删除?(y/n)");
              if (getchar()=='y')
              {
                   for (i=index;i<num-1;i++)
                   {
                   	   Copy(students,i,i+1);
                       //students[i]=students[i+1];    //把后边的对象都向前移动
                   }
                   num--;
              }
             getchar();
         }
         printf("是否继续?(y/n)");
         if (getchar()=='n')
         {
              break;
         }
     }
}
void display()//打印已录入的学生信息
{
	 int index;
     printf("%10s%10s%8s%8s%8s%8s%10s%10s%10s\n","学号","姓名","语文","数学","英语","品德","老师评价","学生评价","综合成绩");
     printf("-------------------------------------------------------------\n");
     for (index=0;index<num;index++)
     {
         printf("%10s%10s%8.2f%8.2f%8.2f%8.2f%10.2f%10.2f%10.2f\n",students[index].ID,students[index].Name,
              students[index].Mark1,students[index].Mark2,students[index].Mark3,students[index].Mark4,students[index].Mark5,students[index].Mark6,students[index].Average);
     }
}
void insert()//指定位置插入学生信息
{
		int a,b,c;
		printf("请输入你要插入的位置");
		scanf("%d",&a);
		if(a>num) {
		printf("输入的位置有误，请重新输入,当前共%d条数据\n",num); 
		scanf("%d",&a);}
     	b=num-1;
     	for(;b>=a-1;b--)
     	{
     		//strcpy(students[b+1].ID,students[b].ID);
     		//strcpy(students[b+1].Name,students[b].Name);
     		//students[b+1].Mark1=students[b].Mark1;
     		//students[b+1].Mark2=students[b].Mark2;
     		//students[b+1].Mark3=students[b].Mark3;
     		//students[b+1].Mark4=students[b].Mark4;
     		//students[b+1].All=students[b].All;
     		//students[b+1].Average=students[b].Average;  
			Copy(students,b+1,b); //根据其输入的位置，将其及以后的数据向后移动一个位置 
     		
		 }
		 num++;
         printf("请输入学号:");
         scanf("%s",&students[a-1].ID);
         getchar();
         printf("请输入姓名:");
         scanf("%s",&students[a-1].Name);
         getchar();
         printf("请输入语文成绩:");
         scanf("%f",&students[a-1].Mark1);
         getchar();
         printf("请输入数学成绩:");
         scanf("%f",&students[a-1].Mark2);
         getchar();
         printf("请输入英语成绩:");
         scanf("%f",&students[a-1].Mark3);
         getchar();
         printf("请输入品德成绩:");
         scanf("%f",&students[a-1].Mark4);  //输入新数据 
         getchar();  
             printf("请输入老师评价:");
         scanf("%f",&students[a-1].Mark4);  //输入新数据 
         getchar();
    printf("请输入学生评价:");
         scanf("%f",&students[a-1].Mark4);  //输入新数据 
         getchar();
         students[a-1].All=students[a-1].Mark1+students[a-1].Mark2+students[a-1].Mark3+students[a-1].Mark4;
         students[a-1].Average=(students[a-1].Mark1+students[a-1].Mark2+students[a-1].Mark3)*0.18+students[a-1].Mark4*0.1+students[a-1].Mark5*0.2+students[a-1].Mark6*0.1;
 
}
void search()//查询学生信息
{
	 while(1)
     {
         char name[20];
         int index;
         printf("请输入要查询的学生的姓名:");
         scanf("%s",&name);
         getchar();
         index=Student_SearchByName(name);   //调用搜查name函数，根据其返回值确定位置 
         if (index==-1)
         {
              printf("学生不存在!\n");
         }
         else
         {
              printf("你要查询的学生信息为:\n");
              Student_DisplaySingle(index);
         }
         printf("是否继续?(y/n)");
         if (getchar()=='n')
         {
              break;
         }
     }
}
void sort()//根据平均分排序
{
	 int i,j;
	 //struct students tmp;
     for (i=0;i<num;i++)
     {
     	students[i].Average=(students[i].Mark1+students[i].Mark2+students[i].Mark3)*0.18+students[i].Mark4*0.1+students[i].Mark5*0.2+students[i].Mark4*0.1;
     }
     for (i=0;i<num;i++)
     {
         for (j=1;j<num-i;j++)
         {
              if (students[j-1].Average<students[j].Average)
              {
                  
				   Copy(students,num,j-1);
				   Copy(students,j-1,j);
				   Copy(students,j,num); 
				   //tmp=students[j-1];
                   //students[j-1]=students[j];
                   //students[j]=tmp;      //冒泡排序 
            }  
         }
     }
     int a;
     printf("%10s%10s%8s%8s%8s%10s%10s%10s%10s\n","学号","姓名","语文","数学","英语","品德","老师评价","学生评价","综合成绩");
     printf("-------------------------------------------------------------\n");
     for (a=0;a<num;a++)
     {
         printf("%10s%10s%8.2f%8.2f%8.2f%8.2f%10.2f%10.2f%10.2f\n",students[a].ID,students[a].Name,
              students[a].Mark1,students[a].Mark2,students[a].Mark3,students[a].Mark4,students[a].Mark5,students[a].Mark6,students[a].Average);
     }
} 
 
 
void SearchLow()//搜索不及格的并输出 
{
	int a;
	printf("           语文不及格的有%10s%10s%8s\n","学号","姓名","语文"); 
	for(a=0;a<num;a++)
	{ 
		if(students[a].Mark1<60)
		printf("%10s%10s%8.2f\n",students[a].Name,students[a].ID,students[a].Mark1);    //从头搜索到尾，若小于60就输出 
	 } 
	 
	printf("           数学不及格的有%10s%10s%8s\n","学号","姓名","数学"); 
	for(a=0;a<num;a++)
	{ 
		if(students[a].Mark2<60)
		printf("%10s%10s%8.2f\n",students[a].Name,students[a].ID,students[a].Mark2);
	 } 
	 
	 printf("           英语不及格的有%10s%10s%8s\n","学号","姓名","英语");
	for(a=0;a<num;a++)
	{ 
		if(students[a].Mark3<60)
		printf("%10s%10s%8.2f\n",students[a].Name,students[a].ID,students[a].Mark3);
	 } 
	 
	 printf("           品德不及格的有%10s%10s%8s\n","学号","姓名","计算机");
	for(a=0;a<num;a++)
	{ 
		if(students[a].Mark4<60)
		printf("%10s%10s%8.2f\n",students[a].Name,students[a].ID,students[a].Mark4);
	 } 
	 system("pause");
}
 
void SearchHigh()//搜索成绩最高者输出 
{
	int a;
	int max ;
	printf("           语文最高分为%10s%10s%8s\n","学号","姓名","语文"); 
	max=students[0].Mark1;
	for(a=1;a<num;a++)
	{ 
		if(students[a].Mark1>max)
		max=students[a].Mark1;
	}
	for(a=0;a<num;a++)
	{ 
		if(max==students[a].Mark1)
		printf("%10s%10s%8.2f\n",students[a].Name,students[a].ID,students[a].Mark1);
	}
	
	printf("           数学最高分为%10s%10s%8s\n","学号","姓名","数学"); 
	max=students[0].Mark2;
	for(a=1;a<num;a++)
	{ 
		if(students[a].Mark2>max)
		max=students[a].Mark2;
	}
	for(a=0;a<num;a++)
	{ 
		if(max==students[a].Mark2)
		printf("%10s%10s%8.2f\n",students[a].Name,students[a].ID,students[a].Mark2);
	}
	
	printf("           英语最高分为%10s%10s%8s\n","学号","姓名","英语"); 
	max=students[0].Mark3;
	for(a=1;a<num;a++)
	{ 
		if(students[a].Mark3>max)
		max=students[a].Mark3;
	}
	for(a=0;a<num;a++)
	{ 
		if(max==students[a].Mark3)
		printf("           %10s%10s%8.2f\n",students[a].Name,students[a].ID,students[a].Mark3);
	}
	
	printf("           品德最高分为%10s%10s%8s\n","学号","姓名","计算机"); 
	max=students[0].Mark4;
	for(a=1;a<num;a++)
	{ 
		if(students[a].Mark4>max)
		max=students[a].Mark4;
	}
	for(a=0;a<num;a++)
	{ 
		if(max==students[a].Mark4)
		printf("           %10s%10s%8.2f\n",students[a].Name,students[a].ID,students[a].Mark4);
	}
	 system("pause");
}
void Save()
{
	FILE*fp = fopen("temp.txt","w+");
	fprintf(fp,"%d\n",num);
	for(int i = 0 ; i< num ;i++)
	{
		fprintf(fp,"%s %s %f %f %f %f %f %f %f\n",students[i].ID,students[i].Name,students[i].Mark1,students[i].Mark2,students[i].Mark3,students[i].Mark4,students[i].Mark5,students[i].Mark6,students[i].Average);
	}
	fclose(fp);
}
void Load()
{
	FILE*fp = fopen("temp.txt","r");
	fscanf(fp,"%d",&num);
	for(int i = 0 ; i< num ;i++)
	{
		fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",students[i].ID,students[i].Name,&students[i].Mark1,&students[i].Mark2,&students[i].Mark3,&students[i].Mark4,&students[i].Mark5,&students[i].Mark6,&students[i].Average);
	}
	fclose(fp);
} 
/*主程序*/
int main(){
	int i;
	while(1){
		 Load();
		 printf("\t\t\t\t\t-------- 学生成绩管理系统-------\n\n\n\n");     //菜单 
         printf("\t\t\t\t\t1. 增加学生记录\n\n");
         printf("\t\t\t\t\t2. 修改学生记录\n\n");
         printf("\t\t\t\t\t3. 删除学生记录\n\n");
         printf("\t\t\t\t\t4. 显示所有记录\n\n");
         printf("\t\t\t\t\t5. 查询学生记录\n\n");
         printf("\t\t\t\t\t6. 按平均成绩排序\n\n");
         printf("\t\t\t\t\t0. 退出\n\n\n");
         printf("请选择(0-9):");
 		 scanf("%d",&i);
			switch(i){
		 case 1:inputt();break;
		 case 2:modify();break;
	 	 case 3:deletee();break;
	 	 case 4:display();break;
		 case 5:search();break;
		 case 6:sort();break;
		 case 0:exit(0);
		 default:  ;
	}
	Save();
}
	 return 0; 
} 