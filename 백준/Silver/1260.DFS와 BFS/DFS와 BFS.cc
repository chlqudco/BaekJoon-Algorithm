#include<stdio.h>

typedef struct _queue{
	int arr[1001];
	int front;
	int rear;
}queue;

//인접행렬 방식
int graph[1001][1001]={0};
int dfs[1001]={0};
int bfs[1001]={0};
queue q;

void Queue_Init(){
	q.front=0;
	q.rear=0;
}

int IsEmpty(){
	if(q.front==q.rear) return 1;
	else return 0;
}

void Insert_Queue(int elem){
	q.arr[q.rear] = elem;
	q.rear++;
}

int Pop_Queue(){
	q.front++;
	return q.arr[q.front-1];
}

void DFS(int V,int N){
	int i;
	//시작지점 방문함 ㅋ
	dfs[V] = 1;

	printf("%d ",V);

	//점 돌면서
	 for(i=1;i<=N;i++){
		 //간선 있고 방문 안했으면
		 if(graph[V][i]==1 && dfs[i]==0){
			 //재귀
			 DFS(i,N);
		 }
	 }
}

void BFS(int V, int N){
	int i,elem;

	printf("%d ",V);
	//시작점 큐에 삽입
	Insert_Queue(V);
	//방문함.
	bfs[V] = 1;

	while(!IsEmpty()){
		//점 하나 꺼내서
		elem = Pop_Queue();

		//정점 ]돌면서
		for(i=1;i<=N;i++){
			//간선이 있고 방문 안했으면
			if(graph[elem][i]==1 && bfs[i]==0){
				//방문 표시
				bfs[i]=1;
				printf("%d ",i);
				//그 점 큐에 삽입
				Insert_Queue(i);
			}
		}
	}
}

int main(){
	int N,M,V;
	int i,a,b;


	scanf("%d %d %d",&N,&M,&V);

	for(i=0;i<M;i++){
		scanf("%d %d",&a,&b);
		//행렬에 간선표시
		graph[a][b]=1;
		graph[b][a]=1;
	}

	DFS(V,N);
	printf("\n");
	BFS(V,N);

	return 0;
}