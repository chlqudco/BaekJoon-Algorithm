#include <iostream>
#include <algorithm>
using namespace std;

//단지 수, 버스 정원, 학교 위치
int N, K, S;
int home[100001] = { 0 };

void Insert_And_Init() {
	int a, b;

	cin >> N >> K >> S;
	for (int i = 0; i < N; i++){
		cin >> a >> b;
        home[a] = b;
	}
}

void Caluclate() {
	int remainSeat = K;
	int startIdx = -1;
	int result = 0;

    //음수 영역
	for (int i = 0; i < S; i++){
		//주민이 사는 경우
		if (home[i] != 0) {
			//출발지 저장
			if (startIdx == -1) startIdx = i;

			//다 태울 수 있는 경우
			if (remainSeat >= home[i]) {
				remainSeat -= home[i];
				home[i] = 0;
			}
			//다 못태우는 경우
			else {
				home[i] -= remainSeat;
				remainSeat = 0;
			}

			//꽉찼으면 배달
			if (remainSeat == 0) {
				result += (S - startIdx) * 2;
				//초기화
				remainSeat = K;
				startIdx = -1;
				//다시 들르기 위해 i--;
				i--;
			}
		}
	}

	//나머지 배달
	if (remainSeat != K) {
		result += (S - startIdx) * 2;
		//초기화
		remainSeat = K;
		startIdx = -1;
	}

	//양수 영역
	for (int i = 100000; i > S; i--) {
		//주민이 사는 경우
		if (home[i] != 0) {
			//출발지 저장
			if (startIdx == -1) startIdx = i;

			//다 태울 수 있는 경우
			if (remainSeat >= home[i]) {
				remainSeat -= home[i];
				home[i] = 0;
			}
			//다 못태우는 경우
			else {
				home[i] -= remainSeat;
				remainSeat = 0;
			}

			//꽉찼으면 배달
			if (remainSeat == 0) {
				result += (startIdx - S) * 2;
				//초기화
				remainSeat = K;
				startIdx = -1;
				//다시 들르기 위해 i--;
				i++;
			}
		}
	}

	//나머지 배달
	if (remainSeat != K) result += (startIdx - S) * 2;

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
