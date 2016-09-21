/*��ջʵ�ּ�����*/ 
/*�����������ϰջ����Ŀ����Ҫ�����沨�����ʽ*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXSIZE 64
#define OK 1
#define ERROR 0

typedef struct
{
	int data[MAXSIZE];
	int top;
}stacknode;

/*����һ��˳��ջ*/
stacknode * sqstack_create(void)
{
	stacknode * p;
	
	p = (stacknode *)malloc(sizeof(*p));
	assert(p);		//����ռ����϶����Ǹ���ϰ��
	p->top = -1;
	
	return p;
}

/*��ջ����*/
int sqstack_push(const int n, stacknode * const p)		//��ϰһ��const���÷���const����ָ��p��ָ�벻�ɸı�
{
	if(p->top == (MAXSIZE - 1))	//ջ��
	{
		return ERROR;
	}
	p->data[++p->top] = n;
	
	return OK;
}

/*��ջ����*/
int sqstack_pop(int *dest, stacknode * const p)
{
	if(p->top == -1)	//ջ��
	{
		return ERROR;
	}
	*dest = p->data[p->top--];
		
	return OK;
}

/*��ȡջ��ֵ*/
int sqstack_top(int *dest,const stacknode *p)		//const����ָ��*p��pָ������ݲ��ɸı�
{
	if(p->top == -1)	//ջ��
	{
		return ERROR;
	}
	*dest = p->data[p->top];
		
	return OK;
}

/*��ӡջ������*/
int sqstack_print(stacknode *p)
{
	int n = p->top;
	
	if(n == -1)	//ջ��
	{
		return ERROR;
	}
	while(n)
	{
		printf(" %d ",p->data[n--]);
	}
	printf("\n");
}

/*�ж�ջ�Ƿ�Ϊ��*/
int sqstack_is_empty(stacknode *p)
{
	return (p->top == -1);
}

/*���ȼ��жϺ���*/
int get_priority(int ope)
{
	switch (ope)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '(':return 0;
		default:return ERROR;
	}
}

/*��ȡ��������һ�����������м��㣬�õ��Ľ����ѹջ*/
void compute(stacknode *pnum,int ope)
{
	int num1,num2;
	int result;
	
	sqstack_pop(&num1,pnum);
	sqstack_pop(&num2,pnum);
	switch (ope)
	{
		case '+':	result = num1 + num2;
		case '-':	result = num1 - num2;
		case '*':	result = num1 * num2;
		case '/':	result = num1 / num2;
	}
	sqstack_push(result,pnum); 
}

/*�������ȼ�����*/
void deal_ope(stacknode *pnum,stacknode *pope,int ope)
{
	int old_ope;
	
	if(sqstack_is_empty(pope)||ope == '(')
	{
		sqstack_push(ope,pope);
		return;
	}
	sqstack_top(&old_ope,pope);
	if(get_priority(ope)>get_priority(old_ope))
	{
		sqstack_push(ope,pope);
		return;
	}
	while(get_priority(ope)<=get_priority(old_ope))
	{
		sqstack_pop(&old_ope,pope);
		compute(pnum,old_ope);
		if(sqstack_is_empty(pope))
		{
			break;
		}
		sqstack_top(&old_ope,pope);
	}
	sqstack_push(ope,pope);	//���µĲ�������ջ
}

void deal_bracket(stacknode *pnum,stacknode *pope)
{
	int old_ope;
	
	sqstack_top(&old_ope,pope);
	while(old_ope != '(')
	{
		sqstack_pop(&old_ope,pope);
		compute(pnum,old_ope);
		sqstack_top(&old_ope,pope);
	}
	sqstack_pop(&old_ope,pope);
}

int main()
{
    /*strΪ���ʽ����*/
    char str[MAXSIZE];
    printf("��������Ҫ����ı��ʽ:\n");
    gets(str);

    int i = 0;
    int value = 0;   //���ֵ�ֵ
    int flag = 0;    
    int old_ope;

    stacknode *pnum,*pope;      // ��������ָ��ջ�ṹ���ָ��

    pnum = sqstack_create();  // ����������ֵ�ջ

    pope = sqstack_create();  // �������������ŵ�ջ

    /* ���ʽ�ַ�����������,Ȼ�󽫸����ȼ��ķ���/(*)���м���������ջ
       �˳�while��ҵ����ȼ���һ��+-*/
    while (str[i] != '\0')
    {
        //��ȡ���������
        if (str[i] >= '0' && str[i] <= '9')//num
        {
            value = value * 10 + str[i] - '0';
            flag = 1;
        }
        else//ope
        {
            if (flag)
            {
                //flag = 1˵��value����洢�����֣�������ջ
                sqstack_push (value, pnum);
                //num��־���㣬value������ֵı�������
                flag = 0;
                value = 0;
            }
            if(str[i] == ')')
            {
                //����������ţ���
                deal_bracket(pnum,pope);
            }
            else//+-*/(����� 
            {
                deal_ope(pnum,pope,str[i]);
            }   
        }   
        i++;
    }
    //���flag = 1.˵��value���滹����ֵ,������ջ 
    if (flag)
    {
        sqstack_push(value,pnum);
    }
    //Ȼ�󽫷������������γ�ջ���㡣���ֳ�ջ�������֮����ٴ���compute����ջ
    while (!sqstack_is_empty(pope))
    {
        sqstack_pop(&old_ope,pope);
        compute(pnum,old_ope);
    }
    //ȡ������ջ���ʣ�µ����֣��������Ĵ�
    sqstack_pop(&value,pnum);
    //��ӡ���
    printf("%s = %d\n",str,value);

    return 0;
}

