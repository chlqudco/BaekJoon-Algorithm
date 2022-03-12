#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, int> p2;

int R, C, T;
int map[51][51] = { 0 };
int tmpmap[51][51] = { 0 };
int dp[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

vector<int> robot;
queue<p2> dust;

void Insert_And_Init() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++){
            cin >> map[i][j];
            //로봇 청소기 일 경우
            if (map[i][j] == -1) robot.push_back(i);
            //먼지 일 경우
            if (map[i][j] > 0) dust.push(make_pair(make_pair(i, j), map[i][j]));
        }
    }
}

bool CanGo(int y, int x) {
    if (y >= 0 && x >= 0 && y < R && x < C && map[y][x] != -1) return true;
    return false;
}

void dustdiffusion() {
    
    //큐 크기 만큼 돌면서 확산
    while(!dust.empty()){
        //현재 값 불러오기
        p2 cur = dust.front(); dust.pop();

        //확산 되는 양
        int value = (int)(cur.second / 5.0);
        int cnt = 0;

        //진짜 확산
        for (int i = 0; i < 4; i++) {
            int nextY = cur.first.first + dp[i][0];
            int nextX = cur.first.second + dp[i][1];

            //갈수 있으면 전달
            if (CanGo(nextY, nextX)) {
                cnt++;
                tmpmap[nextY][nextX] += value;
            }
        }
        //남은거
        tmpmap[cur.first.first][cur.first.second] += (cur.second - (value * cnt));
    }
    //먼지 정보 업데이트
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            map[i][j] = tmpmap[i][j];
        }
    }
    map[robot[0]][0] = -1;
    map[robot[1]][0] = -1;
}

void DoDustRobot() {
    //위쪽
    map[robot[0] - 1][0] = 0;
    for (int i = robot[0]-2; i >= 0; i--){
        map[i+1][0] = map[i][0];
        map[i][0] = 0;
    }
    for (int i = 1; i < C; i++){
        map[0][i - 1] = map[0][i];
        map[0][i] = 0;
    }
    for (int i = 1; i <= robot[0]; i++){
        map[i - 1][C - 1] = map[i][C - 1];
        map[i][C - 1] = 0;
    }
    for (int i = C-2; i > 0; i--){
        map[robot[0]][i + 1] = map[robot[0]][i];
        map[robot[0]][i] = 0;
    }

    //아래쪽
    map[robot[1] + 1][0] = 0;
    for (int i = robot[1]+2; i < R; i++){
        map[i - 1][0] = map[i][0];
        map[i][0] = 0;
    }
    for (int i = 1; i < C; i++){
        map[R - 1][i - 1] = map[R - 1][i];
        map[R - 1][i] = 0;
    }
    for (int i = R-2; i >= robot[1]; i--){
        map[i + 1][C - 1] = map[i][C - 1];
        map[i][C - 1] = 0;
    }
    for (int i = C-2; i > 0; i--){
        map[robot[1]][i + 1] = map[robot[1]][i];
        map[robot[1]][i] = 0;
    }


    //먼지 정보 업데이트
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] > 0) dust.push(make_pair(make_pair(i, j), map[i][j]));
        }
    }
}

void Caluclate() {
    while (T > 0) {
        //1. 먼지 확산
        dustdiffusion();
        
        //2. 공기 청청기 작동
        DoDustRobot();

        //시간 줄이기
        T--;

        //초기화
        memset(tmpmap, 0, sizeof(tmpmap));

        //cout << "\n\n\n\n";
        ////출력
        //for (int i = 0; i < R; i++) {
        //    for (int j = 0; j < C; j++) {
        //        cout << map[i][j] << "  ";
        //    }
        //    cout << "\n";
        //}
    }

    int total = 0;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            total += map[i][j];
        }
    }
    cout << total + 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Insert_And_Init();

    Caluclate();
}
