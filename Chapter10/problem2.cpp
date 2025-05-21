#include <iostream>

using namespace std;

template <class T>
bool equalArray(T arr1[], T arr2[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x[] = { 1,10,100,5,4 };
	int y[] = { 1,10,100,5,4 };
	if (equalArray(x, y, 5)) cout << "Same Array!\n";
	else cout << "Not Same Array\n";
}