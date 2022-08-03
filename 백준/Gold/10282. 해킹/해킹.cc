#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

int T;
int n, d, c;
int a, b, s;

//DFS
vector<p> graph[10001];

//다익스트라
int cost[20001] = { 0 };
int INF = 987654321;

//가중치, 인덱스
priority_queue<p, vector<p>, greater<p>> pq;


void Insert_And_Init() {
	cin >> T;
}

void dijkstra() {
	pq.push(make_pair(0, c));

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
	for (int o = 0; o < T; o++){
		//입력
		cin >> n >> d >> c;
		for (int q = 0; q < d; q++){
			cin >> a >> b >> s;
			graph[b].push_back(make_pair(a, s));
		}
		for (int i = 1; i <= n; i++) cost[i] = INF;
		cost[c] = 0;

		//다익스트라
		dijkstra();

		//답 구하기
		int maxDist = -1;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (cost[i] != INF) {
				cnt++;
				maxDist = max(maxDist, cost[i]);
			}
		}
		cout << cnt << " " << maxDist << "\n";

		//초기화
		for (int i = 1; i <= n; i++) graph[i].clear();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}