#include <iostream>
#include <string>
using namespace std;

int T;
string str;

void Insert_And_Init() {
	cin >> T;
}

void Caluclate() {
	bool flag = false;
	for (int i = 0; i < T; i++){
		flag = false;
		cin >> str;

		//ll사이에 알파벳 있는 경우
		for (int j = 0; j < str.length(); j++) {
			if ((j < str.length() - 2) && str[j] == 'l' && str[j + 2] == 'l' && str[j+1]!='o') {
				cout << "1\n";
				flag = true;
				break;
			}
		}
		if (flag) continue;

		//애초에 lol이 있는경우
		if (str.find("lol") <= str.length()) cout << "0\n";
		//lo만 있는 경우
		else if (str.find("lo") <= str.length()) cout << "1\n";
		//ol만 있는 경우
		else if (str.find("ol") <= str.length()) cout << "1\n";
		//ll만 있는 경우
		else if (str.find("ll") <= str.length()) cout << "1\n";
		//l만 있는 경우
		else if (str.find("l") <= str.length()) cout << "2\n";
		//o만 있는 경우
		else if (str.find("o") <= str.length()) cout << "2\n";
		//암것도 없는 경우
		else cout << "3\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}