/*文件中有一组整数，要求排序后输出到另一个文件中*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1024
#define F_NAME_LEN 10 

void get_data(int *src,int *len)	//从文件中读取数据，存放到数组src中 
{
	FILE *fp =NULL;
	char fname[F_NAME_LEN];		//文件名 
	char c; 
	int num;		//读取的数 
	
	printf("Enter file name:\n");
	scanf("%s",fname);
	getchar();
	if((fp = fopen(fname,"r")) == NULL)	//打开文件 
	{
		printf("file open error!\n");
		exit(1);
	} 
	
	num = *len = 0;		
	while((c = fgetc(fp)) != EOF)	//读取一个字节，光标位置后移一个字节 
	{
		if((c >= 48)&&(c <= 57))	//是数字 
		{
			num = num * 10 + c - 48;
		}
		else		//不是数字 
		{
			src[(*len)++] = num;
			num = 0;
			
			while((c = fgetc(fp)) != EOF)	//防止连续的字符导致src数组被放入字符 
			{
				if(!((c >= 48)&&(c<=57)))
				{
					continue;		//退出当前一步循环 
				}
				else
				{
					num = num * 10 + c - 48;	
					break;
				}
			}
		}
	}
	if(num > 0)	//最后可能有一位 
	{
		src[(*len)++] = num;
	}
	fclose(fp);
}

void release_data(int *src,int len)		//将数据写入文件 
{
	FILE *fp = NULL;
	int *begin,*end;
	
	if((fp = fopen("test.txt","w")) == NULL)
	{
		printf("file open error!\n");
		exit(1);
	}
	begin = src;	//数组的地址 
	end = src + len;	//数组的地址加上长度 
	while(begin != end)
	{
		fprintf(fp,"%d",*begin++);
		fprintf(fp,"%c",' ');
	}
	fclose(fp);
} 

int sort_function(const void *a,const void *b)	//排序规则——从升序 
{
	return *((int *)a) - *((int *)b);
}

int main(void)
{
	int src[MAX_LEN],len;
	
	get_data(src,&len);
	qsort(src,len,sizeof(int),sort_function);	//快排 
	release_data(src,len);
} 
