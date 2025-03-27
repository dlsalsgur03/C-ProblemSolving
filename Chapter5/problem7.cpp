#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class MyIntStack {
	int p[10];
	int tos;
public:
	MyIntStack();
	bool push(int n);
	bool pop(int& n);
};
MyIntStack::MyIntStack() {
	for (int i = 0; i < 10; i++) p[i] = 0;
	tos = 0;
}
bool MyIntStack::push(int n) {
	if (tos >= 10) return false;
	p[tos] = n;
	tos++;
	return true;
}
bool MyIntStack::pop(int& n) {
	if (tos <= 0) return false;
	n = p[--tos];
	return true;	
}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
}