#include <iostream>
#include <map>
using namespace std;

string str;

void Insert_And_Init() {
	cin >> str;
}

bool IsSurprising() {
	int len = str.length();
	for (int i = 1; i <= len - 1; i++) {
		map<string, int> m;
		for (int j = 0; j < len; j++){
			int a = j;
			int b = j + i;
			if (b >= len) break;
			string cur = "";
			cur += str[a];
			cur += str[b];
			if (m[cur] == 1) return false;
			m[cur] = 1;
		}
	}
	return true;
}

void Caluclate() {
	while (str != "*") {
		//검사
		bool flag = IsSurprising();

		//출력
		if (flag) cout << str << " is surprising.\n";
		else cout << str << " is NOT surprising.\n";

		//입력
		cin >> str;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}