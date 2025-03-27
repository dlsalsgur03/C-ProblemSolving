#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }
	Buffer(const Buffer& temp) { this->text = temp.text; }
	void add(string next) { this->text += next; }
	void print() { cout << text << endl; }
};

Buffer& append(Buffer& buf, const string next) {
	buf.add(next);
	return buf;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");
	temp.print();
	buf.print();
}