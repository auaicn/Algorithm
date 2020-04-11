#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF (1987654321)

vector<pair<int,int> > v[900];
bool visit[1000];
int dist[1000];
int dist2[1010];

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<M;i++){
		int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
		v[left].push_back({right,weight});
		v[right].push_back({left,weight});
	}

	int left,right; scanf("%d %d",&left,&right);

	for (int i=0;i<N;i++)
		dist[i+1]=dist2[i+1] = INF;

	dist[left] = 0;
	dist2[right] = 0;

	priority_queue<pair<int,int> > pq;
	pq.push({0,left});

	//dist
	while(!pq.empty()){
		pair<int,int> pos = pq.top(); pq.pop();
		int distance = pos.first; distance*=-1;
		int now = pos.second;
		if(visit[now])
			continue;
		else
			visit[now] = true;

		for (int i=0;i<v[now].size();i++){
			pair<int,int> temp = v[now][i];
			int next = temp.first;
			int weight = temp.second;
			
			if(visit[next])
				continue;

			if(dist[next]>distance+weight){
				dist[next] = distance+weight;
				pq.push({-dist[next],next});
			}
		}
	}

	//dist2
	for (int i=0;i<N;i++)
		visit[i+1] = false;

	pq.push({0,right});

	while(!pq.empty()){
		pair<int,int> pos = pq.top(); pq.pop();
		int distance = pos.first; distance*=-1;
		int now = pos.second;
		if(visit[now])
			continue;
		else
			visit[now] = true;

		for (int i=0;i<v[now].size();i++){
			pair<int,int> temp = v[now][i];
			int next = temp.first;
			int weight = temp.second;
			
			if(visit[next])
				continue;

			if(dist2[next]>distance+weight){
				dist2[next] = distance+weight;
				pq.push({-dist2[next],next});
			}
		}
	}
	if(dist[right]==INF)
		printf("-1\n");
	else if((dist[1]==INF&&dist2[1]==INF)||(dist[N]==INF&&dist2[N]==INF))
		printf("-1\n");
	else
		printf("%d\n",min(dist[1]+dist[right]+dist2[N],dist2[1]+dist2[left]+dist[N]));
	return 0;
}