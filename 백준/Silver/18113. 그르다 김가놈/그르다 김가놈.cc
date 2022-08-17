#include <iostream>
#include <algorithm>

using namespace std;

int N, K, M;
int L[1000001] = {0};

void Insert_And_Init() {
	cin >> N >> K >> M;
	for (int i = 0; i < N; i++){
		cin >> L[i];
		// 두 쪽 자를 수 있으면
		if(L[i] >= 2*K) L[i] = L[i] - 2*K;
		// 한쪽만 자를 수 있으면
		else if(L[i] > K) L[i] = L[i] - K;
		// 너무 짧으면
		else L[i] = 0;
	}
}

void Caluclate() {
	long long result = 0;

	int start = 1;
	int end = 1'000'000'000;

	while(start <= end){
		long long mid = (start + end) / 2;

		if(mid == 0) break;

		long long total = 0;
		for (int i = 0; i < N; i++) total += ( L[i] / mid );

		// 원하는 김밥 개수를 충족 했다면
		if(total >= M){
			result = max(result, mid);
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	if(result == 0) cout<< -1;
	else cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}