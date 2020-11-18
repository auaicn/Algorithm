#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,K; scanf("%d %d",&N,&K);
		// K 개의 array 로 만드는건데 그러면...
		// 하나의 어레이는 길이가 N 이다.
		int mid = N%2?N/2+1:N/2;
		// printf("%d , mid : %d\n",N,mid);
		// N == 1 -> mid = 1 이 나오는데
		long long sum = 0;
		for (int i=1; i<= N*K; i++){
			long long temp; scanf("%lld",&temp);
			if(i > (mid-1)*K){
				// printf("auaicn\n");
				if((i - (mid-1)*K)%(N-mid+1) == 1 || N-mid+1 == 1) // 이게 1로 나눠버리니까 나머지가 0인겨 무조건
					sum += temp;
			}

		}
		printf("%lld\n",sum);
	}
	return 0;
}