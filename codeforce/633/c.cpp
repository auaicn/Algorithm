#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

long long save[100010];

long long max(long long x, long long y){
	return x>y?x:y;
}
int main(int argc, char const *argv[])
{
	long long T; scanf("%lld",&T);
	while(T--){
		long long N; scanf("%lld",&N);
		for (long long i=0;i<N;i++)
			scanf("%lld",&save[i+1]);

		long long res = 0;
		for (long long i=0;i<N-1;i++){
			//looking for i+1 th element and i+1 th element
			long long left = save[i+1];
			long long right = save[i+2];
			if(left<=right)
				continue;
			else{
				long long temp = log2(left-right); //temp >= 0
				temp++;
				if(res<temp)
					res = temp;
				save[i+2] = save[i+1];
			}
		}
		printf("%lld\n",res);

	}
	return 0;
}