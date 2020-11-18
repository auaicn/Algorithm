#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N; scanf("%d",&N);
		printf("%d\n",N);
		for (int i=0;i<N;i++)
			printf("%d ",i+1);
		printf("\n");
	}
	return 0;
}
