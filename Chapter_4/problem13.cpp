#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string s;
public:
	Histogram(string s);
	void put(string s);
	void putc(char c);
	void print();
};

Histogram::Histogram(string s) {
	this->s = s;
	cout << s << '\n';
}

void Histogram::put(string s) {
	this->s += s;
	cout << s;
}
void Histogram::putc(char c) {
	this->s += c;
	cout << c;
}
void Histogram::print() {
	int cnt = 0;

	int alph[27];
	for (int i = 0; i < 27; i++) 
		alph[i] = 0;
	
	for (int i = 0; i < this->s.length(); i++) {
		if (isalpha(this->s[i]) == 1) {
			this->s[i] = tolower(this->s[i]);
			alph[this->s[i] - 'a'] += 1;
			cnt++;
		}
		else if (isalpha(this->s[i]) == 2) {
			alph[this->s[i] - 'a'] += 1;
			cnt++;
		}
	}

	cout << "\n\n총 알파벳 수 " << cnt << "\n\n";

	for (int i = 0; i < 27; i++) {
		cout << (char)('a' + i) << " (" << alph[i] << ")\t: ";
		for (int j = 0; j < alph[i]; j++)
			cout << "*";
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}
