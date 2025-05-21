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
	cout << "���� �����ϰ� �����ϴ� ���α׷��Դϴ�.\n";
	while (true) {
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		int n;
		cin >> n;
		if (n == 1) {
			cout << "�����ϰ��� �ϴ� ���� �������� �̸��� >> ";
			int radius;
			string name;
			cin >> radius >> name;
			cm.push_back(new Circle(radius, name));
		}
		else if (n == 2) {
			cout << "�����ϰ��� �ϴ� ���� �̸��� >> ";
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