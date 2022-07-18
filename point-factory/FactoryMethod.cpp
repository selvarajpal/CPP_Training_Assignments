#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

enum class PointType
{
	cartesian,
	polar
};


class Point
{
	float xc, yc;
	Point(float a, float b, PointType type = PointType::cartesian)
	{
		if (type == PointType::cartesian) {
			xc = a; 
			yc = b;
		}
		else {
			xc = a*cos(b);
			yc = a*sin(b);
		}
	}

	public:

	static Point NewPolar(const float x, const float theta);
	static Point NewCartesian(const float x, const float y);
	friend ostream& operator<<(ostream& os, const Point& p1);
};

Point Point::NewCartesian(float x, float y)
{
	Point p1(x,y, PointType::cartesian); 
	return p1;
}

Point Point::NewPolar(float x, float theata)
{
	Point p1(x, theata, PointType::polar); 
	return p1;
}

ostream& operator<<(ostream& os, const Point& p1)
{
	os << "x:  "<< p1.xc << " y:  " << p1.yc << std::endl;
	return os;
}

int main()
{

	Point p1 = Point::NewPolar(5, M_PI_4);

	Point p2 = Point::NewCartesian(12,56);

	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	return 0;
}
