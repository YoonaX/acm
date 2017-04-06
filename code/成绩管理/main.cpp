#include <stdio.h>

#include <iostream>

#include <stdlib.h>

#include <string>

#define cal_total(x,y) x+y

#define cal_level(x,y) cal_total(x,y)*cal_total(x,y)



using namespace std;



struct student

{

    int id;

    string name;

    int lisanshuxue,daxuewuli;

    int total,level;

};



void input(int n);

void output(int n);

void quick_sort(int i,int j);



student* s[10];



int main()

{

    freopen("in.txt","r",stdin);  //�ض����׼���뵽in.txt���˾���bug =��=

    //freopen("out.txt","w",stdout);  //�ض����׼�������ʹ�ÿ�ȥ��ע��

    int n;

    cin>>n;

    input;

    quick_sort(0,n);

    output��;

    return 0;

}



//���뺯��

void input(int n)

{

    int id,lisanshuxue,daxuewuli;

    string name;

    for(int i=0;i<n;i++)

    {

        s[i] = (student*)malloc(sizeof(student));

        cin>>id>>name>>lisanshuxue>>daxuewuli;

        s[i]->id = id;

        s[i]->name = name;

        s[i]->lisanshuxue = lisanshuxue;

        s[i]->daxuewuli = daxuewuli;

        s[i]->total = cal_total(s[i]->lisanshuxue,s[i]->daxuewuli);

        s[i]->level = cal_level(s[i]->lisanshuxue,s[i]->daxuewuli);

    }

}



//�������

void output(int n)

{

    for(int i=0;i<n;i++)

    {

        cout<<s[i]->id<<" "

        <<s[i]->name<<" "

        <<s[i]->lisanshuxue<<" "

        <<s[i]->daxuewuli<<" "

        <<s[i]->level<<endl;

    }



}



//��������

void quick_sort(int i,int j)

{

    if(i>=j)  //�±����Χ������

        return ;



    student* key = s[i];  //ȡ�����һ��Ԫ��Ϊ��׼ֵ

    int l = i,r = j;



    while(l<r)  //ÿ��ѭ���൱�����һ�ν���

    {

        while(s[r]->level >= key->level && l<r)

            r--;

        s[l] = s[r];

        while(s[l]->level <= key->level && l<r)

            l++;

        s[r] = s[l];

    }

    s[l] = key;  //����һ�α����ǵ�s[i]ֵд��



    quick_sort(i,l-1);  //�ݹ�������������

    quick_sort(l+1,j);  //�ݹ�������������

}
