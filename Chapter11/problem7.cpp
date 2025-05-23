#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 4; i++) {
		cout << left << setw(7) << "dec" << setw(7) << "hexa" << setw(7) << "char";
	}
	cout << '\n';
	for (int i = 0; i < 4; i++) {
		cout << left << setw(7) << "___" << setw(7) << "____" << setw(7) << "____";
	}
	cout << '\n';
	for (int i = 0; i <= 127; i++) {
		cout << left << setw(7) << dec << i << setw(7) << hex << i;
		if (isprint(i)) cout << left << setw(7) << (char)i;
		else cout << left << setw(7) << '.';

		if ((i + 1) % 4 == 0) cout << '\n';
	}
}