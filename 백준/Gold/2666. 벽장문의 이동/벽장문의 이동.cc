#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int N, result = 987654321;
int wall1, wall2, arrlen;
int arr[20];

int tmpcnt = 0;

void Insert_And_Init() {
	cin >> N;
	cin >> wall1 >> wall2;
	cin >> arrlen;

	for (int i = 0; i < arrlen; i++) cin >> arr[i];
}

//선택한 문, 인덱스, 총 합, wall1, wall2
void OpenDoor(int door, int idx, int total, int Rwall1, int Rwall2) {
	tmpcnt++;

	//base case. 문 다열은 경우
	if (idx == arrlen) {
		result = min(result, total);
		return;
	}

	//만약 열 문이 wall2 보다 뒤에 있는경우
	if (door == wall1 && arr[idx] >= wall2) return;
	else if (door == wall2 && arr[idx] <= wall1) return;

	//첫번째 문인경우
	if (door == wall1) {
		wall1 = arr[idx];
		total += abs(door - arr[idx]);
	}
	else {
		wall2 = arr[idx];
		total += abs(door - arr[idx]);
	}

	//cout << tmpcnt << "  idx : " << idx << "\n wall1 : " << wall1 << ", wall2 : " << wall2 << "\n total : " << total << "\n\n\n";

	//recur case
	Rwall1 = wall1;
	Rwall2 = wall2;

	OpenDoor(wall1, idx + 1, total, wall1, wall2);
	
	wall1 = Rwall1;
	wall2 = Rwall2;
	
	OpenDoor(wall2, idx + 1, total, wall1, wall2);
}

void Calculate() {
	int tmp1 = wall1;
	int tmp2 = wall2;

	//첫번째 문으로 탐색시작
	OpenDoor(wall1, 0, 0, wall1, wall2);
	
	//복구
	wall1 = tmp1;
	wall2 = tmp2;

	//두번째 문도 똑같
	OpenDoor(wall2, 0, 0, wall1, wall2);

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}