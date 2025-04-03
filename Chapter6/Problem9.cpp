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
	cout << "************** 게시판입니다. **************\n";
	for (int i = 0; i < ind; i++) {
		cout << i << ": " << texts[i] << '\n';
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요.");
	Board::print();
}
