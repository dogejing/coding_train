/*约瑟夫环：n个人坐一圈，从1到n给每个人编号。从m个人开始报数，数到第k个人，让他出局。
然后从出局后下一个人开始报数，同样是第k个人，再让他出局，如此的反复，直到剩下最后一人。
问题求剩下一个人编号是多少？（链表实现）*/ 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}LNode;

LNode * CreatLinkList(int n)	//创建循环链表 有n个节点 返回头指针 
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
	
	while( p->data < m)	// 从第m个节点开始 
	{
		p = p->next;
	}
//	printf("m = %d \n",p->data);
	n--; 
	printf("出局的编号：");
	while(n--)	//只留一个 
	{
		i = 0;
		while(i < (k-1))	//找到第k-1个节点
		{
			p = p->next;
			i++;
		}		
		q = p;	//q指向第k-1个节点 
		p = p->next;	//p指向第k个节点 
		q->next = p->next;	// q->next指向第k+1个节点 
		printf(" **%d** ",p->data); 
		free(p);	//释放第k个节点
		p = q;	 
	}
	printf("\n剩下的编号： %d\n",p->data);
	
} 

int main(void)
{
	int n, m,k;
	LNode * head;
	
	while(1)
	{
		printf("\n输入n m k："); 
		scanf("%d %d %d",&n, &m,&k);
		head = CreatLinkList(n);
		joseph(head,n,m,k);
	}
} 
