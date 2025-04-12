#include <iostream>

using namespace std;

class Matrix {
	int a1, a2, a3, a4;
public:
	Matrix(int a1 = 0, int a2 = 0, int a3 = 0, int a4 = 0);
	void show();
	void operator>> (int arr[]);
	Matrix& operator<< (int arr[]);
};

Matrix::Matrix(int a1, int a2, int a3, int a4) {
	this->a1 = a1; this->a2 = a2; this->a3 = a3; this->a4 = a4;
}
void Matrix::show() {
	cout << "Matrix = { " << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << " }\n";
}
void Matrix::operator>> (int arr[]) {
	arr[0] = a1;
	arr[1] = a2;
	arr[2] = a3;
	arr[3] = a4;
}
Matrix& Matrix::operator<< (int arr[]) {
	a1 = arr[0];
	a2 = arr[1];
	a3 = arr[2];
	a4 = arr[3];
	return *this;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << '\n';
	b.show();
}