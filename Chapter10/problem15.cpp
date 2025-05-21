#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius, string name) {
		this->radius = radius; this->name = name;
	}
	void setCircle(int radius, string name) {
		this->radius = radius;
		this->name = name;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

class CircleManager {
	vector<Circle*> cm;
public:
	void run();
};
void CircleManager::run() {
	cout << "원을 삽입하고 삭제하는 프로그램입니다.\n";
	while (true) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		int n;
		cin >> n;
		if (n == 1) {
			cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
			int radius;
			string name;
			cin >> radius >> name;
			cm.push_back(new Circle(radius, name));
		}
		else if (n == 2) {
			cout << "삭제하고자 하는 원의 이름은 >> ";
			string name;
			cin >> name;
			vector<Circle*>::iterator it = cm.begin();
			int j = 0;
			for (int i = 0; i <= cm.size(); i++) {
				if (cm[j]->getName() == name) {
					it = cm.erase(it);
				}
				else { it++; j++; }
			}
		}
		else if (n == 3) {
			for (int i = 0; i < cm.size(); i++) {
				cout << cm[i]->getName() << '\n';
			}
			cout << '\n';
		}
		else if (n == 4) break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	CircleManager cm;
	cm.run();
}