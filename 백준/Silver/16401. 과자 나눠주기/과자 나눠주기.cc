#include <iostream>

using namespace std;

int M, N, result = 0;
int L[1000001] = { 0 };

void Insert_And_Init() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
}

void Calculate() {

	//이분 탐색으로 찾아보자
	int start = 1;
	int end = 1000000000;

	while (start <= end) {
		int mid = (start + end) / 2;

		//mid 값으로 M명이 다 쳐먹을 수 있는지 확인
		int cnt = 0;
		for (int i = 0; i < N; i++){
			cnt += L[i] / mid;
		}

		//다 먹을 수 있다면 좀 더 올려봐
		if (cnt >= M) {
			start = mid + 1;
			result = mid;
		}
		//다 못먹으면 더 작게
		else {
			end = mid - 1;
		}
	}

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}