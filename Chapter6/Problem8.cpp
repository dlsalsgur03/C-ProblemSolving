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
		cout << "----- 모든 Trace 정보를 출력합니다. -----\n";
		for (int i = 0; i < ind; i++) {
			cout << stck[i] << '\n';
		}
	}
	else {
		cout << "----- " << tag << "태그의 Trace 정보를 출력합니다. -----\n";
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
	cout << "두 개의 정수를 입력하세요>> ";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Trace::put("main()", "프로그램 시작합니다");
	f();
	Trace::put("main()", "종료");

	Trace::print("f()");
	Trace::print();
}