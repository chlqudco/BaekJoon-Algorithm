#include <iostream>
#include <string.h>
using namespace std;

int T, N, M;
int coin[21] = { 0 };
int dp[10002] = { 0 };

void Insert_And_Init() {
    cin >> T;
}

void Caluclate() {
    for (int i = 0; i < T; i++){
        cin >> N;
        for (int j = 0; j < N; j++) cin >> coin[j]; 
        cin >> M;
        dp[0] = 1;

        //전체 동전을 순회 하면서
        for (int k = 0; k < N; k++) {
            //그 동전으로 j원을 만들 수 있니?
            for (int j = coin[k]; j <= M; j++) {
                //만들 수 있으면 dp[j-coin[k]] 에 0이 없음
                dp[j] += dp[j - coin[k]];
            }
        }

        cout << dp[M] << "\n";
        memset(dp, 0, sizeof(dp));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Insert_And_Init();

    Caluclate();
}
