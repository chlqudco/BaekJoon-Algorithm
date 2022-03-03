#include <iostream>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

int N;

//윗줄 아랫줄 거쳐간 인덱스 담을 set
set<int> src;
set<int> dest;
set<int>::iterator iter;
set<int>::iterator iter2;
//정답을 담고 있는 set
set<int> result;

//DFS
int graph[101] = { 0 };
bool visited[101] = { false };

void Insert_And_Init() {
	cin >> N;
	//번호 i 아래 뭐 적혀 있는지
	for (int i = 1; i <= N; i++) cin >> graph[i];
}

bool IsAllVisited() {
	if (src.size() != dest.size()) return false;

	iter2 = dest.begin();
	for (iter = src.begin(); iter != src.end(); iter++, iter2++) if (*iter != *iter2) return false;
	for (iter = src.begin(); iter != src.end(); iter++) if (!visited[*iter]) return false;
	
	return true;
}

void Addresult() {
	for (iter = src.begin(); iter != src.end(); iter++) result.insert(*iter);
}

void DFS(int idx) {
	//내 위치 방문처리
	visited[idx] = true;

	src.insert(idx);
	dest.insert(graph[idx]);

	//다음 위치 방문 안했으면 못먹어도 고
	if (!visited[graph[idx]]) DFS(graph[idx]);
	//이미 방문 한 곳이면
	else {
		//모든 윗줄 방문 했으면 결과에 포함
		if (IsAllVisited()) Addresult();
	}
}

void Caluclate() {
	// case 1. 모든 정수 DFS
	for (int i = 0; i < N; i++){
		DFS(i + 1);
		src.clear();
		dest.clear();

		memset(visited, false, sizeof(visited));
	}

	//출력
	cout << result.size() << "\n";
	for (iter = result.begin(); iter != result.end(); iter++) cout << *iter << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
