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
 struct zggz wo[100];//�������е�ְ����Ϣ
int Number=0; //��¼�ܵ�ְ������
int i,j,n,m,sum[100],num[100],p=0; 
int score[100][20],lower,maxer,temp=0; 
void read(struct zggz S[])
{

	
       FILE *fp;//�����ļ�ָ��

       if ((fp = fopen("gx.dat", "r")) == NULL)

       {

              printf("�ļ���ʧ��");
              getch();
              exit(-1);

       }
       //����ļ��򿪳ɹ�����ô���ж�����
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

              S[Number]=s;

              Number++;

       }
       n=Number;
       printf("\n��%d��Ա����Ϣ������\n",Number);

       fclose(fp);

       
}
void show()
{ 
printf("\n");
printf("\t���ʹ���ϵͳ \n\n");
printf("\t��ѡ���� ������0~6��\n");
printf("\t\n\n");
printf("\t1. ��ѯ\n");
printf("\t2. �޸�\n");
printf("\t3. ���\n");
printf("\t4. ɾ��\n");
printf("\t5. ����\n");
printf("\t6. Ԥ��\n");
printf("\t0. �˳�\n");
printf("\t\n");
}
void bc(struct zggz *wo)
{
FILE *fp=NULL;
fp=fopen("gx.dat","ab+");
fwrite(wo,sizeof(struct zggz),1,fp);
fclose(fp);
}
//���ְ����Ϣ
void add() 
{
int numberTemp=0;
int i=0;
struct zggz temp; 
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
printf("Ӧ�����ʣ�");
scanf("%d",&temp.yfgz);
printf("��������˰��");
scanf("%d",&temp.grsds);
printf("ʵ�����ʣ�");
scanf("%d",&temp.salary);
wo[Number++]=temp; //д�뵽����
bc(&temp); //д�뵽�ļ�
}
printf("��ӳɹ�\n");
}
//�޸ĳ�Ա����
void modify()
{

}
//Ԥ��
void list() 
{
int i=0;
printf("������ȫ��ְ��\n");
printf("\t����\t����\t��λ����\tн������\tְ����\tУ������\tӦ������\t��������˰\tʵ������\n");
while(i<Number)
{
printf("\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",wo[i].num,wo[i].name,wo[i].gwgz,wo[i].xjsz,wo[i].zwjt,wo[i].xjgz,wo[i].yfgz,wo[i].grsds,wo[i].salary);
i++;
}
}
//����ְ����Ϣ
void find() 
{
int n=0;

printf("1 �����Ų���\n");
 printf("2 ����������\n");
scanf("%d",&n);
switch(n)
{

case 1: ghcz();
break;
case 2: xmcz();
break;
default: printf("��Ա��������!\n");
break;
} 
}
void xmcz()//���������� 
{ 
char name[30];
int i=0;
printf("������Ҫ����ְ������:");
scanf("%s",name);
system("cls");
printf("\t����\t����\t��λ����\tн������\tְ����\tУ������\tӦ������\t��������˰\tʵ������\n");
for (i=0;i<Number;i++)
{
if (strcmp(name,wo[i].name)==0)
{
printf("\t%s\t%s\t%d\t%d\t%d\t%d\t%fd\t%d\t%d\n",wo[i].num,wo[i].name,wo[i].gwgz,wo[i].xjsz,wo[i].zwjt,wo[i].xjgz,wo[i].yfgz,wo[i].grsds,wo[i].salary);
}
}
}
void ghcz()//�����Ų��� 
{
char num[10];
int i=0;
printf("������Ҫ����ְ������:");
scanf("%s",num);
system("cls");
printf("\t����\t����\t��λ����\tн������\tְ����\tУ������\tӦ������\t��������˰\tʵ������\n");
for (i=0;i<Number;i++)
{
if (strcmp(num,wo[i].name)==0)
{
printf("\t%s\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",wo[i].num,wo[i].name,wo[i].gwgz,wo[i].xjsz,wo[i].zwjt,wo[i].xjgz,wo[i].yfgz,wo[i].grsds,wo[i].salary);
}
}
}
//ɾ��ְ����Ϣ
void del() 
{
int n=0;
printf("1 ������ɾ��\n");
printf("2 ������ɾ��\n");
scanf("%d",&n);
switch(n)
{
case 1: ghsc();
break;
case 2: xmsc();
break;
default: printf("��Ա��������!\n");
break;
}
}
void ghsc()//������ɾ�� 
{
FILE *fp=NULL;
char id[60];
int i=0;
int j=0;
printf("������Ҫɾ����ְ�����ţ�");
scanf("%s",id);
for(i=0;i<Number;i++)
{
if (strcmp(id,wo[i].num)==0) 
{
for (j=i;j<Number-1;j++)
{
wo[j]=wo[j+1];
}
Number--;
}
}
//��ʣ������д���ļ� ������ǰ������
fp=fopen("gx.dat","wb");
for (i=0;i<Number;i++)
{
fwrite(&wo[i],sizeof(struct zggz),1,fp);
}
fclose(fp);
printf("ɾ���ɹ�;\n");
}
void xmsc()//������ɾ�� 
{
FILE *fp=NULL;
char name[30];
int i=0;
int j=0;
printf("������Ҫɾ����ְ��������");
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
//��ʣ������д���ļ� ������ǰ������
fp=fopen("gx.dat","wb");
for (i=0;i<Number;i++)
{
fwrite(&wo[i],sizeof(struct zggz),1,fp);
}
fclose(fp);
printf("ɾ���ɹ�;\n");            

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
   if (fwrite(&wo,sizeof(struct zggz),1,fp)!=1)
   printf("file write error\n");
   printf("����ɹ�����");

   fclose(fp);
}
void back()
{
printf("\t��Enter������\n");
}
void main()
{
	struct zggz wo[100];
	
	int choose=0;
while(1) 
{ 
show();
printf("\t\t====>��ѡ��");
scanf("%d",&choose);
system("cls");
switch(choose)
{
case 1: find();
back();// ����ְ����Ϣ 
break;
 case 2: modify();
back();//�޸�ְ����Ϣ
case 3: add();
back();//���ְ����Ϣ
break; 
case 4: del(); 
back();//ɾ��ְ����Ϣ
break;
case 5:write();
back();//�������� 
break;
case 6: list();
back();//Ԥ��
break; 
case 0: exit(0);//�˳�
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