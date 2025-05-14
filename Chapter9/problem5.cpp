#include <iostream>
#include <string>

using namespace std;

class AbstractGate {
protected:
	bool x, y;
public:
	void set(bool x, bool y) { this->x = x; this->y = y; }
	virtual bool operation() = 0;
};

class ANDGate : public AbstractGate {
public:
	virtual bool operation();
};
bool ANDGate::operation() {
	if (x == true && y == true) return true;
	else return false;
}

class ORGate : public AbstractGate {
public:
	virtual bool operation();
};
bool ORGate::operation() {
	if (x == false && y == false) return false;
	else return true;
}

class XORGate : public AbstractGate {
public:
	virtual bool operation();
};
bool XORGate::operation() {
	if (x == y) return false;
	else return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ANDGate andgate;
	ORGate orgate;
	XORGate xorgate;

	andgate.set(true, false);
	orgate.set(true, false);
	xorgate.set(true, false);
	cout.setf(ios::boolalpha);
	cout << andgate.operation() << endl;
	cout << orgate.operation() << endl;
	cout << xorgate.operation() << endl;
}