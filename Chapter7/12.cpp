#include <iostream>

using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

class SortedArray {
	int size;
	int* p;
	void sort();
public:
	SortedArray();
	SortedArray(SortedArray& src);
	SortedArray(int p[], int size);
	~SortedArray();
	SortedArray operator+ (SortedArray& op2);
	SortedArray& operator= (const SortedArray& op2);
	void show();
};

void SortedArray::sort() {
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0; j--) {
			if (p[j] < p[j - 1])
				swap(p[j], p[j - 1]);
		}
	}
}

SortedArray::SortedArray() {
	p = nullptr;
	size = 0;
}
SortedArray::SortedArray(SortedArray& src) {
	size = src.size;
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = src.p[i];
}
SortedArray::SortedArray(int p[], int size) {
	this->size = size;
	this->p = new int[size];
	for (int i = 0; i < size; i++) {
		this->p[i] = p[i];
	}
}
SortedArray::~SortedArray() {
	if (p)
		delete[]p;
}
SortedArray SortedArray::operator+ (SortedArray& op2) {
	SortedArray tmp;
	tmp.size = this->size + op2.size;
	tmp.p = new int[tmp.size];
	for (int i = 0; i < this->size; i++)
		tmp.p[i] = this->p[i];
	for (int i = 0; i < op2.size; i++)
		tmp.p[i + this->size] = op2.p[i];
	return tmp;
}
SortedArray& SortedArray::operator= (const SortedArray& op2) {
	size = op2.size;
	p = new int[size];
	for (int i = 0; i < size; i++)
		p[i] = op2.p[i];
	return *this;
}
void SortedArray::show() {
	sort();
	cout << "배열 출력 : ";
	for (int i = 0; i < size; i++) {
		cout << p[i] << ' ';
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;

	a.show();
	b.show();
	c.show();
}