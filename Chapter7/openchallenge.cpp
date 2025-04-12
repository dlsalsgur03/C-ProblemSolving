#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string song;
public:
	Histogram(string song);
	Histogram& operator<< (string s);
	Histogram& operator<< (char c);
	bool operator! ();
};

Histogram::Histogram(string song) {
	this->song = song;
}

Histogram& Histogram::operator<<(string s) {
	song += s;
	return *this;
}
Histogram& Histogram::operator<<(char c) {
	song += c;
	return *this;
}
bool Histogram::operator! () {
	if (song == "") return false;
	else {
		cout << song << '\n' << '\n';

		int cnt = 0;
		int arr[26];
		for (int i = 0; i < 26; i++) {
			arr[i] = 0;
		}

		for (int i = 0; i < song.length(); i++) {
			if (isalpha(song[i]) == 1) {
				song[i] = tolower(song[i]);
				arr[song[i] - 'a']++;
				cnt++;
			}
			else if (isalpha(song[i]) == 2) {
				arr[song[i] - 'a']++;
				cnt++;
			}
			else continue;
		}

		cout << "총 알파벳 수 " << cnt << '\n';
		for (int i = 0; i < 26; i++) {
			cout << (char)('a' + i) << ':';
			for (int j = 0; j < arr[i]; j++) 
				cout << '*';
			cout << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
	song << "falling" << " in love with you." << "by ";
	song << 'k' << 'i' << 't';
	!song;
}
