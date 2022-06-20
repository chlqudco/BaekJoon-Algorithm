#include <iostream>
#include <queue>
using namespace std;

int N, a, b;
int bridge[10001];

//BFS
bool visited[10001] = { false };
queue<int> que;

void Input_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> bridge[i];
	cin >> a >> b;
	a--; b--;
}

bool CanGo(int idx) {
	if (idx < N && idx>=0 && visited[idx] == false) return true;
	return false;
}

int BFS() {
	int cnt = 0;

	visited[a] = true;
	que.push(a);

	while (!que.empty()) {
		int que_size = que.size();
		for (int j = 0; j < que_size; j++) {
			int cur = que.front(); que.pop();

			//도착!
			if (cur == b) return cnt;

			for (int i = cur; i < N; i += bridge[cur]) {
				if (CanGo(i)) {
					que.push(i);
					visited[i] = true;
				}
			}
			for (int i = cur; i >= 0; i -= bridge[cur]) {
				if (CanGo(i)) {
					que.push(i);
					visited[i] = true;
				}
			}
		}
		cnt++;
	}
	
	return -1;
}

void Calculate() {
	cout<<BFS();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}