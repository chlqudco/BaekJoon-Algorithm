#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> wood;

void Insert_And_Init() {
	int tmp;
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		wood.push_back(tmp);
	}
}

void Caluclate() {
	//이분 탐색 재료
	long long start, end, mid;

	start = 0; end = 2000000000;

	long long result = 0;

	while (start <= end) {
		//자르면 총 몇미터 나오는지
		long long total = 0;

		mid = (start + end) / 2;

		for (int i = 0; i < N; i++) {
			// 잘랐을 때 총 개수 저장
			if (wood[i] > mid) total += (wood[i] - mid);
		}
		// 총 길이가 아쉬우면
		if (total < M) {
			end = mid - 1;
		}
		// 많이 잘랐으면 저장
		else {
			if (result < mid) result = mid;
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