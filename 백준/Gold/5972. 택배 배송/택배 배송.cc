#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;

int N, M;

//다익스트라
int cost[50001] = { 0 };
vector<p> graph[50001];
int INF = 987654321;

void Input_And_Init() {
	int a, b, c;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	for (int i = 1; i <= N; i++) cost[i] = INF;
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
	Dijkstra(1);
	cout << cost[N];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}