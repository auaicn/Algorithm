#include <stdio.h>
#include <iostream>

using namespace std;

int parent[10010];
int cost[10010];

int min(int x, int y){
	return x<y?x:y;
}

int find(int x){
	if(x==parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void union_(int x, int y){
	int parent_x = find(x);
	int parent_y = find(y);
	if(parent_y==parent_x)
		return;
	else{
		parent[parent_x] = parent_y;
		cost[parent_y] = min(cost[parent_x],cost[parent_y]);
	}
}

int main(int argc, char const *argv[])
{
	int N,M,K; scanf("%d %d %d",&N,&M,&K);

	for (int i=0;i<N;i++)
		parent[i+1] = i+1;
	
	for (int i=0;i<N;i++)
		scanf("%d",&cost[i+1]);

	for (int i=0;i<M;i++){
		int left,right; scanf("%d %d",&left,&right);
		union_(left,right);
	}

	int res = 0;

	for (int i=0;i<N;i++)
		if(parent[i+1]==i+1)
			res+= cost[i+1];

	if(K>=res)
		printf("%d\n",res);
	else
		printf("Oh no\n");
	/* code */
	return 0;
}

