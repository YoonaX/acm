#include <iostream>
#include <cmath>
#include <fstream>
#include <istream>
#include <ostream>
using namespace std;

///////////////////////////////////////////////////////////
/*�ҽ�point �� point3Dֱ��д�����ˣ��������̾Ϳ���ֱ�������ҵĴ�����
������������֮ǰ����ʵ��д�ġ�
ֱ��ճ��������*/

class Point
{
	public:
	Point();
	Point(double x, double y);
	~Point();

	double get_x() const;
	double get_y() const;

	void set_x(double x);
	void set_y(double y);

	void display_point() const;

	protected:
	double m_x;
	double m_y;
};
Point::Point()
{
    m_x=0;
    m_y=0;
}
Point::Point(double x, double y)
{
    m_x=x;
    m_y=y;
}

Point::~Point()
{
    //dtor
}
double Point::get_x ()const
{
    return m_x;

}
double Point::get_y() const
{
    return m_y;

}

void Point::set_x(double x)
{
    m_x=x;

}
void Point::set_y(double y)
{
    m_y=y;

}

void Point::display_point() const
{

    cout<<m_x<<","<<m_y<<endl;
}

class Point3D :public Point
{
    public:
        Point3D(double x=0,double y=0,double z=0);
        virtual ~Point3D();
        void set_z(double z);
        double get_z() const;
        void display_point() const;

    private:
        double m_z;


};


Point3D::Point3D(double x,double y,double z)
{
    m_x=x;
    m_y=y;
    m_z=z;
}

Point3D::~Point3D()
{
    //dtor
}
void Point3D::set_z(double z)
{

    m_z=z;

}
double Point3D::get_z() const
{
    return m_z;


}
void Point3D::display_point() const
{

    cout<<m_x<<","<<m_y<<","<<m_z<<endl;
}
///////////////////////////////////////////////////////////
/*��������ҵ�Curve3D��*/

class Curve3D
{
	public://ȫ���ķ��������Զ���public����
	Curve3D(double x=0,double y=0,double z=0);//Ĭ�ϵĿռ����ԭ��
    Curve3D( const Curve3D& t ) ;//ǳ�������캯��
	~Curve3D();
	void DisplayCurve();//չʾ�����еĵ�
	double CurveLen();//�������߳���
	Curve3D operator+(const Point3D& point ) const;//���ؼӷ�����
	const Curve3D& operator=( const Curve3D& tr ) ;//���صȺŲ���
    Point3D* pointarray;//ָ�����飬�����Ա��Point3D����
	int num;//��¼���ߵ�ĸ���
    Curve3D operator-(const Point3D& point ) const;//���ؼ�������
    void write_txt(ofstream &os)const;
    Curve3D read_txt(ifstream &is);
    void write_binary(ofstream &os)const;
    Curve3D read_binary(ifstream &is);

};

Curve3D::~Curve3D()
{
    if(num>=1)//������û�е��Աʱ��ʲô������
    {
        if(num==1)
        delete pointarray;//�ͷ�һ����
        else
        delete[] pointarray;//�ͷ�ָ������
    }
}
Curve3D::Curve3D(double x,double y,double z)//Ĭ�����߰���һ���㣬��ָ��ʱ������ԭ��
{
    num=1;
    pointarray=new Point3D(x,y,z);
}
void Curve3D::DisplayCurve()//��ӡ�����еĵ�
{
     cout<<"The coordinates of the points is: "<<endl;
    for(int i=0;i<num;i++)
    cout<<pointarray[i].get_x()<<','<<pointarray[i].get_y()<<','<<pointarray[i].get_z()<<endl;
}

double Curve3D::CurveLen()//�������ߵĳ���
{
    if(this->num<=1)
    {
        cout<<"The length of the curve is "<<0<<endl;
        return 0;
    }
    double ans=0;
    for(int i=1;i<num;i++)
    {
       double x=fabs(pointarray[i].get_x()-pointarray[i-1].get_x());
       double y=fabs(pointarray[i].get_y()-pointarray[i-1].get_y());
       double z=fabs(pointarray[i].get_z()-pointarray[i-1].get_z());
       ans+=sqrt(x*x+y*y+z*z);
    }
    cout<<"The length of the curve is "<<ans<<endl;
     return ans;
}
Curve3D Curve3D::operator+(const Point3D& point) const//���ؼӷ������
{

    Curve3D temp;
    temp.num=this->num+1;//num����1
    delete temp.pointarray;//ɾ��temp��ָ������
    temp.pointarray=new Point3D[temp.num];//��̬�����ڴ�
    for(int i=0;i<temp.num-1;i++)//�����ߵĵ�ȫ��������ȥ
    {
        temp.pointarray[i].set_x(this->pointarray[i].get_x());
        temp.pointarray[i].set_y(this->pointarray[i].get_y());
        temp.pointarray[i].set_z(this->pointarray[i].get_z());
    }//�����һ����ӽ�ȥ
    temp.pointarray[temp.num-1].set_x(point.get_x());
    temp.pointarray[temp.num-1].set_y(point.get_y());
    temp.pointarray[temp.num-1].set_z(point.get_z());
    return temp;
}
const Curve3D& Curve3D::operator=(const Curve3D& t)
{
    if ( this != &t)//��ֹ�Լ������Լ������³���
    {
        if(num>=1)
        {
            if(num==1)
            delete pointarray;
            else
            delete[] pointarray;
        }
        pointarray=NULL;//��ָ�븳Ϊ��

        num = t.num;
        //������ǿյ�ʱ����п���
        if(num>=1)pointarray = new Point3D[num];
        for ( int i = 0 ; i < num ; i++ )
           pointarray[i] = t.pointarray[i] ;
    }
    return *this ;
}
Curve3D::Curve3D(const Curve3D& tr)//�������캯��
{
    num = tr.num;
     if(num>=1)pointarray = new Point3D[num];
     else pointarray=NULL;//���Ƕ���ָ��Ϊ�յ����
    for ( int i = 0 ; i < num ; i++ )
        pointarray[i] = tr.pointarray[i];
}
Curve3D Curve3D::operator-(const Point3D& point) const//���ؼ���������
{
    for(int i=0;i<this->num;i++)//�ҵ���ͬ�ĵ���±�i
    {
        if(point.get_x()==this->pointarray[i].get_x()
           &&point.get_y()==this->pointarray[i].get_y()
           &&point.get_z()==this->pointarray[i].get_z())
        {
             Curve3D temp;//����tmep������ߣ���������߽��й��죬ʹ�ý�ȥ�±�Ϊi�ĵ㡣
             delete  temp.pointarray;
             temp.pointarray=NULL;//��ָ�븳ֵnull
            temp.num=this->num-1;
            if(temp.num>=1)temp.pointarray=new Point3D[temp.num];

            for(int j=0;j<i;j++)//���±�С��i�Ŀ���
            {
                temp.pointarray[j].set_x(this->pointarray[j].get_x());
                temp.pointarray[j].set_y(this->pointarray[j].get_y());
                temp.pointarray[j].set_z(this->pointarray[j].get_z());
            }
            for(int j=i;j<temp.num;j++)//�����±�Ϊi�ĵ㣬��������
            {
                temp.pointarray[j].set_x(this->pointarray[j+1].get_x());
                temp.pointarray[j].set_y(this->pointarray[j+1].get_y());
                temp.pointarray[j].set_z(this->pointarray[j+1].get_z());
            }
            return temp;
        }
    }
    //���û����ͬ�ĵ�Ļ����Ϳ��Է���ԭ��������
    Curve3D temp=*this;
    return temp;
}



void Curve3D::write_txt(ofstream &os)const//�������еĵ�д���ļ���
{
    for(int i=0;i<num;i++)
    {
        os<<pointarray[i].get_x()<<' '<<pointarray[i].get_y()<<' '<<pointarray[i].get_z()<<endl;
    }

}
Curve3D Curve3D::read_txt(ifstream &is)//���ļ��е����Ϣ���������浽������
{
    Curve3D temp;Point3D p;
    temp=temp-p;//��temp���û�е������
    for(int i=0;i<num;i++)
    {

        double  x,y,z;
        is>>x>>y>>z;//��������Ϣ��
        p.set_x(x);p.set_y(y);p.set_z(z);
        temp=temp+p;//����ӵ�������
    }
    return temp;
}
void Curve3D::write_binary(ofstream &bout)const//�����ߵ���Ϣд���������ļ���
{
    int object_size=sizeof(Point3D);
    for(int i=0;i<num;i++)//�������еĵ�һ�����Զ����Ƶ���ʽд���ļ���
    {
        Point3D temp(pointarray[i].get_x(),pointarray[i].get_y(),pointarray[i].get_z());

        bout.write(reinterpret_cast<char *>(&temp),object_size);
    }
}
Curve3D Curve3D::read_binary(ifstream &bin)//���������ļ��е����Ϣ������
{
    Curve3D temp;
    Point3D p;
    int object_size=sizeof(p);
    temp=temp-p;//��temp��������е�ԭ���ȥ,ʹ��temp��Ϊû�е������
    while(bin.read(reinterpret_cast<char *>(&p),object_size))//����Ϣ����point3d�У�ֱ���������
    {
        temp=temp+p;
    }

    return temp;
}





void show( Curve3D& a) //չʾһ�����߶���
{
    cout<<"The num is "<<a.num<<endl;
    a.CurveLen();
    a.DisplayCurve();
    cout<<endl;

}
int main()//��main�������棬������Щ����
{
    Point3D point1(5,8,9);
    Point3D point2(4.5,1.9,4.8);
    Point3D point3;//�������ԭ��
    Point3D point4(0,8,6);

    Curve3D a;//���������Ĺ��죬��ʱ����aֻ��һ���㣬��ԭ��
    show(a);

    Curve3D b(1.8,8.7,9.84);//�������Ĺ��죬ֻ��һ����
    show(b);

    //�������صļӼ������
    a=a-point3;show(a);
    a=a-point4;show(a);
    a=a+point1;show(a);
    a=a+point2;show(a);
    a=a+point3;show(a);
    a=a-point3;show(a);
    a=a-point4;show(a);

    //��������ļ�����

    ofstream out( "curve3d1.txt",ios::app);//���ļ�
    if(out.fail())//��ʧ�ܵĻ��������ʾ��Ϣ
    {
        cerr<<"Failure to open the out.txt for output."<<endl;
        return 1;
    }

    ifstream in( "curve3d1.txt" );
    if(in.fail())//��ʧ�ܵĻ��������ʾ��Ϣ��
    {
        cerr<<"Failure to open the in.txt for input."<<endl;
        return 1;
    }

    cout<<endl<<"I will test the file operations."<<endl;
    a.write_txt(out);//������aд�뵽�ļ���
    Curve3D c=a.read_txt(in);//���ļ��еĶ�������Ϣ���浽����c��
    a.DisplayCurve();//��a������ߴ�ӡ����
    c.DisplayCurve();//��c������ߴ�ӡ����

    in.close();out.close();//�ر��ļ�




    //������Զ������ļ��Ķ�д����
    cout<<endl<<"I will test the binary file operations."<<endl;
    remove("curve3d2.txt");//�Ƚ��ļ�ɾ��,�������ڸ��ļ���ɾ��ʧ�ܣ��������У������쳣�˳���


    ofstream bout( "curve3d2.txt",ios::binary|ios::app);//��׷�ӵ���ʽ���ı��ĵ�
    if(bout.fail())//��ӡʧ�ܵ�ʱ�������ʾ��Ϣ
    {
        cerr<<"Failure to open the out.txt for output."<<endl;
        return 1;
    }

    a.write_binary(bout);//��a������ߵ���Ϣ����������ı�
    bout.close();//�ر��ļ�

    ifstream bin( "curve3d2.txt" ,ios::binary );//���ļ������ж�ȡ
    if(bin.fail())//��ʧ�ܵ�ʱ�������ʾ��Ϣ
    {
        cerr<<"Failure to open the in.txt for input."<<endl;
        return 1;
    }
    Curve3D d=a.read_binary(bin);//�����ļ��������Ϣ�����뵽����d��
    a.DisplayCurve();//������a��ӡ����
    d.DisplayCurve();//������d��ӡ���������жԱ�
    bin.close();//�ر��ļ�
    return 0;
}









