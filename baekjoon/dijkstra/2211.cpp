#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF (1987654321)

vector<pair<int,int> > v[1010];
int dist[1010];
int parent[1010];

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<M;i++){
		int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
		v[left].push_back({right,weight});
		v[right].push_back({left,weight});
	}

	for (int i=0;i<N;i++)
		dist[i+1] = INF;

	priority_queue<pair<int,int> > pq;
	pq.push({0,1}); dist[1] = 0;

	while(!pq.empty()){
		pair<int,int> pos = pq.top(); pq.pop();
		int now = pos.second;

		for (int i=0;i<v[now].size();i++){
			pair<int,int> next_ = v[now][i];
			int next = next_.first;
			int weight_ = next_.second;
			if(dist[next]>dist[now]+weight_){
				dist[next] = dist[now] + weight_;
				parent[next] = now;
				pq.push({-dist[next],next});
			}
		}
	}

	printf("%d\n",N-1);

	for (int i=1;i<N;i++){
		printf("%d %d\n",i+1,parent[i+1]);
	}

	return 0;
}