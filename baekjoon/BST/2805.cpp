#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_HEIGHT (1000000000)

long long save[1000010];

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<N;i++)
		scanf("%lld",&save[i+1]);

	// low be possible(sufficient)
	// high be impossible.
	// we get [low,high]
	// look at mid = (low+high)/2;
	// we want low be greater(among possible, we want greatest height)

	long long low = 0;
	long long high = MAX_HEIGHT;

	while(low+1 < high){
		long long mid = (low + high) / 2;
		long long sum_ = 0;
		for (int i=0;i<N;i++)
			if(mid<save[i+1])
				sum_ += save[i+1]-mid;
		if(sum_ < M){
			high = mid - 1 ;
		}else
			//	만족!
			low = mid;

	}
	printf("%lld\n",low);

	return 0;
}