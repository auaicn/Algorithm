#include <stdio.h>
#include <iostream>

using namespace std;

int save[10010];

int main(int argc, char const *argv[])
{
	int K,N; scanf("%d %d",&K,&N);
	for (int i=0;i<K;i++)
		scanf("%d",&save[i+1]);

	long long low = 0L;
	long long high = 1L<<32;

	while(high!=low+1){

		long long mid = (low + high) / 2;

		int cnt_ = 0;
		for (int i=0;i<K;i++)
			cnt_ += save[i+1] / mid;

		if (cnt_ >= N)
			// possible
			low = mid;
		else
			high = mid;

	}
	printf("%lld\n",low);
	return 0;
}