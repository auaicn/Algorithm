#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

#define INF (1987654321)

using namespace std;

int time_cost[510];
int indegree[510];
int dist[510];
int result[510];

vector<int> v[510];

int max(int x, int y){
	return x>y?x:y;
}

int min(int x, int y){
	return x<y?x:y;
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);

	for (int i=0;i<N;i++)
		dist[i+1] = -1;

	for (int i=0;i<N;i++){
		scanf("%d",&time_cost[i+1]);

		int temp;
		while(scanf("%d",&temp),temp!=-1){
			indegree[i+1]++;
			v[temp].push_back(i+1);
		}
	}


	queue<int> q;
	for (int i=0;i<N;i++)
		if(!indegree[i+1]){
			q.push(i+1);
			dist[i+1] = 0;
		}

	while(!q.empty()){
		
		int pos = q.front(); q.pop(); result[pos] = dist[pos]+time_cost[pos];

		for (int i=0;i<v[pos].size();i++){
			int next = v[pos][i];
			indegree[next]--;
			dist[next] = max(dist[next],result[pos]);

			if(!indegree[next]){
				q.push(next);
			}

		}
	}

	for (int i=0;i<N;i++)
		printf("%d\n",result[i+1]);

	return 0;

}