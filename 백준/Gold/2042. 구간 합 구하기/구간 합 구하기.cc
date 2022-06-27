#include <iostream>
#define N_SIZE 1000001

using namespace std;

typedef long long ll;

int N, M, K;

//원소 들어있는 배열
ll arr[N_SIZE];
//구간합 트리, 원소X4 만큼 할당 필요
ll tree[N_SIZE*4];

//구간 합 트리 생성
ll make_tree(int s, int e, int node) {
	if (s == e) return tree[node] = arr[s];
	int mid = (s + e) / 2;
	return tree[node] = make_tree(s, mid, node * 2) + make_tree(mid + 1, e, node * 2 + 1);
}

//구간 합 구하는 알고리즘
ll tree_sum(int s, int e, int node, int left, int right) {
	//예외 처리 : 범위를 벗어남
	if (left > e || right < s) return 0;

	//값이 범위안에 있음
	if (left <= s && e <= right) return tree[node];
	
	//아니면 나눠서 구하기
	int mid = (s + e) / 2;
	return tree_sum(s, mid, node * 2, left, right) + tree_sum(mid + 1, e, node * 2 + 1, left, right);
}

//특정 원소 값 수정 -> 해당 원소를 포함하고 있는 모든 구간 합 노드 갱신
void tree_update(int s, int e, int node, int index, ll dif) {
	//예외 처리 : 범위를 벗어남
	if (index < s || index > e) return;

	//값이 범위안에 있으면 수정
	tree[node] += dif;

	//끝났으면 끝
	if (s == e) return;

	//아니면 나눠
	int mid = (s + e) / 2;
	tree_update(s, mid, node * 2, index, dif);
	tree_update(mid + 1, e, node * 2 + 1, index, dif);
}

void Input_And_Init() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	make_tree(0, N - 1, 1);
}

void Calculate() {
	ll a, b, c;
	
	for (int i = 0; i < M + K; i++) {	
		cin >> a >> b >> c;
		if (a == 1) {
            //b번째 원소를 c로 고치기
			tree_update(0, N - 1, 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
        //b번째 원소부터 c번째 원소까지의 합 구하기
		else cout << tree_sum(0, N - 1, 1, b - 1, c - 1) << "\n";
	}
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}