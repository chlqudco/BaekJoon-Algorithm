#include <iostream>

using namespace std;

int N, M, J;
int apple[21] = { 0 };
int start_bucket = 0, end_bucket = 0;

void Input_And_Init() {
	cin >> N >> M >> J;
	for (int i = 0; i < J; i++) cin >> apple[i];
	start_bucket = 1; end_bucket = M;
}

void Calculate() {
	int answer = 0;

	// 사과 돌면서
	for (int i = 0; i < J; i++){
		int cur_apple = apple[i];

		// 이미 범위 안에 있으면 아무것도 안함
		if (start_bucket <= cur_apple && cur_apple <= end_bucket) continue;
	
		// 시작 부분을 움직여야 하는 경우
		if (start_bucket > cur_apple) {
			int differ = start_bucket - cur_apple;
			start_bucket -= differ;
			end_bucket -= differ;
			answer += differ;
		}
		// 끝 부분을 움직여야 하는 경우
		else {

			int differ = cur_apple - end_bucket;
			start_bucket += differ;
			end_bucket += differ;
			answer += differ;
		}
	
	}

	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	Input_And_Init();
	Calculate();
}