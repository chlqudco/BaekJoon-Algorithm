#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> p;

int N, M, X;

//다익스트라
vector<p> graph[1001];
int cost[1001] = { 0 };
int INF = 987654321;

void InitCost() {
	for (int i = 1; i <= N; i++) cost[i] = INF;
}

void Insert_And_Init() {
	int u, v, w;

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++){
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}
	InitCost();
}

void Dijkstra(int start) {
	priority_queue<p, vector<p>, greater<p>> pq;

	cost[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();
		int dist = cur.first; int idx = cur.second;

		if (cost[idx] < dist) continue;

		for (int i = 0; i < graph[idx].size(); i++){
			int nextIdx = graph[idx][i].first;
			int nextDist = dist + graph[idx][i].second;

			if (cost[nextIdx] > nextDist) {
				cost[nextIdx] = nextDist;
				pq.push(make_pair(nextDist, nextIdx));
			}
		}
	}
}

void Caluclate() {
	int studentCost[1001] = { 0 };
	for (int i = 1; i <= N; i++){
		if (i != X) {
			Dijkstra(i);
			studentCost[i] = cost[X];
			InitCost();
		}
	}

	Dijkstra(X);
	for (int i = 1; i <= N; i++) {
		studentCost[i] += cost[i];
	}
	int maxValue = -1;
	for (int i = 1; i <= N; i++) {
		if (maxValue < studentCost[i]) maxValue = studentCost[i];
	}
	cout << maxValue;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}