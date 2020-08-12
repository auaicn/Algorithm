#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int min_board[400010];
int max_board[400001];
int left_[400010];
int right_[400010];

int max(int x, int y){
	return x>y?x:y;
}

int min(int x, int y){
	return x<y?x:y;
}

int find_max(int start, int end, int now){
	if(right_[now] < start || end < left_[now])
		return -1;
	if(start<=left_[now] && right_[now] <= end)
		return max_board[now];
	else
		return max(find_max(start,end,now*2),find_max(start,end,now*2+1));
}

int find_min(int start, int end, int now){
	if(right_[now] < start || end < left_[now])
		return 1987654321;
	if(start <= left_[now] && right_[now] <= end)
		return min_board[now];
	else
		return min(find_min(start,end,now*2),find_min(start,end,now*2+1));
}

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);

	int width = log2(N);
	if(1 << width == N)
		width--;
	width++;
	int adjust = 1 << width;

	for (int i=0; i<adjust; i++){
		if(i<N){
			scanf("%d",&min_board[adjust+i]);
			max_board[adjust+i] = min_board[adjust+i];
		}
		else{
			min_board[adjust+i] = 1987654321;
			max_board[adjust+i] = -1;
		}
		left_[adjust+i] = i+1;
		right_[adjust+i] = i+1;
	}

	for (int i = adjust-1; i > 0; i--){
		min_board[i] = min(min_board[i*2],min_board[i*2+1]);
		max_board[i] = max(max_board[i*2],max_board[i*2+1]);
		left_[i] = left_[i*2];
		right_[i] = right_[i*2+1];
	}

	for (int i=0;i<M;i++){
		int left_,right_; scanf("%d %d",&left_,&right_);
		printf("%d ",find_min(left_,right_,1));
		printf("%d\n",find_max(left_,right_,1));
	}

	return 0;
}