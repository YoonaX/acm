#include <iostream>
#include<stdio.h>
using namespace std;
int mat[10000];
int  read()//�Ƚ����ݶ����������ҷ�������Ԫ�صĸ�����
{
    int n=0;
    while(scanf("%d",&mat[n])!=EOF)
    {
       n++;
    }
    return n;
}

int AdjustArray(int l, int r) //���ص������׼����λ��
{
	int i = l, j = r;
	int x = mat[l];
	while (i < j)
	{
		// ����������С��x��������s[i]
		while(i < j && mat[j] >= x)
			j--;
		if(i < j)
		{
			mat[i] =mat[j]; //��s[j]�s[i]�У�s[j]���γ���һ���µĿ�
			i++;
		}

		// ���������Ҵ��ڻ����x��������s[j]
		while(i < j && mat[i] < x)
			i++;
		if(i < j)
		{
			mat[j] = mat[i]; //��s[i]�s[j]�У�s[i]���γ���һ���µĿ�
			j--;
		}
	}
	//�˳�ʱ��i����j����x�������С�
	mat[i] = x;

	return i;
}

void sort( int l, int r)//������еݹ�Ŀ�������
{
    if (l < r)
    {
        int i = AdjustArray( l, r);
        sort( l, i - 1); // �ݹ����
        sort( i + 1, r);
    }
}



void print(int num)//��ӡ������
{

    for(int i=0;i<num;i++)
    {
        printf("%d,",mat[i]);
    }
    printf("\n");
}

int main()
{
    //�ѵ�һ���ļ����룬���п�������
    freopen("in1.txt","r",stdin);
    int num=read();
    printf("Before  the sort,the mat is:\n");
    print(num);
    sort(0,num-1);
    printf("After  the sort,the mat is:\n");
    print(num);
    //���ڶ����ļ����룬���п��Ų�����
    freopen("in2.txt","r",stdin);

    num =read();
    printf("Before  the sort,the mat is:\n");
    print(num);
    sort(0,num-1);
    printf("After  the sort,the mat is:\n");
    print(num);

    return 0;
}
