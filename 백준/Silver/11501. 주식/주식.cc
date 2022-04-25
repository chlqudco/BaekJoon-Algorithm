#include <iostream>
using namespace std;

int T, N;
int price[1000001] = { 0 };

void Insert_And_Init() {
    cin >> T;
}

void InputCost() {
    
}

void Caluclate() {
    for (int j = 0; j < T; j++){
        //입력
        cin >> N;
        for (int i = 0; i < N; i++) cin >> price[i];

        //계산 전 초기화
        long long total = 0;
        int topStockPrice = price[N - 1];

        //뒤에서 부터 돌면서
        for (int i = N - 2; i >= 0; i--){
            // 최대값보다 작으면 구매
            if (price[i] < topStockPrice) total += (topStockPrice - price[i]);
            // 최대값보다 크면 갱신
            else if (price[i] > topStockPrice) topStockPrice = price[i];
        }

        cout << total << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Insert_And_Init();

    Caluclate();
}