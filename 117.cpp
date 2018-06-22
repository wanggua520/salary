#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>
int a,b,c,d,e,f;
struct zggz
{
char num[10];
char name[30];
float gwgz;
float xjsz;
float zwjt;
float xjgz;
float yfgz;
float grsds;
float salary;
};
int dq(struct worker wo[]);
void show(void);
void bc(struct worker wo[]); 
void ghcz();
void xmcz();
void xmsc();
void ghsc();
void statistics();
 struct zggz wo[100];//保存所有的职工信息
int Number=0; //记录总的职工人数
int i,j,n,m,sum[100],num[100],p=0; 
int score[100][20],lower,maxer,temp=0; 
void read(struct zggz S[])
{

	
       FILE *fp;//定义文件指针

       if ((fp = fopen("gx.dat", "r")) == NULL)

       {

              printf("文件打开失败");
              getch();
              exit(-1);

       }
	   int count=0;

       //如果文件打开成功，那么进行读数据
       struct zggz s;
       while (!feof(fp))

       {

              fscanf(fp, "%s\t", &s.num);

              fscanf(fp, "%s\t", &s.name);

              fscanf(fp, "%f\t", &s.gwgz);

			  fscanf(fp, "%f\t", &s.xjsz);
			  
			  fscanf(fp, "%f\t", &s.zwjt);
			  
			  fscanf(fp, "%f\t", &s.xjgz);

              fscanf(fp, "%f\t", &s.yfgz);

              fscanf(fp, "%d\n", &s.grsds);

              fscanf(fp, "%f\n", &s.salary);

              S[count]=s;

              count++;

       }
       n=count;
       printf("\n有%d个员工信息被读入\n",n);

       fclose(fp);

       
}
void show()
{ 
printf("\n");
printf("\t工资管理系统 \n\n");
printf("\t请选择功能 （输入0~6）\n");
printf("\t\n\n");
printf("\t1. 查询\n");
printf("\t2. 修改\n");
printf("\t3. 添加\n");
printf("\t4. 删除\n");
printf("\t5. 保存\n");
printf("\t6. 预览\n");
printf("\t0. 退出\n");
printf("\t\n");
}
void bc(struct zggz *wo)
{
FILE *fp=NULL;
fp=fopen("gx.dat","ab+");
fwrite(wo,sizeof(struct zggz),1,fp);
fclose(fp);
}
//添加职工信息
void add() 
{
int numberTemp=0;
int i=0;
struct zggz temp; 
printf("添加职工个数：");
scanf("%d",&numberTemp);
for(i=0;i<numberTemp;i++)
{
printf("输入第%d个职工信息\n",i+1);
printf("工号：");
scanf("%s",temp.num);
printf("姓名：");
scanf("%s",temp.name);
printf("岗位工资：");
scanf("%d",&temp.gwgz);
printf("薪级工资：");
scanf("%d",&temp.xjsz);
printf("职务工资：");
scanf("%d",&temp.zwjt);
printf("校绩工资：");
scanf("%d",&temp.xjgz);
printf("应发工资：");
scanf("%d",&temp.yfgz);
printf("个人所得税：");
scanf("%d",&temp.grsds);
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
//预览
void list() 
{
int i=0;
printf("以下是全部职工\n");
printf("\t工号\t姓名\t岗位工资\t薪级工资\t职务工资\t校绩工资\t应发工资\t个人所得税\t实发工资\n");
while(i<Number)
{
printf("\t%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",wo[i].num,wo[i].name,wo[i].gwgz,wo[i].xjsz,wo[i].zwjt,wo[i].xjgz,wo[i].yfgz,wo[i].grsds,wo[i].salary);
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
default: printf("该员工不存在!\n");
break;
} 
}
void xmcz()//按姓名查找 
{ 
char name[30];
int i=0;
printf("请输入要查找职工姓名:");
scanf("%s",name);
system("cls");
printf("\t工号\t姓名\t岗位工资\t薪级工资\t职务工资\t校绩工资\t应发工资\t个人所得税\t实发工资\n");
for (i=0;i<Number;i++)
{
if (strcmp(name,wo[i].num)==0)
{
printf("\t%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",wo[i].num,wo[i].name,wo[i].gwgz,wo[i].xjsz,wo[i].zwjt,wo[i].xjgz,wo[i].yfgz,wo[i].grsds,wo[i].salary);
}
}
}
void ghcz()//按工号查找 
{
char id[10];
int i=0;
printf("请输入要查找职工工号:");
scanf("%s",num);
system("cls");
printf("\t姓名\t工号\t岗位工资\t薪级工资\t职务工资\t校绩工资\t应发工资\t个人所得税\t实发工资\n");
for (i=0;i<Number;i++)
{
if (strcmp(id,wo[i].name)==0)
{
printf("\t%s\t%s\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",wo[i].num,wo[i].name,wo[i].gwgz,wo[i].xjsz,wo[i].zwjt,wo[i].xjgz,wo[i].yfgz,wo[i].grsds,wo[i].salary);
}
}
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
FILE *fp=NULL;
char name[30];
int i=0;
int j=0;
printf("请输入要删除的职工姓名：");
scanf("%s",name);
for(i=0;i<Number;i++)
{
if (strcmp(name,wo[i].name)==0)
{
for (j=i;j<Number-1;j++)
{
wo[j]=wo[j+1];
}
Number--;
}
}
//将剩余数据写入文件 擦除以前的数据
fp=fopen("gx.dat","wb");
for (i=0;i<Number;i++)
{
fwrite(&wo[i],sizeof(struct zggz),1,fp);
}
fclose(fp);
printf("删除成功;\n");            

}
void ghsc()//按工号删除 
{
FILE *fp=NULL;
char id[60];
int i=0;
int j=0;
printf("请输入要删除的职工工号：");
scanf("%s",num);
for(i=0;i<Number;i++)
{
if (strcmp(id,wo[i].name)==0) 
{
for (j=i;j<Number-1;j++)
{
wo[j]=wo[j+1];
}
Number--;
}
}

//将剩余数据写入文件 擦除以前的数据
fp=fopen("gx.dat","wb");
for (i=0;i<Number;i++)
{
fwrite(&wo[i],sizeof(struct zggz),1,fp);
}
fclose(fp);
printf("删除成功;\n");
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

//保存数据
void write()
{
printf("\t已自动保存.....\n");
}
void back()
{
printf("\t按Enter键返回\n");
}
void main()
{
	struct zggz wo[100];
	int choose=0;
while(1) 
{ 
show();
printf("\t\t====>请选择：");
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

fflush(stdin);
getchar();
system("cls");
}
}
	read(wo);

}	   
