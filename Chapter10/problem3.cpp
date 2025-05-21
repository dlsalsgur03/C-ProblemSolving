#include <iostream>

using namespace std;

template <class T>
void reverseArray(T arr[], int size) {
	T* temp = new T[size];
	for (int i = 1; i <= size; i++) {
		temp[i - 1] = arr[size - i];
	}
	for (int i = 0; i < size; i++) {
		arr[i] = temp[i];
	}
	delete[]temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x[] = { 1,10,100,5,4 };
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++) cout << x[i] << ' ';
}