#include <iostream>

using namespace std;

class Matrix {
	int a1, a2, a3, a4;
public:
	Matrix(int a1 = 0, int a2 = 0, int a3 = 0, int a4 = 0);
	void show();
	Matrix operator+ (Matrix op2);
	Matrix& operator+= (Matrix op2);
	bool operator== (Matrix op2);
};
Matrix::Matrix(int a1, int a2, int a3, int a4) {
	this->a1 = a1; this->a2 = a2; this->a3 = a3; this->a4 = a4;
}
void Matrix::show() {
	cout << "Matrix = { " << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << " }\n";
}
Matrix Matrix::operator+ (Matrix op2) {
	Matrix tmp;
	tmp.a1 = a1 + op2.a1;
	tmp.a2 = a2 + op2.a2;
	tmp.a3 = a3 + op2.a3;
	tmp.a4 = a4 + op2.a4;
	return tmp;
}
Matrix& Matrix::operator+= (Matrix op2) {
	a1 += op2.a1;
	a2 += op2.a2;
	a3 += op2.a3;
	a4 += op2.a4;
	return *this;
}
bool Matrix::operator== (Matrix op2) {
	if (a1 == op2.a1 && a2 == op2.a2 && a3 == op2.a3 && a4 == op2.a4) return true;
	else return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << '\n';
}