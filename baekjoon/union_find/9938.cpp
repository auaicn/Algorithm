#include <stdio.h>
#include <iostream>

using namespace std;

bool visit[300010];
int parent[300010];

int find(int x){
	if(parent[x]==0)
		return x;
	else
		return parent[x] = find(parent[x]);
}

int main(int argc, char const *argv[])
{
	int N,L; scanf("%d %d",&N,&L);
	for (int i=0;i<N;i++){
		int left,right; scanf("%d %d",&left,&right);
		if(!visit[left]){
			visit[left] =  true;
			if(!visit[right])
				parent[left] = right;
		}else{
			if(!visit[right]){
				visit[right] = true;
				if(!visit[find(left)]){
					visit[find(left)]= true;
					parent[right] = find(left);
				}
			}else{
				if(!visit[find(left)]){
					visit[find(left)]=true;
				}else if(!visit[find(right)]){
					visit[find(right)] = true;
				}
				printf("SMECE\n");
				continue;
			}
		}
		printf("LADICA\n");
	}
	return 0;
}