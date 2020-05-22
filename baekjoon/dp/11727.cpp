#include <stdio.h>
#include <iostream>

using namespace std;

int save[1010];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	save[0] = 1;
	save[1] = 1;
	save[2] = 3;

	for (int i=2;i<N;i++){
		save[i+1] = 2*save[i-1]+save[i];
		save[i+1]%=10007;
	}
	printf("%d\n",save[N]);
	return 0;
}