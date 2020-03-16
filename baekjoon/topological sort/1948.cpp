#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int indegree[10010];
int time_cost[10010];

bool visit[10010];

vector<pair<int,int> > v[10010];
vector<int> r[10010];

int main(int argc, char const *argv[])
{

	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<M;i++){
		int from,to,weight; scanf("%d %d %d",&from,&to,&weight);
		v[from].push_back({to,weight});
		indegree[to]++;
	}
	int S,E; scanf("%d %d",&S,&E);

	queue<int> q; q.push(S); 
	while(!q.empty()){
		int pos = q.front(); q.pop();

		// maybe r not be needed

		for (int i=0;i<v[pos].size();i++){
			int next = v[pos][i].first;
			int weight = v[pos][i].second;

			indegree[next]--;
			if(!indegree[next])
				q.push(next);

			if(time_cost[next]>time_cost[pos]+weight)
				continue;
			else if(time_cost[next]==time_cost[pos]+weight)
				r[next].push_back(pos);
			else{
				// time_cost renewed
				time_cost[next] = time_cost[pos]+weight;
				r[next].clear();
				r[next].push_back(pos);
			}

		}
	}

	printf("%d\n",time_cost[E]);

	int res = 0;

	q.push(E); visit[E] = true;
	while(!q.empty()){
		int pos = q.front(); q.pop();
		for (int i=0;i<r[pos].size();i++){
			int next = r[pos][i];
			res++;
			if(!visit[next]){
				q.push(next);
				visit[next] = true;
			}
		}
	}

	printf("%d\n",res);
	return 0;
}

/*
5 5
1 2 7
2 4 100
4 5 1000
2 3 1001
3 5 99
1
5
*/