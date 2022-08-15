#include <iostream>
#include <string.h>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> p;

int N, M;
int hackingCount[10001] = { 0 };
priority_queue<p, vector<p>, greater<p>> pq;

//BFS
vector<int> graph[10001];
bool visited[10001] = { false };

void Input_And_Init() {
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		graph[b].push_back(a);
	}
}

int BFS(int start) {
	queue<int> que;
	que.push(start);
	visited[start] = true;

	int cnt = 1;
	while (!que.empty()){
		int curIdx = que.front(); que.pop();

		for (int i = 0; i < graph[curIdx].size(); i++){
			int nextIdx = graph[curIdx][i];
			// 아직 방문 안한 애면
			if (!visited[nextIdx]) {
				que.push(nextIdx);
				visited[nextIdx] = true;
				cnt++;
			}
		}
	}

	return cnt;
}

void Calculate() {
	//모든 정점을 기준으로 BFS
	for (int i = 1; i <= N; i++){
		//본인을 방문하지 않았다면
		hackingCount[i] = BFS(i);
		memset(visited, false, sizeof(visited));
	}

	//최대값 찾기
	int maxCnt = -1;
	for (int i = 1; i <= N; i++) maxCnt = max(maxCnt, hackingCount[i]);
	
	//최대 인덱스 출력
	for (int i = 1; i <= N; i++) {
		if (hackingCount[i] == maxCnt) cout << i << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}