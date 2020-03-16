#include <stdio.h>
#include <iostream>

using namespace std;

int save[1000010];

int find(int x){
	if(x==save[x])
		return x;
	return save[x] = find(save[x]);
}

void union_(int x, int y){
	save[find(x)] = find(save[y]);
}

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);

	for (int i=0;i<N+1;i++)
		save[i] = i;

	for (int i=0;i<M;i++){
		int cmd,left,right; scanf("%d %d %d",&cmd,&left,&right);
		if(cmd){
			if(find(left)==find(right))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			union_(left,right);
	}
	return 0;
}