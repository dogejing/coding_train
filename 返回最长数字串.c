/*写一个函数，它的原型是int continumax（char *outputstr，char *intputstr）；
功能：在字符串中找出连续最长的数字串，并把这个串的长度返回，并把这个最长数字串付给
一个函数参数outputstr所指的内存。例如：“abcd12345ed125ss123456789”的首地址传给inputstr后，函数返回9，outputstr所指的值为123456789*/

#include <stdio.h>
#include <assert.h>

int  continumax(char *outputstr,char *intputstr)
{
	assert((outputstr != NULL) && (intputstr != NULL));
	
	char *p = intputstr;
	char *p_max = NULL;
	int count = 0,max = 0;
	
	while(*p)
	{
		if((*p >= '0')&&(*p <= '9'))
		{
			p++;
			count++;
		}
		else
		{
			count = 0;
			p++;
		}
		if(count >= max)
		{
			max = count;
			p_max = p - max;
		}
	}
	count = max;
	while((*outputstr++ = *p_max++)&&(--count));
	*outputstr = '\0' ;
	
	return max;
} 

int main(void)
{
	char str[] = "12qwe3rrr2qwe34112eee234551322r23212we35213qew21eqw3r324132q4t52q21f";
	char p[20];
	int r = 0;
	
	r = continumax(p,str);
	printf("\n----------------------\n");
	printf("%d  %s \n",r,p);
}
