#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct compare {
	bool operator()(string a, string b) {
		if (a.length() != b.length()) return a.length() > b.length();
		return a > b;
	}
};

int N;
string str[101];
priority_queue<string, vector<string>, compare> pq;

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> str[i];
}

void Caluclate() {
	//문자열 한개씩 돌면서
	for (int i = 0; i < N; i++){
		int str_len = str[i].length();

		//숫자
		string num = "";

		for (int j = 0; j < str_len; j++){
			//영어 인 경우
			if (str[i][j] >= 'a' && str[i][j] <= 'z') {
				
				if (num != "") {
					while (num.length() >= 2 && num[0] == '0') {
						num.erase(0, 1);
					}
					pq.push(num);
				}
				num = "";
			}
			//숫자 인 경우
			else {
				num += str[i][j];
			}
		}
		//숫자 남아있으면 넣기
		if (num != "") {
			while (num.length() >= 2 && num[0] == '0') {
				num.erase(0, 1);
			}
			pq.push(num);
		}
	}

	while (!pq.empty()) {
		cout << pq.top() << "\n";
		pq.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}