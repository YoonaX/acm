#include<stdio.h>
#include <string.h>
#include<iostream>
#define number 100//����Ԫ�ظ������ֵ��ͬʱҲ��Ԫ�����ֳ��ȵ����ֵ
#define MAX 100000//·��Ȩֵ���ֵ
using namespace std;
int mat[number][number];//��¼�ڵ�֮��ľ���
int n;//��¼�ڵ����Ŀ
int v[number];//����ͼ��ʱ���¼�ڵ��Ƿ񱻷��ʹ�
char s[number][number];//��¼ÿ��Ԫ�ؽ�ʲô����
int dis[number];//��¼��ʼ�ڵ㵽�����ڵ����̾���
int que[number];//��¼��ʼ�ڵ㵽�����ڵ����·�������һ��Ԫ��
void dfs(int i)//�����������
{
    printf("%s\n",s[i]);//����i��Ԫ�ش�ӡ���
    v[i]=1;//��i��¼���Ѿ����ʹ�
    for(int j=0;j<n;j++)
    {
        if(mat[i][j]<MAX&&v[j]==0)
        {
            dfs(j);
        }
    }

}
void path()
{
    int mark[number];//������飬��¼��ЩԪ�ر����ʹ�
    int i, j, min, k, tmp;
    memset(que,0,sizeof(que));//���нڵ㵽��ʼ�ڵ��·����ʼ��Ϊֱ�ӵ���
    memset(mark,0,sizeof(mark));
    //��ʼ��dis����
    for (i = 0; i < n; i ++)
        dis[i] = mat[0][i];
    dis[0] = 0;
    mark[0] = 1;//��0����ڵ��ó��Ѿ����ʹ�

//�����ǵ��͵�Dijkstra�㷨�������ҵ������ʼ�ڵ�����Ľڵ㣬Ȼ������ɳڲ�����ÿ��ѭ���ҵ�һ���ڵ㣬���Խ���n-1��ѭ��
    for (i = 1; i < n; i ++)
    {
        min = MAX;
        for (j = 0; j < n; j ++)
        {
            if (!mark[j] && dis[j] < min) {
                k = j;
                min = dis[j];
            }
        }
        mark[k] = 1;


        for (j = 0; j < n; j ++) {
            tmp = mat[k][j] + dis[k];
            if (tmp < dis[j] )
            {
                dis[j] = tmp;
                que[j]=k;
            }
        }
    }

}

void show(int v)   //��ӡ���·���ϵĸ�������
{
    //�Ƚ����е���Ϣѹ��ջ�У�Ȼ��������
    int stack[number];
    int a=0;
    int u=v;
    while(v!=0)
    {
        a++;
        stack[a]=v;
        v=que[v];
    }
    a++;
    stack[a]=v;
    while(a!=0)
    {
        cout<<s[stack[a]]<<",";
        a--;
    }

}

int main()
{
    //���ȶԵ�һ���ļ����в�������������ʦ���ļ��кܶ����õ���Ϣ�����Ҹ�ʽ�ܸ��ӣ������ҵĶ������д�ĺ��ҡ�
   // ���������ǽ��ڵ㰴��˳�����s�����ά�����У��������֮��ľ������mat��ά�����У�
    memset(mat,0x3f,sizeof(mat));//���ڵ�֮��ľ��븳ֵ�ɺܴ����

    freopen("ex3_Graph1.txt","r",stdin);
	char c;
	scanf("%c",&c);
	while(c!=':')scanf("%c", &c);
	scanf("%c", &c);
	 n = c - '0';
	scanf("%s",s[1]);
	for(int i=0;i<n;i++)
    scanf("%s", s[i]);

    char cs[number];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", cs);
		for (int j = 0; j < n; j++)
		{
			int x;
			scanf("%d\n",&x);
			if(x!=-1)
			mat[i][j] = x;


		}
	}

//	for(int i=0;i<n;i++)
//        mat[i][i]=0;

    memset(v,0,sizeof(v));
	dfs(0);
	path();
	//�����ӡ���
	printf("graph1:\n");
    for(int i=1;i<n;i++)
    {

        printf("%s->%s path:",s[0],s[i]);
        // ��ӡ·��
        show(i);//��ӡ��ʼ�ڵ㵽�����ڵ����̾���
        printf("value=%d\n",dis[i]);
    }




//����򿪵ڶ����ļ������в�����������ȫһ���������ڴ�ӡ��� ��ʱ�����в�ͬ

    memset(mat,0x3f,sizeof(mat));//���ڵ�֮��ľ��븳ֵ�ɺܴ����
    freopen("ex3_Graph2.txt","r",stdin);
	scanf("%c",&c);
	while(c!=':')scanf("%c", &c);
	scanf("%c", &c);
	 n = c - '0';
	scanf("%s",s[1]);
	for(int i=0;i<n;i++)
    scanf("%s", s[i]);


	for (int i = 0; i < n; i++)
	{
		scanf("%s", cs);
		for (int j = 0; j < n; j++)
		{
			int x;
			scanf("%d\n",&x);
			if(x!=-1)
			mat[i][j] = x;


		}
	}
//
//	for(int i=0;i<n;i++)
//        mat[i][i]=0;

    memset(v,0,sizeof(v));
	dfs(0);
	path();
	printf("graph2:\n");
    printf("%s->%s path:",s[0],s[7]);
    show(7);
    printf("value=%d\n",dis[7]);

	return 0;
}
