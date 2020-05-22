#include <stdio.h>
#include <iostream>

using namespace std;

long long save[110][2];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);

	save[1][1] = 1;
	save[1][0] = 0;

	for (int i=1;i<N;i++){
		save[i+1][0] = save[i][1]+save[i][0];
		save[i+1][1] = save[i][0];
	}

	printf("%lld\n",save[N][0]+save[N][1]);
	return 0;
}