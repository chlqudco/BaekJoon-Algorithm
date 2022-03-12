#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;
map<int,int> ms;

void Insert_And_Init() {
    int tmp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        //해당 값의 인덱스와 몇번 나오는지
        ms[tmp]++;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
}

void Caluclate() {
    int total = 0;
    if (N <= 2) {
        cout << total;
        return;
    }
   //모든 원소를 돌믄서
    for (int i = 0; i < N-1; i++){
        for (int j = i + 1; j < N; j++) {
            //둘중 0이 있으면 예외처리
            if (v[j] == 0 || v[i] == 0) {
                if (v[j] == 0 && v[i] == 0 && ms[0] == 2) continue;
                else if (ms[v[i] + v[j]] == 1) continue;
            }
            total += ms[v[i] + v[j]];
            ms[v[i] + v[j]] = 0;
        }
    }

    cout << total;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Insert_And_Init();

    Caluclate();
}
