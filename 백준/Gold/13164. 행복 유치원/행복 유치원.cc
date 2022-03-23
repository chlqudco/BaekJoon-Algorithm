#include <iostream>
#include<queue>
using namespace std;

int N, K;
int height[300001] = { 0 };
priority_queue <int, vector<int>, greater<int>> pq;

void Insert_And_Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin>>height[i];
    for (int i = 0; i < N-1; i++) pq.push(height[i + 1] - height[i]);
}

long long Make_Group() {
    long long result = 0;
    while (N != K) {
        int tmp = pq.top(); pq.pop();
        result += tmp;
        N--;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    Insert_And_Init();

    cout<<Make_Group();
}