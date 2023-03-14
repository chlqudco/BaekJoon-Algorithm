#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, pair<int, int>> p;

int V, E, answer = 0;

//유니온 파인드
int parent[10001] = { 0 };

//가중치 정렬 용 우선순위 큐
priority_queue<p, vector<p>, greater<p>> pq;

void Insert_And_Init() {
	//간선 입력
	int a, b, c;
	cin >> V >> E;
	for (int i = 0; i < E; i++){
		cin >> a >> b >> c;
		// 가중치를 오름차순으로 뽑기 위해 우선순위큐 사용
		pq.push(make_pair(c, make_pair(a, b)));
	}

	//유니온 파인드 초기화
	for (int i = 1; i <= V; i++) parent[i] = i;
}

int node_find(int node) {
	// 부모면 리턴
	if (parent[node] == node) return node;

	// 아니면 부모 찾아가기
	return parent[node] = node_find(parent[node]);
}

bool isLinked(int start, int end) {
	//각자의 부모 불러오기
	start = node_find(start);
	end = node_find(end);

	//서로의 부모가 같으면 연결됨
	if (start == end) return true;
	else return false;
}


void node_union(int start, int end) {
	//부모 불러와봐
	start = node_find(start);
	end = node_find(end);

	//부모가 다르면 연결
	if (start != end) parent[end] = start;
}

void Calculate() {
	
	// 크루스칼 알고리즘 사용, 모든 간선을 돌면서
	for (int i = 0; i < E; i++){
		// 가중치가 가장 작은 간선 선택
		p cur = pq.top(); pq.pop();

		// 두 정점이 연결되어 있는지 확인, 연결 되어 있지 않는 경우
		if (!isLinked(cur.second.first, cur.second.second)) {
			// 해당 간선을 포함시키고
			answer += cur.first;

			// 두 정점 연결
			node_union(cur.second.first, cur.second.second);
		}
	}

	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}