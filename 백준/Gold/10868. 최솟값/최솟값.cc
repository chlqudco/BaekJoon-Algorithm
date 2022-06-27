#include <iostream>
#include <algorithm>
#define N_SIZE 100001

using namespace std;

typedef long long ll;

int N, M, K;
int INF = 1000000001;

//원소 들어있는 배열
int arr[N_SIZE];
//구간합 트리, 원소X4 만큼 할당 필요
int tree[N_SIZE * 4];

//구간 합 트리 생성
int make_tree(int s, int e, int node) {
	if (s == e) return tree[node] = arr[s];
	int mid = (s + e) / 2;
	return tree[node] = min(make_tree(s, mid, node * 2) , make_tree(mid + 1, e, node * 2 + 1));
}

//최소값 구하기
int get_min_num(int node, int s, int e, int l, int r)
{
	if (e < l || r < s) return INF; // 찾아야하는 구간과 노드구간이 겹치지 않을 때
	if (l <= s && e <= r) return tree[node]; // 찾아야하는 구간내에 노드구간이 포함될 때
	int mid = (s + e) / 2;
	// 찾아야하는 구간이 노드구간에 포함되거나, 부분적으로 겹치는 경우
	return min(get_min_num(2 * node, s, mid, l, r), get_min_num(2 * node + 1, mid + 1, e, l, r));
}

void Input_And_Init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	make_tree(0, N - 1, 1);
}

void Calculate() {
	int a, b;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		cout << get_min_num(1, 0, N - 1, a - 1, b - 1) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}