#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

long long taste[100010];
int parent[100010];
bool visit[100010];

int find(int x){
	if (x==parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

long long union_(int x, int y){
	int parent_x = find(x);
	int parent_y = find(y);
	if(parent_x==parent_y)
		return 0;
	else{
		parent[parent_y] = parent_x;
		taste[parent_x] += taste[parent_y];
		return taste[parent_x];
	}
}

int main(int argc, char const *argv[])
{
	int N; long long M; scanf("%d %lld",&N,&M);

	for (int i=0;i<N;i++)
		parent[i+1] = i+1;

	priority_queue<pair<int,int> > pq;
	for (int i=0;i<N;i++){
		long long T; int S; scanf("%lld %d",&T,&S);
		pq.push({-S,i+1}); taste[i+1] = T;
	}

	while(!pq.empty()){
		pair<int,int> pos = pq.top(); pq.pop();
		int spice = -pos.first;
		int index = pos.second;
		visit[index] = true;

		if(taste[index]>=M){
			printf("%d\n",spice);
			return 0;
		}

		if(visit[index-1])
			if(union_(index,index-1)>=M){
				printf("%d\n",spice);
				return 0;
			}
		if(visit[index+1])
			if(union_(index,index+1)>=M){
				printf("%d\n",spice);
				return 0;
			}
	}
	return 0;
}