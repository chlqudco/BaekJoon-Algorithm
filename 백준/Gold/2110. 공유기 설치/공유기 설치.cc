#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> home;

void Insert_And_Init() {
	int tmp;
	cin >> N >> C;
	for (int i = 0; i < N; i++){
		cin >> tmp;
		home.push_back(tmp);
	}
	sort(home.begin(), home.end());
}

void Caluclate() {
	//이분 탐색 재료
	//mid = 집 사이 간격
	long long start, end, mid;

	start = 0; end = 1000000000;

	long long result = 1;

	while (start <= end) {
		//total = 총 설치할 수 있는 공유기 개수
		long long total = 1;

		mid = (start + end) / 2;

		//최근에 설치한 집 인덱스
		int idx = 0;
		// 몇개 심을 수 있는지 확인
		for (int i = 1; i < N; i++) {
			//현재집과 전에 설치한 집 거리 차이
			int diff = home[i] - home[idx];
			if (diff >= mid) {
				total++;
				idx = i;
			}
		}

		// 원하는 설치 갯수보다 작으면
		if (total < C) {
			end = mid - 1;
		}
		// 원하는 수보다 많이 설치 할 수 있으니 저장
		else {
			if (result < mid) result = mid;
			start = mid + 1;
		}
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}