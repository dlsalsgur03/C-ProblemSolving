#include <iostream>

using namespace std;

template <class T>
T* concat(T src1[], int sizea, T src2[], int sizeb) {
	T* dest = new T[sizea + sizeb];
	for (int i = 0; i < sizea; i++) {
		dest[i] = src1[i];
	}
	for (int i = 0; i < sizeb; i++) {
		dest[i + sizea] = src2[i];
	}
	return dest;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x[] = { 1,10,100,5,4 };
	int y[] = { 2,11,101,6,5 };
	int* z = concat(x, 5, y, 5);
	for (int i = 0; i < 10; i++) {
		cout << z[i] << ' ';
	}
	cout << '\n';

	double a[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double b[] = { 6.6, 7.7, 8.8, 9.9 };
	double* c = concat(a, 5, b, 4);
	for (int i = 0; i < 9; i++) {
		cout << c[i] << ' ';
	}
	cout << '\n';
}