#include <iostream>
#include <algorithm>

using namespace std;

int N, K, B;
int broken[100001] = { 0 };

void Insert_And_Init() {
	int tmp;
	cin >> N >> K >> B;

	//신호등이 있으면 1
	for (int i = 0; i <= N; i++) broken[i] = 1;

	//신호등 고장나면 0
	for (int i = 0; i < B; i++){
		cin >> tmp;
		broken[tmp] = 0;
	}

	//구간합 구하기
	for (int i = 2; i <= N; i++) broken[i] += broken[i - 1];

	//고칠 신호등 구하기
	int answer = 0;
	//최소 K개 연속이여야 하므로 K부터 보면 됨
	for (int i = K; i <= N; i++){
		//현재 값과 몇개 부셔야 하는지 구하기
		answer = max(answer, broken[i] - broken[i - K]);
	}

	cout << K - answer;

}

void Calculate() {

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}