#include<stdio.h>
#include<bios.h>
#define Key_Up 0x4800    // ���Ϸ���� ����
#define Key_Down 0x5000  // ���·����
#define Key_Right 0x4d00  // ���ҷ����
#define Key_Left 0x4b00   // �������
void main()
{
    int key=bioskey(0); ����
    switch(key) ����
    {
     ����case Key_Up : {printf(" ���Ϸ����������"); break;}����
     ����case Key_Down : {printf(" ���·����������"); break;}
    ���� case Key_Left : {printf(" �������������"); break;}
    ���� case Key_Right : {printf(" ���ҷ����������"); break;} ����
    }
}
