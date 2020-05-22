#include <stdio.h>
#include <iostream>

using namespace std;

#define ADJUST (10000000)

int save[20000010];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int temp; scanf("%d",&temp);
		save[temp+ADJUST]++;
	}

	int M; scanf("%d",&M);
	for (int i=0;i<M;i++){
		int temp; scanf("%d",&temp);
		printf("%d ",save[temp+ADJUST]);
	}
	printf("\n");


	return 0;
}