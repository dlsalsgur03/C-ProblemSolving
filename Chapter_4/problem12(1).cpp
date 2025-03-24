#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius) {
		this->name = name;
		this->radius = radius;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

class CircleManager {
	Circle* p;
	int size;
public:
	CircleManager(int size);
	~CircleManager();
	Circle* getCircle() { return p; }
	void searchByName();
	void searchByArea();
};
CircleManager::CircleManager(int size) {
	p = new Circle[size];
	this->size = size;
}
CircleManager::~CircleManager() {
	delete[]p;
}

void CircleManager::searchByName() {
	cout << "검색하고자 하는 원의 이름 >> ";
	string name;
	cin >> name;
	int flag = 0;
	for (int i = 0; i < size; i++) {
		if (p[i].getName() == name) {
			cout << name << "의 면적은 " << p[i].getArea() << "\n";
			flag = 1;
		}
	}
	if (flag == 0) cout << "찾으시는 원이 없습니다.\n";
}

void CircleManager::searchByArea() {
	cout << "최소 면적을 정수로 입력하세요 >> ";
	int area;
	cin >> area;
	cout << area << "보다 큰 원을 검색합니다.\n";
	int flag = 0;
	for (int i = 0; i < size; i++) {
		if (p[i].getArea() >= area) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
			flag = 1;
		}
	}
	cout << "\n";
	if (flag == 0) cout << "찾으시는 원이 없습니다.\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "원의 개수 >> ";
	int size;
	cin >> size;

	CircleManager c(size);

	string name; int r;
	for (int i = 0; i < size; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> name >> r;
		c.getCircle()[i].setCircle(name, r);
	}
	c.searchByName();
	c.searchByArea();
}
