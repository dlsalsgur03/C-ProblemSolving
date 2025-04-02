#include <iostream>

using namespace std;

class MyVector {
	int* mem;
	int size;
public:
	MyVector(int n = 100, int val = 0);
	~MyVector() { delete[]mem; }
	int getSize() { return size; }
	void show();
};

MyVector::MyVector(int n, int val) {
	mem = new int[n];
	size = n;
	for (int i = 0; i < size; i++) mem[i] = val;
}

void MyVector::show() {
	for (int i = 0; i < size; i++) {
		cout << mem[i] << "(" << i + 1 << ")" << '\n';
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	MyVector* v1, * v2;
	v1 = new MyVector();
	v2 = new MyVector(150, 1);

	v1->show();
	v2->show();

	cout << v1->getSize() << '\n' << v2->getSize() << '\n';
}