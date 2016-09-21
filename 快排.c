#include <stdio.h>

void swap(int *x,int *y)	//���������� 
{
	*x = *x + *y - (*y = *x);	//���ò���ʵ������������ 
	
//	int teleftp;
//	teleftp = *x;
//	*x = *y;
//	*y = teleftp;
}

int midian3(int *a,int left,int right)  //����ֵ�ָ
{
	int mid = (left + right) / 2;
	
	if(a[left] <= a[mid])
	{
		swap(&a[left],&a[mid]);
	}
	if(a[mid] <= a[right])
	{
		swap(&a[mid],&a[right]);
	}
	if(a[left] <= a[mid])
	{
		swap(&a[left],&a[mid]);
	}
	
	return a[mid];
} 

#if 1
void quicksort(int * a,int left,int right)
{
	int i = left+1,j = right;	//a[left]�����ŦԪ���ڱ�i��left+1��ʼ�ƶ� 
	int mid;		
	int key;		
	
	if(left < right)
	{	
		mid = (left + right) / 2;	
		key = midian3(a,left,right);	
		swap(&a[left],&a[mid]);		//����ŦԪ�ŵ����� 
		while(i <= j)
		{
		
			while((i <= right) && (a[i] <= key))	//�ڱ�i���� ��������������ŦԪ������ͣ�� 
			{
				i++;
			}
			while((j >= left) && (a[j] > key))		//�ڱ�j���� ��������С����ŦԪ������ͣ�� 
			{
				j--;
			}
			if(i < j)		//	���������� 
			{
				swap(&a[i],&a[j]);
			}			
		}
		//��i��j�ڱ���������ֹͣ 
		swap(&a[left],&a[j]);	//����ŦԪ���ڱ�ֹͣ�ĵ�Ԫ�����������м�Ԫ�ز������м�λ�� 
		printf("\n");
//		for(i=left;i<right;i++)
//		{
//			printf(" %d ",a[i]);
//		}
		printf("\n");
		quicksort(a,left,j-1);	//���Σ��ݹ� 
		quicksort(a,j+1,right);
	}	
}
#endif


//���� 
int main(void)
{
	int a[7] = {2,5,9,3,5,7,1};
	int i;
	
	for(i=0;i<7;i++)
	{
		printf(" %d ",a[i]);
	}
	quicksort(a,0,6);
	printf("\n"); 
	for(i=0;i<7;i++)
	{
		printf(" %d ",a[i]);
	}
}
