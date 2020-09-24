#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// vector<long long> leftTrace;
// vector<long long> rightTrace;

long long leftTrace[110];
long long rightTrace[110];

long long max(long long x, long long y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	long long N, K; int Q; scanf("%lld %lld %d",&N,&K,&Q);
	for (int q=0;q<Q;q++){
		long long left,right; scanf("%lld %lld",&left,&right);
		// left trace 나 right trace 나 1로 끝나겠지.

		if(K==1){
			printf("%lld\n",max(left-right,right-left));
			continue;
		}

		int leftCnt = 0;
		int rightCnt = 0;

		while(left > 1){
			leftTrace[++leftCnt] = left;
			left += K-2;
			left /= K;
		}
		leftTrace[++leftCnt] = 1L;

		while(right > 1){
			rightTrace[++rightCnt] = right;
			right += K-2;
			right /= K;
		}
		rightTrace[++rightCnt] = 1L;

		while(leftCnt != 0 && rightCnt != 0 && (leftTrace[leftCnt] == rightTrace[rightCnt])){
			leftCnt--;
			rightCnt--;

		}
		printf("%d\n",leftCnt + rightCnt);
	}
	return 0;
}
