 /*
	��д������ʵ���ַ������� 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * func1(char * str)	//��ͨ����
{
	char * temp = str;
			
	while(*str++);
	char * result = (char *)malloc((str - temp + 1)*sizeof(char));
	temp = result;
	
	str -= 2;

	while(*(temp-1))
	{
		*temp++ = *str--;
	}
	*temp = '\0';
	
	return result;
} 

char * func2(char * str)	//������� 
{
	char * result = str;
	char * temp = str;
	
	while(*(temp+1))
	{
		temp++;
	}


	while(temp > result)
	{
		*temp = *temp ^ *str;	
		*str = *str ^ *temp;
		*temp-- ^= *str++;	
	}
	
	return result;
}

char* Reverse(char* s)	//������� 
{
    char * r = s ;

    //��pָ���ַ������һ���ַ�
    char* p = s;
    while (*(p + 1) != '\0')
    {
    	++p;
	}    

    // ʹ�����������н���
    while (p > s)
    {
        *p ^= *s;
        *s ^= *p;
     //   *(p--) ^= *(s++);
    	*p-- = *p ^ *s++;
    }

    return r ;
}

// ���ַ���s������left��right֮��������򣬵ݹ鷨
void Reverse_2( char* s, int left, int right )
{
    if(left >= right)
        return;

    char t = s[left] ;
    s[left] = s[right] ;
    s[right] = t ;

    Reverse_2(s, left + 1, right - 1) ;
}

int main(void)
{
	char str[] = "qwerq1234567890!";
	char *result;

	puts(str);
	
	result = Reverse(str);
	puts(result);
	
}
