#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

char& find(char a[], char c, bool& success) {
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (!b) {
		cout << "M�� �߰��� �� ����." << '\n';
		return 0;
	}
	loc = 'm';
	cout << s << '\n';

	return 0;
}