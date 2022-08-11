#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
int arr[4]={0};
priority_queue< int, vector<int>, less<int> > pq;
priority_queue< int, vector<int>, greater<int> > pq2;

void Insert_And_Init() {
	int tmp;
	cin>>N;
	for (int i = 0; i < N; i++){
		cin>>tmp;
		if (pq.size() != 4){
			pq.push(tmp);
		} else {
			if(pq.top() > tmp){
				pq.pop();
				pq.push(tmp);
			}
		}
	}
}

void Caluclate() {
	if(N >= 4) N = 4;

	for (int i = 0; i < N; i++){
		arr[i] = pq.top();
		pq.pop();
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if(i == j) continue;

			int cur_num1 = stoi(to_string(arr[i]) + to_string(arr[j]));
			pq2.push(cur_num1);
		}
	}

	pq2.pop();
	pq2.pop();
	cout<<pq2.top();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}