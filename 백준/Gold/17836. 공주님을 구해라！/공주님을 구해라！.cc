#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

typedef pair<int, int> p;

int N, M, T;
int map[101][101] = { 0 };
int timeMap[101][101] = { 0 };
bool isKnife = false;
int curTime = 0;

//BFS 재료
bool visited[101][101] = { false };
int dp[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
queue<p> que;
p knife;

void Insert_And_Init() {
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++) cin >> map[i][j];
    }
}

bool CanGo(int y, int x) {
    if (isKnife) {
        if (y >= 0 && x >= 0 && y < N && x < M && (visited[y][x] == false)) return true;
    }
    else {
        if (y >= 0 && x >= 0 && y < N && x < M && (visited[y][x] == false) && map[y][x] != 1) return true;
    }
    return false;
}

bool CanGo2(int y, int x) {
    if (y >= 0 && x >= 0 && y < N && x < M && (visited[y][x] == false) && map[y][x] != 1) return true;
    return false;
}

void BFS_no_sword(int y, int x) {
    bool knifeflag = false;

    visited[y][x] = true;
    que.push(make_pair(y, x));

    while (!que.empty()) {
        curTime++;
        int queLen = que.size();
        for (int i = 0; i < queLen; i++) {
            p tmp = que.front(); que.pop();

            for (int i = 0; i < 4; i++) {
                int nextY = tmp.first + dp[i][0];
                int nextX = tmp.second + dp[i][1];

                if (CanGo2(nextY, nextX)) {
                    visited[nextY][nextX] = true;
                    timeMap[nextY][nextX] = curTime;
                    que.push(make_pair(nextY, nextX));

                    if (nextY == N - 1 && nextX == M - 1) return;
                }
            }
        }
    }
}

void BFS(int y, int x) {
    bool knifeflag = false;

    visited[y][x] = true;
    que.push(make_pair(y, x));

    while (!que.empty()) {
        curTime++;
        int queLen = que.size();
        for (int i = 0; i < queLen; i++){
            p tmp = que.front(); que.pop();

            for (int i = 0; i < 4; i++) {
                int nextY = tmp.first + dp[i][0];
                int nextX = tmp.second + dp[i][1];

                if (CanGo(nextY, nextX)) {
                    if (map[nextY][nextX] == 2) {
                        isKnife = true;
                        knifeflag = true;
                        knife = make_pair(nextY, nextX);
                        memset(visited, false, sizeof(visited));
                        break;
                    }

                    visited[nextY][nextX] = true;

                    timeMap[nextY][nextX] = curTime;

                    que.push(make_pair(nextY, nextX));
                }
            }
            if (knifeflag == true) {
                while (!que.empty()) que.pop();
                que.push(knife);
                knifeflag = false;
                visited[knife.first][knife.second] = true;
                break;
            }
        }  
    }
}

void Caluclate() {
    BFS_no_sword(0, 0);

    //초기화
    int noSwordTime;
    if (visited[N - 1][M - 1] == true && timeMap[N - 1][M - 1] <= T) noSwordTime = timeMap[N - 1][M - 1];
    else noSwordTime = 999999;
    memset(visited, false, sizeof(visited));
    while (!que.empty()) que.pop();
    curTime = 0;


    BFS(0, 0);
    if (visited[N - 1][M - 1] == true && timeMap[N - 1][M - 1] <= T) cout << min(timeMap[N - 1][M - 1], noSwordTime);
    else cout << "Fail";
    
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << timeMap[i][j] << " ";
        }
        cout << "\n";
    }*/

    //cout << timeMap[N - 1][M - 1];

    //if (timeMap[N - 1][M - 1] <= T && timeMap[N - 1][M - 1] != 0) cout << timeMap[N - 1][M - 1];
   // else cout << "Fail";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Insert_And_Init();

    Caluclate();
}
