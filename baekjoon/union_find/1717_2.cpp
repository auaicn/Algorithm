#include <bits/stdc++.h>

using namespace std;

int parent[100010];

int find(int x){
	if(x==parent[x])
		return x;
	else
		return parent[x] = find(parnet[x]);
}

void union_

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<N;i++){
		int cmd, A,B; scanf("%d %d %d",&cmd,&A,&B);

	}
	return 0;
}