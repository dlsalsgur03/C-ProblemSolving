#include <iostream>
#include <string>

using namespace std;

class UI {
public:
	static int menu();
	static int select();
	static int deleting();
};

int UI::menu() {
	int num;
	cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
	cin >> num;
	return num;
}
int UI::select() {
	int num;
	cout << "��:1, ��:2, �簢��:3 >> ";
	cin >> num;
	return num;
}
int UI::deleting() {
	int num;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
	cin >> num;
	return num;
}

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() { }
	void paint() { draw(); }
	Shape* add(Shape* p) {
		this->next = p;
		return p;
	}
	Shape* getNext() { return next; }
};
class Line : public Shape {
public:
	virtual void draw() {
		cout << "Line\n";
	}
};
class Circle : public Shape {
public:
	virtual void draw() {
		cout << "Circle\n";
	}
};
class Rect : public Shape {
public:
	virtual void draw() {
		cout << "Rectangle\n";
	}
};

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
	int size;
public:
	GraphicEditor() {
		pStart = NULL;
		pLast = pStart;
		size = 0;
	}
	void run();
};

void GraphicEditor::run() {
	cout << "�׷��� �������Դϴ�.\n";
	int m;
	while ((m = UI::menu()) != 4) {
		if (m == 1) {
			int n = UI::select();
			if (n == 1) {
				if (size == 0) {
					pStart = new Line;
					pLast = pStart;
					size += 1;
				}
				else pLast = pLast->add(new Line);
			}
			else if (n == 2) {
				if (size == 0) {
					pStart = new Circle;
					pLast = pStart;
					size += 1;
				}
				else pLast = pLast->add(new Circle);
			}
			else if (n == 3) {
				if (size == 0) {
					pStart = new Rect;
					pLast = pStart;
					size += 1;
				}
				else pLast = pLast->add(new Rect);
			}
		}
		else if (m == 2) {
			int n = UI::deleting();

			Shape* p = pStart;
			if (p == NULL) cout << "������ ������ �����ϴ�.\n";
			else if (n == 0) {
				Shape* q = p->getNext();
				delete p;
				p = q;
			}
			else {
				Shape* q = p;
				Shape* r = p;
				for (int i = 0; i <= n; i++) {
					q = q->getNext();
				}
				while (p->getNext() != q) {
					p = p->getNext();
				}
				while (r->getNext() != p) {
					r = r->getNext();
				}
				delete p;
				r->add(q);
			}
		}
		else if (m == 3) {
			Shape* p = pStart;
			int i = 0;
			while (p != NULL) {
				cout << i << ": ";
				p->paint();
				p = p->getNext();
				i += 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	GraphicEditor* g = new GraphicEditor();
	g->run();
}