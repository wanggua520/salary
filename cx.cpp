#include<stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>
int a,b,c,d,e,f;
struct worker
{
char num[10];
char name[30];
int gwgz;
int xjsz;
int zwjt;
int xjgz;
int yfgz;
int grsds;
int salary;
};
int dq(struct worker wo[]);
void show();
void bc(struct worker wo[]);
void read(struct worker *wo);
void write();
void find();
void list();
void modify();
void del();
void add(); 
void grads();
void ghcz();
void xmcz();
void xmsc();
void ghsc();
void statistics();
void ghxg(); 
void xmxg();
void back();
struct worker wo[100]; //保存所有的职工信息
int Number=0; //记录总的职工人数
int i,j,n,m,sum[100],num[100],p=0; 
int score[100][20],lower,maxer,temp=0; 
void show()
{ 
printf("\n");
printf("\t工资管理系统 \n\n");
printf("\t\n\n");
printf("\t1. 查找职工信息\n");
printf("\t2. 修改职工信息\n");
printf("\t3. 添加职工信息\n");
printf("\t4. 删除职工信息\n");
printf("\t5. 保 存  数 据\n");
printf("\t6. 预览\n");
printf("\t0. 退 出 系 统 \n");
printf("\t\n");
}
void read(struct worker *wo)
{
FILE *fp=NULL;
fp=fopen("gx.dat","wb+");
fread(wo,sizeof(struct worker),1,fp);
while(i<Number)
{
printf("\t%s\t%s\t%d\n",wo[i].num,wo[i].name,wo[i].salary);
}
fclose(fp);
}

void bc(struct worker *wo)
{
FILE *fp=NULL;
fp=fopen("gx.dat","wb+");
fwrite(wo,sizeof(struct worker),1,fp);
fclose(fp);
}
//添加职工信息
void add() 
{
int numberTemp=0;
int i=0;
struct worker temp; 
printf("请输入要添加职工个数：");
scanf("%d",&numberTemp);
for(i=0;i<numberTemp;i++)
{
printf("输入第%d个职工信息\n",i+1);
printf("工号：");
scanf("%s",temp.num);
printf("姓名：");
scanf("%s",temp.name);
printf("实发工资：");
scanf("%d",&temp.salary);
wo[Number++]=temp; //写入到数组
bc(&temp); //写入到文件
}
printf("添加成功\n");
}
//修改成员数据
void modify()
{

}
//查看职工信息
void list() 
{
int i=0;
printf("以下是全部职工\n");
printf("\t工号\t姓名\t基本工资\n");
while(i<Number)
{
printf("\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",wo[i].num,wo[i].name,wo[i].gwgz,wo[i].xjsz,wo[i].zwjt,wo[i].xjgz,wo[i].yfgz,wo[i].grsds,wo[i].salary);
i++;
}
}
//查找职工信息
void find() 
{
int n=0;
printf("1 按姓名查找\n");
printf("2 按工号查找\n"); 
scanf("%d",&n);
switch(n)
{
case 1: xmcz();
break;
case 2: ghcz();
break;
default: printf("输入错误!\n");
break;
} 
}
void xmcz()//按姓名查找 
{ 

}
void ghcz()//按工号查找 
{
}
//删除职工信息
void del() 
{
int n=0;
printf("1 按姓名删除\n");
printf("2 按工号删除\n");
scanf("%d",&n);
switch(n)
{
case 1: xmsc();
break;
case 2: ghsc();
break;
}
}
void xmsc()//按姓名删除 
{
}
void ghsc()//按工号删除 
{


}
//统计职工工资
void statistics() 
{
int i=0;
double s=0.0;
double sum[100];
for(i=0;i<Number;i++)
{
sum[i]=wo[i].salary;
printf("%s的总工资为：%f\n",wo[i].name,sum[i]);
}
for(i=0;i<Number;i++)
{
s+=sum[i];
}
printf("平均工资为：%f\n",s/Number); 
} 
//void list()
//保存数据
void write()
{
printf("\t=====程序在运行时已自动保存.....\n");
}
void back()
{
printf("\t===>按Enter键返回主菜单\n");
}
void system()
{
int choose=0;
while(1) 
{ 
show();
printf("\t\t====>请选择您要做的事：");
scanf("%d",&choose);
system("cls");
switch(choose)
{
case 1: find();
back();// 查找职工信息 
break;
 case 2: modify();
back();//修改职工信息
case 3: add();
back();//添加职工信息
break; 
case 4: del(); 
back();//删除职工信息
break;
case 5:write();
back();//保存数据 
break;
case 6: list();
back();//预览
break; 
case 7: statistics();
back();//统计职工工资
break;
case 0: exit(0);//退出
break;
break;
default:
break;
}
fflush(stdin);
getchar();
system("cls");
}
}

void menu(void)
{
	char ch;
	while(1)
	{
	   printf("\n");
printf("\t 欢迎使用本系统 \n\n");
printf("\t请选择功能 （输入1~7）\n");
printf("\t\n");
printf("\t1. 工资管理系统 \n");
printf("\t2. 退 出 系 统 \n");
printf("\t\n");
	   ch=getch();fflush(stdin);
	   switch(ch)
	   {
		   case '1':system();break;
		   case '2':exit(0);
	   }
	}


}

void main(void)
{
	menu();
}