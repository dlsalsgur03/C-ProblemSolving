#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n;
		cin >> n;
		int* nArr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> nArr[i];
		}
		int n1, n2;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			n1 = nArr[i];
			int min, max;
			for (int j = i+1; j < n; j++) {
				n2 = nArr[j];
				if (n1 > n2) {
					min = n2;
					max = n1;
				}
				else {
					min = n1;
					max = n2;
				}
				for (int i = min; i > 0; i--) {
					if (min % i == 0 && max % i == 0) {
						sum += i;
						break;
					}
				}
			}
		}
		cout << sum << "\n";
	}
}
