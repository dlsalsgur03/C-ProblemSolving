#include <iostream>

using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;
	virtual int size() = 0;
};

class IntStack : public AbstractStack {
	int tos;
	int capacity;
	int* mem;
public:
	IntStack() { tos = 0; capacity = 5; mem = new int[capacity]; }
	virtual bool push(int n) {
		if (tos == capacity) return false;
		mem[tos++] = n;
		return true;
	}
	virtual bool pop(int& n) {
		if (tos == 0) return false;
		n = mem[--tos];
		return true;
	}
	virtual int size() { return tos; }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	IntStack intStack;

	cout.setf(ios::boolalpha);

	for (int i = 0; i < 6; i++) {
		if (intStack.push(i)) cout << " push " << i << ", size " << intStack.size() << '\n';
		else cout << "Stack is full!\n";
	}
	for (int i = 0; i < 6; i++) {
		int n = 0;
		if (intStack.pop(n)) cout << " pop " << n << ", size = " << intStack.size() << '\n';
		else cout << "Stack is empty...\n";
	}
}