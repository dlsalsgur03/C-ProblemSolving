#include <iostream>
#include <string>

using namespace std;

istream& prompt(istream& ins) {
	cout << "암호?";
	return ins;
}

istream& pos(istream& ins) {
	cout << "위치는? ";
	return ins;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string password;
	while (true) {
		cin >> prompt >> password;
		if (password == "C++") {
			cout << "login success!!" << endl;
			break;
		}
		else
			cout << "login fail. try again!!" << endl;
	}

	int x, y;
	cin >> pos >> x;
	cin >> pos >> y;
	cout << x << ',' << y << endl;
}