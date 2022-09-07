#include <iostream>

using namespace std;

long long N;
long long max_clothes = 0;
long long people_num = 0;
void Insert_And_Init() {
	long long tmp;

	cin >> N;
	for (int i = 0; i < N; i++){
		cin>>tmp;
		max_clothes = max( max_clothes , tmp);
		people_num += tmp;
	}
}

void Calculate(){
	if ((people_num == 2 && max_clothes == 2) || (people_num > 2 && max_clothes > people_num/2)) cout << "Unhappy";
	else cout << "Happy";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Insert_And_Init();

	Calculate();
}