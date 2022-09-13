#include <iostream>

using namespace std;

int N;
int A[1000001] = {0};

void Insert_And_Init() {
	int tmp;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		A[tmp]++;
	}
}

void Calculate(){
	int result = 0;
	int tmp;

	for (int i = 0; i < N; i++){
		cin >> tmp;
		if(A[tmp] >= 1) A[tmp]--;
		else result++;
	}

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}