#include <iostream>
#include <set>
using namespace std;

int R, C;
string str[1001];

void Insert_And_Init() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) cin >> str[i];
}

void Calculate() {
	// 첫번째 줄 부터 마지막 줄 까지?
	int start = 0;
	int end = R - 1;
	int mid = 0;

	bool isFind = false;

	while (start <= end) {
		isFind = false;
		mid = (start + end) / 2;
		set<string> s;
		//첫번째 항목부터 마지막 항목까지
		for (int j = 0; j < C; j++) {
			//현재 문자열
			string cur = "";
			for (int k = mid; k < R; k++) cur += str[k][j];
			s.insert(cur);
		}
		if (s.size() != C) {
			end = mid - 1;
			isFind = true;
		}
		else start = mid + 1;
	}
	if (isFind) cout << mid - 1;
	else cout << mid;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}