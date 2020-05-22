#include <stdio.h>
#include <iostream>

using namespace std;

long long min(long long x,long long y){
	return x<y?x:y;
}

int main(int argc, char const *argv[])
{
	int N; long long K; scanf("%d %lld",&N, &K);

	long long low = 0;
	long long high = 10000000000L;

	while(high != low+1){

		long long mid = (low + high)/2;

		// sum : mid값 보다 작거나 같은 요소 개수
		long long sum = 0;
		for (long long i=0;i<N;i++)
			sum += min((i+1) * N, mid)/(i+1);

		// printf("[%3lld-%5lld] mid[%5lld] sum[%5lld]\n",low, high, mid, sum);

		// sum 이 K보다 작다는 것은 그 인덱스가 작다는 거여. mid를 올려야돼.
		// 같은경우엔? 그이하 개수가 같다는건데. 그럼 3 by 3에서 mid가 7이나 8이나 똑같거든.
		// sum값은 같긴하거든. 그럴땐 mid조정이 필요하긴 할텐데...
		// 같을땐 왼쪽으로 가야겠지.

		if(K <= sum)
			high = mid;
		else
			low = mid;

	}
	printf("%lld\n",high);

	return 0;
}