#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int board[1000010];
int zeros[1000010];
int leftmost[1000010];
int rightmost[1000010];

int find_sign(int start, int end, int now){
	if(rightmost[now] < start || end < leftmost[now])
		return 1;
	else if (start <= leftmost[now] && rightmost[now] <= end)
		return board[now];
	else
		return find_sign(start,end,now*2) * find_sign(start,end,now*2+1);
}

int find_zero(int start, int end, int now){
	if(rightmost[now] < start || end < leftmost[now])
		return 0;
	else if (start <= leftmost[now] && rightmost[now] <= end)
		return zeros[now];
	else
		return find_zero(start,end,now*2) + find_zero(start,end,now*2+1);
}

int main(int argc, char const *argv[])
{
	
	int N,M; 
	while(scanf("%d %d",&N,&M) != EOF){

		int width = log2(N);
		if(1 << width == N)
			width--;
		width++;
		int adjust = 1 << width;

		for (int i=0;i<adjust;i++){
			
			board[adjust+i] = 1;
			zeros[adjust+i] = 0;
			leftmost[adjust+i] = i+1;
			rightmost[adjust+i] = i+1;
			
			if(i<N){
				int temp; scanf("%d",&temp);
				if(temp == 0)
					zeros[adjust+i] = 1;
				else if (temp < 0)
					board[adjust+i] = -1;
			}

		}

		for (int i=adjust-1;i>0;i--){
			board[i] = board[i*2] * board[i*2+1];
			zeros[i] = zeros[i*2] + zeros[i*2+1];
			leftmost[i] = leftmost[i*2];
			rightmost[i] = rightmost[i*2+1];
		}

		for (int i=0;i<2*adjust;i++)
			printf("%4d [%2d:%2d] %4d%4d\n",i+1, leftmost[i+1],rightmost[i+1], board[i+1],zeros[i+1]);

		for (int i=0;i<M;i++){
			char cmd; scanf(" %c",&cmd);
			//printf("\ncmd : [%c]",cmd);
			if(cmd == 'C'){
				// Changing
				int pos, value; scanf("%d %d",&pos, &value);
				
				pos += adjust - 1;

				if(value > 0)
					value = 1;
				else if (value < 0)
					value = -1;

				if(zeros[pos]){
					// it was 0
					if(value == 0)
						continue;
					else{
						// zeros --
						// 1 no need
						// -1 -> reverse sign
						while(pos){
							zeros[pos]--;
							if(value != 1)
								board[pos] *= -1;
							pos /= 2;
						}
					}

				}else{
					// it was 1 or -1
					if(board[pos] == value)
							continue;

					if(value == 0){

						// 1 no need
						// -1 -> reverse
						while(pos){
							zeros[pos]++;
							if(value != 1)
								board[pos] *= -1;
							pos /= 2;
						}
					}else{
						// same -> no need
						// different -> reverse
						while(pos){
							board[pos] *= -1;
							pos /= 2;
						}
					}
				}
			}else{

				int start,end; scanf("%d %d",&start,&end);
				int num_zero = find_zero(start,end,1);
				int ret = find_sign(start,end,1);

				char result;
				if (num_zero)
					result = '0';
				else
					result = ret > 0 ? '+' : '-';

				printf("%c",result);
			}

		}

		printf("\n");
	}
	return 0;
}
