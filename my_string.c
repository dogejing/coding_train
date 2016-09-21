/*×Ô¼º±àÐ´µÄstring¿â*/
#include <assert.h>
#include <stdio.h>


int my_strlen( const char * str)
{
	assert( str != NULL);
	
	int len = 0;
	while( (*str++) != '\0')
	{
		len++;
	}
	
	return len;
} 

char * my_strcpy( char * strDest, const char * strSrc )
{
	assert((strDest != NULL) && (strSrc != NULL));
	
	char * address = strDest;
	while( (*strDest++ = *strSrc++) != '\0');
	
	return address; 
}


int main(void)
{
	char *str = "hello!";
	char res1[10];
	char res2[10];
	
	printf("*******%d***********\n",my_strlen(str));
	printf("%s\n",my_strcpy(res1,str));
	puts(res1);
}
