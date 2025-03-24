#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc;
	cout << "원의 개수 >> ";
	cin >> tc;

	int cnt = 0;
	Circle* c = new Circle[tc];
	int n;
	for (int i = 0; i < tc; i++) {
		cout << "원 " << i+1 << "의 반지름 >> ";
		cin >> n;
		c[i].setRadius(n);

		if (c[i].getArea() > 100) cnt += 1;
	}

	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다\n";
}
