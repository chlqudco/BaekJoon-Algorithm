---
- 시간 복잡도 정리
	- 시간 제한이 1초 일 때
	- N <= 500   -> O(N^3) 까지 가능
	- N <= 2,000 -> O(N^2) 까지 가능
	- N <= 100,000  -> O(NlogN) 까지 가능
	- N <= 10,000,000  -> O(N) 까지 가능

- int형 변수 10,000,000개 --> 40MB

---
- STL 정리
- 뒤부터 순회할땐 역반복자 사용해보기
- 같은? 자료구조 형식(선형, 트리형) 컨테이너는 비슷한 함수를 갖고 있음 
- 많은 컨테이너들은 생성시에 (숫자,숫자)를 써서 초기화가 됨


0. 연관 컨테이너 : set, multiset, map, multimap
	- 노드 기반, 균형 이진트리, 멤버 변수, 생성자가 다 비슷


1. set 컨테이너 : #include <set> a
	- 생성 : set<자료형> s;
	- 원소는 중복이 허용되지 않음
	- 자동 정렬, default 는 오름차순, 내림차순 하고 싶으면 set<string,greater<string>> s;
	- 중위 순회 하면 오름차순으로 순회 가능 (iterator 사용)
	- s.clear() : 모든 원소 제거
	- s.count(원소) : 있으면 1, 없으면 0
	- 삽입 : s.insert(원소)
	- 삭제 : s.erase(iter) : iter가 가르키는 원소 제거
	- 조회? : s.lower_bound(원소) : 원소가 시작하는 구간의 iter리턴?


2. list 컨테이너 : include<list>            https://blockdmask.tistory.com/76
	- 양방향 연결리스트 방식
	- 생성 : list<데이터 타입> 변수이름
		- 변수 이름 옆에(숫자) 쓰면 숫자만큼 0으로 초기화된 원소 가짐
		- 변수 이름 옆에(숫자, 숫자2) 쓰면 숫자만큼 숫자2로 초기화된 원소 가짐
	- 접근 : at이나 []로 접근 불가능, 반복자로 ++ or -- 해야됨
	- 삽입 : push 백 or front, insert(반복자,원소)..? 불편
	- 삭제 : remove(원소) : 값 원소 다삭제
		- erase(반복자) : 반복자가 가리키는 원소 삭제..? 뭔말?
	- 이외
		- 정렬 : sort() : 오름차순 정렬
		- 크기반환 : size()
		- 뒤집기 : reverse()


3. vector 컨테이너 : include<vector>
	- 메모리가 자동으로 할당되는 배열
	- 배열기반이라 중간에서 하는 삽입-삭제는 비효율적
	- 생성 : vector<데이터 타입> 변수이름
		- 변수 이름 옆에(숫자) 쓰면 숫자만큼 0으로 초기화된 원소 가짐
		- 변수 이름 옆에(숫자, 숫자2) 쓰면 숫자만큼 숫자2로 초기화된 원소 가짐
	- 접근 : 벡터.at(인덱스) 로 인덱스의 멤버 접근 가능
		- 벡터[인덱스]랑 똑같
		- 벡터.front() 나 벡터.back() 가능
	- 삽입 : 공식적으론 뒤로만 삽입 가능 
		- 중간에 넣기 : v.insert(idx,value) : idx위치에 밸류값 넣기
	- 삭제 : 공식적으론 뒤로만 삭제 가능
		- 중간값? 삭제 : v.erase(iter) : iter가 가르키는 원소 제거


4. deque 컨테이너 : #include <deque>
	- 벡터와 비슷한데 더 편리하다는 평가, 벡터를 쓸빠엔 deque를 쓰나? 아니지?
	- 생성 : deque<자료형> dq;
	- 초기화? : dq.assign(a,b) : b값으로 a개 원소 할당
	- 참조 : dq.at(인덱스) or dq[인덱스] : 참조 개꿀띠!
	- 참조 : dq.front() or dq.back()
	- 올삭제! : dq.clear()
	- 삽입 : dq.push_front(원소), dq.push_back(원소) or insert
	- 제거 : dq.pop_front() or dq.pop_back() or erase
	- iter는 begin, rbegin다 됨


5. map 컨테이너 : #include<map>
	- 생성 : map<자료형,자료형> m
	- key와 value가 쌍으로 저장되는 컨테이너
	- key는 중복이 불가능
	- key는 자동정렬(오름차순)
	- 삽입 : m.insert(make_pair(원소1,원소2))
	         - m[key] = value 로도 삽입 and 수정 가능
	- 함수는 set과 동일


6. queue 컨테이너 : #include <queue>
	- 생성 : queue<자료형> que;
	- FIFO(First In First Out) 구조
	- 삽입 : que.push(원소) 하면 맨뒤에 추가
	- 삭제 : que.pop() 하면 맨앞 삭제
	- 조회 : que.front(), que.back() 둘다 됨
	- iter못씀ㅋㅋ 도대체 왜쓰냐 얘는


7. stack 컨테이너 : #include <stack>
	- 생성 : stack<자료형> st;
	- LIFO(Last in First out) 방식
	- 삽입 : st.push(원소)
	- 삭제 : st.pop()


8. multiset 컨테이너 : #include<set>
	- 생성 : multiset<자료형> ms
	- 키값이 중복이 되는 setㅎㅎ; 뭐지
	- 나머지 함수는 set이랑 다 똑같



9. multimap 컨테이너 : #include<map>
	- 생성 : multimap<자료형1, 자료형2> mm
	- map이랑 다똑같은데 key값이 중복이 됨



999. priority_queue 컨테이너 : #include<queue>
	- 기본 값은 최대힙

	- 생성 : priority_queue< 자료형, vector<자료형>, (비교함수) > pq;
	- 비교함수
		- greater<int>는 내림차순
		- less<int>는 오름차순
		- 직접 만들기
		
		```
		struct compare
			{
				bool operator()(구조체& a, 구조체& b) {
					if (a.C != b.C) return a.C < b.C;
					return a.S > b.S;
				}
			};
		```

		- 간단하게 구현한 비교함수 bool cmp(T a, T b){return a < b;}
	- 야매 팁
		- 넣을때 -를 이용하면 어디선가 쓸모가 있다

---
- 헤더 정리

** iter1 과 iter2는 배열에서는 배열, 배열+크기 로 고쳐쓸 수 있다.

1. algorithm 라이브러리
	- find (iter1, iter2, value): iter1과 2 사이에 value값이 있으면 첫번째 값의 iter반환
		-ex)	int myints[] = {10, 20, 30, 40};
			int* p;

			p = std::find(myints, myints + 4, 30);
			if (p != myints + 4)
				std::cout << "Element found in myints: " << *p << '\n';
			else
				std::cout << "Element not found in myints\n";

			// using std::find with vector and iterator:
			std::vector<int> myvector(myints, myints + 4);
			std::vector<int>::iterator it;

			it = find(myvector.begin(), myvector.end(), 30);
			if (it != myvector.end())
				std::cout << "Element found in myvector: " << *it << '\n';
			else
				std::cout << "Element not found in myvector\n";

		- ex2) if(s.find(6)!=s.end())

		- find_if는 조건을 줄 수도 있음

	- count(iter1, iter2, value) : iter1과 2 사이에 있는 value의 개수
		-ex)	int myints[] = {10, 20, 30, 30, 20, 10, 10, 20};  // 8 elements
			int mycount = std::count(myints, myints + 8, 10);
			std::cout << "10 은 " << mycount << " 번 등장합니다.\n";

			// 컨테이너 안에 특정 원소의 개수를 셉니다.
			std::vector<int> myvector(myints, myints + 8);
			mycount = std::count(myvector.begin(), myvector.end(), 20);
		- count_if는 조건을 줄 수도 있음

	- swap(v1, v2) : 두 원소를 교환
	- iter_swap(i1, i2) : 두 반복자가 가르키는 원소를 교환

	- replace(iter1, iter2, v1, v2) : iter1과 2 사이에 v1인 값을 v2로 변환
		- ex)  replace(s.begin(), s.end(), 8, 88);

	- fill(iter1, iter2, v1) :  iter1과 2 사이 값을 모두 v1로 바꿈
		- ex) fill(myvector.begin(), myvector.begin() + 4, 5);

	-remove(iter1, iter2, v1) : iter1과 2 사이 v1값을 모두 맨뒤로 보내버림
		-실제로 지우려면 erase랑 같이  써야됨
		-ex)	std::string str1 = "Text with some   spaces";
			// 문자열에서 띄어쓰기를 모두 지운다.
			str1.erase(std::remove(str1.begin(), str1.end(), ' '), str1.end());

	-unique(iter1, iter2) : 중복 제거 ( 중복된 수들은 뒤로 보낸다 ), 정렬되어 있어야햄
		-ex) erase(unique(v.begin(), v.end()) , v.end()) : 중복 제거
	

	- reverse(?1, ?2) : ?1부터 ?2까지 뒤집음
		- ex)	std::vector<int> v{1, 2, 3};
			std::reverse(std::begin(v), std::end(v));

			int a[] = {4, 5, 6, 7};
			std::reverse(std::begin(a), std::end(a));


	- sort(iter1, iter2) : 오룸차순으로 정렬!
		- ex)	std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
			std::sort(s.begin(), s.end())

			//내림차순이 하고싶오?
			 std::sort(s.begin(), s.end(), std::greater<int>());
		- 객체 정렬은 몰라~ 검색해~

	- stable_sort(iter1, iter2) : 안정정렬, 사용방법은 검색 ㅎㅎ;;

	- nth_element(iter1, n? , iter2) : n번째? 원소 찾기
		- ex)	std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};

			std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
			std::cout << "중간값은 " << v[v.size() / 2] << '\n';

			std::nth_element(v.begin(), v.begin() + 1, v.end(), std::greater<int>());
			std::cout << "두 번째로 큰 원소는 " << v[1] << '\n';

	- 정렬된 원소들에 대해 작동하는 함수
		- lower_bound(iter1, iter2, v1) : v1 보다 크거나 같은 첫번째 원소의 인덱스 리턴,
		- upper_bound(iter1, iter2, v1) : v1보다 큰 첫번째 원소의 인덱스 리턴
		- binary_search(iter1, iter2, v1) : v1값이 있는지 이진탐색, 있으면 true, 없으면 false

	- set_union : 두 정렬된 원소의 합집합 반환, ㅇ떻게 쓰는지 모름

	- min : 최소값 찾음, 어덯게..?
	- min_element : 최소값 원소의 반복자를 리턴
	- *max_element(arr, arr+size) 같이 접근하면 편하지

	- 배열 합치는 알고리즘
		- int a[] = {1, 4, 5, 5, 8};
		 int b[] = {2, 3, 4, 7, 9};
		 vector<int> result(10);
	
		- merge(a,a+5,b,b+5,result.begin()) : a,b 합쳐서 result에 저장
		- iter=set_union(인자 위랑 같음) : 중복원소 없이 a,b 합침
		- iter=set_intersection : 교집합
		- iter=set_difference() : 차집합
		
		- set으로 시작하는 함수는 사이즈 교정 해줘야함 : result.resize(iter - result.begin());
			-set으로 시작하는 함수는 iter 반환

	- 배열 나누는 알고리즘
		- 참이면 앞쪽, 거짓이면 뒤쪽으로 보냄
		- 예시로는 홀수 짝수 나누기
		- 재료 : 함수 : bool isOdd(int n){ return n%2==1; }
		       : 배열 : int a[10] = {1, 2, 4, 5, 3, 6, 8, 5, 7, 9};
		- int *p = partition(a, a+10, isOdd);
		- 참인애들 접근 for(int i=0; i<p-a; i++), 거짓인애들 접근 for(int i=p-a; i<10; i++)

	- 조건에 맞는 모든 값을 특정한 값으로 바꿈 replace_if(), replace_if(a, a+10, isOdd, 7);


	


2. string 라이브러리



3. math.h
	-절대값 저장 편하게..




3. 야매? 팁
	- 붙어있는 숫자를 한글자식 끊어서 저장 scanf("%1d", &arr[i][j]);

	- 한줄 입력 받기 ; string헤더 넣고, getline(cin, str);

	- memset(배열, 0, sizeof(배열)) : 배열 0으로 초기화 
		- string.h 헤더 필요

	- 정렬 문제는 pq도 좋지만 lowe_bound를 잘 이용하자


---
- 알고리즘 정리

- 그리디
- 당장 눈앞의 이익에만 집중
1. 특정 조건으로 정렬해두면 구현이 쉬워지는 경우가 많다.
2. 많은 그리디는 동적플밍으로 풀수 있다.


그리디 두가지 속성 확인
1. 탐욕적 선택 속성 : 각 단계에서 우리가 선택한 답을 포함하는 최적해가 있는지
2. 최적 부분 구조 : 각 단계에서 최적선택을 했을때 전체 최적해를 구할 수 있는지


- 그리디를 써도 되는지에 대한 정당성을 입증 해야 함
	- ex) 거스름돈 문제는 작은 단위의 동전이 큰 단위의 배수 이므로 정당함
2839 설탕배달 : 5의 배수 될때까지 3 존나게 빼기
11399 ATM : 금방 끝나는 애부터 돈뽑기
11047 동전0 : 큰 가치 동전부터 존나 더하기
1931 회의실 배정 : 많이 회의 해야 되니까 일찍 끝나는 새끼부터 더하기
1026 보물 : 젤 큰것 끼리 먼저 더하기
1541 잃어버린 괄호 : 플러스 끼리 묶고 나중에 마이너스
5585 거스름돈 : 동전이랑 똑같음
2217 로프 : pq로 큰 밧줄부터 추가하면서 계산
10162 전자레인지 : 큰 분 부터 지정, 초단위 있으면 노
13305 주유소 : 나보다 싼곳 찾은뒤 가는데 드는 비용 더하기
1789 수들의 합 : 1부터 더한뒤 초과하면 끝
10610 30 : 30의 배수가 되는지 체크한뒤 되면 큰수부터 꺼내기
1946 신입사원 : 둘중 한 조건으로 정렬뒤 나보다 점수 낮은애로 갱신
1715 카드 정렬하기 : 작은 조각부터 합치기
1339 단어 수학 : 졸라 어려웡
1439 뒤집기 : 0에서1 or 1에서 0으로 바뀌는 지점 중 최소값
16953 A->B : dfs 완전탐색 
4796 캠핑 : 휴가길이 / P일 * L 한뒤 + 휴가길이 % P일
1202 보석 도둑 : 가치 내림차순 정렬하고 적절한 가방 찾기
1049 기타줄 : 순차탐색 하면서 가격 비교 하기
1744 수 묶기 : 도대체 내가 이걸 어떻게 품?
2864 5와 6의 차이 : 5를 6으로 다 바꾸기
1543 문서검색 : 맨앞에서부터 맞는지 보고 맞으면 길이만큼 더하기
1080 행렬 : 완전탐색 하면서 아니면 뒤집어
1449 수리공 항승 : 얘도 앞에서부터 탐색하면서 길이만큼 붙여
2437 저울 : 시작점 1로 두고 큰 추 부터 올리면서 만들 수 있는지 확인 
11000 강의실 배정 : 시작 시간 빠른것(그 다음 종료시간 빠른것)부터 정렬,
        그 다음 2개 pq 알아서 잘 비교
2720 세탁소 사장 동혁 : 평범한 거스름돈 문제

- 이진탐색
-코드 간단하니까 쳐 외우셈
	-떡볶이 떡 반복문 이진탐색 코드
	int result = 0; 
	while (start <= end) {
		long long int total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++) {
			// 잘랐을 때의 떡의 양 계산
			if (arr[i] > mid) total += arr[i] - mid; 
		}
		if (total < m) { // 떡의 양이 부족한 경우 더 많이 자르기(왼쪽 부분 탐색)
			end = mid - 1;
		}
		else { // 떡의 양이 충분한 경우 덜 자르기(오른쪽 부분 탐색)
			result = mid; // 최대한 덜 잘랐을 때가 정답이므로, 여기에서 result에 기록 
			start = mid + 1;
		}
	}
cout << result << '\n'

- 배열 or 이진탐색트리

- 말도 안되게 큰 수를 보면 이진 탐색을 의심해야함

- 뭐를 start, end, mid로 잡을지만 파악하면 문제가 너무 간단해짐

- 간단하게 값만 찾으려면 걍 binary_search 함수 검색
	- binary_search(A, A + N, target) : 있으면 1 반환

---  

- 세그먼트 트리

목적 : 여러개의 데이터의 특정 범위 합을 빠르게 구함

구간 내의 최소값과 최대값도 아주 빠르게 찾을수 있음 : 코드 다름

트리 크기는 데이터 개수 * 4 해야함

```
//구간 합 트리 생성
int make_tree(int s, int e, int node) {
	if (s == e) return tree[node] = arr[s];
	int mid = (s + e) / 2;
	return tree[node] = make_tree(s, mid, node * 2) + make_tree(mid + 1, e, node * 2 + 1);
}

//구간 합 구하는 알고리즘
int tree_sum(int s, int e, int node, int left, int right) {
	//예외 처리 : 범위를 벗어남
	if (left > e || right < s) return 0;

	//값이 범위안에 있음
	if (left <= s && e <= right) return tree[node];
	
	//아니면 나눠서 구하기
	int mid = (s + e) / 2;
	return tree_sum(s, mid, node * 2, left, right) + tree_sum(mid + 1, e, node * 2 + 1, left, right);
}

//특정 원소 값 수정 -> 해당 원소를 포함하고 있는 모든 구간 합 노드 갱신
void tree_update(int s, int e, int node, int index, int dif) {
	//예외 처리 : 범위를 벗어남
	if (index < s || index > e) return;

	//값이 범위안에 있으면 수정
	tree[node] += dif;

	//끝났으면 끝
	if (s == e) return;

	//아니면 나눠
	int mid = (s + e) / 2;
	tree_update(s, mid, node * 2, index, dif);
	tree_update(mid + 1, e, node * 2 + 1, index, dif);
}

```

---
- DP

반환값 이름(인자){
	//base case if(인자 == 특정값) return 특정값
	//return case if(dp[] != -1) return dp[]
	//recur case return dp[] = max?(이름(인자), 어쩌구 등등)
}

2579 계단오르기 : dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);

11053 가장 긴 증가하는 부분 수열 : 자기 이전까지의 원소 중 자기보다 작은 숫자 이면서 가장 긴 증가하는 수열 찾기
	for (int j = 0; j < i; j++) if (A[i] > A[j]) dp[i] = max(dp[i], dp[j] + 1);
		
1912 연속합 : 현재 숫자랑 여태 합만 비교하면 끝, 이유는 도저히 모르겠음
	dp[i] = max(dp[i-1] + arr[i], arr[i]); ans = max(ans, dp[i]);

10844 쉬운계단수 : dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]), 0와 9는 예외처리

2666 벽장문 : 3차원 dp에 쫄자.  dp[index][open1][open2] = open1과 open2번째의 벽장이 열려있을 때
			    index 단계의 벽장을 열기 위한 최소 이동횟수
	      2가지 경우중 최소값을 선택해야 함
		선택지 1 : open1으로 문을 열 경우, abs(open1 - target) + dp[index+1][target][open2]
		선택지 2 : open2으로 문을 열 경우, abs(open2 - target) + dp[index+1][open1][target]
	     이걸 어떻게 생각하냐고...

동전으로 특정값 만들 수 있는 개수 = 걍 외워
dp[0] = 1;
for (int j = 0; j < N; j++) {
	for (int k = coin[j]; k <= M; k++) dp[k] += dp[k - coin[j]];
}


메모이제이션 : 배열을 마련해두고, 한번 계산한 값을 저장해 뒀다가 재활용하는 기법
ex) int arr[10][10] = {-1};
    int 재귀(int a, int b){
    만약 배열에 값이 있거나, 베이스케이스면 리턴
    아니면 재귀
}
사용 가능한 경우 : 같은 입력에 항상 같은 값을 반환하는 경우.
1. base case를 젤 먼저 처리
2. 배열은 모두 -1로 초기화(반환값이 항상 0이상 일때)
	#include <string.h>
	memset(arr, -1, sizeof(arr));

푸는 방법
1. 재귀로 풀수 있는 완전탐색 알고리즘 만들기
2. 중복된 부분을 없애도록 메모이제이션 사용

dp 함수 예시
int findMax(int a, int b) {
    if (a == N-1) return arr[a][b];
    if (dp[a][b] != -1) return dp[a][b];
    return dp[a][b] = max(findMax(a + 1, b), findMax(a + 1, b + 1)) + arr[a][b];
}

동적 계획법 레시피(235p)
1. 완전 탐색 알고리즘 만들기
2. 부분 문제 정의 바꾸기
3. 중복 없애고 메모이제이션 활용


동적 계획법 코딩법(탑다운)
0. 함수의 반환값으로 나올 수 없는 값으로 배열 초기화
1. 항상 기저 사례를 먼저 처리

동적플밍은 최적화 문제를 찾기 위해 많이 쓴다
최적화 문제 : 여러 답중 가장 좋은 답을 찾는 문제
최적화 문제에 특정 성질이 적용하면 메모이제이션보다 효율적인 dp설계가 가능

-조건
	-큰 문제를 작은 문제로 나눌 수 있다
	-작은 문제의 정답은 더 큰 문제에서도 동일하다

-메모이제이션
	-한 번 구한 결과를 메모리 공간에 저장 해두는 것

-재귀 구현 (탑다운)
	-종료조건
	-메모리 확인
	-점화식

-반복문 구현(바텀업)
	-메모이제이션은 탑다운에서만 쓰는 말, 바텀업은 DP테이블이라고 부름

-DP와 분할정복의 차이
	-둘다 큰 문제를 작게 나누고 있음
	-DP는 나눈 문제들이 서로 영향을 끼침
  
- 다익스트라

-특정 노드에서의 최다 경로 구하는 알고리즘
- 음의 간선 없어야 함
-그리디 알고리즘임 (매번 가장 cost가 적은 길을 선택함으로)

-1. 출발 도시 설정
-2. 최단 거리 테이블(1차원 배열) 초기화
-3. 현재 도시 기준으로 방문안한 도시중 제일 cost 작은 노드 선택
-4. 테이블 갱신

-1. 코드 간결 -> 동작 느림 O(도시^2)
	-3번 과정에서 모든 리스트를 순차 탐색함

-2. 코드 복잡 -> 동작 빠름 O(간선log정점)
	-3번에서 우선순위큐 사용
	-왜 이걸 쳐 넣어도 시간초과가 나냐 도대체?



- 그래프
그래프 인접리스트 방식
vector<list<int>> adjacent;
adjacent[i] 는 정점 i와 연결된 정점들의 번호들을 담은 리스트

인접리스트 방식 DFS
vector<list<int>> adjacent;
vector<bool> visited;
void dfs(int here){
 //출력
 //visited[here]=true;
 for(int i=0;i<adj[here].size();i++){
  if(!visited[adj[here][i]]) dfs(there);
 }
}

그래프 인접행렬 방식
vector<vector<bool>> adjacent
adjacent[i][j]는 정점 i와 정점j가 연결되어있는지


vector 초기화
vector<bool> visited;
visited = vector<bool>(adj.size(),false);

---
 - 소수 판별 함수
 bool isPrimeNumber(int x) {
    // 2부터 x의 제곱근까지의 모든 수를 확인하며
    for (int i = 2; i <= (int) sqrt(x); i++) {
        // x가 해당 수로 나누어떨어진다면
        if (x % i == 0) {
            return false; // 소수가 아님
        }
    }
    return true; // 소수임
}

- 에라토스테네스의 체 : 소수 여러개 찾기 알고리즘
int n = 1000; // 2부터 1,000까지의 모든 수에 대하여 소수 판별
// 처음엔 모든 수가 소수(True)인 것으로 초기화(0과 1은 제외)
vector<int> arr(n + 1, true);

int main() {
    // 에라토스테네스의 체 알고리즘 수행
    // 2부터 n의 제곱근까지의 모든 수를 확인하며
    for (int i = 2; i <= (int) sqrt(n); i++) {
        // i가 소수인 경우(남은 수인 경우)
        if (arr[i] == true) {
            // i를 제외한 i의 모든 배수를 지우기
            int j = 2;
            while (i * j <= n) {
                arr[i * j] = false;
                j += 1;
            }
        }
    }
    // 모든 소수 출력
    for (int i = 2; i <= n; i++) {
        if (arr[i]) cout << i << ' ';
    }
}
