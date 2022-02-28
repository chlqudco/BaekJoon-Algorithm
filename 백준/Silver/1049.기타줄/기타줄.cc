#include <iostream>
using namespace std;

int N, M;
int min_package=99999, min_each=99999;

void Insert_And_Init() {
	int tmp_p, tmp_e;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> tmp_p >> tmp_e;
		if (tmp_p < min_package) min_package = tmp_p;
		if (tmp_e < min_each) min_each = tmp_e;
	}
}

void Caluclate() {
	int money = 0;
	//낱개로 사는게 더 싸면 다 낱개로 구입
	if (min_each * 6 < min_package) {
		cout << N * min_each;
		return;
	}
	//그게 아니면 일단 패키지 구입
	else {
		money = (N / 6) * min_package;
		N = N - (N / 6) * 6;
	}

	//남은 자투리를 패키지로 살지 낱개로 살지 정해
	if (min_each * N < min_package) money += min_each * N;
	else money += min_package;

	cout << money;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
