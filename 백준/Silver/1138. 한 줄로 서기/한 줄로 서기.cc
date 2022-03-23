#include <iostream>
#include <list>
using namespace std;

int N;
int arr[11] = { 0 };

list<int> li;
list<int>::iterator iter;

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	//맨뒤 놈은 일단 무조건 맨앞에 배치
	li.push_back(N);
	li.push_back(0);
}

void Calculate() {
	//뒤에서부터 차근 차근
	for (int i = N - 2; i >= 0; i--){
		int cur = arr[i];
		//리스트를 돌면서
		int cnt = 0;
		for (iter = li.begin(); iter != li.end(); iter++){
			//넣을 자리 도착하면 넣기
			if (cur == cnt) {
				li.insert(iter, i + 1);
				break;
			}
			cnt++;
		}

	}
	//출력
	for (iter = li.begin(); (iter != li.end()) && (*iter != 0); iter++) cout << *iter << " ";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}