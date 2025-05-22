#include <iostream>

using namespace std;

void problem3() {
	char ch;
	cin.ignore(100, ';');
	while ((ch = cin.get()) != EOF) {
		cout.put(ch);
		if (ch == '\n')
			cin.ignore(100, ';');
	}
}
void problem4() {
	char ch;
	while ((ch = cin.get()) != EOF) {
		if (ch == ';') {
			cout.put('\n');
			cin.ignore(100, '\n');
		}
		else
			cout.put(ch);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	problem4();
}