#include<iostream>
#include<string.h>
#include<queue>
#include <math.h>
using namespace std;

int T;
string A, B;
int cnt = 0;

//BFS재료
bool visited[10006] = { false };
queue<string> que;

void Input_And_Init() {
	cin >> T;
}

bool sosu(int num) {
	if (num < 2) return false;
	int a = (int)sqrt(num);
	for (int i = 2; i <= a; i++) if (num % i == 0) return false;
	return true;
}

int Change(string num) {
	return (num[0] - '0') * 1000 + (num[1] - '0') * 100 + (num[2] - '0') * 10 + (num[3] - '0');
}

bool BFS() {
	int num = Change(A);
	que.push(A);
	visited[num] = true;

	while (!que.empty()) {
		int que_size = que.size();
		for (int t = 0; t < que_size; t++) {
			string cur = que.front(); que.pop();
			if (cur == B) return true;

			//cur의 자리수
			for (int i = 0; i < 4; i++) {
				//dp의 자리수
				for (int j = 0; j < 10; j++) {
					string tmp = cur;
					//i번째 자리를 j번째 수로 바꾸기
					tmp[i] = '0' + j;
					int curNum = Change(tmp);
					if ((tmp[0] != '0') && (visited[curNum] == false) && (sosu(curNum))) {
						que.push(tmp);
						visited[curNum] = true;
					}
				}
			}
		}
		cnt++;
	}

	return false;
}

void Calculate() {
	for (int i = 0; i < T; i++){
		//입력
		cin >> A >> B;

		//바꾸기 시작
		bool result = BFS();

		//출력
		if (result) cout << cnt << "\n";
		else cout << "Impossible\n";
		
		//초기화
		memset(visited, 0, sizeof(visited));
		while (!que.empty()) que.pop();
		cnt = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}