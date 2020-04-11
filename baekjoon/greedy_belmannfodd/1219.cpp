#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define INF (1987654321)

vector<pair<pair<int,int>,long long> > v;
vector<int> rev[110];
bool visit[110];
long long earn[110];
long long dist[110];

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
	int N,S,E,M; scanf("%d %d %d %d",&N,&S,&E,&M);
	for (int i=0;i<M;i++){
		int left,right; long long weight;scanf("%d %d %lld",&left,&right,&weight);
		v.push_back({{left,right},weight});
		rev[right].push_back(left);
	}
	for (int i=0;i<N;i++)
		scanf("%lld",&earn[i]);

	// find nodes that is reachable to end point E
	dfs(E);
	
	for (int i=0;i<N;i++)
		dist[i] = INF;
	dist[S] = -earn[S];

	for (int k=0;k<N-1;k++){
		for (int i=0;i<M;i++){
			pair<pair<int,int>,int> pos = v[i];
			int left = pos.first.first;
			int right = pos.first.second;
			int weight = pos.second;
			if(dist[left]==INF)
				continue;
			else if (dist[right]>dist[left]+weight-earn[right])
				dist[right] = dist[left]+weight-earn[right];
		}
	}

	bool sw = false;
	for (int i=0;i<M;i++){
		pair<pair<int,int>,long long> pos = v[i];
		int left = pos.first.first;
		int right = pos.first.second;
		long long weight = pos.second;
		if(dist[left]==INF)
			continue;
		else if (dist[right]>dist[left]+weight-earn[right])
			if(visit[right])
				sw = true;
	}

	// output

	if(!visit[S])
		printf("gg\n");
	else if (sw)
		printf("Gee\n");
	else 
		printf("%lld\n",-dist[E]);

	return 0;
}
/*
5 0 4 4
0 4 1
1 2 1
2 3 1
3 1 1
10 100 200 300 10000


5 0 4 5
0 4 1
0 1 1
1 2 1
2 3 1
3 1 1
10 100 200 300 10000

5 0 4 6
0 4 1
0 1 1
1 2 1
2 3 1
3 1 1
3 4 1
10 100 200 300 10000

5 0 4 5
0 4 1
1 2 1
2 3 1
3 1 1
3 4 1
10 100 200 300 10000



*/