#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

long long segtree[4000010];
int left_[4000010];
int right_[4000010];

void update(int pos, long long value){

	long long diff = value;
	while(pos){
		segtree[pos] += diff;
		pos /= 2;
	}

}

long long range_sum(int pos, int left, int right){
	if (left <= left_[pos] && right_[pos] <= right)
		return segtree[pos];
	else if (right_[pos] < left || right < left_[pos])
		return 0L;
	else
		return range_sum(pos*2,left,right) + range_sum(pos*2+1,left,right);
}

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	int adjust = log2(N);
	if(N == 1 << adjust)
		adjust --;
	adjust++;
	int size = 1 << adjust;

	for (int i=0;i<size;i++){
		left_[size + i] = i + 1;
		right_[size + i] = i + 1;
	}
	for (int i = size-1; i>0; i--){
		left_[i] = left_[i*2];
		right_[i] = right_[i*2 + 1];
 	}


	for (int i=0;i<M;i++){
		int cmd; scanf("%d",&cmd);
		if(cmd == 1){
			int pos; long long value; scanf("%d %lld",&pos,&value);
			update(pos + size - 1,value);
		}else{
			int left,right; scanf("%d %d",&left,&right);
			printf("%lld\n",range_sum(1, left, right));
		}
	}

	return 0;
}