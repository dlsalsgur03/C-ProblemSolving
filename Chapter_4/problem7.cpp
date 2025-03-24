#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

Circle::Circle() {
	radius = 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int cnt = 0;
	Circle c[3];
	int n;
	for (int i = 0; i < 3; i++) {
		cout << "원 " << i+1 << "의 반지름 >> ";
		cin >> n;
		c[i].setRadius(n);

		if (c[i].getArea() > 100) cnt += 1;
	}

	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다\n";
}
