//ID부여 안하면 틀린다 
#include<iostream>
using namespace std;

//보드
int board[10][10] = {0};
//총점
int total = 0;
//타일이 들어있는 칸의 갯수
int tile_count = 0;
int id = 1;

void DownBlock(int t, int i, int j) {
	int k;
	//블럭 배치하고
	board[i][j] = id;

	//크기에 따라 다르게 놓기
	if (t==1){
		//블럭 내리기
		for (k = 4; k < 10; k++){
			//빈칸 찾는 도중 비어있고, 다음이 막혀있으면
			if (board[k][j] == 0 && (k==9 || board[k + 1][j] > 0)) {
				board[k][j] = id;
				board[i][j] = 0;
				break;
			}
		}
	}
	else if (t == 2) {
		board[i][j + 1] = id;
		//블럭 내리기
		for (k = 4; k < 10; k++) {
			//빈칸 찾는 도중 비어있고, 다음이 막혀있으면
			if (board[k][j]+board[k][j+1] == 0 && (k==9 || board[k + 1][j] >0 || board[k + 1][j+1] >0)) {
				board[k][j] = id;
				board[k][j+1] = id;
				board[i][j] = 0;
				board[i][j + 1] = 0;
				break;
			}
		}
	}
	else {
		board[i + 1][j] = id;
		//블럭 내리기
		for (k = 4; k < 10; k++) {
			//빈칸 찾는 도중 비어있고, 다음이 막혀있으면
			if (board[k][j]+ board[k+1][j] == 0 && (k == 8 || board[k + 2][j] >0)) {
				board[k][j] = id;
				board[k+1][j] = id;
				board[i][j] = 0;
				board[i + 1][j] = 0;
				break;
			}
		}
	}
}

void RightBlock(int t, int i, int j) {
	int k;
	//블럭 배치하고
	board[i][j] = id;

	//크기에 따라 다르게 놓기
	if (t == 1) {
		//블럭 옮기기
		for (k = 4; k < 10; k++) {
			//빈칸 찾는 도중 비어있고, 다음이 막혀있으면
			if (board[i][k] == 0 && (k == 9 || board[i][k+1] >0)) {
				board[i][k] = id;
				board[i][j] = 0;
				break;
			}
		}
	}
	else if (t == 2) {
		board[i][j + 1] = id;
		//블럭 옮기기
		for (k = 4; k < 10; k++) {
			//빈칸 찾는 도중 비어있고, 다음이 막혀있으면
			if (board[i][k]+ board[i][k+1] == 0 && (k == 8 || board[i][k + 2] >0)) {
				board[i][k] = id;
				board[i][k+1] = id;
				board[i][j] = 0;
				board[i][j + 1] = 0;
				break;
			}
		}
	}
	else {
		board[i + 1][j] = id;
		//블럭 옮기기
		for (k = 4; k < 10; k++) {
			//빈칸 찾는 도중 비어있고, 다음이 막혀있으면
			if (board[i][k]+ board[i+1][k] == 0 && (k == 9 || board[i][k + 1] >0 || board[i+1][k + 1] >0)) {
				board[i][k] = id;
				board[i+1][k] = id;
				board[i][j] = 0;
				board[i + 1][j] = 0;
				break;
			}
		}
	}
}

int GreenPoint() {
	for (int i = 6; i < 10; i++)
	{
		if (board[i][0] >0 && board[i][1] > 0 && board[i][2] > 0 && board[i][3] > 0) {
			total++;
			board[i][0] = 0;
			board[i][1] = 0;
			board[i][2] = 0;
			board[i][3] = 0;
			return i;
		}
	}
	return 0;
}

int BluePoint() {
	for (int i = 6; i < 10; i++)
	{
		if (board[0][i] > 0 && board[1][i] > 0 && board[2][i] > 0 && board[3][i] > 0) {
			total++;
			board[0][i] = 0; board[1][i] = 0; board[2][i] = 0; board[3][i] = 0;
			return i;
		}
	}
	return 0;

}

int RemainGreenBlock() {
	//옮길 수 있는지 확인
	for (int i = 4; i < 9; i++){
		for (int j = 0; j < 4; j++){
			//0, 3은 따로처리
			if (j == 0) {
				//아래칸 비어있고 오른칸이랑 번호 다르면 내려 
				if ((board[i][j] > 0) && (board[i][j + 1] != board[i][j]) && board[i + 1][j] == 0) {
					board[i + 1][j] = board[i][j];
					board[i][j] = 0;
					return 1;
				}
				//두칸 같고 아래 두칸 비었으면
				if (board[i][j] > 0 && board[i][j + 1] == board[i][j] && board[i + 1][j] == 0 && board[i + 1][j + 1] == 0) {
					board[i + 1][j] = board[i][j];
					board[i + 1][j + 1] = board[i][j];
					board[i][j] = 0;
					board[i][j + 1] = 0;
					return 1;
				}
			}
			else if (j == 3) {
				//아래칸 비어있고 왼칸이랑 번호 다르면 내려
				if (board[i][j] > 0 && (board[i][j - 1] != board[i][j]) && board[i + 1][j] == 0) {
					board[i + 1][j] = board[i][j];
					board[i][j] = 0;
					return 1;
				}
			}
			else {
				//아래칸 비어있고 오른칸 왼칸이랑 값 다르면 바꿔
				if (board[i][j] > 0 && (board[i][j + 1] != board[i][j]) && board[i + 1][j] == 0 && (board[i][j - 1] != board[i][j])) {
					board[i + 1][j] = board[i][j];
					board[i][j] = 0;
					return 1;
				}
				//두칸 같고 아래 두칸 비었으면
				if (board[i][j] > 0 && board[i][j + 1] == board[i][j] && board[i + 1][j] == 0 && board[i + 1][j + 1] == 0) {
					board[i + 1][j] = board[i][j];
					board[i + 1][j + 1] = board[i][j];
					board[i][j] = 0;
					board[i][j + 1] = 0;
					return 1;
				}
			}
		}
	}
	return 0;
}

int RemainBlueBlock() {
	//옮길 수 있는지 확인
	for (int i = 4; i < 9; i++) {
		for (int j = 0; j < 4; j++) {
			//0 , 3은 따로처리
			if (j == 0) {
				//아래칸이랑 값 다르고 오른칸 비어있으면 바꿔
				if (board[j][i] >0 && board[j][i + 1] == 0 && (board[j + 1][i] != board[j][i])) {
					board[j][i + 1] = board[j][i];
					board[j][i] = 0;
					return 1;
				}
				//아래칸이랑 값 같고 오른쪽 2칸 비어있으면
				if (board[j][i] > 0 && board[j][i] == board[j + 1][i] && board[j][i + 1] == 0 && board[j + 1][i + 1] == 0) {
					board[j][i + 1] = board[j][i];
					board[j + 1][i + 1] = board[j][i];
					board[j][i] = 0;
					board[j + 1][i] = 0;
					return 1;
				}
			}
			else if (j == 3) {
				//윗칸이랑 값 다르고 오른 비어있으면 내려
				if (board[j][i] > 0 && board[j][i + 1] == 0 && (board[j - 1][i] != board[j][i])) {
					board[j][i+1] = board[j][i];
					board[j][i] = 0;
					return 1;
				}
			}
			else {
				//윗칸 아래칸 값 다르고 오른칸 비어있으면 바꿔
				if (board[j][i] > 0 && board[j][i + 1] == 0 && (board[j + 1][i] != board[j][i]) && (board[j - 1][i] != board[j][i])) {
					board[j][i + 1] = board[j][i];
					board[j][i] = 0;
					return 1;
				}
				//아래칸이랑 값 같고 오른쪽 2칸 비어있으면
				if (board[j][i] > 0 && board[j][i] == board[j + 1][i] && board[j][i + 1] == 0 && board[j + 1][i + 1] == 0) {
					board[j][i + 1] = board[j][i];
					board[j + 1][i + 1] = board[j][i];
					board[j][i] = 0;
					board[j + 1][i] = 0;
					return 1;
				}
			}
			
		}
	}
	return 0;
}

void CheckPoint() {
	int line;
	//초록색 검사
	while (line=GreenPoint())
	{
		//점수 획득 했으면
		//한칸 씩 무조건 내려
		for (int i = line - 1; i >= 6; i--)
		{
			//덮어쓰기
			board[i + 1][0] = board[i][0];
			board[i + 1][1] = board[i][1];
			board[i + 1][2] = board[i][2];
			board[i + 1][3] = board[i][3];
			board[i][0] = 0; board[i][1] = 0; board[i][2] = 0; board[i][3] = 0;
		}
		

		//더 내릴수 있는지 확인?
		while (RemainGreenBlock());
		
	}
		
	//파란색 검사
	while(line = BluePoint())
	{
		for (int i = line - 1; i >= 6; i--)
		{
			//덮어쓰기
			board[0][i + 1] = board[0][i];
			board[1][i + 1] = board[1][i];
			board[2][i + 1] = board[2][i];
			board[3][i + 1] = board[3][i];
			board[0][i] = 0; board[1][i] = 0; board[2][i] = 0; board[3][i] = 0;
		}
		while (RemainBlueBlock());
	}
}

int GreenShadow() {
	if (board[5][0] >0 || board[5][1] > 0 || board[5][2] > 0 || board[5][3] > 0) return 1;
	else return 0;
}

int BlueShadow() {
	if (board[0][5] > 0 || board[1][5] > 0 || board[2][5] > 0 || board[3][5] > 0) return 1;
	else return 0;
}

void CheckShadowZone() {
	//초록색에 연한 부분 있는지
	while (GreenShadow()) {
		//연한 부분에 블럭 있으면 맨 아랫줄 삭제
		board[9][0] = 0; board[9][1] = 0; board[9][2] = 0; board[9][3] = 0;
		//덮어쓰기
		for (int i = 8; i >= 4; i--){
			board[i + 1][0] = board[i][0];
			board[i + 1][1] = board[i][1];
			board[i + 1][2] = board[i][2];
			board[i + 1][3] = board[i][3];
			board[i][0] = 0; board[i][1] = 0; board[i][2] = 0; board[i][3] = 0;
		}
		
		//더 내릴수 있는지 확인?
		while (RemainGreenBlock()) {
			CheckPoint();
		}
	}
	
	//파란색에 연한 부분 있는지
	while (BlueShadow()) {
		board[0][9] = 0; board[1][9] = 0; board[2][9] = 0; board[3][9] = 0;
		for (int i = 8; i >= 4; i--)
		{
			//덮어쓰기
			board[0][i + 1] = board[0][i];
			board[1][i + 1] = board[1][i];
			board[2][i + 1] = board[2][i];
			board[3][i + 1] = board[3][i];
			board[0][i] = 0; board[1][i] = 0; board[2][i] = 0; board[3][i] = 0;
		}
		//더 내릴수 있는지 확인?
		while (RemainBlueBlock()) {
			CheckPoint();
		}
	}
}

void CountTile() {
	//초록색 세기
	for (int i = 6; i < 10; i++){
		for (int j = 0; j < 4; j++){
			if (board[i][j] > 0) tile_count++;
		}
	}
	//파란색 세기
	for (int i = 0; i < 4; i++) {
		for (int j = 6; j < 10; j++) {
			if (board[i][j] > 0) tile_count++;
		}
	}
}


int main() { 
	//속도 증가
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

	int N,t,x,y;

	cin >> N;

	for (int i = 0; i < N; i++){
		cin >> t >> x >> y;
		//아래로 내리고
		DownBlock(t, x, y);
		//옆으로 옮기고
		RightBlock(t,x,y);
		//점수획득 검사 하고
		CheckPoint();
		//연한 칸 처리
		CheckShadowZone();
		//CheckPoint();
		
		id++;
	}
	//타일 갯수 세기
	CountTile();

	cout << total << "\n" << tile_count;
}