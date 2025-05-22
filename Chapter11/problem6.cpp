#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << left << setw(15) << "Number" << setw(15) << "Square" << setw(15) << "Square Root" << endl;
	cout.fill('_');
	for (int i = 0; i <= 9; i++) {
		cout << left << setw(15) << 5 * i << setw(15) << (long)pow(5 * i, 2) << setw(15) << setprecision(3) << sqrt(5 * i) << endl;
	}
}