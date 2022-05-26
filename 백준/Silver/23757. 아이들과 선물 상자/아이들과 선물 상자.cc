#include <iostream>
#include <queue>
using namespace std;

//선물상자
priority_queue<int, vector<int>, less<int>> pq;
int N, M;
int w[100001] = { 0 };

void Insert_And_Init() {
	int tmp;
	cin >> N >> M;
	//선물상자 입력
	for (int i = 0; i < N; i++){
		cin >> tmp;
		pq.push(tmp);
	}
	//아이들 입력
	for (int i = 0; i < M; i++) cin >> w[i];
	
}

void Caluclate() {
	bool flag = true;
	//아이들을 순회하며
	for (int i = 0; i < M; i++){
		//젤 선물많은 상자 가져오기
		int top = pq.top(); pq.pop();

		//얘가 원하는 개수보다 적으면 실망
		if (w[i] > top) {
			flag = false;
			break;
		}

		//많으면 ㄱㅊ
		top -= w[i];
		if (top > 0) pq.push(top);
	}
	if (flag) cout << 1;
	else cout << 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}