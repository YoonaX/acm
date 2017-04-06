#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <malloc.h>

struct node//����ڵ�
{
	int number;
	struct node *next;
};
struct node *head;//���������ͷ
void creat()//��������
{
	int n;
	//��ʼ��ͷ���
	head = (node*)malloc(sizeof(node));
	scanf("%d", &n);
	head->number = n;
	head->next = NULL;
	struct node *curr = head;
	//���������ڵ�,���ļ����������ڵ�����
	while (scanf("%d", &n)!=EOF)
	{
		curr->next = (node*)malloc(sizeof(node));
		curr = curr->next;
		curr->number = n;
		curr->next = NULL;
	}
}
void print()
{    //��ӡ��������нڵ㣬
	node *p = head;
	while (p != NULL)
	{
		printf("%d ",p->number);
		p = p->next;
	}
	printf("\n");
}

int len()
{
	node *p = head;
	int ans = 0;//��¼����ĳ���
	while (p != NULL)
	{
		ans++;
		p = p->next;
	}
	return ans;
}
void find(int x)//�ҵ� �����е�һ��������x��Ԫ���±�
{
	node *p = head;
	int n = 0;
	while (p)
	{
		if (x==p->number)//�ҵ�����֮�󣬽�����������
		{
			printf("The position of %d is ", x);
			printf("%d\n", n); return;
		}
		n++;
		p = p->next;
	}
		printf("Sorry,the number is not in tne linklist.\n");
}
//���������򣬲��ҷ��������ͷָ��

node *rebuild(node *head)
 {
   node *newHead;
   //���������Ԫ�ظ���������1�Ļ��������ݹ�
    if ((head == NULL) || (head->next == NULL))
        return head;
    newHead = rebuild(head->next); /*�ݹ鲿��*/
    head->next->next = head; /*��˷����*/
    head->next = NULL;
	return newHead;
 }
void index(int position, int x)
{
	if (position < 0)
		printf("The position must be a positive number.");
	node *p = head;
	int n = 0;//n��¼Ԫ��λ��
	while (p != NULL)
	{
		//�ҵ���λ�ú󣬽��в������
		if (n==position)
		{
			int temp = p->number;
			p->number = x;
			node *p2 = (node*)malloc(sizeof(node));
			p2->number = temp;
			p2->next = p->next;
			p->next = p2;
			return;
		}
		n++;
		p = p->next;
	}
	printf("Sorry,the position is too large.\n");

}
//ɾ����һ����ֵ��x��Ԫ��
int del(int x)
{
	node *p;
	node *temp;
	if (head == NULL)
	{
		return 0;
	}
	if (head->number == x)//���ͷ������ֵ��x�Ļ�������ɾ������
	{
		temp = head;
		head = head->next;
		free(temp);
		return 1;
	}
	p = head->next;
	temp = head;//tempָ��p��ǰһ�����
	while (p)
	{
		if (p->number == x)//�ҵ���һ����ֵ��x��Ԫ��֮�󣬽���ɾ������
		{
			temp->next=p->next;
			free(p);
			return 1;
		}
		p = p->next;
		temp = temp->next;
	}
	return 0;

}

int sort()
{


	node *p1 = head;
	node *p2 = head;
	//���ѭ��ʹ��p1ָ�룬ѭ��Ԫ�ظ�����
	for (p1 = head; p1 != NULL; p1 = p1->next)
		//�ڲ�ѭ��ʹ��p2ָ�룬ѭ��Ԫ�ظ�����ȥһ��
		for (p2 = head; p2->next != NULL; p2 = p2->next)
		{//���ǰ��Ԫ�ص�ֵ���ں���Ԫ�ص�ֵ�ͽ��л���
			if (p2->number > p2->next->number)
			{
				int temp = p2->number;
				p2->number = p2->next->number;
				p2->next->number = temp;
			}
		}
	return 0;
}
int main()
{
    freopen("in.txt","r",stdin);

	creat();fclose(stdin);
    freopen("CON", "r", stdin);
	printf("The linklist has finished.\n");
	printf("The linklist is ");
	print();

	sort();
	printf("After the  sort .The linklist is ");
	print();

	int x,position;

	printf("Please input the value.");
	scanf("%d", &x);
	find(x);

	printf("Please input  the position and the value.");
	scanf("%d %d", &position,&x);
	index(position, x);
	printf("The linklist is ");
	print();

	scanf("%d", &x);
	del( x);
	printf("After delet ,the linklist is ");
	print();

	printf("The length of the listlink is  %d\n", len());

	head=rebuild(head);
	printf("After the rebulid,the linklist is ");
	print();
	return 0;
}
/*
1 3 5 8 9 4 6 7 55 30 48 12 4 513 1 54 1997
1997
0 1997
1997

*/

























