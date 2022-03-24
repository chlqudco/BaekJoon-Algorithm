#include<iostream>
#include<queue>
using namespace std;

int T,N,tmp;
long long money;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;
	for (int i = 0; i < T; i++){
		money = 0;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			pq.push(tmp);
		}
		for (int j = 0; j < N-1; j++)
		{
			long long tmp1 = pq.top(); pq.pop();
			long long tmp2 = pq.top(); pq.pop();
			money += tmp1 + tmp2;
			pq.push(tmp1 + tmp2);
		}
		cout << money << "\n";
	}
}