#include <stdio.h>

void Merge(int *a,int left ,int right,int rightend)	//只能作用于有序的数组排序 
{
	if((NULL == a))
	{
		return;
	} 
	
	int temp[rightend+1];
	int i = left;				//注意，赋值要从left开始，而不是0   ps：我就是这边错了，找了好久 
	int leftend = right - 1;	//左边数组的边界 
	int len = rightend - left + 1;	//要排序的数的个数 
	
	while((left  <= leftend) && (right <= rightend))	//将两边数组中的数合并排序到temp中 
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
	while(left  <= leftend) 	//将剩下的数赋给temp 
	{
		temp[i++] = a[left ++];		
	}
	while(right <= rightend)
	{
		temp[i++] = a[right++];	
	}
	for(i=0;i<len;i++,rightend--)		//将temp[]中的值赋给a[]，注意：位置要正确 
	{
		a[rightend] = temp[rightend];
	}	
} 

void Mergesort(int *a,int left ,int right)	//递归，让各个子集有序化 
{
	int mid = (left + right) / 2;
	
	if(left < right)	//当left = right是结束递归，开始返回 
	{
		Mergesort(a,left,mid);	//前一半的排序 
		Mergesort(a,mid+1,right);	//后一半排序 
		Merge(a,left,mid+1,right);
	}
}

//测试 
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
