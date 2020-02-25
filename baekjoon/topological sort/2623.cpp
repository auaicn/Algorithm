#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int indegree[1010];
vector<int> v[1010];
vector<int> result;

int main(){

	int N,M; scanf("%d %d",&N,&M); // N upto 1,000 and M upto 100
	for (int i=0;i<M;i++){
		
		int K; scanf("%d",&K);

		int from; scanf("%d",&from);
		for (int j=0;j<K-1;j++){
			int to; scanf("%d",&to);
			v[from].push_back(to);
			indegree[to]++;
			from = to;
		}
	}

	int num=0;
	queue<int> q;
	for (int i=0;i<N;i++)
		if(!indegree[i+1])
			q.push(i+1);

	while(!q.empty()){
		int pos = q.front();q.pop(); result.push_back(pos); num++;
		for (int i=0;i<v[pos].size();i++){
			int next = v[pos][i];
			indegree[next]--;
			if(!indegree[next])
				q.push(next);
		}

	}
	
	/*
	for (int i=0;i<N;i++){
		printf("%d : ",i+1);
		for (int j=0;j<v[i+1].size();j++)
			printf("%4d ",v[i+1][j]);
		printf("\n");
	}
	*/

	if(num!=N)
		printf("0\n");
	else
		for (int i=0;i<N;i++)
			printf("%d\n",result[i]);

	return 0;

}