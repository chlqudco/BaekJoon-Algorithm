#include <iostream>
#include <queue>
using namespace std;

//전화번호 저장용 우선순위 큐
priority_queue<string, vector<string>, greater<string>> pq;
int t, n;

void Insert_And_Init() {
	cin >> t;
}

string Check() {
	while (!pq.empty()) {
		string cur = pq.top(); pq.pop();
		//한개 남은거면 일관성 있는 경우임
		if (pq.empty()) return "YES\n";

		string nextNum = pq.top();
		if (cur.length() >= nextNum.length()) continue;

		if (nextNum.substr(0, cur.length()) == cur) return "NO\n";
	}
	return "YES\n";
}

void Caluclate() {
	string tmp;
	for (int i = 0; i < t; i++){
		//전화 번호 입력
		cin >> n;
		for (int j = 0; j < n; j++){
			cin >> tmp;
			pq.push(tmp);
		}

		//일관성 확인
		cout << Check();

		//초기화
		while (!pq.empty()) pq.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
