#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> p;

int N;
char map[7][7];
bool result = false;
vector<p> teacher;

void Insert_And_Init() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			if (map[i][j] == 'T') teacher.push_back(make_pair(i, j));
		}
	}
}

void dfs(int cnt) {
	//3개 다 세운 경우
	if (cnt == 3) {
		int size = teacher.size();
		bool flag = true;
		for (int i = 0; i < size; i++){
			p cur = teacher[i];
			int y = cur.first;
			int x = cur.second;

			//상
			for (int j = y; j >= 0; j--){

				if (map[j][x] == 'O') break;

				//학생이면 노
				if (map[j][x] == 'S') {
					flag = false;
					break;
				}
			}

			//하
			for (int j = y; j < N; j++) {

				if (map[j][x] == 'O') break;

				//학생이면 노
				if (map[j][x] == 'S') {
					flag = false;
					break;
				}
			}

			//좌
			for (int j = x; j >=0 ; j--) {

				if (map[y][j] == 'O') break;

				//학생이면 노
				if (map[y][j] == 'S') {
					flag = false;
					break;
				}
			}

			//우
			for (int j = x; j < N; j++) {

				if (map[y][j] == 'O') break;

				//학생이면 노
				if (map[y][j] == 'S') {
					flag = false;
					break;
				}
			}
		}
		if (flag) result = true;
		return;
	}


	//3개 다 안세운 경우
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'X') {
				//벽세우기
				map[i][j] = 'O';
				dfs(cnt + 1);
				//벽 허물기
				map[i][j] = 'X';
			}
		}
	}
}

void Caluclate() {
	//3개의 벽 설치
	dfs(0);

	if (result) cout << "YES";
	else cout << "NO";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}