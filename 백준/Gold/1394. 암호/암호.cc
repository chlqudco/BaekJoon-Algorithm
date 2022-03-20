#include <iostream>
#include <map>
using namespace std;

//첫번째 줄
string amho;
//두번째 줄
string amho2;

//암호 길이
int amholen,amholen2;

//첫번째 줄 암호 저장
map<char, int> m;

void Insert_And_Init() {
	cin >> amho;
	amholen = amho.length();
	for (int i = 0; i < amholen; i++) m[amho[i]] = i + 1;
	cin >> amho2;
	amholen2 = amho2.length();
}

void Calculate() {
	long long total = 0;
	long long cnt = 1;
	//뒤에서 부터 순회
	for (int i = amholen2 - 1; i >= 0; i--) {
		char cur = amho2[i];
		if (m[cur] == 0) {
			cout << 0;
			return;
		}
		total += (cnt * m[cur]);
		cnt *= amholen;
		cnt = (cnt % 900528);
	}
	cout << total%900528;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}