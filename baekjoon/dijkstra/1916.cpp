#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF (1987654321)

int dist[1010];
bool visit[1010];

vector<pair<int,int> > v[1010];

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<M;i++){
		int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
		v[left].push_back({right,weight});
		//v[right].push_back({left,weight});
	}
	int S,E; scanf("%d %d",&S,&E);

	for (int i=0;i<N;i++)
		dist[i+1] = INF;
	dist[S] = 0;

	priority_queue<pair<int,int> > pq;
	pq.push({0,S}); 

	while(!pq.empty()){

		pair<int,int> pos = pq.top(); pq.pop();
		int now = pos.second;
		int distance = pos.first; distance *= -1;
		if(visit[now])
			continue;
		else
			visit[now] = true;

		for (int i=0;i<v[now].size();i++){
			int next = v[now][i].first;
			int weight = v[now][i].second;
			if(visit[next])
				continue;
			else if(dist[next]>distance+weight){
				dist[next] = distance+weight;
				pq.push({-dist[next],next});
			}
		}
	}

	printf("%d\n",dist[E]);
	return 0;
}