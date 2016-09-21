/*用栈实现计算器*/ 
/*经典的用来练习栈的题目，需要借助逆波兰表达式*/

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

/*创建一个顺序栈*/
stacknode * sqstack_create(void)
{
	stacknode * p;
	
	p = (stacknode *)malloc(sizeof(*p));
	assert(p);		//分配空间后加上断言是个好习惯
	p->top = -1;
	
	return p;
}

/*入栈操作*/
int sqstack_push(const int n, stacknode * const p)		//复习一下const的用法，const修饰指针p，指针不可改变
{
	if(p->top == (MAXSIZE - 1))	//栈满
	{
		return ERROR;
	}
	p->data[++p->top] = n;
	
	return OK;
}

/*出栈操作*/
int sqstack_pop(int *dest, stacknode * const p)
{
	if(p->top == -1)	//栈空
	{
		return ERROR;
	}
	*dest = p->data[p->top--];
		
	return OK;
}

/*获取栈顶值*/
int sqstack_top(int *dest,const stacknode *p)		//const修饰指针*p，p指向的内容不可改变
{
	if(p->top == -1)	//栈空
	{
		return ERROR;
	}
	*dest = p->data[p->top];
		
	return OK;
}

/*打印栈中内容*/
int sqstack_print(stacknode *p)
{
	int n = p->top;
	
	if(n == -1)	//栈空
	{
		return ERROR;
	}
	while(n)
	{
		printf(" %d ",p->data[n--]);
	}
	printf("\n");
}

/*判断栈是否为空*/
int sqstack_is_empty(stacknode *p)
{
	return (p->top == -1);
}

/*优先级判断函数*/
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

/*提取两个数和一个操作符进行计算，得到的结果再压栈*/
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

/*进行优先级计算*/
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
	sqstack_push(ope,pope);	//将新的操作符入栈
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
    /*str为表达式数组*/
    char str[MAXSIZE];
    printf("请输入你要计算的表达式:\n");
    gets(str);

    int i = 0;
    int value = 0;   //数字的值
    int flag = 0;    
    int old_ope;

    stacknode *pnum,*pope;      // 定义两个指向栈结构体的指针

    pnum = sqstack_create();  // 创建存放数字的栈

    pope = sqstack_create();  // 创建存放运算符号的栈

    /* 表达式字符串解析函数,然后将高优先级的符号/(*)进行计算重新入栈
       退出while大家的优先级都一样+-*/
    while (str[i] != '\0')
    {
        //获取输入的数字
        if (str[i] >= '0' && str[i] <= '9')//num
        {
            value = value * 10 + str[i] - '0';
            flag = 1;
        }
        else//ope
        {
            if (flag)
            {
                //flag = 1说明value里面存储了数字，将其入栈
                sqstack_push (value, pnum);
                //num标志清零，value存放数字的变量清零
                flag = 0;
                value = 0;
            }
            if(str[i] == ')')
            {
                //如果是右括号，则
                deal_bracket(pnum,pope);
            }
            else//+-*/(等情况 
            {
                deal_ope(pnum,pope,str[i]);
            }   
        }   
        i++;
    }
    //如果flag = 1.说明value里面还有数值,将其入栈 
    if (flag)
    {
        sqstack_push(value,pnum);
    }
    //然后将符号与数字依次出栈计算。数字出栈计算完成之后回再次在compute中入栈
    while (!sqstack_is_empty(pope))
    {
        sqstack_pop(&old_ope,pope);
        compute(pnum,old_ope);
    }
    //取出数字栈最后剩下的数字，就是最后的答案
    sqstack_pop(&value,pnum);
    //打印结果
    printf("%s = %d\n",str,value);

    return 0;
}

