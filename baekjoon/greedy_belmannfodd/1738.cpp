#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define INF (1987654321)

vector<pair<pair<int,int>,int> > v;
vector<int> res[110];
int dist[110];
int _prev[110];
bool visit[110];

void dfs(int x){
	visit[x] = true;
	for (int i=0;i<res[x].size();i++){
		int next = res[x][i];
		if(!visit[next])
			dfs(next);
	}
}


int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<M;i++){
		int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
		v.push_back({{left,right},-weight});
		res[right].push_back(left);
	}

	for (int i=0;i<N;i++)
		dist[i+1] = INF;

	dfs(N);

	dist[1] = 0;
	int num = N-1;
	while(num--){
		for (int i=0;i<M;i++){
			pair<pair<int,int>,int> lookup = v[i];
			int left = lookup.first.first;
			int right = lookup.first.second;
			int weight = lookup.second;
			if(dist[left]==INF)
				continue;
			else if (dist[right]>dist[left]+weight){
				_prev[right] = left;
				dist[right] = dist[left]+weight;
			}
		}
		/*
		for (int i=0;i<N;i++)
			printf("%4d",dist[i+1]);
		printf("\n");
		*/

	}

	bool sw = false;
	for (int i=0;i<M;i++){
		pair<pair<int,int>,int> lookup = v[i];
		int left = lookup.first.first;
		int right = lookup.first.second;
		int weight = lookup.second;
		if(dist[left]==INF)
			continue;
		else if(dist[right]>dist[left]+weight)
			if(visit[right]){
				sw = true;
				break;
			}
	}
	/*
	for (int i=0;i<N;i++)
		printf("%4d",_prev[i+1]);
	printf("\n");
	*/
	if(sw||dist[N]==INF){
		printf("-1\n");
		return 0;
	}

	stack<int> s;
	s.push(N);
	while(true){
		int top_ = s.top();
		int next = _prev[top_];
		s.push(next);
		if(next==1)
			break;
	}

	while(!s.empty()){
		printf("%d ",s.top());s.pop();
	}
	printf("\n");

	return 0;
}