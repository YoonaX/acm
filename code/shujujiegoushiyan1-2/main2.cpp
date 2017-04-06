#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <malloc.h>

using namespace std;



struct Node {
	double coef;//ϵ��
	int expn;//ָ��
	Node *next;//ָ�룬ָ����һ���ڵ�
};

Node *A = NULL;//������������ʽָ��
Node *B = NULL;
Node *c = NULL;
void sort(Node *&head)//������
{
	if (head->next->next == NULL)  //���ֻ��һ���ڵ�Ļ�����������ֱ�ӷ��ؼ���
	{
		 return;
	}
	else
	{//����ð������
		for (Node *p = head->next; p != NULL; p = p->next)//���ѭ����ѭ��Ԫ�ظ�����
		{
			for (Node *q = head->next; q->next != NULL; q = q->next)//�ڲ�ѭ����ѭ��Ԫ�ظ�����ȥһ��
			{
				if (q->expn > q->next->expn)//���ǰ���Ԫ��ָ�����ں���ģ��ͽ��л���
				{
					int temp1 = q -> expn;
					q->expn = q->next->expn;
					q->next->expn = temp1;
					double temp2=  q->coef;
					q->coef = q->next->coef;
					q->next->coef = temp2;
				}
			}
		}

	}

}

void sort2(Node *&head)//��������������� ����ʵ��c���������
{
	if (head->next->next == NULL)  //���ֻ��һ���ڵ�Ļ�����������ֱ�ӷ��ؼ���
	{
		return;
	}
	else
	{//����ð������
		for (Node *p = head->next; p != NULL; p = p->next)//���ѭ����ѭ��Ԫ�ظ�����
		{
			for (Node *q = head->next; q->next != NULL; q = q->next)//�ڲ�ѭ����ѭ��Ԫ�ظ�����ȥһ��
			{
				if (q->expn < q->next->expn)//���ǰ���Ԫ��ָ��С�ں���ģ��ͽ��л���
				{
					int temp1 = q->expn;
					q->expn = q->next->expn;
					q->next->expn = temp1;
					double temp2 = q->coef;
					q->coef = q->next->coef;
					q->next->coef = temp2;
				}
			}
		}

	}

}
void CreatPolynomial(Node *&head)//���� һ�� ����ʽ����
{
	head = (Node *)malloc(sizeof(Node));
	head->coef = 0;
	head->expn = 0;
	head->next = NULL;
	Node *p = head;
	int a, b;
	scanf("%d %d", &a, &b);
	while(b>=0)
	{
		p->next = (Node *)malloc(sizeof(Node));  //  �����½�㣬β������������
		p = p->next;
		p->coef = a;
		p->expn = b;
		p->next = NULL;
		scanf("%d %d", &a, &b);
	}

}

void PrintPolynomial(Node *&head)//��ӡ����ʽ
{
	if (head==NULL) //  �������ʽû��Ԫ�ؾ�ֱ���˳�
	{
		printf("\n"); return ;
	}
	else {
		for (Node *p = head->next; p != NULL; p = p->next)//head->next�ǵ�һ��Ԫ�أ����Դ�����ʼ��ӡ
		{
			cout <<'['<< p->coef<<' '<<p->expn<<']';
		}
	}
	cout << endl;//��ӡ���з�
}


void Free(Node *&head)//����һ�����������������Ķ���
{
	Node *q = NULL;
	for (Node *p = head; p != NULL; p = q) {
		q = p->next;
		free(p);
	}
}

char cmp(int a, int b)
{
	if (a > b)
		return '>';
	if (a < b)
		return '<';
	return '=';
}

void AddPolynomial(Node *&pA, Node *&pB)//  �������������ͷָ��
{
	c = (Node *)malloc(sizeof(Node));
	c->coef = 0;
	c->expn = 0;
	c->next = NULL;
	Node *p = c;
	Node *ha = pA;
	Node *hb = pB;
	Node *qa = ha->next; //  ha, hb�ֱ����qa, qb�ĺ�һλ��
	Node *qb = hb->next; //  qa, qb�ֱ�ָ��Pa, Pb�е�ǰ�Ƚ�Ԫ��
	while (qa && qb)
	{
		double sum = 0;
		int a = qa->expn;
		int b = qb->expn;
		switch (cmp(a, b)) //�Ƚ�qa��qb��ϵ��
		{
		case '<':
			p->next = (Node *)malloc(sizeof(Node));  //  �����½�㣬β������������
			p = p->next;
			p->coef = qa->coef;
			p->expn =qa->expn ;
			p->next = NULL;

			ha = qa;
			qa = qa->next;
			break;
		case '>':
			p->next = (Node *)malloc(sizeof(Node));  //  �����½�㣬β������������
			p = p->next;
			p->coef = qb->coef;
			p->expn = qb->expn;
			p->next = NULL;

			hb = qb;
			qb = qb->next;
			break;

		case '=':
			sum = qa->coef + qb->coef;
			if (sum != 0.0)
			{

				p->next = (Node *)malloc(sizeof(Node));  //  �����½�㣬β������������
				p = p->next;
				p->coef = sum;
				p->expn = qa->expn;
				p->next = NULL;
				ha = qa;
				hb = qb;
			}
			qb = qb->next;
			qa = qa->next;
			break;
		}
	}
	if (qa)
	{
		while (qa)
		{
			p->next = (Node *)malloc(sizeof(Node));  //  �����½�㣬β������������
			p = p->next;
			p->coef = qa->coef;
			p->expn = qa->expn;
			p->next = NULL;

			ha = qa;
			qa = qa->next;
		}
	}
	if (qb)
	{
		while (qb)
		{
			p->next = (Node *)malloc(sizeof(Node));  //  �����½�㣬β������������
			p = p->next;
			p->coef = qb->coef;
			p->expn = qb->expn;
			p->next = NULL;
			hb = qb;
			qb = qb->next;
		}
	}
}
int main()
{

	int times;
	scanf("%d", &times);
	while(times--)
	{
		CreatPolynomial(A);  sort(A);//������ʽ������������Ұ�����������
		CreatPolynomial(B);  sort(B);

		AddPolynomial(A, B); //  c = A + B
		sort2(c);
		PrintPolynomial(c);//  ���c
		Free(A); Free(B);//  ����ͷŽ��
	}
	return 0;
}
/*
2
-1 17 2 20 5 9 -7 7 10 4 22 2 2 0 16 5 0 -1
2 19 7 7 3 17 4 4 15 10 -10 5 13 2 -7 0 8 -8
3 5 -2 1 4 0 0 -1
7 7 1 6 -1 5 8 -8



*/
