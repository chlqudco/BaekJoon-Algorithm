#include <iostream>
#include <string>
using namespace std;

string doc, search;

void Insert_And_Init() {
	getline(cin, doc);
	getline(cin, search);
}

bool IsMatched(int idx) {
	for (int i = 0; i < search.length(); i++){
		if (search[i] != doc[i + idx]) return false;
	}
	return true;
}

void Caluclate() {
	int doc_len = doc.length();
	int search_len = search.length();
	int cnt = 0;

	for (int i = 0; i <= doc_len - search_len; i++){
		if (IsMatched(i)) {
			i += search_len-1;
			cnt++;
		}
	}

	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Caluclate();
}
