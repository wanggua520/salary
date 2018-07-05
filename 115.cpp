/************************************************************
    Copyright (C), 1988-1999, wanggua.  Ltd.
    FileName: 115.cpp
    Author: Version : Date:
    Description: // 模块描述
    Version: // 版本信息
    Function List: // 主要函数及其功能
    1. 查询职工工资记录
    2. 修改职工工资记录
    3. 添加职工工资记录
    4. 删除职工工资记录
    5. 保存数据到文件
    6. 预览职工记录
    7. 退出系统    
    History: // 历史修改记录
    <author> <time> <version > <desc>
    David 18/70/1 1.0 build this moudle
***********************************************************/ 
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>
struct worker
{
    char num[10];//职工工号
    char name[30];//职工姓名
    float gwgz;//岗位工资
    float xjsz;//薪级工资
    float zwjt;//职务津贴
    float xjgz;//效绩工资
    float yfgz;//应发工资
    float grsds;//个人所得税
    float salary;//实发工资

}zggz[100];/*定义结构体数组zggz*/

    int n=0; /*记录总的职工人数*/ 

    float grsds(int m);

/*************************************************
    Function: read()
    Description: 主要进行文件的读
    Calls: 无
    Called By: // maim( )
    Input: // 输入参数说明，包括每个参数的作
    Output: 是否正确打开文件
    Return: // 函数返回值的说明
    Others: // 其它说明
*************************************************/ 

void read()
{

	int i=0, nRes;
       FILE *fp;/*定义文件指针*/

       if ((fp = fopen("gx.dat", "rb")) == NULL)

       {

              printf("文件打开失败");
              getch();
              exit(-1);

       }
       printf("文件打开成功\n");
       for(i = 0; i<100; i++)

       {
			 nRes = fscanf(fp,"%s %s %f %f %f %f",zggz[i].num,zggz[i].name,&(zggz[i].gwgz),&(zggz[i].xjsz),&(zggz[i].zwjt),&(zggz[i].xjgz));
			  zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjsz+zggz[i].zwjt+zggz[i].xjgz;
              grsds(i);/*调用个人所得税*/
		      zggz[i].salary=zggz[i].yfgz-grsds(zggz[i].yfgz);
              //printf("%s\t %s\t %5.1f\t %5.1f\t %5.1f\t %5.1f\t %5.1f\t %5.1f\t %5.1f\t\n",p[i].num,p[i].name,p[i].gwgz,p[i].xjsz,p[i].zwjt,p[i].xjgz,p[i].yfgz,p[i].grsds,p[i].salary); 
            if(nRes == -1)
			{
				n=i;
				break;
			}
	   }
       
       printf("\n有%d个员工信息被读入\n",n);

       fclose(fp);

       
}

/*************************************************
     Function: write
     Description: 保存函数
     Calls: 无
     Called By: modify(),find( ),add( )
     Input: // 输入参数说明，包括每个参数的作。
     Output: // 对输出参数的说明。
     Return: // 函数返回值的说明
     Others: // 其它说明
*************************************************/ 

/*保存数据*/
void write() 
{

    int i;
    FILE*fp;
    if ((fp=fopen("gx.dat","wb+"))==NULL)/*创建文件并判断是否能打开*/
    {

         printf("cannot open file\n");
         exit(0);

    }
    for(i=0;i<n;i++) /*将内存中职工的信息输出到磁盘文件中去*/
    {
	    fwrite(&zggz[i],sizeof(struct worker),1,fp);
         
	}
	fclose(fp);
	printf("保存成功！！");
}

/*************************************************
    Function: 查询函数
    Description: 用来查找职工信息
    Calls: // 被本函数调用的函数清单
    Called By: main( )
    Table Accessed: // 被访问的表（此项仅对于牵扯到数据库操作的程序）
    Table Updated: // 被修改的表（此项仅对于牵扯到数据库操作的程序）
    Input: 输入要输入的职工的具体数值
    Output: // 对输出参数的说明。
    Return: // 函数返回值的说明
    Others: // 其它说明
*************************************************/ 

/*查找职工信息*/
void find() 
{
	     
    char gonghao[10];
    int i=0;
    printf("请输入要查找职工工号:");
    scanf("%s",gonghao);
    system("cls");
    printf("工号\t\t 姓名\t\t岗位工资\t薪级工资\t 职务工资\t校绩工资\t应发工资\t个人所得税\t实发工资\n");
    for (i=0;i<n;i++)

	{
        if (strcmp(gonghao,zggz[i].num)==0)

		{
            printf("%-10s\t %-10s\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
	
		}
	}
}

/*************************************************
     Function: 添加职工信息
     Description: 添加新的职工信息
     Calls: write( )
     Called By: main( )
     Table Accessed: // 被访问的表（此项仅对于牵扯到数据库操作的程序）
     Table Updated: // 被修改的表（此项仅对于牵扯到数据库操作的程序）
     Input: 输入每个添加职工信息具体值
     Output: // 对输出参数的说明。
     Return: // 函数返回值的说明
     Others: // 其它说明
*************************************************/ 

/*添加职工信息*/
void add() 
{ 
	 n++;/*从第n个开始*/ 
     printf("添加职工：\n");

	 {
         printf("工号：");
         scanf("%s",zggz[n-1].num);
         printf("姓名：");
         scanf("%s",zggz[n-1].name);
         printf("岗位工资：");
         scanf("%f",&zggz[n-1].gwgz);
         printf("薪级工资：");
         scanf("%f",&zggz[n-1].xjsz);
         printf("职务工资：");
         scanf("%f",&zggz[n-1].zwjt);
         printf("校绩工资：");
         scanf("%f",&zggz[n-1].xjgz);
         zggz[n-1].yfgz=zggz[n-1].gwgz+zggz[n-1].xjsz+zggz[n-1].zwjt+zggz[n-1].xjgz;
         grsds(n-1);/*调用个人所得税*/
		 zggz[n-1].salary=zggz[n-1].yfgz-zggz[n-1].grsds;
	 }

	 write();
     printf("添加成功\n");
} 

/*************************************************
 Function: 预览职工信息
 Description: 预览所有得职工信息
 Calls: write( )，grsds()
 Called By: main( )
 Table Accessed: // 被访问的表（此项仅对于牵扯到数据库操作的程序）
 Table Updated: // 被修改的表（此项仅对于牵扯到数据库操作的程序）
 Input: // 输入参数说明，包括每个参数的
 Output: // 对输出参数的说明。
 Return: // 函数返回值的说明
 Others: // 其它说明
*************************************************/ 

/*预览职工信息*/
void list( ) 
{
	system("cls");
    int i=0;
    printf("以下是全部职工\n");
	
    printf("工号\t\t 姓名\t\t岗位工资\t薪级工资\t 职务工资\t校绩工资\t应发工资\t个人所得税\t实发工资\n");
    while(i<n)
	{
		 zggz[i].yfgz=(zggz[i].gwgz+zggz[i].xjsz+zggz[i].zwjt+zggz[i].xjgz);/*计算应发工资*/
		 grsds(i);/*调用个人所得税函数*/
		 zggz[i].salary=zggz[i].yfgz-zggz[i].grsds;/*计算实发工资*/
         printf("%-10s\t %-10s\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t\n",
			 zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,
			 zggz[i].zwjt,zggz[i].xjgz,
			 zggz[i].yfgz,zggz[i].grsds,
			 zggz[i].salary);
         i++;
	}
	
}

/*************************************************
 Function: 修改职工信息
 Description: 预览所有的职工信息
 Calls: write( )
 Called By: main( )
 Table Accessed: // 被访问的表（此项仅对于牵扯到数据库操作的程序）
 Table Updated: // 被修改的表（此项仅对于牵扯到数据库操作的程序）
 Input: 输入要修改的职工信息
 Output: // 对输出参数的说明。
 Return: // 函数返回值的说明
 Others: // 其它说明
*************************************************/ 

/*修改成员数据*/
void modify()
{

	FILE *fp=NULL;
    char gonghao[10];
	int m,i,f; 
    printf("请输入要修改职工工号:");
    scanf("%s",gonghao);
    for (m=0;m<n;m++)

	{
	    if(strcmp(gonghao,zggz[m].num)==0)
		{

			printf("\n已找到此人，原始记录为：\n");
            printf("工号\t\t 姓名\t\t岗位工资\t薪级工资\t 职务工资\t校绩工资\t应发工资\t个人所得税\t实发工资\n");/*显示所有修改的职工信息*/
            printf("%-10s\t %-10s\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t\n",zggz[m].num,zggz[m].name,zggz[m].gwgz,zggz[m].xjsz,zggz[m].zwjt,zggz[m].xjgz,zggz[m].yfgz,zggz[m].grsds,zggz[m].salary);
            printf("\n确实要修改此人信息请按1\n");
            scanf("%d",&f);
			if(f==1)

			{ 

			    i=m;/*记住当然位置*/
		        printf("工号：");
                scanf("%s",zggz[i].num);
                printf("姓名：");
                scanf("%s",zggz[i].name);
                printf("岗位工资：");
                scanf("%f",&zggz[i].gwgz);
                printf("薪级工资：");
                scanf("%f",&zggz[i].xjsz);
                printf("职务工资：");
                scanf("%f",&zggz[i].zwjt);
                printf("校绩工资：");
	    	    scanf("%f",&zggz[i].xjgz);   
		        write();
			    printf("修改成功\n");
				break;
			}
            
		}

	}       
	
}

/*************************************************
     Function: 删除职工信息
     Description: 删除不要的职工信息
     Calls: write( )
     Called By: main( )
     Table Accessed: // 被访问的表（此项仅对于牵扯到数据库操作的程序）
     Table Updated: // 被修改的表（此项仅对于牵扯到数据库操作的程序）
     Input: // 输入参数说明，包括每个参数的
     Output: // 对输出参数的说明。
     Return: // 函数返回值的说明
     Others: // 其它说明
*************************************************/ 

/*删除职工信息*/
void del() 
{
   
    char gonghao[60];
    int i=0;
    int j=0;
    int f;
    printf("请输入要删除的职工工号：");
    scanf("%s",gonghao);
    for(i=0;i<n;i++)

	{
        if (strcmp(gonghao,zggz[i].num)==0) 

		{
	        printf("\n已找到此人，原始记录为：\n");
            printf("工号\t\t 姓名\t\t岗位工资\t薪级工资\t 职务工资\t校绩工资\t应发工资\t个人所得税\t实发工资\n");/*显示所有删除的职工信息*/
            printf("%-10s\t %-10s\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
 
            printf("\n确实要删除此人信息请按1\n");
            scanf("%d",&f);

            if(f==1)   /*如果删除，则其他的信息都往上移一行*/
   
            for (j=i;j<n-1;j++)

			{
                zggz[j]=zggz[j+1];
			}

            n--;

		}

        write();

        
	}
	printf("删除成功;\n");
}

/*************************************************
     Function: 计算个人所得税
     Description: 按照应发工资的多少和税收表的税率来计算
     Calls: 
     Called By:read(),list()
     Table Accessed: // 被访问的表（此项仅对于牵扯到数据库操作的程序）
     Table Updated: // 被修改的表（此项仅对于牵扯到数据库操作的程序）
     Input: // 输入参数说明，包括每个参数的
     Output: // 对输出参数的说明。
     Return: grsds()
     Others: // 其它说明
*************************************************/ 
 

/* 计算个人所得税 */
float grsds(int i)
{
	if(zggz[i].yfgz<=500)/*低于500的税收*/
	{
		zggz[i].grsds=zggz[i].yfgz*0.05;
	}
	else if(zggz[i].yfgz<=2000)/*低于2000的税收*/
	{
		zggz[i].grsds=(zggz[i].yfgz-500)*0.10+500*0.05;
	}
    else if(zggz[i].yfgz<=5000)/*低于5000的税收*/
    {
		zggz[i].grsds=(zggz[i].yfgz-2000)*0.15+1500*0.10+500*0.05;
	}
    else if(zggz[i].yfgz<=20000)/*低于20000的税收*/
	{
		zggz[i].grsds=(zggz[i].yfgz-5000)*0.20+3000*0.15+1500*0.10+zggz[i].yfgz*0.05;
	}
    else if(zggz[i].yfgz<=40000)/*低于40000的税收*/
    {
		zggz[i].grsds=(zggz[i].yfgz-20000)*0.25+15000*0.20+3000*0.15+1500*0.10+500*0.05;
	}
    else if(zggz[i].yfgz<=60000)/*低于60000的税收*/
    {
		zggz[i].grsds=(zggz[i].yfgz-40000)*0.30+20000*0.25+15000*0.20+3000*0.15+1500*0.10+500*0.05;
	}
    else if(zggz[i].yfgz<=80000)/*低于80000的税收*/
    {
		zggz[i].grsds=(zggz[i].yfgz-60000)*0.35+20000*0.30+20000*0.25+15000*0.20+3000*0.15+1500*0.10+500*0.05;
	}

    else if(zggz[i].yfgz<=100000)/*低于100000的税收*/
	{
		zggz[i].grsds=(zggz[i].yfgz-80000)*0.40+2000*0.35+20000*0.30+20000*0.25+15000*0.20+3000*0.15+1500*0.10+500*0.05;
	}                                  
									     /*高于100000的税收*/
    else zggz[i].grsds=(zggz[i].yfgz-100000)*0.45+20000*0.40+2000*0.35+20000*0.30+20000*0.25+15000*0.20+3000*0.15+1500*0.10+500*0.05;
	

        return zggz[i].grsds;/*返回个人所得税的值*/
}

/*主函数*/
void main()

{	

	int choose;
    read();/*调用read()函数打开文件*/
	system("cls");
     while(1) 
	 {   
         printf("\n\n\n\n");
         printf("\t\t###     欢迎使用广西民族大学软件与信息安全学院职工工资管理系统    ###\n\n");
         printf("\t\t请选择功能 <输入1~7>）：\n");
         printf("\t\t=====================================================================\n");
         printf("\t\t:              1. 查询职工工资记录                                  :\n");
         printf("\t\t:              2. 修改职工工资记录                                  :\n");
         printf("\t\t:              3. 添加职工工资记录                                  :\n");
         printf("\t\t:              4. 删除职工工资记录                                  :\n");
         printf("\t\t:              5. 保存数据到文件                                    :\n");
         printf("\t\t:              6. 预览职工记录                                      :\n");
         printf("\t\t:              7. 退出系统                                          :\n");
         printf("\t\t=====================================================================\n");
         printf("\t\n");
		 printf("\t\t你的请选择是：");
         scanf("%d",&choose);
         //system("cls");
             switch(choose)
			 {
                 case 1: find();/*查找职工信息 */
                 break;

                 case 2: modify();/*修改职工信息*/
                 
                 break;
                 case 3: add();/*添加职工信息*/
                 break; 

                 case 4: del();/*删除职工信息*/ 
                 break;

                 case 5:write();/*保存数据 */
                 break;

                 case 6: list();/*预览*/
                 break; 

                 case 7: exit(0);/*退出*/
                 break;
                 default:
                 break;
                 fflush(stdin);
                 getchar();
                 system("cls");

			 }

	 }

}