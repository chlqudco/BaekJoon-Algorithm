#include<iostream>
using namespace std;

long long total = 0;
int N, idx = 0, tmpidx;
int road[100001] = { 0 };
int price[100001] = { 0 };

void Insert() {
    cin >> N;
    for (int i = 0; i < N-1; i++) cin >> road[i];
    for (int i = 0; i < N; i++) cin >> price[i];
}

long long FindCheaperPrice(int tmpidx) {
    long long len = 0;
    for (int i = tmpidx; i < N; i++)
    {
        len += road[i];
        idx++;
        if (price[tmpidx] > price[i + 1]) return len;
    }
    return len;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Insert();

    while (idx < N - 1) {
        tmpidx = idx;
        long long len = FindCheaperPrice(idx);
        total = total + (len * price[tmpidx]);
    }
    cout << total;
}