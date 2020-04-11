#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

#define INF (1987654321)

bool visit[20010];
int dist[20010];
vector<pair<int,int> > v[20010];

int min(int x, int y){
	return x<y?x:y;
}

int main(int argc, char const *argv[])
{
	int V,E; scanf("%d %d",&V,&E);
	int S; scanf("%d",&S);
	for (int i=0;i<E;i++){
		int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
		v[left].push_back({right,weight});
	}

	for (int i=0;i<V;i++)
		dist[i+1] = INF;
	dist[S] = 0;

	priority_queue<pair<int,int> > pq;
	pq.push({0,S});

	while(!pq.empty()){

		pair<int,int> pos = pq.top(); pq.pop();
		int x = pos.second;
		int weight = -pos.first;

		if(visit[x])
			continue;

		visit[x] = true;
		
		dist[x] = weight;

		for (int i=0;i<v[x].size();i++){

			pair<int,int> now = v[x][i];
			int next = now.first;
			int weight_ = now.second;

			if(visit[next])
				continue;
			dist[next] = min(dist[next],weight+weight_);
			pq.push({-dist[next],next});

		}
	}

	for (int i=0;i<V;i++)
		if(dist[i+1]==INF)
			printf("INF\n");
		else
			printf("%d\n",dist[i+1]);

	/* code */
	return 0;
}

/*
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
*/