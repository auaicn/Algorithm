#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF (11987654321)

vector<pair<int,int> > v[50010];
vector<int> flight[50010];

int min(int x, int y){
	return x<y?x:y;
}

long long dist[50010];
bool visit[50010];

int main(int argc, char const *argv[])
{
	int N,M,F,S,E; scanf("%d %d %d %d %d",&N,&M,&F,&S,&E);
	for (int i=0;i<M;i++){
		int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
		v[left].push_back({right,weight});
		v[right].push_back({left,weight});
	}
	for (int i=0;i<F;i++){
		int left,right; scanf("%d %d",&left,&right);
		flight[left].push_back(right);
	}

	for (int i=0;i<N;i++)
		dist[i] = INF;
	dist[S] = 0;

	priority_queue<pair<long long,pair<int,bool> > > pq;
	pq.push({0,{S,false}});

	while(!pq.empty()){
		pair<long long,pair<int,bool> > pos = pq.top(); pq.pop();
		long long distance = pos.first; distance*=-1; 
		pair<int,bool> temp = pos.second;
		int now = temp.first; 
		bool used = temp.second;

		if(now == E){
			break;
		}

		if(visit[now]) 
			continue;
		else
			visit[now] = true;

		//printf("%4d%4d%4d\n",distance,now,used);

		for (int i=0;i<v[now].size();i++){
			pair<int,int> next = v[now][i];
			int next_x = next.first;
			int edge_weight = next.second;
			if(visit[next_x])
				continue;

			if(dist[next_x]>distance+edge_weight){
				dist[next_x] = distance + edge_weight;
				pq.push({-(distance+edge_weight),{next_x,used}});
			}
		}

		if(!used){
			for (int i=0;i<flight[now].size();i++){
				int next = flight[now][i];
				if(visit[next])
					continue;
				else if(distance<dist[next]){
					dist[next] = dist[now];
					pq.push({-distance,{next,true}});
				}
			}
		}
	}
	printf("%lld\n",dist[E]);
	return 0;
}