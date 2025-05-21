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
	cout << "그래픽 에디터입니다." << '\n';
	while (true) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		int n;
		cin >> n;
		if (n == 1) {
			cout << "선:1, 원:2, 사각형:3 >> ";
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
			cout << "삭제하고자 하는 도형의 인덱스 >> ";
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