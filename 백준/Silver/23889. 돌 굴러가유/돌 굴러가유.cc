#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;

//몇개 부수는지, 시작 마을
typedef pair<int, int> p;


struct compare {
	bool operator()(p a, p b) {
		if (a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	}
};

int N, M, K;
int x[100000] = { 0 };
int start_stone[100000] = { 0 };
priority_queue<p, vector<p>, compare> pq;
priority_queue<int, vector<int>, greater<int>> pq2;

void Insert_And_Init() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> x[i];
	for (int i = 0; i < K; i++) cin >> start_stone[i];

	//돌들 순항 하면서
	for (int i = 0; i < K - 1; i++){
		//현재 돌 시작지점
		int s = start_stone[i] - 1;
		//현재 돌 끝지점
		int e = start_stone[i + 1] - 1;

		//합 구하기
		int total = 0;
		for (int j = s; j < e; j++) total += x[j];
		
		//삽입
		pq.push(make_pair(total, s + 1));
	}

	//마지막 돌
	int total = 0;
	for (int i = start_stone[K - 1] -1; i < N; i++) total += x[i];
	pq.push(make_pair(total, start_stone[K-1]));
}

void Caluclate() {
	
	//벽 개수만큼 빼기
	for (int i = 0; i < M; i++){
		pq2.push(pq.top().second);
		pq.pop();
	}

	while (!pq2.empty()) {
		cout << pq2.top() << "\n";
		pq2.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}