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
