#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, long long> p;

int N, M, K;
vector<p> beer;
long long result = 2147483647;

void Input_And_Init() {
	int v;
	long long c;

	cin >> N >> M >> K;
	
	for (int i = 0; i < K; i++) {
		cin >> v >> c;
		beer.push_back(make_pair(v, c));
	}

	sort(beer.begin(), beer.end(), greater<p>());
}

void Calculate() {
	long long start = 1, end = 2147483647;
	bool flag = false;

	while (start <= end) {
		//mid = 간 세기
		long long mid = (start + end) / 2;

		int total = 0;
		int cnt = 0;
		//로직
		for (int i = 0; i < K; i++){
			//먹을 수 있으면
			if (beer[i].second <= mid) {
				total += beer[i].first;
				cnt++;
			}
			if (cnt == N) break;
		}

		//원하는 선호도 이면
		if (cnt == N && total >= M) {
			flag = true;
			result = min(result, mid);
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	if (flag) cout << result;
	else cout << "-1";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}