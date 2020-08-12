#include <stdio.h>
#include <iostream>

using namespace std;

long long sum[100010];

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<N;i++){
		long long temp; scanf("%lld",&temp);
		sum[i+1] = sum[i] + temp;
	}
	for (int i=0;i<M;i++){
		int left,right; scanf("%d %d",&left,&right);
		printf("%lld\n",sum[right]-sum[left-1]);
	}

	return 0;
}