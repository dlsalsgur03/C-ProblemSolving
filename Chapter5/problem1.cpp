#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	int getRadius() { return radius; }
	double getArea() { return 3.14 * radius * radius; }
	void setRadius(int radius) { this->radius = radius; }
};

void swap(Circle& c1, Circle& c2) {
	Circle tmp;
	tmp.setRadius(c1.getRadius());
	c1.setRadius(c2.getRadius());
	c2.setRadius(tmp.getRadius());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	Circle donut(10);
	Circle pizza(30);
	cout << donut.getRadius() << '\t' << pizza.getRadius() << '\n';

	swap(donut, pizza);

	cout << donut.getRadius() << '\t' << pizza.getRadius();
}
