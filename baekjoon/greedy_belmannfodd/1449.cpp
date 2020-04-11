#include <stdio.h>
#include <iostream>

using namespace std;

bool visit[1010];

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<N;i++){
		int temp; scanf("%d",&temp);
		visit[temp] = true;
	}

	int res = 0;
	for (int i=0;i<1000;i++){
		// looking for i+1 th element
		if(visit[i+1]){
			res++;
			i+=M-1;
		}
	}

	printf("%d\n",res);
	return 0;
}