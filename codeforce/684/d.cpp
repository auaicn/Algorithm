#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v[100010];
int num_neighbor[100010];
bool visit[100010];

queue<int> q;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,M,K; scanf("%d %d %d",&N,&M,&K);
		// K-neighbors subsets 구할거다.

		// initialize
		for (int i=0;i<N;i++){
			v[i+1].clear();
			num_neighbor[i+1] = 0;
			visit[i+1] = false; 
		}

		// scan
		for (int i=0;i<M;i++){
			int left,right; scanf("%d %d",&left,&right);
			v[left].push_back(right);
			v[right].push_back(left);
			num_neighbor[left]++;
			num_neighbor[right]++;
		}
		// neightbor 을 줄일 것이다.
		// 될떄까지인데, M 번 돌겠..지?
		// N 개를 스캔하면서 없으면, neighbor을 줄여주는 식으로, 또 터진놈 있으면,
		// 터진놈잇으면 queue 에 넣고, 
		int left = N;
		for (int i=0;i<N;i++){
			if(num_neighbor[i+1] < K){
				q.push(i+1);
				visit[i+1] = true;
				left--;
			}
		}
		while(!q.empty()){
			int pos = q.front(); q.pop();
			for (int i=0;i<v[pos].size();i++){
				int next = v[pos][i];
				if(visit[next])
					continue;
				num_neighbor[next]--;
				if(num_neighbor[next]<K){
					q.push(next);
					visit[next] = true;
					left--;
				}
			}
		}
		// at least K neighbor 하다는 것은 size at least K+1 이라는 뜻이 아니겠니. 최소한이지만.
		if(left >= K+1){
			printf("subset\n");
			printf("1\n");
			for (int i=0;i<N;i++)
				if(visit[i+1])
					continue;
				else
					printf("%d ",i+1);
			printf("\n");
			continue;
		}
		printf("-1\n");
	}
	return 0;
}

