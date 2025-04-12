#include <iostream>

using namespace std;

class Stack {
	int* arr;
	int size;
	int ind;
public:
	Stack();
	~Stack();
	void resize();
	void push(int n);
	bool operator! ();
	Stack& operator<< (int n);
	Stack& operator>> (int& n);
};
Stack::Stack() {
	size = 0;
	ind = 0;
	arr = new int[size];
}
Stack::~Stack() {
	if (!arr)
		delete[]arr;
}
void Stack::resize() {
	size += 1;
	int* nArr = new int[size];
	for (int i = 0; i < size; i++)
		nArr[i] = arr[i];
	delete[]arr;
	arr = nArr;
}
void Stack::push(int n) {
	if (ind == size) resize();
	arr[ind++] = n;
}

bool Stack::operator! () {
	if (ind < 0) return true;
	else return false;
}

Stack& Stack::operator<< (int n) {
	push(n);
	return *this;
}
Stack& Stack::operator>> (int& n) {
	if (ind == size) ind--;
	n = arr[ind--];
	return *this;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << '\n';
}