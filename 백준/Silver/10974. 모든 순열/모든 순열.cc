#include <iostream>
#include <vector>

using namespace std;

int N;

//DFS
bool visited[9] = { false };

void Insert_And_Init() {
	cin >> N;
}

void DFS(vector<int> result) {
	// 출력 해야 하는 경우
	if (result.size() == N) {
		for (int i = 0; i < N; i++) cout << result[i] << " ";
		cout << "\n";
		return;
	}

	// 다음 정보를 보자
	for (int i = 1; i <= N; i++){
		if (!visited[i]) {
			result.push_back(i);
			visited[i] = true;
			DFS(result);
			visited[i] = false;
			result.pop_back();
		}
	}
}

void Calculate() {
	vector<int> result;
	DFS(result);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}