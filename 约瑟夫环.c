/*Լɪ�򻷣�n������һȦ����1��n��ÿ���˱�š���m���˿�ʼ������������k���ˣ��������֡�
Ȼ��ӳ��ֺ���һ���˿�ʼ������ͬ���ǵ�k���ˣ����������֣���˵ķ�����ֱ��ʣ�����һ�ˡ�
������ʣ��һ���˱���Ƕ��٣�������ʵ�֣�*/ 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}LNode;

LNode * CreatLinkList(int n)	//����ѭ������ ��n���ڵ� ����ͷָ�� 
{
	LNode * head = NULL,*p = NULL,*q = NULL;
	int i=1;
	
	head = p = (struct node *)malloc(sizeof(struct node));
	if(p == NULL)
	{
		printf("p creat linklist error!\n");
		
		return 0;
	}
	p->data = i;
	for(i=2; i<=n; i++)
	{
		q = (struct node *)malloc(sizeof(struct node));
		if(q == NULL)
		{
			printf("q creat linklist error!\n");
		
			return 0;
		}
		q->data = i;
		p->next = q;
		p = q;
	}
	p->next = head;
	
	return head;
}

void joseph(LNode * p,int n,int m,int k)
{
	int i;
	LNode * q = NULL;
	
	while( p->data < m)	// �ӵ�m���ڵ㿪ʼ 
	{
		p = p->next;
	}
//	printf("m = %d \n",p->data);
	n--; 
	printf("���ֵı�ţ�");
	while(n--)	//ֻ��һ�� 
	{
		i = 0;
		while(i < (k-1))	//�ҵ���k-1���ڵ�
		{
			p = p->next;
			i++;
		}		
		q = p;	//qָ���k-1���ڵ� 
		p = p->next;	//pָ���k���ڵ� 
		q->next = p->next;	// q->nextָ���k+1���ڵ� 
		printf(" **%d** ",p->data); 
		free(p);	//�ͷŵ�k���ڵ�
		p = q;	 
	}
	printf("\nʣ�µı�ţ� %d\n",p->data);
	
} 

int main(void)
{
	int n, m,k;
	LNode * head;
	
	while(1)
	{
		printf("\n����n m k��"); 
		scanf("%d %d %d",&n, &m,&k);
		head = CreatLinkList(n);
		joseph(head,n,m,k);
	}
} 
