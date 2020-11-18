#include <stdio.h>
#include <iostream>

using namespace std;

int abs(int x){
	return x>0?x:-x;
}

int min(int x, int y){
	return x<y?x:y;
}

int board[110][110];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,M; scanf("%d %d",&N,&M);
		int min_ = 101;
		int sum = 0;
		int num_negative = 0;

		for (int i=0;i<N;i++){
			for (int j=0;j<M;j++){
				scanf("%d",&board[i+1][j+1]);
				sum += abs(board[i+1][j+1]);
				min_ = min(min_,abs(board[i+1][j+1]));
				if(board[i+1][j+1]<0)
					num_negative++;
			}
		}
		if(num_negative%2){
			// one left then
			printf("%d\n",sum - 2 * min_);
		}else
			printf("%d\n",sum);
	}
	return 0;
}