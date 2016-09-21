#include <stdio.h>

void Merge(int *a,int left ,int right,int rightend)	//ֻ��������������������� 
{
	if((NULL == a))
	{
		return;
	} 
	
	int temp[rightend+1];
	int i = left;				//ע�⣬��ֵҪ��left��ʼ��������0   ps���Ҿ�����ߴ��ˣ����˺þ� 
	int leftend = right - 1;	//�������ı߽� 
	int len = rightend - left + 1;	//Ҫ��������ĸ��� 
	
	while((left  <= leftend) && (right <= rightend))	//�����������е����ϲ�����temp�� 
	{
		if(a[left ] <= a[right])
		{
			temp[i++] = a[left++];
		}
		else
		{
			temp[i++] = a[right++];
			
		}
	}
	while(left  <= leftend) 	//��ʣ�µ�������temp 
	{
		temp[i++] = a[left ++];		
	}
	while(right <= rightend)
	{
		temp[i++] = a[right++];	
	}
	for(i=0;i<len;i++,rightend--)		//��temp[]�е�ֵ����a[]��ע�⣺λ��Ҫ��ȷ 
	{
		a[rightend] = temp[rightend];
	}	
} 

void Mergesort(int *a,int left ,int right)	//�ݹ飬�ø����Ӽ����� 
{
	int mid = (left + right) / 2;
	
	if(left < right)	//��left = right�ǽ����ݹ飬��ʼ���� 
	{
		Mergesort(a,left,mid);	//ǰһ������� 
		Mergesort(a,mid+1,right);	//��һ������ 
		Merge(a,left,mid+1,right);
	}
}

//���� 
int main(void)
{
	int a[10] = {2,94,64,14,89,10,0,2,1,23};
	int i;
	
	for(i=0;i<10;i++)
	{
		printf(" %d ",a[i]);
	}
	Mergesort(a,0,9);
	printf("\n");
	for(i=0;i<10;i++)
	{
		printf(" %d ",a[i]);
	}
}
