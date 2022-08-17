#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int tree[1000001] = { 0 };

void Insert_And_Init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> tree[i];
}

void Caluclate() {
	int result = 0;

	int start = 0;
	int end = 1000000000;

	while (start <= end) {
		//자를 높이 설정
		int mid = (start + end) / 2;

		long long total = 0;
		//얼만큼 가져가는지
		for (int i = 0; i < N; i++){
			if (mid < tree[i]) total += (tree[i] - mid);
		}

		//더 높은 높이가 필요하면 start를 조정
		if (total < M) end = mid - 1;
		//아니면 최대 높이 저장
		else {
			result = max(mid, result);
			start = mid + 1;
		}
	}

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}