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
    struct worker zggz[100];//保存所有的职工信息
    int Number=0; //记录总的职工人数
    int i,j,n,m,sum[100],num[100],p=0; 
    int temp=0; 
    int read(struct worker S[])
{

	int i=0;
	FILE *fp;
	    if((fp=fopen("gx.dat","r"))==NULL)//当前目录下是否存在gx.dat文件
	{
	    printf("没有文件");
	    getch();
	    exit(-1);
	}
	    struct worker s;
            while(!feof(fp))
			{
	            fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",&(s.num),&(s.name),&(s.gwgz),&(s.xjsz),&(s.zwjt),
                &(s.xjgz),&(s.yfgz),&(s.grsds),&(s.salary));
            	printf("%s %s %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f\n",s.num,s.name,s.gwgz,s.xjsz,s.zwjt,s.xjgz,s.yfgz,s.grsds,s.salary); 
	            n++;
	            i++;
			}
	
	       printf("有%d工人信息录入",n);//输出职工人数
	       fclose(fp);
           return 0;
}
/*void read(struct worker S[])
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

              fscanf(fp, "%s\t", s.num);

              fscanf(fp, "%s\t", s.name);

              fscanf(fp, "%.2f\t", &s.gwgz);

			  fscanf(fp, "%.2f\t", &s.xjsz);
			  
			  fscanf(fp, "%.2f\t", &s.zwjt);
			  
			  fscanf(fp, "%.2f\t", &s.xjgz);

              fscanf(fp, "%.2f\t", &s.yfgz);

              fscanf(fp, "%.2f\n", &s.grsds);

              fscanf(fp, "%.2ff\n", &s.salary);

              S[Number]=s;

              Number++;

       }
       n=Number;
       printf("\n有%d个员工信息被读入\n",n);

       fclose(fp);

       
}*/
void fwrite(struct worker *zggz)
{
    FILE *fp=NULL;
    fp=fopen("gx.dat","ab+");
    if(zggz>0)
	{
	    fwrite(zggz,sizeof(struct worker),1,fp);
	}
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
            printf("\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
			zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
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
         /*printf("应发工资：");
         
         printf("个人所得税：");
         grsds();
         printf("实发工资：");*/

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
		 zggz[i].yfgz=(zggz[i].gwgz+zggz[i].xjsz+zggz[i].zwjt+zggz[i].xjgz);
		 //grsds();
		 zggz[i].salary=zggz[i].yfgz-zggz[i].grsds;
         printf("\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
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
            scanf("%s",num);
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

            printf("\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
 
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
    while(i<Number)
	{
	//for(int i=0;i<20;i++)
		if(zggz[i].yfgz<=500)
		zggz[i].grsds=zggz[i].yfgz*0.05;

		    else if(zggz[i].yfgz<=2000)
		    zggz[i].grsds=(zggz[i].yfgz-500)*0.10+zggz[i].yfgz*0.05;

                else if(zggz[i].yfgz<=5000)
                zggz[i].grsds=(zggz[i].yfgz-2000)*0.15+(zggz[i].yfgz-500)*0.10+zggz[i].yfgz*0.05;

                    else if(zggz[i].yfgz<=20000)
	                zggz[i].grsds=(zggz[i].yfgz-5000)*0.20+(zggz[i].yfgz-2000)*0.15+(zggz[i].yfgz-500)*0.10+zggz[i].yfgz*0.05;

                        else if(zggz[i].yfgz<=40000)
                        zggz[i].grsds=(zggz[i].yfgz-20000)*0.25+(zggz[i].yfgz-5000)*0.20+(zggz[i].yfgz-2000)*0.15+(zggz[i].yfgz-500)*0.10+zggz[i].yfgz*0.05;

                            else if(zggz[i].yfgz<=60000)
                            zggz[i].grsds=(zggz[i].yfgz-40000)*0.30+(zggz[i].yfgz-20000)*0.25+(zggz[i].yfgz-5000)*0.20+(zggz[i].yfgz-2000)*0.15+(zggz[i].yfgz-500)*0.10+zggz[i].yfgz*0.05;

                                else if(zggz[i].yfgz<=80000)
                                zggz[i].grsds=(zggz[i].yfgz-60000)*0.35+(zggz[i].yfgz-40000)*0.30+(zggz[i].yfgz-20000)*0.25+(zggz[i].yfgz-5000)*0.20+(zggz[i].yfgz-2000)*0.15+(zggz[i].yfgz-500)*0.10+zggz[i].yfgz*0.05;

                                    else if(zggz[i].yfgz<=100000)
                                    zggz[i].grsds=(zggz[i].yfgz-80000)*0.40+(zggz[i].yfgz-60000)*0.35+(zggz[i].yfgz-40000)*0.30+(zggz[i].yfgz-20000)*0.25+(zggz[i].yfgz-5000)*0.20+(zggz[i].yfgz-2000)*0.15+(zggz[i].yfgz-500)*0.10+zggz[i].yfgz*0.05;

                                         else zggz[i].grsds=(zggz[i].yfgz-80000)*0.45+(zggz[i].yfgz-80000)*0.40+(zggz[i].yfgz-60000)*0.35+(zggz[i].yfgz-40000)*0.30+(zggz[i].yfgz-20000)*0.25+(zggz[i].yfgz-5000)*0.20+(zggz[i].yfgz-2000)*0.15+(zggz[i].yfgz-500)*0.10+zggz[i].yfgz*0.05;
i++;	}

                                              return zggz[i].grsds;
}
void main()
{
	struct worker zggz[100];
	
	int choose=0;

     while(1) 
	 { 
         printf("\n");
         printf("\t\t###欢迎使用广西民族大学软件与信息安全学院职工工资管理系统 ###\n\n");
         printf("\t\t请选择功能 <输入1~7>）：\n");
         printf("\t\t=============================================================\n");
         printf("\t\t:              1. 查询职工工资记录                          :\n");
         printf("\t\t:              2. 修改职工工资记录                          :\n");
         printf("\t\t:              3. 添加职工工资记录                          :\n");
         printf("\t\t:              4. 删除职工工资记录                          :\n");
         printf("\t\t:              5. 保存数据到文件                            :\n");
         printf("\t\t:              6. 预览职工记录                              :\n");
         printf("\t\t:              7. 退出系统                                  :\n");
         printf("\t\t=============================================================\n");
         printf("\t\n");
		 printf("\t\t请选择：");
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
                 case 7: exit(0);//退出
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