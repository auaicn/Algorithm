#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define INF (1987654321)

vector<pair<pair<int,int>,int> > v;
vector<int> rev[1010];
int dist[1010];
bool visit[1010];

void dfs(int x){
	visit[x] = true;
	for (int i=0;i<rev[x].size();i++){
		int next = rev[x][i];
		if(!visit[next])
			dfs(next);
	}
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	for (int t=0;t<T;t++){

		int N,M; scanf("%d %d",&N,&M);
		//init
		v.clear();
		for (int i=0;i<N;i++){
				dist[i] = INF;
				rev[i].clear();
				visit[i] = false;
			}
		dist[0] = 0;

		for (int i=0;i<M;i++){
			int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
			v.push_back({{left,right},weight});
			rev[right].push_back(left);
		}

		for (int k=0;k<N-1;k++){
			for (int i=0;i<M;i++){
				pair<pair<int,int>,int> edge = v[i];
				int left = edge.first.first;
				int right = edge.first.second;
				int weight = edge.second;
				if (dist[left]==INF)
					continue;
				else if(dist[right]>dist[left]+weight){
					dist[right] = dist[left] + weight;
				}
			}
		}

		dfs(0);

		bool sw = false;
		for (int i=0;i<M;i++){
			pair<pair<int,int>, int > edge = v[i];
			int left = edge.first.first;
			int right = edge.first.second;
			int weight = edge.second;
			if(dist[right]>dist[left]+weight){
				if(visit[right]){
					sw = true;
					break;
				}
			}
		}

		printf("Case #%d: ",t+1);
		if(sw)
			printf("possible\n");
		else
			printf("not possible\n");
	}
	return 0;
}