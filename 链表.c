/*����ļ򵥲���*/ 

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

/*��ʼ����������ͷ���*/ 
int InitList(LinkList * L)
{
	*L = (LinkList)malloc(sizeof(Node)); 
	if(*L == NULL)
		return ERROR;
	(*L)->next = NULL;
	
	return OK;
} 

/*����һ����n���ڵ������β�巨*/ 
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

/*������ĵ�n���ڵ�����һ���ڵ�*/
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

/*ɾ����n���ڵ�*/
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

/*�����ÿ�*/
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

/*��������*/
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
	printf("\n��������\n");
	CreatList(&L,10);
	PrintList(L);
	printf("\n����\n");
	InsertNode(&L,5);
	PrintList(L);
	printf("\nɾ��\n");
	DelectNode(&L,6);
	PrintList(L);
	printf("\n�������\n");
	ClearList(&L);
	PrintList(L);
}


