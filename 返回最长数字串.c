/*дһ������������ԭ����int continumax��char *outputstr��char *intputstr����
���ܣ����ַ������ҳ�����������ִ�������������ĳ��ȷ��أ������������ִ�����
һ����������outputstr��ָ���ڴ档���磺��abcd12345ed125ss123456789�����׵�ַ����inputstr�󣬺�������9��outputstr��ָ��ֵΪ123456789*/

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
