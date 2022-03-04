#include <iostream>
#include <algorithm>
using namespace std;

int N, yesan, maxmoney = -999;
int money[10001] = { 0 };

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
		maxmoney = max(maxmoney, money[i]);
	}
	cin >> yesan;
}

void Caluclate() {
	//이분 탐색 재료
	long long start, end, mid;

	start = 0; end = maxmoney;

	long long result = 0;

	while (start <= end) {
		//자르면 총 몇미터 나오는지
		long long total = 0;

		mid = (start + end) / 2;

		for (int i = 0; i < N; i++) {
			// 총 가격 계산
			if (money[i] >= mid) total += mid;
			else total += money[i];
		}
		// 예산 부족하면
		if (total > yesan) {
			end = mid - 1;
		}
		// 안 부족하면
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
