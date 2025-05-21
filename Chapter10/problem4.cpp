#include <iostream>

using namespace std;

template <class T>
bool search(T src, T arr[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == src)
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x[] = { 1,10,100,5,4 };
	if (search(100, x, 5)) cout << "100 is included in array\n";
	else cout << "100 isn't included in array\n";
}