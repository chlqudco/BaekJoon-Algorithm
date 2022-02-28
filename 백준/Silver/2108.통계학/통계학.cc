#include <iostream>
#include <queue>
#include <math.h>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef pair<int, int> p;

struct compare
{
	bool operator()(p a, p b) {
		if (a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	}
};

int N;
int arr[500001] = { 0 };
//평균을 위한 총합
int total = 0;
//몇번 나왔는지 확인
int value[8002] = { 0 };
//최빈값을 위한 pq
priority_queue<p, vector<p>, compare> pq;

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
		value[arr[i] + 4000]++;
		pq.push(make_pair(value[arr[i] + 4000], arr[i]));
		total += arr[i];
	}
	sort(arr, arr + N);
}

void Caluclate() {
	//1. 평균
	float mean = round(total / (float)N);
	if (mean == -0) mean = 0;
	cout << mean << "\n";
	//printf("%.0f\n", mean);
	//2. 중앙값
	cout << arr[N / 2] << "\n";
	//3. 최빈값
	p tmp = pq.top(); pq.pop();
	if (!pq.empty() && tmp.first == pq.top().first) cout << pq.top().second << "\n";
	else cout << tmp.second << "\n";
	//4. 범위
	cout << arr[N - 1] - arr[0] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
