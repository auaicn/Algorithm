#include <stdio.h>
#include <iostream>

using namespace std;

int parent[1010];

int find(int x){
	if(x==parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void union_(int x,int y){
	int parent_x = find(x);
	int parent_y = find(y);
	if(parent_x!=parent_y)
		parent[parent_x] = parent_y;
}

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);

	for (int i=0;i<N;i++)
		parent[i+1] = i+1;

	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			int temp; scanf("%d",&temp);
			if(temp)
				union_(i+1,j+1);
		}
	}


	bool sw = true;
	int previous; scanf("%d",&previous);
	for (int i=1;i<M;i++){
		int next; scanf("%d",&next);
		if(find(previous)!=find(next))
			sw = false;
		else
			previous = next;
	}

	if(sw)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}