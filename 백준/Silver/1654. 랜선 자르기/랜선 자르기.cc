#include <iostream>
#include <algorithm>
using namespace std;

int K, N;
int lan[10001] = { 0 };

void Insert_And_Init() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) cin >> lan[i];
}

void Caluclate() {
	long long result = 0;

	long long start = 1;
	long long end = 2147483647;

	while (start<=end){
		//미드 설정
		long long mid = (start + end) / 2;

		long long total = 0;
		//총 랜선 갯수 계산
		for (int i = 0; i < K; i++) total += (lan[i] / mid);
		
		//충분히 챙겨 갈 수 있는 경우
		if (total >= N) {
			result = max(result, mid);
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}