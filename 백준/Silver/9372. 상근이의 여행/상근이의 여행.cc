#include<iostream>
using namespace std;

int T, N, M;

void Insert() {
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		Insert();
		//모든 점 돌면서 최소값 찾기
		/*
		for (int j = 0; j < N; j++){
			Findnum();
		}
		*/
		cout << N - 1 << "\n";
	}
}