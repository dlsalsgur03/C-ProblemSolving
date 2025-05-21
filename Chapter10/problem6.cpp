#include <iostream>

using namespace std;

template <class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	T* temp = new T[sizeSrc];
	retSize = 0;
	for (int i = 0; i < sizeSrc; i++) {
		int flag = 0;
		for (int j = 0; j < sizeMinus; j++) {
			if (src[i] == minus[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			temp[retSize++] = src[i];
	}
	T* rtnArr = new T[retSize];
	for (int i = 0; i < retSize; i++) {
		rtnArr[i] = temp[i];
	}
	delete[]temp;
	return rtnArr;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x[] = { 1,2,3,4,5 };
	int y[] = { 3,4,5,6,7 };
	int retSize = 0;
	int* z = remove(x, 5, y, 5, retSize);
	for (int i = 0; i < retSize; i++) {
		cout << z[i] << ' ';
	}
	cout << '\n';

	double a[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double b[] = { 2.2, 4.4, 7.7, 6.6 };
	double* c = remove(a, 5, b, 4, retSize);
	for (int i = 0; i < retSize; i++) {
		cout << c[i] << ' ';
	}
	cout << '\n';
}