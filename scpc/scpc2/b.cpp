#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_ARRAY_SIZE (300010)

int save[MAX_ARRAY_SIZE];
int sum_[MAX_ARRAY_SIZE];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--)
	{
		int N; scanf("%d",&N); int M; scanf("%d",&M);
		for (int i=0;i<N;i++)
			scanf("%d",&save[i+1]);

		for (int i=0;i<N;i++)
			sum_[i+1] = sum_[i] + save[i+1];

		printf("\n");
		for (int i=0;i<N;i++)
			printf("%d ",sum_[i+1]);
		printf("\n");


	}
	return 0;
}