using namespace std;

#include <math.h>
#include <iostream>
#include <stdio.h>

double const  PI = 3.1415926;


/*
S表示两点直线距离
T表示方位角
*/
struct tagPnt2D{
	double x;
	double y;
};

void zhengsuan(tagPnt2D p1, double S, double T, tagPnt2D &p2){
	p2.x = p1.x + S*cos(T);
	p2.y = p1.y + S*sin(T);
}

double Cal_Azimuth(double x, double y){

	if (x > 0 && y > 0){
		return atan(y / x);
	}
	if (x < 0 && y > 0){
		return PI + atan(y / x);
	}
	if (x < 0 && y < 0){
		return PI + atan(y / x);
	}
	if (x > 0 && y < 0){
		return 2*PI + atan(y / x);
	}
}

void fansuan(tagPnt2D p1, tagPnt2D p2, double &S, double &T){
	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;
	S = sqrt(dx*dx + dy*dy);
	T = Cal_Azimuth(dx, dy);
}

------------------------------------------------------------------
//定义平面控制点类CPnt2D, 以该类变量为参数编写正算函数、坐标反算函数
	
class Pnt2D{
   public:
	CString name;
	double x,y;
   public:
	Pnt2D(){
	    name="";
	    x=y=0;
	}
	Pnt2D(CString sname,double sx,double sy){
	    name = sname;
	    x = sx;
	    y = sy;
	}
}
void zhengsuan(Pnt2D p1, double S, double T, Pnt2D &p2){
	p2.x = p1.x + S*cos(T);
	p2.y = p1.y + S*sin(T);
}
void fansuan(Pnt2D p1, Pnt2D p2, double &S, double &T){
	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;
	S = sqrt(dx*dx + dy*dy);
	T = Cal_Azimuth(dx, dy);
}

------------------------------------------------------------------
//.创建一个简单的对话框应用程序，用对话框按钮对编写的函数进行测试
void CMy1233Dlg::OnButton1(){
	tagPnt2D p1,p2;
	double S = 100;
	double T = 0.7;
	p1.x = 222;
	p1.y = 333;

        zhengsuan(p1,S,T,p2);
	
	CString str;
	str Format("%lf","%lf",&p1.x,&p1.y);
	AfxMessageBox(str);
}	
	
