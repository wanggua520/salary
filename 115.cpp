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
}zggz[100],*p;
    //struct worker zggz[100];//�������е�ְ����Ϣ
    int n=0; //��¼�ܵ�ְ������
    int i,j,m,sum[100],num[100]; 
    int temp=0; 
/*int read()
{

    FILE *fp;
	int i=0;
	p=zggz;
	if((fp=fopen("gx.dat","rt"))==NULL)//��ǰĿ¼���Ƿ����gx.dat�ļ�
	{
	    printf("���ļ�ʧ��");
	    getch();
	    exit(-1);
	}
		
		for(i=0;i<=100;i++)
		{
			fread(p,sizeof(struct worker),1,fp);
            n++;
			p++;
			if(feof(fp))
			{
				printf("���ļ�ʧ��!\n");
				break;
			}
		}
	    
           /* while(!feof(fp))
			{
	            fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",&(s.num),&(s.name),&(s.gwgz),&(s.xjsz),&(s.zwjt),
                &(s.xjgz),&(s.yfgz),&(s.grsds),&(s.salary));
            	printf("%s %s %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f\n",s.num,s.name,s.gwgz,s.xjsz,s.zwjt,s.xjgz,s.yfgz,s.grsds,s.salary); 
	            i++;
			}
	
	       printf("��%d������Ϣ¼��",n);//���ְ������
	       fclose(fp);
           return 0;
}*/
void read()
{

	int i=0;
       FILE *fp;//�����ļ�ָ��
	   p=zggz;

       if ((fp = fopen("gx.dat", "rt+")) == NULL)

       {

              printf("�ļ���ʧ��");
              getch();
              exit(-1);

       }
       while (!feof(fp))

       {
		      printf("�ļ��򿪳ɹ�\n");
			  printf("\t����\t����\t��λ����\tн������\tְ����\tУ������\tӦ������\t��������˰\tʵ������\n");
			  fscanf(fp,"%s %s %f %f %f %f %f %f %f\n",&(p[i].num),&(p[i].name),&(p[i].gwgz),&(p[i].xjsz),&(p[i].zwjt),
              &(p[i].xjgz),&(p[i].yfgz),&(p[i].grsds),&(p[i].salary));
              printf("%s %s %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f\n",p[i].num,p[i].name,p[i].gwgz,p[i].xjsz,p[i].zwjt,p[i].xjgz,p[i].yfgz,p[i].grsds,p[i].salary); 
              i++;
			  n=i;
	   }
       
       printf("\n��%d��Ա����Ϣ������\n",n);

       fclose(fp);

       
}
//��������
void write() 
{
    int i;
    FILE*fp;
    if ((fp=fopen("gx.dat","wb"))==NULL)  //�����ļ����ж��Ƿ��ܴ�
    {
         printf ("cannot open file\n");
         exit(0);
    }
         for (i=0;i<m;i++) //���ڴ���ְ������Ϣ����������ļ���ȥ
         if (fwrite(&zggz,sizeof(struct worker),1,fp)!=1)
         printf("file write error\n");
         printf("����ɹ�����");
         fclose(fp);
}
//����ְ����Ϣ
void find() 
{
	     
    char gonghao[10];
    int i=0;
    printf("������Ҫ����ְ������:");
    scanf("%s",gonghao);
    system("cls");
    printf("\t����\t����\t��λ����\tн������\tְ����\tУ������\tӦ������\t��������˰\tʵ������\n");
    for (i=0;i<n;i++)
	{
        if (strcmp(gonghao,zggz[i].num)==0)//�ȽϹ���
		{
            printf("%s %s %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
		}
	}
}
//���ְ����Ϣ
void add() 
{ 
	 
     //int numberTemp=0;
	 n++;
     int i=0;
     //struct worker temp; 
     printf("���ְ����\n");
	 {
		 
        // printf("�����%d��ְ����Ϣ\n",i+1);
         printf("���ţ�");
         scanf("%s",zggz[n-1].num);
         printf("������");
         scanf("%s",zggz[n-1].name);
         printf("��λ���ʣ�");
         scanf("%d",&zggz[n-1].gwgz);
         printf("н�����ʣ�");
         scanf("%d",&zggz[n-1].xjsz);
         printf("ְ���ʣ�");
         scanf("%d",&zggz[n-1].zwjt);
         printf("У�����ʣ�");
         scanf("%d",&zggz[n-1].xjgz);
         printf("Ӧ�����ʣ�");
         zggz[n-1].yfgz=zggz[n-1].gwgz+zggz[n-1].xjsz+zggz[n-1].zwjt+zggz[n-1].xjgz;
         printf("��������˰��");
         grsds(zggz);
         printf("ʵ�����ʣ�");
		 zggz[n-1].salary=zggz[n-1].yfgz-zggz[n-1].grsds;
	 }
         FILE *fp=NULL;
         fp=fopen("gx.dat","ab+");
         if(zggz>0)
		 {
	          fwrite(zggz,sizeof(struct worker),1,fp);
		 }
         fclose(fp);

        // zggz[n++]=temp; //д�뵽����
        // write(); //д�뵽�ļ�
		 
     
	     
         printf("��ӳɹ�\n");
}

//Ԥ��
void list() 
{
    int i=0;
    printf("������ȫ��ְ��\n");
    printf("\t����\t����\t��λ����\tн������\tְ����\tУ������\tӦ������\t��������˰\tʵ������\n");
    while(i<n)
	{
		 zggz[i].yfgz=(zggz[i].gwgz+zggz[i].xjsz+zggz[i].zwjt+zggz[i].xjgz);
		 //grsds(zggz);
		 zggz[i].salary=zggz[i].yfgz-zggz[i].grsds;
         printf("%s %s %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f %5.1f\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
         i++;
	}
}
//�޸ĳ�Ա����
void modify()
{
	FILE *fp=NULL;
    char gonghao[10];
	int m,i; 
    printf("������Ҫ�޸�ְ������:");
    scanf("%s",gonghao);
    for (m=0;m<n;m++)
	{
	    if(strcmp(gonghao,zggz[m].num)==0)
		{
			printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n");
            printf("\t����\t����\t��λ����\tн������\tְ����\tУ������\tӦ������\t��������˰\tʵ������\n");
            printf("\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",zggz[m].num,zggz[m].name,zggz[m].gwgz,zggz[m].xjsz,zggz[m].zwjt,zggz[m].xjgz,zggz[m].yfgz,zggz[m].grsds,zggz[m].salary);
            printf("\nȷʵҪ�޸Ĵ�����Ϣ�밴1\n");
            scanf("%d",&f);
			if(f==1)
			{ 
			    i=m;
		        printf("���ţ�");
                scanf("%s",zggz[i].num);
                printf("������");
                scanf("%s",zggz[i].name);
                printf("��λ���ʣ�");
                scanf("%d",&zggz[i].gwgz);
                printf("н�����ʣ�");
                scanf("%d",&zggz[i].xjsz);
                printf("ְ���ʣ�");
                scanf("%d",&zggz[i].zwjt);
                printf("У�����ʣ�");
	    	    scanf("%d",&zggz[i].xjgz);
        
           // zggz[n++]=temp; //д�뵽����
            //fwrite(&temp);//д�뵽�ļ�
                write();
			}
		}

	}       
	
}

//ɾ��ְ����Ϣ
void del() 
{
   FILE *fp=NULL;
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
            printf("\t����\t����\t��λ����\tн������\tְ����\tУ������\tӦ������\t��������˰\tʵ������\n");
   printf("\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
 
            printf("\nȷʵҪɾ��������Ϣ�밴1\n");
   scanf("%d",&f);

            if(f==1)   /*���ɾ��������������Ϣ��������һ��*/
   
for (j=i;j<n-1;j++)
{
zggz[j]=zggz[j+1];
}
n--;


}
//��ʣ������д���ļ� ������ǰ������
fp=fopen("gx.dat","wb");
for (i=0;i<n;i++)
{
fwrite(&zggz[i],sizeof(struct worker),1,fp);
}
fclose(fp);

printf("ɾ���ɹ�;\n");
}
}
int grsds(struct worker *zggz)
{
    while(i<n)
	{
	for(int i=0;i<20;i++)
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
	int choose=0;
    read();
     while(1) 
	 { 
         printf("\n");
         printf("\t\t###��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ ###\n\n");
         printf("\t\t��ѡ���� <����1~7>����\n");
         printf("\t\t=============================================================\n");
         printf("\t\t:              1. ��ѯְ�����ʼ�¼                          :\n");
         printf("\t\t:              2. �޸�ְ�����ʼ�¼                          :\n");
         printf("\t\t:              3. ���ְ�����ʼ�¼                          :\n");
         printf("\t\t:              4. ɾ��ְ�����ʼ�¼                          :\n");
         printf("\t\t:              5. �������ݵ��ļ�                            :\n");
         printf("\t\t:              6. Ԥ��ְ����¼                              :\n");
         printf("\t\t:              7. �˳�ϵͳ                                  :\n");
         printf("\t\t=============================================================\n");
         printf("\t\n");
		 printf("\t\t��ѡ��");
         scanf("%d",&choose);
         system("cls");
             switch(choose)
			 {
                 case 1: find();
                 // ����ְ����Ϣ 
                 break;
                  case 2: modify();
                 //�޸�ְ����Ϣ
                 case 3: add();
                 //���ְ����Ϣ
                 break; 
                 case 4: del(); 
                 //ɾ��ְ����Ϣ
                 break;
                 case 5:write();
                 //�������� 
                 break;
                 case 6: list();
                 //Ԥ��
                 break; 
                 case 7: exit(0);//�˳�
                 break;
                 break;
                 default:
                 break;
                 fflush(stdin);
                 getchar();
                 system("cls");

			 }

	 }

}