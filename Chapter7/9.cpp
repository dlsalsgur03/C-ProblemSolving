#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " 인 원" << '\n'; }
	friend Circle operator+ (int n, Circle op);
};

Circle operator+ (int n, Circle op) {
	Circle tmp;
	tmp = n + op.radius;
	return tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Circle a(5), b(4);
	b = 1 + a;
	a.show();
	b.show();
}
