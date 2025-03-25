#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n1, n2;
	cin >> n1 >> n2;
	int min, max;
	if (n1 < n2) {
		min = n1;
		max = n2;
	}
	else {
		min = n2;
		max = n1;
	}
	int gcd;
	for (int i = min; i > 0; i--) {
		if (min % i == 0 && max % i == 0) {
			gcd = i;
			break;
		}
	}
	int lcm;
	for (int i = 1; true; i++) {
		if ((max * i) % min == 0) {
			lcm = max * i;
			break;
		}
	}
	cout << gcd << "\n" << lcm;
}
