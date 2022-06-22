#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> p;

int N, M, S;

//다익스트라
vector<p> graph[20001];
int cost[20001] = { 0 };
int INF = 987654321;
//가중치, 인덱스
priority_queue<p, vector<p>, greater<p>> pq;

void Insert_And_Init() {
	int s, e, c;

	cin >> N >> M >> S;
	for (int i = 0; i < M; i++){
		cin >> s >> e >> c;
		graph[s].push_back(make_pair(e, c));
	}
	for (int i = 1; i <= N; i++) cost[i] = INF;
	cost[S] = 0;
}

void dijkstra() {
	pq.push(make_pair(0, S));

	while (!pq.empty()) {
		p cur = pq.top(); pq.pop();
		int dist = cur.first; int idx = cur.second;

		//선택된게 어차피 최단경로가 아닌 경우
		//이거 때문에 visited가 필요가 없음
		if (dist > cost[idx]) continue;

		for (int i = 0; i < graph[idx].size(); i++) {
			//반복문안에서 보고 있는 노드
			int nextIdx = graph[idx][i].first;
			//현재 큐에서 선택된 노드까지의 거리 + 직진거리
			int nextDist = dist + graph[idx][i].second;

			//지금 본 경로가 더 가까우면 갱신
			if (cost[nextIdx] > nextDist) {
				cost[nextIdx] = nextDist;
				pq.push(make_pair(nextDist, nextIdx));
			}
		}
	}
}

void Caluclate() {
	dijkstra();
	for (int i = 1; i <= N; i++){
		if (cost[i] == INF) cout << "INF\n";
		else cout << cost[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}