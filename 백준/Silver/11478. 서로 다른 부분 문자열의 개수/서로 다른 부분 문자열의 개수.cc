#include <iostream>
#include <set>

using namespace std;

string S;
set<string> result_set;

void Insert_And_Init() {
	cin >> S;
}

void Calculate() {
	int len = S.length();

	// 시작 지점
	for (int i = 0; i < len; i++){
		//몇번 째 까지 볼건지
		for (int j = 1; j + i <= len; j++) {
			result_set.insert(S.substr(i, j));
		}
	}

	cout << result_set.size();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}