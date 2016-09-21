/*�ļ�����һ��������Ҫ��������������һ���ļ���*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1024
#define F_NAME_LEN 10 

void get_data(int *src,int *len)	//���ļ��ж�ȡ���ݣ���ŵ�����src�� 
{
	FILE *fp =NULL;
	char fname[F_NAME_LEN];		//�ļ��� 
	char c; 
	int num;		//��ȡ���� 
	
	printf("Enter file name:\n");
	scanf("%s",fname);
	getchar();
	if((fp = fopen(fname,"r")) == NULL)	//���ļ� 
	{
		printf("file open error!\n");
		exit(1);
	} 
	
	num = *len = 0;		
	while((c = fgetc(fp)) != EOF)	//��ȡһ���ֽڣ����λ�ú���һ���ֽ� 
	{
		if((c >= 48)&&(c <= 57))	//������ 
		{
			num = num * 10 + c - 48;
		}
		else		//�������� 
		{
			src[(*len)++] = num;
			num = 0;
			
			while((c = fgetc(fp)) != EOF)	//��ֹ�������ַ�����src���鱻�����ַ� 
			{
				if(!((c >= 48)&&(c<=57)))
				{
					continue;		//�˳���ǰһ��ѭ�� 
				}
				else
				{
					num = num * 10 + c - 48;	
					break;
				}
			}
		}
	}
	if(num > 0)	//��������һλ 
	{
		src[(*len)++] = num;
	}
	fclose(fp);
}

void release_data(int *src,int len)		//������д���ļ� 
{
	FILE *fp = NULL;
	int *begin,*end;
	
	if((fp = fopen("test.txt","w")) == NULL)
	{
		printf("file open error!\n");
		exit(1);
	}
	begin = src;	//����ĵ�ַ 
	end = src + len;	//����ĵ�ַ���ϳ��� 
	while(begin != end)
	{
		fprintf(fp,"%d",*begin++);
		fprintf(fp,"%c",' ');
	}
	fclose(fp);
} 

int sort_function(const void *a,const void *b)	//������򡪡������� 
{
	return *((int *)a) - *((int *)b);
}

int main(void)
{
	int src[MAX_LEN],len;
	
	get_data(src,&len);
	qsort(src,len,sizeof(int),sort_function);	//���� 
	release_data(src,len);
} 
