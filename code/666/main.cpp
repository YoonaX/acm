#include <fstream>
#include <stdio.h>
#include <cstring>
#define SIX_TIMES 10

using namespace std;

string current_six = "";

int main()
{

         ofstream output_file;
        int six_time;
         for (six_time = 0; six_time < SIX_TIMES; six_time++)
         {

                   current_six =  current_six +"6";
                   output_file.open("six.txt",  ios::out | ios::app );
                   /*
                   ���������ϴ��룬�����ˮƽ�����ļ������Ĵ򿪷�ʽ�����ԣ�
                   �����޸ģ�������ļ���β������Ϳ����ˡ�


                   */

                   output_file << current_six.c_str() << endl;
                    output_file.close();
         }

    return 0;

}
