/************************************************************
    Copyright (C), 1988-1999, wanggua.  Ltd.
    FileName: 115.cpp
    Author: Version : Date:
    Description: // ģ������
    Version: // �汾��Ϣ
    Function List: // ��Ҫ�������书��
    1. ��ѯְ�����ʼ�¼
    2. �޸�ְ�����ʼ�¼
    3. ���ְ�����ʼ�¼
    4. ɾ��ְ�����ʼ�¼
    5. �������ݵ��ļ�
    6. Ԥ��ְ����¼
    7. �˳�ϵͳ    
    History: // ��ʷ�޸ļ�¼
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
    char num[10];//ְ������
    char name[30];//ְ������
    float gwgz;//��λ����
    float xjsz;//н������
    float zwjt;//ְ�����
    float xjgz;//Ч������
    float yfgz;//Ӧ������
    float grsds;//��������˰
    float salary;//ʵ������

}zggz[100];/*����ṹ������zggz*/

    int n=0; /*��¼�ܵ�ְ������*/ 

    float grsds(int m);

/*************************************************
    Function: read()
    Description: ��Ҫ�����ļ��Ķ�
    Calls: ��
    Called By: // maim( )
    Input: // �������˵��������ÿ����������
    Output: �Ƿ���ȷ���ļ�
    Return: // ��������ֵ��˵��
    Others: // ����˵��
*************************************************/ 

void read()
{

	int i=0, nRes;
       FILE *fp;/*�����ļ�ָ��*/

       if ((fp = fopen("gx.dat", "rb")) == NULL)

       {

              printf("�ļ���ʧ��");
              getch();
              exit(-1);

       }
       printf("�ļ��򿪳ɹ�\n");
       for(i = 0; i<100; i++)

       {
			 nRes = fscanf(fp,"%s %s %f %f %f %f",zggz[i].num,zggz[i].name,&(zggz[i].gwgz),&(zggz[i].xjsz),&(zggz[i].zwjt),&(zggz[i].xjgz));
			  zggz[i].yfgz=zggz[i].gwgz+zggz[i].xjsz+zggz[i].zwjt+zggz[i].xjgz;
              grsds(i);/*���ø�������˰*/
		      zggz[i].salary=zggz[i].yfgz-grsds(zggz[i].yfgz);
              //printf("%s\t %s\t %5.1f\t %5.1f\t %5.1f\t %5.1f\t %5.1f\t %5.1f\t %5.1f\t\n",p[i].num,p[i].name,p[i].gwgz,p[i].xjsz,p[i].zwjt,p[i].xjgz,p[i].yfgz,p[i].grsds,p[i].salary); 
            if(nRes == -1)
			{
				n=i;
				break;
			}
	   }
       
       printf("\n��%d��Ա����Ϣ������\n",n);

       fclose(fp);

       
}

/*************************************************
     Function: write
     Description: ���溯��
     Calls: ��
     Called By: modify(),find( ),add( )
     Input: // �������˵��������ÿ������������
     Output: // �����������˵����
     Return: // ��������ֵ��˵��
     Others: // ����˵��
*************************************************/ 

/*��������*/
void write() 
{

    int i;
    FILE*fp;
    if ((fp=fopen("gx.dat","wb+"))==NULL)/*�����ļ����ж��Ƿ��ܴ�*/
    {

         printf("cannot open file\n");
         exit(0);

    }
    for(i=0;i<n;i++) /*���ڴ���ְ������Ϣ����������ļ���ȥ*/
    {
	    fwrite(&zggz[i],sizeof(struct worker),1,fp);
         
	}
	fclose(fp);
	printf("����ɹ�����");
}

/*************************************************
    Function: ��ѯ����
    Description: ��������ְ����Ϣ
    Calls: // �����������õĺ����嵥
    Called By: main( )
    Table Accessed: // �����ʵı����������ǣ�������ݿ�����ĳ���
    Table Updated: // ���޸ĵı����������ǣ�������ݿ�����ĳ���
    Input: ����Ҫ�����ְ���ľ�����ֵ
    Output: // �����������˵����
    Return: // ��������ֵ��˵��
    Others: // ����˵��
*************************************************/ 

/*����ְ����Ϣ*/
void find() 
{
	     
    char gonghao[10];
    int i=0;
    printf("������Ҫ����ְ������:");
    scanf("%s",gonghao);
    system("cls");
    printf("����\t\t ����\t\t��λ����\tн������\t ְ����\tУ������\tӦ������\t��������˰\tʵ������\n");
    for (i=0;i<n;i++)

	{
        if (strcmp(gonghao,zggz[i].num)==0)

		{
            printf("%-10s\t %-10s\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
	
		}
	}
}

/*************************************************
     Function: ���ְ����Ϣ
     Description: ����µ�ְ����Ϣ
     Calls: write( )
     Called By: main( )
     Table Accessed: // �����ʵı����������ǣ�������ݿ�����ĳ���
     Table Updated: // ���޸ĵı����������ǣ�������ݿ�����ĳ���
     Input: ����ÿ�����ְ����Ϣ����ֵ
     Output: // �����������˵����
     Return: // ��������ֵ��˵��
     Others: // ����˵��
*************************************************/ 

/*���ְ����Ϣ*/
void add() 
{ 
	 n++;/*�ӵ�n����ʼ*/ 
     printf("���ְ����\n");

	 {
         printf("���ţ�");
         scanf("%s",zggz[n-1].num);
         printf("������");
         scanf("%s",zggz[n-1].name);
         printf("��λ���ʣ�");
         scanf("%f",&zggz[n-1].gwgz);
         printf("н�����ʣ�");
         scanf("%f",&zggz[n-1].xjsz);
         printf("ְ���ʣ�");
         scanf("%f",&zggz[n-1].zwjt);
         printf("У�����ʣ�");
         scanf("%f",&zggz[n-1].xjgz);
         zggz[n-1].yfgz=zggz[n-1].gwgz+zggz[n-1].xjsz+zggz[n-1].zwjt+zggz[n-1].xjgz;
         grsds(n-1);/*���ø�������˰*/
		 zggz[n-1].salary=zggz[n-1].yfgz-zggz[n-1].grsds;
	 }

	 write();
     printf("��ӳɹ�\n");
} 

/*************************************************
 Function: Ԥ��ְ����Ϣ
 Description: Ԥ�����е�ְ����Ϣ
 Calls: write( )��grsds()
 Called By: main( )
 Table Accessed: // �����ʵı����������ǣ�������ݿ�����ĳ���
 Table Updated: // ���޸ĵı����������ǣ�������ݿ�����ĳ���
 Input: // �������˵��������ÿ��������
 Output: // �����������˵����
 Return: // ��������ֵ��˵��
 Others: // ����˵��
*************************************************/ 

/*Ԥ��ְ����Ϣ*/
void list( ) 
{
	system("cls");
    int i=0;
    printf("������ȫ��ְ��\n");
	
    printf("����\t\t ����\t\t��λ����\tн������\t ְ����\tУ������\tӦ������\t��������˰\tʵ������\n");
    while(i<n)
	{
		 zggz[i].yfgz=(zggz[i].gwgz+zggz[i].xjsz+zggz[i].zwjt+zggz[i].xjgz);/*����Ӧ������*/
		 grsds(i);/*���ø�������˰����*/
		 zggz[i].salary=zggz[i].yfgz-zggz[i].grsds;/*����ʵ������*/
         printf("%-10s\t %-10s\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t\n",
			 zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,
			 zggz[i].zwjt,zggz[i].xjgz,
			 zggz[i].yfgz,zggz[i].grsds,
			 zggz[i].salary);
         i++;
	}
	
}

/*************************************************
 Function: �޸�ְ����Ϣ
 Description: Ԥ�����е�ְ����Ϣ
 Calls: write( )
 Called By: main( )
 Table Accessed: // �����ʵı����������ǣ�������ݿ�����ĳ���
 Table Updated: // ���޸ĵı����������ǣ�������ݿ�����ĳ���
 Input: ����Ҫ�޸ĵ�ְ����Ϣ
 Output: // �����������˵����
 Return: // ��������ֵ��˵��
 Others: // ����˵��
*************************************************/ 

/*�޸ĳ�Ա����*/
void modify()
{

	FILE *fp=NULL;
    char gonghao[10];
	int m,i,f; 
    printf("������Ҫ�޸�ְ������:");
    scanf("%s",gonghao);
    for (m=0;m<n;m++)

	{
	    if(strcmp(gonghao,zggz[m].num)==0)
		{

			printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
            printf("����\t\t ����\t\t��λ����\tн������\t ְ����\tУ������\tӦ������\t��������˰\tʵ������\n");/*��ʾ�����޸ĵ�ְ����Ϣ*/
            printf("%-10s\t %-10s\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t %-10.2f\t\n",zggz[m].num,zggz[m].name,zggz[m].gwgz,zggz[m].xjsz,zggz[m].zwjt,zggz[m].xjgz,zggz[m].yfgz,zggz[m].grsds,zggz[m].salary);
            printf("\nȷʵҪ�޸Ĵ�����Ϣ�밴1\n");
            scanf("%d",&f);
			if(f==1)

			{ 

			    i=m;/*��ס��Ȼλ��*/
		        printf("���ţ�");
                scanf("%s",zggz[i].num);
                printf("������");
                scanf("%s",zggz[i].name);
                printf("��λ���ʣ�");
                scanf("%f",&zggz[i].gwgz);
                printf("н�����ʣ�");
                scanf("%f",&zggz[i].xjsz);
                printf("ְ���ʣ�");
                scanf("%f",&zggz[i].zwjt);
                printf("У�����ʣ�");
	    	    scanf("%f",&zggz[i].xjgz);   
		        write();
			    printf("�޸ĳɹ�\n");
				break;
			}
            
		}

	}       
	
}

/*************************************************
     Function: ɾ��ְ����Ϣ
     Description: ɾ����Ҫ��ְ����Ϣ
     Calls: write( )
     Called By: main( )
     Table Accessed: // �����ʵı����������ǣ�������ݿ�����ĳ���
     Table Updated: // ���޸ĵı����������ǣ�������ݿ�����ĳ���
     Input: // �������˵��������ÿ��������
     Output: // �����������˵����
     Return: // ��������ֵ��˵��
     Others: // ����˵��
*************************************************/ 

/*ɾ��ְ����Ϣ*/
void del() 
{
   
    char gonghao[60];
    int i=0;
    int j=0;
    int f;
    printf("������Ҫɾ����ְ�����ţ�");
    scanf("%s",gonghao);
    for(i=0;i<n;i++)

	{
        if (strcmp(gonghao,zggz[i].num)==0) 

		{
	        printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
            printf("����\t\t ����\t\t��λ����\tн������\t ְ����\tУ������\tӦ������\t��������˰\tʵ������\n");/*��ʾ����ɾ����ְ����Ϣ*/
            printf("%-10s\t %-10s\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t %-10.1f\t\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
 
            printf("\nȷʵҪɾ��������Ϣ�밴1\n");
            scanf("%d",&f);

            if(f==1)   /*���ɾ��������������Ϣ��������һ��*/
   
            for (j=i;j<n-1;j++)

			{
                zggz[j]=zggz[j+1];
			}

            n--;

		}

        write();

        
	}
	printf("ɾ���ɹ�;\n");
}

/*************************************************
     Function: �����������˰
     Description: ����Ӧ�����ʵĶ��ٺ�˰�ձ��˰��������
     Calls: 
     Called By:read(),list()
     Table Accessed: // �����ʵı����������ǣ�������ݿ�����ĳ���
     Table Updated: // ���޸ĵı����������ǣ�������ݿ�����ĳ���
     Input: // �������˵��������ÿ��������
     Output: // �����������˵����
     Return: grsds()
     Others: // ����˵��
*************************************************/ 
 

/* �����������˰ */
float grsds(int i)
{
	if(zggz[i].yfgz<=500)/*����500��˰��*/
	{
		zggz[i].grsds=zggz[i].yfgz*0.05;
	}
	else if(zggz[i].yfgz<=2000)/*����2000��˰��*/
	{
		zggz[i].grsds=(zggz[i].yfgz-500)*0.10+500*0.05;
	}
    else if(zggz[i].yfgz<=5000)/*����5000��˰��*/
    {
		zggz[i].grsds=(zggz[i].yfgz-2000)*0.15+1500*0.10+500*0.05;
	}
    else if(zggz[i].yfgz<=20000)/*����20000��˰��*/
	{
		zggz[i].grsds=(zggz[i].yfgz-5000)*0.20+3000*0.15+1500*0.10+zggz[i].yfgz*0.05;
	}
    else if(zggz[i].yfgz<=40000)/*����40000��˰��*/
    {
		zggz[i].grsds=(zggz[i].yfgz-20000)*0.25+15000*0.20+3000*0.15+1500*0.10+500*0.05;
	}
    else if(zggz[i].yfgz<=60000)/*����60000��˰��*/
    {
		zggz[i].grsds=(zggz[i].yfgz-40000)*0.30+20000*0.25+15000*0.20+3000*0.15+1500*0.10+500*0.05;
	}
    else if(zggz[i].yfgz<=80000)/*����80000��˰��*/
    {
		zggz[i].grsds=(zggz[i].yfgz-60000)*0.35+20000*0.30+20000*0.25+15000*0.20+3000*0.15+1500*0.10+500*0.05;
	}

    else if(zggz[i].yfgz<=100000)/*����100000��˰��*/
	{
		zggz[i].grsds=(zggz[i].yfgz-80000)*0.40+2000*0.35+20000*0.30+20000*0.25+15000*0.20+3000*0.15+1500*0.10+500*0.05;
	}                                  
									     /*����100000��˰��*/
    else zggz[i].grsds=(zggz[i].yfgz-100000)*0.45+20000*0.40+2000*0.35+20000*0.30+20000*0.25+15000*0.20+3000*0.15+1500*0.10+500*0.05;
	

        return zggz[i].grsds;/*���ظ�������˰��ֵ*/
}

/*������*/
void main()

{	

	int choose;
    read();/*����read()�������ļ�*/
	system("cls");
     while(1) 
	 {   
         printf("\n\n\n\n");
         printf("\t\t###     ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ    ###\n\n");
         printf("\t\t��ѡ���� <����1~7>����\n");
         printf("\t\t=====================================================================\n");
         printf("\t\t:              1. ��ѯְ�����ʼ�¼                                  :\n");
         printf("\t\t:              2. �޸�ְ�����ʼ�¼                                  :\n");
         printf("\t\t:              3. ���ְ�����ʼ�¼                                  :\n");
         printf("\t\t:              4. ɾ��ְ�����ʼ�¼                                  :\n");
         printf("\t\t:              5. �������ݵ��ļ�                                    :\n");
         printf("\t\t:              6. Ԥ��ְ����¼                                      :\n");
         printf("\t\t:              7. �˳�ϵͳ                                          :\n");
         printf("\t\t=====================================================================\n");
         printf("\t\n");
		 printf("\t\t�����ѡ���ǣ�");
         scanf("%d",&choose);
         //system("cls");
             switch(choose)
			 {
                 case 1: find();/*����ְ����Ϣ */
                 break;

                 case 2: modify();/*�޸�ְ����Ϣ*/
                 
                 break;
                 case 3: add();/*���ְ����Ϣ*/
                 break; 

                 case 4: del();/*ɾ��ְ����Ϣ*/ 
                 break;

                 case 5:write();/*�������� */
                 break;

                 case 6: list();/*Ԥ��*/
                 break; 

                 case 7: exit(0);/*�˳�*/
                 break;
                 default:
                 break;
                 fflush(stdin);
                 getchar();
                 system("cls");

			 }

	 }

}