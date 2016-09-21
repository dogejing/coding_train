/*��������*/ 

#include <stdio.h>

// ��ָ��p��q֮��������ַ�����
void ReverseWord(char* p, char* q)
{
    while(p < q)
    {
        char t = *p ;
        *p++ = *q ;
        *q-- = t ;
    }
}

// �����Ӱ���������
char* ReverseSentence(char* s)
{
    // ������ָ������ȷ��һ�����ʵ���β�߽�
    char* p = s ; // ָ�򵥴ʵ����ַ�
    char* q = s ; // ָ��ո���� '\0'


    while(*q != '\0')
    {
        if (*q == ' ')
        {
            ReverseWord(p, q - 1) ;
            q++ ; // ָ����һ���������ַ�
            p = q ;
        }
        else
            q++ ;
    }

    ReverseWord(p, q - 1) ; // �����һ����������
    ReverseWord(s, q - 1) ; // ��������������

    return s ;
}

int main(void)
{
	char str[] = "i work from shanghai";
	char * result = NULL;
	
	result = ReverseSentence(str);
	puts(result);	
	
	return 0; 
}

