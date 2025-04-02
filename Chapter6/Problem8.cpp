#include <iostream>
#include <string>

using namespace std;

class Trace {
	static string* stck;
	static int ind;
public:
	static void put(string tag, string debugInfo);
	static void print(string tag = "");
};

string* Trace::stck = new string[100];
int Trace::ind = 0;

void Trace::put(string tag, string debugInfo) {
	stck[ind++] = tag + ':' + debugInfo;
}
void Trace::print(string tag) {
	if (tag == "") {
		cout << "----- ��� Trace ������ ����մϴ�. -----\n";
		for (int i = 0; i < ind; i++) {
			cout << stck[i] << '\n';
		}
	}
	else {
		cout << "----- " << tag << "�±��� Trace ������ ����մϴ�. -----\n";
		for (int i = 0; i < ind; i++) {
			int fInd = stck[i].find(':');
			if (stck[i].substr(0, fInd) == tag) {
				cout << stck[i] << '\n';
			}
		}
	}
}

void f() {
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ���>> ";
	cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���");
	c = a + b;
	Trace::put("f()", "�� ���");
	cout << "���� " << c << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Trace::put("main()", "���α׷� �����մϴ�");
	f();
	Trace::put("main()", "����");

	Trace::print("f()");
	Trace::print();
}