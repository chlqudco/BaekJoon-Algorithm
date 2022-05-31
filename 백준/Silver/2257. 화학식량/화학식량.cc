#include <iostream>
#include <stack>
using namespace std;

string str;
int H = 0, C = 0, O = 0;
stack<char> st;

void Insert_And_Init() {
	cin >> str;
}

void Caluclate() {
	int str_len = str.length();
	int ghcnt = 0;
	//전체 문자 돌면서
	for (int i = 0; i < str_len; i++){
		//여는 괄호일 경우
		if (str[i] == '(') {
			ghcnt++;
			st.push('(');
		}
		//닫는 괄호일 경우
		else if (str[i] == ')'){
			ghcnt--;
			//뒤에 숫자 있는경우
			if ((i + 1 != str_len) && str[i + 1] >= '2' && str[i + 1] <= '9') {
				
				//괄호 끝이면 스택에서 다꺼내기
				if (ghcnt == 0) {
					while (!st.empty()) {
						char top = st.top(); st.pop();
						if (top == '(') break;

						if (top == 'H') H += str[i + 1] - '0';
						else if (top == 'C') C += str[i + 1] - '0';
						else if (top == 'O') O += str[i + 1] - '0';
					}
				}
				//괄호가 남아있으면 옮기기
				else {
					stack<char> st2;
					while (!st.empty()) {
						char top = st.top(); st.pop();
						if (top == '(') break;
						for (int k = 0; k < str[i+1]-'0'; k++) st2.push(top);
					}
					while (!st2.empty()) {
						char top = st2.top(); st2.pop();
						 st.push(top);
					}
				}
				i++;
			}
			//숫자 없으면 괄호 없애기
			else {
				stack<char> st2;
				while (!st.empty()) {
					char top = st.top(); st.pop();
					if (top == '(') break;
					st2.push(top);
				}
				while (!st2.empty()) {
					char top = st2.top(); st2.pop();
					st.push(top);
				}
			}
		}
		//문자나 숫자인 경우
		else {
			//숫자면
			if(str[i]>='2' && str[i]<='9') {
				//괄호 있으면 그만큼 쳐넣기
				if (ghcnt > 0) {
					char top = st.top();
					for (int j = 0; j < str[i]-'1'; j++) st.push(top);
				}
				//없으면 앞의 문자 더하기
				else{
					if (str[i - 1] == 'H') H += (str[i] - '1');
					else if (str[i - 1] == 'C') C += (str[i] - '1');
					else if (str[i - 1] == 'O') O += (str[i] - '1');
				}
			}
			//문자면
			else {
				if (ghcnt > 0) st.push(str[i]);
				else {
					if (str[i] == 'H') H++;
					else if (str[i] == 'C') C++;
					else if (str[i] == 'O') O++;
				}
			}
		}
	}
	//스택에 남은 경우
	while (!st.empty()) {
		char top = st.top(); st.pop();
		if (top == 'H') H ++;
		else if (top == 'C') C ++;
		else if (top == 'O') O ++;
	}

	int result = H + O * 16 + C * 12;
	cout << result;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}