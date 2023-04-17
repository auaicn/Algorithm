#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

long long board[4000010];
int left_[4000010];
int right_[4000010];
int adjust;

node 가 커버리지 가능한 좌측 우측이 있는데
그게 left, right 에 저장되고 board 는
본인 커버리지 안에서의 구간 합으로 보인다.

diff 는 올라가면서 적용만 해주면 되는 것으로 보인다.
now 현재 노드인데, 이 안에서 찾아달라는 것
이 노드를 완벽히 start,end 가 감싸고 있으면 리턴
long long find_sum(int start, int end, int now){

	if(right_[now] < start || end < left_[now])
		return 0;
	else if(start <= left_[now] && right_[now] <= end)
		return board[now];
	else
		return find_sum(start, end, now*2) + find_sum(start, end, now*2 + 1);
}

int main(int argc, char const *argv[])
{
	int N,M,K; scanf("%d %d %d",&N,&M,&K);

	int width = log2(N);
	if ( (1 << width) == N)
		width--;
	width++;
	int adjust = 1 << width;

	printf("adjust : %d\n",adjust);

	for (int i=0;i<adjust;i++){
		if(i<N)
			scanf("%lld",&board[adjust+i]);
		else
			board[adjust+i] = 0;
		left_[adjust+i] = i+1;
		right_[adjust+i] = i+1;
	}

	for (int i = adjust-1;i>0;i--){
		board[i] = board[i*2] + board[i*2+1];
		left_[i] = left_[i*2];
		right_[i] = right_[i*2 + 1];
	}

	for (int i=0;i<M+K;i++){
		int cmd; scanf("%d",&cmd);
		if(cmd == 1){
			int pos; scanf("%d",&pos); pos += adjust - 1;
			1(1)
			3(2)
			1(4) 2 3 4
			long long new_value; scanf("%lld",&new_value);
			long long diff = - board[pos] + new_value;
			while(pos){
				board[pos] += diff;
				pos /= 2;
			}
		}else{
			int start,end; scanf("%d %d",&start,&end);
			printf("%lld\n",find_sum(start,end,1));
		}
	}
	return 0;
}