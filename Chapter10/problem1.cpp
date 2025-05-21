#include <iostream>

using namespace std;

template <class T>
T biggest(T arr[], int size) {
	T max;
	for (int i = 0; i < size; i++) {
		if (i == 0) max = arr[i];
		else {
			if (arr[i] > max)
				max = arr[i];
		}
	}
	return max;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x[] = { 1,2,10,8,5 };
	cout << biggest(x, 5) << '\n';
}