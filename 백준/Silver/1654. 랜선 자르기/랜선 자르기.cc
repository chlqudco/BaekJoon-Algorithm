#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> lan;

void Insert_And_Init() {
	int tmp;
	cin >> K >> N;
	for (int i = 0; i < K; i++){
		cin >> tmp;
		lan.push_back(tmp);
	}
}

void Caluclate() {
	//이분 탐색 재료
	long long start, end, mid;

	start = 1; end = 2147483647;

	long long result = 1;

	while (start <= end) {
		//자르면 총 몇개 나오는지
		long long total = 0;

		mid = (start + end) / 2;

		for (int i = 0; i < K; i++) {
			// 잘랐을 때 총 개수 저장
			total += (lan[i] / mid);
		}
		// 자른 갯수가 N개보다 적으면 더 작게 잘라야 함
		if (total < N) {
			end = mid - 1;
		}
		// N개 이상이면 최대값 조사
		else {
			if ((result < mid)) result = mid;
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