#include <iostream>
#include <queue>
using namespace std;

//끝시간, 시작시간, 옮기는양
typedef pair<int, pair<int, int>> p;

int N, M, totalBox;
//끝시간을 기준으로 오름차순
priority_queue<p, vector<p>, greater<p>> pq;
int boxdest[2001] = { 0 };

void Insert_And_Init() {
    int a, b, c;
    cin >> N >> totalBox >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        pq.push(make_pair(b, make_pair(a, c)));
    }
}

void Caluclate() {
    int totalSend = 0;

    //큐 빌 때까지
    while (!pq.empty()) {
        //현재 원소 가져와
        p cur = pq.top(); pq.pop();

        //얼마큼 가져갈수 있는지 조사해
        int canBring = cur.second.second;
        for (int i = cur.second.first; i < cur.first; i++) canBring = min(canBring, totalBox - boxdest[i]);
        
        //그만큼을 추가하고 더해
        for (int i = cur.second.first; i < cur.first; i++) boxdest[i] += canBring;
        totalSend += canBring;
    }

    cout << totalSend;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Insert_And_Init();

    Caluclate();
}