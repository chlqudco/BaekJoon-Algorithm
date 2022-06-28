#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> pq;
int N;

void Insert_And_Init() {
	int tmp;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		pq.push(tmp);
	}
}

void Caluclate(){
	int cnt = 1;
	int w = pq.top(); pq.pop();

	while (!pq.empty()) {
		cnt++;
		int tmp = pq.top(); pq.pop();
		if (tmp * cnt > w) w = tmp * cnt;
	}

	cout << w;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}