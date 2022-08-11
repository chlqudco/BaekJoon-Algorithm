#include <iostream>
#include <queue>

using namespace std;

int N;
int seat[1025][1025] = {0};

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> seat[i][j];
		}
	}
}

int FindSeat(int N, int x, int y){
	// base case
	if(N == 1) return seat[y][x];

	priority_queue< int, vector<int>, greater<int> > pq;
	// 4구역에서 상품 받는 애들 반환
	pq.push( FindSeat(N/2, x, y ) );
	pq.push( FindSeat(N/2, x + N/2, y ));
	pq.push( FindSeat(N/2, x, y + N/2 ));
	pq.push( FindSeat(N/2, x + N/2, y + N/2 ));

	//경품 받는 번호 반환
	pq.pop();
	return pq.top();
}

void Caluclate() {
	cout << FindSeat(N, 0, 0);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}