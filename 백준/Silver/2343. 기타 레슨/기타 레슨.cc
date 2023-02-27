#include <iostream>
#include <algorithm>

using namespace std;

long long  N, M, result = 1;
long long  lecture[100001] = { 0 };

void Insert_And_Init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> lecture[i];
}

void Calculate() {
	//기준은 강의 녹화 시간
	long long start = 1;
	long long end = 11111111111111;

	while (start <= end) {
		long long  mid = (start + end) / 2;

		// mid 분 강의로 M개를 채울 수 있는지 확인
		int cnt = 0;
		long long  current_minute = 0;
		for (int i = 0; i < N; i++){
			//애초에 못채우는 경우
			if (lecture[i] > mid) {
				cnt = 9999999;
				break;
			}

			//1개 채웠으면
			if (current_minute + lecture[i] > mid) {
				cnt++;
				current_minute = lecture[i];
			}
			else if (current_minute + lecture[i] == mid) {
				cnt++;
				current_minute = 0;
			}
			//부족한 경우
			else {
				current_minute += lecture[i];
				//딱맞는 강의
				if (current_minute == mid) {
					cnt++;
					current_minute = 0;
				}
			}
		}
		if (current_minute != 0) cnt++;

		//M개 이하면 ㄱㅊ
		if (cnt <= M) {
			result = mid;
			end = mid - 1;
		}
		//너무 많이 담았다면 시간 늘려
		else{ 
			start = mid + 1;
		}
	}

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}