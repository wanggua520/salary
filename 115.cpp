#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>
int a,b,c,d,e,f;
struct worker
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
int dq(struct worker zggz[]);
void write(struct worker zggz[]); 
void ghcz();
void xmcz();
int grsds();
 struct worker zggz[100];//保存所有的职工信息
int Number=0; //记录总的职工人数
int i,j,n,m,sum[100],num[100],p=0; 
int temp=0; 
void read(struct worker S[])
{

	
       FILE *fp;//定义文件指针

       if ((fp = fopen("gx.dat", "r")) == NULL)

       {

              printf("文件打开失败");
              getch();
              exit(-1);

       }
       //如果文件打开成功，那么进行读数据
       struct worker s;
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

              S[Number]=s;

              Number++;

       }
       n=Number;
       printf("\n有%d个员工信息被读入\n",n);

       fclose(fp);

       
}
void fwrite(struct worker *zggz)
{
FILE *fp=NULL;
fp=fopen("gx.dat","ab+");
if(zggz>0)
{
	fwrite(zggz,sizeof(struct worker),1,fp);}
fclose(fp);
}
//保存数据
void write() 
{
   int i;
   FILE*fp;
   if ((fp=fopen("gx.dat","wb"))==NULL)  //创建文件并判断是否能打开
   {
     printf ("cannot open file\n");
     exit(0);
   }
   for (i=0;i<m;i++) //将内存中职工的信息输出到磁盘文件中去
   if (fwrite(&zggz,sizeof(struct worker),1,fp)!=1)
   printf("file write error\n");
   printf("保存成功！！");

   fclose(fp);
}
//查找职工信息
void find() 
{
int n=0;

printf("1 按工号查找\n");
 printf("2 按姓名查找\n");
scanf("%d",&n);
switch(n)
{
case 1: ghcz();
break;
case 2: xmcz();
break;
default: printf("输入错误!\n");
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
if (strcmp(name,zggz[i].name)==0)
{
printf("\t%s\t%s\t%d\t%d\t%d\t%d\t%fd\t%d\t%d\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
}
}
}
void ghcz()//按工号查找 
{
char gonghao[10];
int i=0;
printf("请输入要查找职工工号:");
scanf("%s",gonghao);
system("cls");
printf("\t姓名\t工号\t岗位工资\t薪级工资\t职务工资\t校绩工资\t应发工资\t个人所得税\t实发工资\n");
for (i=0;i<Number;i++)
{
if (strcmp(gonghao,zggz[i].num)==0)//比较工号
{
printf("\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
}
}
}
//添加职工信息
void add() 
{
int numberTemp=0;
int i=0;
struct worker temp; 
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
temp.yfgz=temp.gwgz+temp.xjsz+temp.zwjt+temp.xjgz;
printf("个人所得税：");
//temp.grsds=
printf("实发工资：");

zggz[Number++]=temp; //写入到数组
fwrite(&temp); //写入到文件
}
printf("添加成功\n");
}

//预览
void list() 
{
int i=0;
printf("以下是全部职工\n");
printf("\t工号\t姓名\t岗位工资\t薪级工资\t职务工资\t校绩工资\t应发工资\t个人所得税\t实发工资\n");
while(i<Number)
{
printf("\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
i++;
}
}
//修改成员数据
void modify()
{
  char gonghao[10];
  int n=0; 
  printf("请输入要修改职工工号:");
scanf("%s",num);
printf("\t工号\t姓名\t岗位工资\t薪级工资\t职务工资\t校绩工资\t应发工资\t个人所得税\t实发工资\n");
for (n=0;n<Number;n++)
{
	if(strcmp(gonghao,zggz[n].num)==0)
	{
		printf("工号：");
        scanf("%s",zggz[n].num);
        printf("姓名：");
        scanf("%s",zggz[n].name);
        printf("岗位工资：");
        scanf("%d",&zggz[n].gwgz);
        printf("薪级工资：");
        scanf("%d",&zggz[n].xjsz);
        printf("职务工资：");
        scanf("%d",&zggz[n].zwjt);
        printf("校绩工资：");
		scanf("%d",&zggz[n].xjgz);
        
        //wo[Number++]=temp; //写入到数组
        //fwrite(&wo); //写入到文件
		
}

}       
	
}

//删除职工信息
void del() 
{
FILE *fp=NULL;
char gonghao[60];
int i=0;
int j=0;
printf("请输入要删除的职工工号：");
scanf("%s",gonghao);
for(i=0;i<Number;i++)
{
if (strcmp(gonghao,zggz[i].num)==0) 
{
	 printf("\n已找到此人，原始记录为：\n");
            printf("\t工号\t姓名\t岗位工资\t薪级工资\t职务工资\t校绩工资\t应发工资\t个人所得税\t实发工资\n");
   printf("\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
 
            printf("\n确实要删除此人信息请按1\n");
   scanf("%d",&n);

            if(n==1)   /*如果删除，则其他的信息都往上移一行*/
   {
for (j=i;j<Number-1;j++)
{
zggz[j]=zggz[j+1];
}
Number--;
}

}
//将剩余数据写入文件 擦除以前的数据
fp=fopen("gx.dat","wb");
for (i=0;i<Number;i++)
{
fwrite(&zggz[i],sizeof(struct worker),1,fp);
}
fclose(fp);

printf("删除成功;\n");
}
}
int grsds()
{

return 0;
}
void main()
{
	struct worker zggz[100];
	
	int choose=0;
while(1) 
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
printf("\t\t====>请选择：");
scanf("%d",&choose);
system("cls");
switch(choose)
{
case 1: find();
// 查找职工信息 
break;
 case 2: modify();
//修改职工信息
case 3: add();
//添加职工信息
break; 
case 4: del(); 
//删除职工信息
break;
case 5:write();
//保存数据 
break;
case 6: list();
//预览
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

read(zggz);

}