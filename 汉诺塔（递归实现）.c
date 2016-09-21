/*N阶汉诺塔递归实现:如果将n个盘子（由小到大）从a通过b，搬到c，移动的规则如下：这些圆形盘只能在3个塔问进行移动．一 
次只能移动一个盘子，且任何时候都不允许将较大的盘子压在比它小的盘子的上面。*/

//思路：把n-1个盘子移动到b柱子上，然后把第n个盘子移动到c柱子上，最后把n-1个盘子移动到c柱子上

#include <stdio.h>

int i = 0;

void move(int n,char a,char b)
{	
	i++; 
	printf("%d盘子:%c -> %c  第%d次\n",n,a,b,i);
}

void hannuo(int n,char a,char b,char c)
{	
	if(0 == n)
	{
		return;
	}
	if(1 == n)
	{
		i++; 
		printf("%d盘子:%c -> %c  第%d次\n",n,a,c,i);
	}
	else
	{
		hannuo(n-1,a,c,b);	//把n-1个盘子移动到b柱子上
		move(n,a,c);		//把第n个盘子移动到c柱子上
		hannuo(n-1,b,a,c);	//把n-1个盘子移动到c柱子上
	}
}

//测试 
int main(void)
{
	hannuo(10,'a','b','c');
}
