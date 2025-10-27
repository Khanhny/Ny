#include "Point.h"


double Point::GetX()
{
	return x;
}

double Point::GetY()
{
	return y;

}
void Point::SetX(double _x)
{
	this->x = _x;
}
void Point::SetY(double _y)
{
	this->y = _y;
}
float Point::kc();
{
	return sqrt(x * x + y * y);
}
int Point::input()
{
	int n;
	cout << "Vui long nhap so luong diem: " << endl;
	cin >> n;
}
void Point::point(int, int)
{

}
Point::Point()
{

}

