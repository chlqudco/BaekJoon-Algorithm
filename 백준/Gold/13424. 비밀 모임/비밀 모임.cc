#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int T, N, M, K;
int totalCost[101] = { 0 };

//다익스트라
int cost[101] = { 0 };
vector<p> graph[101];
int INF = 987654321;

void InitCost() {
	for (int i = 0; i <= N; i++) cost[i] = INF;
}

void InitGraph() {
	for (int i = 1; i <= N; i++) graph[i].clear();
	memset(totalCost, 0, sizeof(totalCost));
}

void Input_And_Init() {
	cin >> T;
	InitCost();
}

void Dijkstra(int start) {
	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push(make_pair(0, start));
	cost[start] = 0;

	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();
		int dist = cur.first; int idx = cur.second;

		if (dist > cost[idx]) continue;
		for (int i = 0; i < graph[idx].size(); i++){
			int nextDist = dist + graph[idx][i].second;
			int nextIdx = graph[idx][i].first;

			if (cost[nextIdx] > nextDist) {
				cost[nextIdx] = nextDist;
				pq.push(make_pair(nextDist, nextIdx));
			}
		}
	}
}

void Calculate() {
	int a, b, c, tmp;
	for (int k = 0; k < T; k++){
		cin >> N >> M;

		//그래프 입력
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(b, c));
			graph[b].push_back(make_pair(a, c));
		}
		for (int i = 0; i <= N; i++) cost[i] = INF;

		//친구 정보 입력
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> tmp;
			Dijkstra(tmp);
			//비용 더하기
			for (int j = 1; j <= N; j++) totalCost[j] += cost[j];
			InitCost();
		}

		//최소 방 찾기
		int minCost = INF;
		for (int i = 1; i <= N; i++) minCost = min(minCost, totalCost[i]);
		for (int i = 1; i <= N; i++){
			if (minCost == totalCost[i]) {
				cout << i << "\n";
				break;
			}
		}
		//초기화
		InitGraph();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}