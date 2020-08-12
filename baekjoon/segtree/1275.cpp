#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

long long board[400010];
int left_[400010];
int right_[400010];

long long find_sum(int start, int end, int now){

	if (end < left_[now] || right_[now] < start)
		return 0L;
	else if (start <= left_[now] && right_[now] <= end)
		return board[now];
	else
		return find_sum(start,end,now*2) + find_sum(start,end,now*2+1);
}

int min(int x, int y){
	return x<y?x:y;
}

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int N,Q; scanf("%d %d",&N,&Q);

	int width = log2(N);
	if((1 << width) == N)
		width --;
	width++;
	int first_idx = 1 << width;

	for (int i=0;i<first_idx;i++){
		if(i<N)
			scanf("%lld",&board[first_idx+i]);
		else
			board[first_idx+i] = 0L;
		left_[first_idx+i] = i+1;
		right_[first_idx+i] = i+1;
	}

	for (int i=first_idx-1;i>0;i--){
		left_[i] = left_[2*i];
		right_[i] = right_[2*i+1];
		board[i] = board[i*2] + board[i*2+1];
	}

	for (int i=0;i<Q;i++){
		
		int start,end; scanf("%d %d",&start,&end);
		int min_ = min(start,end);
		int max_ = max(start,end);

		printf("%lld\n",find_sum(min_,max_,1));

		int pos; long long new_value; scanf("%d %lld",&pos,&new_value);

		pos += first_idx - 1;
		long long diff = -board[pos] + new_value;
		while(pos){
			board[pos] += diff;
			pos /= 2;
		}

	}
	return 0;
}