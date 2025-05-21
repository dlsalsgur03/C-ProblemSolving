#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint();
};
void Shape::paint() {
	draw();
}

class Line : public Shape {
protected:
	void draw();
};
void Line::draw() {
	cout << "Line" << '\n';
}

class Circle : public Shape {
protected:
	void draw();
};
void Circle::draw() {
	cout << "Circle" << '\n';
}

class Rect : public Shape {
protected:
	void draw();
};
void Rect::draw() {
	cout << "Rectangle" << '\n';
}

class GraphicEditor {
	vector<Shape*> v;
public:
	void run();
};
void GraphicEditor::run() {
	cout << "�׷��� �������Դϴ�." << '\n';
	while (true) {
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
		int n;
		cin >> n;
		if (n == 1) {
			cout << "��:1, ��:2, �簢��:3 >> ";
			int s;
			cin >> s;
			if (s == 1)
				v.push_back(new Line);
			else if (s == 2)
				v.push_back(new Circle);
			else if (s == 3)
				v.push_back(new Rect);
		}
		else if (n == 2) {
			cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
			int d;
			cin >> d;
			vector<Shape*>::iterator it = v.begin();
			int j = 0;
			for (int i = 0; i < v.size(); i++) {
				if (i == d) {
					it = v.erase(it);
					break;
				}
				else it++;
			}
		}
		else if (n == 3) {
			for (int i = 0; i < v.size(); i++) {
				cout << i << ": ";
				v[i]->paint();
			}
		}
		else if (n == 4) break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	GraphicEditor GE;
	GE.run();
}