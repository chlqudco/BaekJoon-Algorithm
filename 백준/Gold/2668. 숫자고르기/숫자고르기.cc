#include <iostream>
#include <set>
#include <string.h>
using namespace std;

int N;
//출발지 정보
int start;

//정답 idx를 담을 set (iter로 꺼내면 자동 오름차순이라 set 씀, 중복방지도 되고 1석2조)
set<int> result;

//DFS 재료
int graph[101] = { 0 };
bool visited[101] = { false };

void Insert_And_Init() {
	cin >> N;
	//번호 i 아래 뭐 적혀 있는지만 저장하면 됨
	for (int i = 1; i <= N; i++) cin >> graph[i];
}

void Addresult() {
	//방문한곳 다 쳐넣기
	for (int i = 0; i < 101; i++) if (visited[i] == true) result.insert(i);
}

void DFS(int idx) {
	//내 위치 방문처리
	visited[idx] = true;

	//다음 위치 방문 안했으면 못먹어도 고
	if (!visited[graph[idx]]) DFS(graph[idx]);
	//이미 방문 한 곳이면
	else {
		//시작 idx이면 결과 set에 넣기
		if (graph[idx] == start) Addresult();
	}
}

void Caluclate() {
	// 모든 값 DFS
	for (int i = 0; i < N; i++){
		start = i + 1;
		//이미 결과값에 있으면 굳이 할 필요 없음
		if(!result.count(start)) DFS(start);
		//visited 초기화
		memset(visited, false, sizeof(visited));
	}

	//출력
	cout << result.size() << "\n";
	for (auto iter = result.begin(); iter != result.end(); iter++) cout << *iter << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
