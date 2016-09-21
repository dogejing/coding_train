/*单词逆序*/ 

#include <stdio.h>

// 对指针p和q之间的所有字符逆序
void ReverseWord(char* p, char* q)
{
    while(p < q)
    {
        char t = *p ;
        *p++ = *q ;
        *q-- = t ;
    }
}

// 将句子按单词逆序
char* ReverseSentence(char* s)
{
    // 这两个指针用来确定一个单词的首尾边界
    char* p = s ; // 指向单词的首字符
    char* q = s ; // 指向空格或者 '\0'


    while(*q != '\0')
    {
        if (*q == ' ')
        {
            ReverseWord(p, q - 1) ;
            q++ ; // 指向下一个单词首字符
            p = q ;
        }
        else
            q++ ;
    }

    ReverseWord(p, q - 1) ; // 对最后一个单词逆序
    ReverseWord(s, q - 1) ; // 对整个句子逆序

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

