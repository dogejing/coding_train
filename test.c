#include <stdio.h> 

unsigned int intvert(unsigned int x,int p, int n)
{
	unsigned int y = 0 ;		//定义的变量一定要初始化！ 
	
	while(n--)
	{
		y |= (1<<(n+p));
	}	
	x=((~x)&y)|(x&(~y));
	
	return x;
	
}

int main()
{
	unsigned int x = 0b00010001;
	unsigned int y = 0;
	
	y = intvert(x,4,3);
	printf("%d \n",y);
	int a = 0b01100001;
	printf("%d \n",a);
}
