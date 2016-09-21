/*链表的简单操作*/ 

#include <stdio.h>
#include <stdlib.h>

#define OK 	  1
#define ERROR 0

int num = 0;

typedef struct Node
{
	int data;
	struct Node * next;
}Node;
typedef struct Node * LinkList;

/*初始化链表，生成头结点*/ 
int InitList(LinkList * L)
{
	*L = (LinkList)malloc(sizeof(Node)); 
	if(*L == NULL)
		return ERROR;
	(*L)->next = NULL;
	
	return OK;
} 

/*创建一个有n个节点的链表，尾插法*/ 
void CreatList(LinkList *L,int n)
{
	LinkList p = NULL,q = NULL;
	
//	*L = (LinkList)malloc(sizeof(Node));
	p = *L;
	while(n--)
	{
		q = (LinkList)malloc(sizeof(Node));
		p->next = q;
		q->data = num++;
		p = q;
	}
	p->next = NULL;	
} 

/*在链表的第n个节点后插入一个节点*/
void InsertNode(LinkList *L,int n)
{
	LinkList p = NULL,q = NULL;
	
	q = (LinkList)malloc(sizeof(Node));
	q->data = 100;
	p = (*L);
	while(n--)
	{
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
} 

/*删除第n个节点*/
void DelectNode(LinkList *L ,int n)
{
	LinkList p = NULL,q = NULL; 
	
	p = *L;
	n--;
	while(n--)
	{
		p = p->next; 
	}
	q = p;
	p = p->next;
	q->next = p->next;
	free(p);
	p = NULL;
}

/*将表置空*/
void ClearList(LinkList *L)
{
	LinkList p = NULL,q = NULL;
	
	p = (*L)->next;
	while(p->next != NULL)
	{
		q = p;
		free(p);
		p = NULL;
		p = q->next;
	} 
	(*L)->next = NULL;	 
} 

/*遍历链表*/
void PrintList(LinkList L)
{
	LinkList p = NULL;
	
	p = L->next;
	while(p->next != NULL)
	{
		printf(" %d ",p->data);
		p = p->next;
	}
	printf(" %d ",p->data);
} 

int main(void)
{
	LinkList L;
	
	InitList(&L);
	printf("\n创建链表\n");
	CreatList(&L,10);
	PrintList(L);
	printf("\n插入\n");
	InsertNode(&L,5);
	PrintList(L);
	printf("\n删除\n");
	DelectNode(&L,6);
	PrintList(L);
	printf("\n清空链表\n");
	ClearList(&L);
	PrintList(L);
}


