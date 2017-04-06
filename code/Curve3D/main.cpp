#include <iostream>
#include <cmath>
using namespace std;


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





class Curve3D
{
	public://ȫ���ķ��������Զ���public����
	Curve3D(int x=0,int y=0,int z=0);//Ĭ�ϵĿռ����ԭ��
    Curve3D( const Curve3D& t ) ;//ǳ�������캯��
	~Curve3D();
	void DisplayCurve();
	double CurveLen();
	Curve3D operator+(const Point3D& point ) const;//���ؼӷ�����
	const Curve3D& operator=( const Curve3D& tr ) ;//���صȺŲ���
    Point3D* pointarray;//ָ�����飬�����Ա��Point3D����
	int num;
    Curve3D operator-(const Point3D& point ) const;//���ؼ�������

//	void  write_txt(ofstream &os);
//	Curve3D read_txt(ifstream &is);
//	void write_binary(ofstream &os);
//     Curve3D read_binary(ifstream &is);
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
Curve3D::Curve3D(int x,int y,int z)//Ĭ�����߰���һ���㣬��ָ��ʱ������ԭ��
{
    num=1;
    pointarray=new Point3D(x,y,z);
}
void Curve3D::DisplayCurve()
{
     cout<<"The coordinates of the points is: "<<endl;
    for(int i=0;i<num;i++)
    cout<<pointarray[i].get_x()<<','<<pointarray[i].get_y()<<','<<pointarray[i].get_z()<<endl;
}

double Curve3D::CurveLen()
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
Curve3D Curve3D::operator+(const Point3D& point) const
{

    Curve3D temp;
    temp.num=this->num+1;
    delete temp.pointarray;
    temp.pointarray=new Point3D[temp.num];
    for(int i=0;i<temp.num-1;i++)
    {
        temp.pointarray[i].set_x(this->pointarray[i].get_x());
        temp.pointarray[i].set_y(this->pointarray[i].get_y());
        temp.pointarray[i].set_z(this->pointarray[i].get_z());
    }
    temp.pointarray[temp.num-1].set_x(point.get_x());
    temp.pointarray[temp.num-1].set_y(point.get_y());
    temp.pointarray[temp.num-1].set_z(point.get_z());
    return temp;
}
const Curve3D& Curve3D::operator=(const Curve3D& t)
{

    if ( this != &t)
    {
        if(num>=1)
        {
            if(num==1)
            delete pointarray;
            else
            delete[] pointarray;
        }
        else pointarray=NULL;

        num = t.num;
        if(num>=1)pointarray = new Point3D[num];
        else pointarray=NULL;
        for ( int i = 0 ; i < num ; i++ )
           pointarray[i] = t.pointarray[i] ;
    }
    return *this ;
}
Curve3D::Curve3D(const Curve3D& tr)
{
    num = tr.num;
     if(num>=1)pointarray = new Point3D[num];
     else pointarray=NULL;
    for ( int i = 0 ; i < num ; i++ )
        pointarray[i] = tr.pointarray[i];
}
Curve3D Curve3D::operator-(const Point3D& point) const
{

    for(int i=0;i<this->num;i++)//�ҵ���ͬ�ĵ���±�
    {
        if(point.get_x()==this->pointarray[i].get_x()
           &&point.get_y()==this->pointarray[i].get_y()
           &&point.get_z()==this->pointarray[i].get_z())
        {
             Curve3D temp;
             delete  temp.pointarray;
            temp.num=this->num-1;
            if(temp.num>=1)temp.pointarray=new Point3D[temp.num];
            else temp.pointarray=NULL;
            for(int j=0;j<i;j++)
            {
                temp.pointarray[j].set_x(this->pointarray[j].get_x());
                temp.pointarray[j].set_y(this->pointarray[j].get_y());
                temp.pointarray[j].set_z(this->pointarray[j].get_z());
            }
            for(int j=i;j<temp.num;j++)
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

//void Curve3D::write_txt(ofstream &os)
//{
//    for(int i=0;i<this->num;i++)
//        os<<this->pointarray[i].display_point()<<endl;
//}
//Curve3D Curve3D::read_txt(ifstream &is)
//{
//    Curve3D temp;//temp�ĵ�һ�����ǣ�0��0��0��
//    for(int i=0;i<this->num;i++)
//    {
//        Point3D a;
//        double x,y,z;
//        cin>>x>>y>>z;
//        a.set_x(x);
//        a.set_y(y);
//        a.set_z(z);
//        temp=temp+a;
//    }
//    Point3D a;
//    temp=temp-a;
//    /*temp�ĵ�һ�����ǣ�0,0,0����aҲ�ǣ�0,0,0��������temp��ȥa֮��Ϳ���ȥ����һ����*/
//    return temp;
//}
//void Curve3D::write_binary(ofstream &os)
//{
//    for(int i=0;i<this->num;i++)
//        os<<this->pointarray[i].display_point()<<endl;
//
//
//}
//Curve3D Curve3D::read_binary(ifstream &is)
//{
//
//    Curve3D temp;//temp�ĵ�һ�����ǣ�0��0��0��
//    for(int i=0;i<this->num;i++)
//    {
//        Point3D a;
//        double x,y,z;
//        cin>>x>>','>>y>>','>>z;
//        a.set_x(x);
//        a.set_y(y);
//        a.set_z(z);
//        temp=temp+a;
//    }
//    Point3D a;
//    temp=temp-a;
//    /*temp�ĵ�һ�����ǣ�0,0,0����aҲ�ǣ�0,0,0��������temp��ȥa֮��Ϳ���ȥ����һ����*/
//    return temp;
//}




void show( Curve3D& a) //չʾһ�����ߵ����Ժͷ�����
{
    cout<<"The num is "<<a.num<<endl;
    a.CurveLen();
    a.DisplayCurve();
    cout<<endl;

}
int main()
{
    Point3D point1(5,8,9);
    Point3D point2(4.5,1.9,4.8);
    Point3D point3;//�������ԭ��
    Point3D point4(0,8,6);

    Curve3D a;
    show(a);

    a=a-point3;show(a);
    a=a-point3;show(a);
    a=a+point1;show(a);

    a=a+point2;show(a);

    a=a+point3;show(a);

    a=a-point3;show(a);

    a=a-point4;show(a);




//
//    ifstream is("file.txt");
//    ofstream os("file.txt");
//
//     a.write_txt(os);
//     Curve3D b;
//     b=b.read_txt(is);



//
//    is.close();
//    os.close();









    return 0;
}









