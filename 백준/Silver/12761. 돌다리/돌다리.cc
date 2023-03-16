#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int A, B, N, M;

//내사랑 BFS
int visited[100001] = { 0 };

void Insert_And_Init() {
	cin >> A >> B >> N >> M;
}

bool CanGo(int cur) {
	if (cur >= 0 && cur <= 100000 && visited[cur] == 0) return true;
	return false;
}

int BFS() {
	queue<p> que;
	visited[N] = 1;
	que.push(make_pair(N, 0));

	while (!que.empty()){
		p cur = que.front(); que.pop();

		//+1칸
		int next = cur.first + 1;
		if (CanGo(next)) {
			visited[next] = cur.second + 1;
			que.push(make_pair(next, cur.second + 1));
		}

		//-1칸
		next = cur.first - 1;
		if (CanGo(next)) {
			visited[next] = cur.second + 1;
			que.push(make_pair(next, cur.second + 1));
		}

		//A만큼 앞점프
		next = cur.first + A;
		if (CanGo(next)) {
			visited[next] = cur.second + 1;
			que.push(make_pair(next, cur.second + 1));
		}

		//A만큼 뒷점프
		next = cur.first - A;
		if (CanGo(next)) {
			visited[next] = cur.second + 1;
			que.push(make_pair(next, cur.second + 1));
		}

		//B만큼 앞점프
		next = cur.first + B;
		if (CanGo(next)) {
			visited[next] = cur.second + 1;
			que.push(make_pair(next, cur.second + 1));
		}

		//B만큼 뒷점프
		next = cur.first - B;
		if (CanGo(next)) {
			visited[next] = cur.second + 1;
			que.push(make_pair(next, cur.second + 1));
		}

		//A배 만큼 슈퍼점프
		next = cur.first * A;
		if (CanGo(next)) {
			visited[next] = cur.second + 1;
			que.push(make_pair(next, cur.second + 1));
		}

		//B배 만큼 슈퍼점프
		next = cur.first * B;
		if (CanGo(next)) {
			visited[next] = cur.second + 1;
			que.push(make_pair(next, cur.second + 1));
		}

	}
	return visited[M];
}

void Calculate() {
	cout << BFS();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}