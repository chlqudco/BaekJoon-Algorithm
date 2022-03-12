#include <iostream>
using namespace std;

int T, N, M, minCoin = 99999;
int coin[21] = { 0 };

void Insert_And_Init() {
    cin >> T;
}


void Caluclate() {
    for (int i = 0; i < T; i++){
        int dp[10001] = { 0 };
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> coin[j];
            minCoin = min(minCoin, coin[j]);
        }
        cin >> M;
        dp[0] = 1;

        //전체 동전을 순회 하면서
        for (int k = 0; k < N; k++) {
            //그 동전으로 j원을 만들 수 있니?
            for (int j = coin[k]; j <= M; j++) {
                //만들 수 있으면 dp[j-coin[i]] 에 0이 없음
                dp[j] += dp[j - coin[k]];
            }
        }

        cout << dp[M]<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Insert_And_Init();

    Caluclate();
}
