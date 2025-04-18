#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Morse {
	string alphabet[26];
	string digit[10];
	string slash, question, comma, period, plus, equal;
public:
	Morse();
	void text2Morse(string text, string& morse);
	bool morse2Text(string morse, string& text);
};

Morse::Morse() {
	alphabet[0] = ".-"; alphabet[1] = "-..."; alphabet[2] = "-.-.";
	alphabet[3] = "-.."; alphabet[4] = "."; alphabet[5] = "..-.";
	alphabet[6] = "--."; alphabet[7] = "...."; alphabet[8] = "..";
	alphabet[9] = ".---"; alphabet[10] = "-.-"; alphabet[11] = ".-..";
	alphabet[12] = "--"; alphabet[13] = "-."; alphabet[14] = "---";
	alphabet[15] = ".--."; alphabet[16] = "--.-"; alphabet[17] = ".-.";
	alphabet[18] = "..."; alphabet[19] = "-"; alphabet[20] = "..-";
	alphabet[21] = "...-"; alphabet[22] = ".--"; alphabet[23] = "-..-";
	alphabet[24] = "-.--"; alphabet[25] = "--..";

	digit[0] = "-----"; digit[1] = ".----"; digit[2] = "..---"; digit[3] = "...--"; digit[4] = "....-";
	digit[5] = "....."; digit[6] = "-...."; digit[7] = "--..."; digit[8] = "---.."; digit[9] = "---.";

	slash = "-..-."; question = "..--.."; comma = "--..--";
	period = ".-.-.-"; plus = ".-.-."; equal = "-...-";
}

void Morse::text2Morse(string text, string& morse) {
	for (int i = 0; i < text.length(); i++) {
		if (isalpha(text[i]) == 2)
			morse.append(alphabet[(int)(text[i] - 'a')]);
		else if (isdigit(text[i]) != 0) {
			morse.append(digit[(int)(text[i] - '0')]);
		}
		else {
			if (text[i] == ' ') morse.append("   ");
			else if (text[i] == '/') morse.append(slash);
			else if (text[i] == '?') morse.append(question);
			else if (text[i] == ',') morse.append(comma);
			else if (text[i] == '.') morse.append(period);
			else if (text[i] == '+') morse.append(plus);
			else if (text[i] == '=') morse.append(equal);
		}
		morse.append(" ");
	}
}

bool Morse::morse2Text(string morse, string& text) {
	string tmp;
	int sInd = 0, fInd = 0;
	int space = 0;
	while (sInd != morse.length()) {
		fInd = morse.find(" ", sInd);
		tmp = morse.substr(sInd, fInd - sInd);
		int flag = 0;
		for (int ii = 0; ii < 26; ii++) {
			if (tmp == alphabet[ii]) {
				text.push_back('a' + ii);
				flag++;
				space = 0;
				break;
			}
		}
		if (flag == 0) {
			for (int ii = 0; ii < 10; ii++) {
				if (tmp == digit[ii]) {
					text.append(to_string(ii));
					flag++;
					space = 0;
					break;
				}
			}
		}
		if (flag == 0) {
			if (tmp == slash) {
				text.append("/"); space = 0;
			}
			else if (tmp == question) {
				text.append("?"); space = 0;
			}
			else if (tmp == comma) {
				text.append(","); space = 0;
			}
			else if (tmp == period) {
				text.append("."); space = 0;
			}
			else if (tmp == plus) {
				text.append("+"); space = 0;
			}
			else if (tmp == equal) {
				text.append("="); space = 0;
			}
			if (space == 0) {
				text.append(" ");
				space = 1;
			}
		}
		sInd = fInd + 1;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Morse m;
	cout << "아래의 영문 텍스트를 입력하세요. 모스 부호로 바꿉니다.\n";
	string txt;
	getline(cin, txt);
	string mrs;
	m.text2Morse(txt, mrs);
	cout << mrs;
	cout << "\n\n모스 부호를 다시 영문 텍스트로 바꿉니다.\n";
	string rtxt;
	m.morse2Text(mrs, rtxt);
	cout << rtxt << '\n';
}