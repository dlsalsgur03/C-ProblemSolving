#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	int getRadius() { return radius; }
};

void swap(Circle& c1, Circle& c2) {
	Circle tmp;
	tmp = c1;
	c1 = c2;
	c2 = tmp;
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
