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
    struct worker zggz[100];//�������е�ְ����Ϣ
    int Number=0; //��¼�ܵ�ְ������
    int i,j,n,m,sum[100],num[100],p=0; 
    int temp=0; 
    int read(struct worker S[])
{

	int i=0;
	FILE *fp;
	    if((fp=fopen("gx.dat","r"))==NULL)//��ǰĿ¼���Ƿ����gx.dat�ļ�
	{
	    printf("û���ļ�");
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
	
	       printf("��%d������Ϣ¼��",n);//���ְ������
	       fclose(fp);
           return 0;
}
/*void read(struct worker S[])
{

	
       FILE *fp;//�����ļ�ָ��

       if ((fp = fopen("gx.dat", "r")) == NULL)

       {

              printf("�ļ���ʧ��");
              getch();
              exit(-1);

       }
       //����ļ��򿪳ɹ�����ô���ж�����
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
       printf("\n��%d��Ա����Ϣ������\n",n);

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
    for (i=0;i<Number;i++)
	{
        if (strcmp(gonghao,zggz[i].num)==0)//�ȽϹ���
		{
            printf("\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
			zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
		}
	}
}
//���ְ����Ϣ
void add() 
{
     int numberTemp=0;
     int i=0;
     struct worker temp; 
     printf("���ְ��������");
     scanf("%d",&numberTemp);
     for(i=0;i<numberTemp;i++)
	 {
         printf("�����%d��ְ����Ϣ\n",i+1);
         printf("���ţ�");
         scanf("%s",temp.num);
         printf("������");
         scanf("%s",temp.name);
         printf("��λ���ʣ�");
         scanf("%d",&temp.gwgz);
         printf("н�����ʣ�");
         scanf("%d",&temp.xjsz);
         printf("ְ���ʣ�");
         scanf("%d",&temp.zwjt);
         printf("У�����ʣ�");
         scanf("%d",&temp.xjgz);
         /*printf("Ӧ�����ʣ�");
         
         printf("��������˰��");
         grsds();
         printf("ʵ�����ʣ�");*/

         zggz[Number++]=temp; //д�뵽����
         fwrite(&temp); //д�뵽�ļ�
     }
         printf("��ӳɹ�\n");
}

//Ԥ��
void list() 
{
    int i=0;
    printf("������ȫ��ְ��\n");
    printf("\t����\t����\t��λ����\tн������\tְ����\tУ������\tӦ������\t��������˰\tʵ������\n");
    while(i<Number)
	{
		 zggz[i].yfgz=(zggz[i].gwgz+zggz[i].xjsz+zggz[i].zwjt+zggz[i].xjgz);
		 //grsds();
		 zggz[i].salary=zggz[i].yfgz-zggz[i].grsds;
         printf("\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
         i++;
	}
}
//�޸ĳ�Ա����
void modify()
{
    char gonghao[10];
	int n=0; 
    printf("������Ҫ�޸�ְ������:");
    scanf("%s",num);
    printf("\t����\t����\t��λ����\tн������\tְ����\tУ������\tӦ������\t��������˰\tʵ������\n");
    for (n=0;n<Number;n++)
	{
	    if(strcmp(gonghao,zggz[n].num)==0)
		{
		    printf("���ţ�");
            scanf("%s",num);
            printf("������");
            scanf("%s",zggz[n].name);
            printf("��λ���ʣ�");
            scanf("%d",&zggz[n].gwgz);
            printf("н�����ʣ�");
            scanf("%d",&zggz[n].xjsz);
            printf("ְ���ʣ�");
            scanf("%d",&zggz[n].zwjt);
            printf("У�����ʣ�");
		    scanf("%d",&zggz[n].xjgz);
        
            //wo[Number++]=temp; //д�뵽����
            //fwrite(&wo); //д�뵽�ļ�
		
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
    printf("������Ҫɾ����ְ�����ţ�");
    scanf("%s",gonghao);
    for(i=0;i<Number;i++)
	{
        if (strcmp(gonghao,zggz[i].num)==0) 
		{
	        printf("\n���ҵ����ˣ�ԭʼ��¼Ϊ��\n");

            printf("\t����\t����\t��λ����\tн������\tְ����\tУ������\tӦ������\t��������˰\tʵ������\n");

            printf("\t%s\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",zggz[i].num,zggz[i].name,zggz[i].gwgz,zggz[i].xjsz,zggz[i].zwjt,zggz[i].xjgz,zggz[i].yfgz,zggz[i].grsds,zggz[i].salary);
 
            printf("\nȷʵҪɾ��������Ϣ�밴1\n");
            scanf("%d",&n);

            if(n==1)   /*���ɾ��������������Ϣ��������һ��*/
			{
                for (j=i;j<Number-1;j++)
				{
                     zggz[j]=zggz[j+1];
				}
                Number--;
			}

		}
        //��ʣ������д���ļ� ������ǰ������
        fp=fopen("gx.dat","wb");
        for (i=0;i<Number;i++)
	
		
		{
             fwrite(&zggz[i],sizeof(struct worker),1,fp);
		}
             fclose(fp);
 
             printf("ɾ���ɹ�;\n");
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
read(zggz);
}