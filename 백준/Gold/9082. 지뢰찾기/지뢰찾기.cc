#include <iostream>
using namespace std;

int T, N, result =0;
int num[101];
string mine;
bool isMine[101] = { false };

void Insert_And_Init() {
    cin >> T;
}

bool isWell(int idx) {
    int cnt = 0;
    if (idx == 0) {
        if (isMine[idx]) cnt++;
        if (isMine[idx + 1]) cnt++;
    }
    else if (idx == N-1) {
        if (isMine[idx]) cnt++;
        if (isMine[idx - 1]) cnt++;
    }
    else {
        if (isMine[idx - 1]) cnt++;
        if (isMine[idx]) cnt++;
        if (isMine[idx + 1]) cnt++;
    }
    if (num[idx] == cnt) return true;
    return false;
}

bool isMatch(int idx) {
    for (int i = 0; i < idx; i++){
        if (!isWell(i)) return false;
    }
    return true;
}

void BuildMine(int idx) {
    //base case
    if (idx == N) {
        int cnt = 0;
        if (isMatch(idx)) {
            for (int i = 0; i < N; i++) if (isMine[i]) cnt++;
            result = max(result, cnt);
        }
        return;
    }

    //무조건 설치면
    if (isMine[idx] && isMatch(idx)) BuildMine(idx + 1);

    //무적건은 아니면
    else {
        //1. 설치하고 이전까지 짝짝꿍인지 확인
        isMine[idx] = true;
        //잘 맞으면 설치하고 진행
        if (isMatch(idx)) BuildMine(idx + 1);
        //안맞으면 설치 취소하고 진헤
        else {
            isMine[idx] = false;
            BuildMine(idx + 1);
        }
    }
}

void Caluclate() {
    string tmpnum;
    for (int i = 0; i < T; i++){
        cin >> N;

        //초기화
        result = 0;
        for (int j = 0; j < 101; j++) isMine[j] = false;

        //입력
        cin >> tmpnum;
        for (int j = 0; j < N; j++) num[N - j - 1] = tmpnum[N - j - 1] - '0';

        cin >> mine;
        for (int j = 0; j < N; j++) if (mine[j] == '*') isMine[j] = true;

        //첫칸에 무적건 설치면 설치로만 진행
        if (isMine[0]) {
            BuildMine(1);
        }
        //아니면 둘다 진행
        else {
            isMine[0] = true;
            BuildMine(1);
            isMine[0] = false;
            BuildMine(1);
        }
        cout << result<<"\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    Insert_And_Init();

    Caluclate();
}
