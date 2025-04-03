#include <iostream>
#include <string>

using namespace std;

class Board {
	static string* texts;
	static int ind;
public:
	static void add(string text);
	static void print();
};

string* Board::texts = new string[100];
int Board::ind = 0;

void Board::add(string text) {
	texts[ind++] = text;
}
void Board::print() {
	cout << "************** �Խ����Դϴ�. **************\n";
	for (int i = 0; i < ind; i++) {
		cout << i << ": " << texts[i] << '\n';
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���.");
	Board::print();
}
