#include <stdio.h>

void swap(int *x,int *y)	//交换两个数 
{
	*x = *x + *y - (*y = *x);	//不用参数实现两个数交换 
	
//	int teleftp;
//	teleftp = *x;
//	*x = *y;
//	*y = teleftp;
}

int midian3(int *a,int left,int right)  //三中值分割法
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
	int i = left+1,j = right;	//a[left]存放枢纽元，哨兵i从left+1开始移动 
	int mid;		
	int key;		
	
	if(left < right)
	{	
		mid = (left + right) / 2;	
		key = midian3(a,left,right);	
		swap(&a[left],&a[mid]);		//将枢纽元放到最左 
		while(i <= j)
		{
		
			while((i <= right) && (a[i] <= key))	//哨兵i左移 ，当遇到大于枢纽元的数则停下 
			{
				i++;
			}
			while((j >= left) && (a[j] > key))		//哨兵j右移 ，当遇到小于枢纽元的数则停下 
			{
				j--;
			}
			if(i < j)		//	交换两个数 
			{
				swap(&a[i],&a[j]);
			}			
		}
		//当i，j哨兵相遇，则停止 
		swap(&a[left],&a[j]);	//将枢纽元和哨兵停止的单元交换，即将中间元素插入中中间位置 
		printf("\n");
//		for(i=left;i<right;i++)
//		{
//			printf(" %d ",a[i]);
//		}
		printf("\n");
		quicksort(a,left,j-1);	//分治，递归 
		quicksort(a,j+1,right);
	}	
}
#endif


//测试 
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
