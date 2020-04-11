#include <stdio.h>
#include <iostream>

using namespace std;

int board[60][60];
long long memo[60][60][60][60];
long long sum[60][60];

long long min(long long x,long long y){
	return x<y?x:y;
}

long long dfs(int x_start,int y_start,int x_end,int y_end){

	//printf("%3d%3d%3d%3d\n",x_start,y_start,x_end,y_end);

	if(memo[x_start][y_start][x_end][y_end]>=0){
		//printf("%lld returned\n",memo[x_start][y_start][x_end][y_end]);
		return memo[x_start][y_start][x_end][y_end];
	}

	long long res = 1L<<32;

	for (int i=x_start;i<x_end;i++)
		res = min(res,dfs(x_start,y_start,i,y_end)+dfs(i+1,y_start,x_end,y_end));

	for (int i=y_start;i<y_end;i++){
		res = min(res,dfs(x_start,y_start,x_end,i)+dfs(x_start,i+1,x_end,y_end));
	}

	memo[x_start][y_start][x_end][y_end] = res+sum[x_end][y_end]-sum[x_start-1][y_end]-sum[x_end][y_start-1]+sum[x_start-1][y_start-1];
	//printf("%lld set and returned\n",memo[x_start][y_start][x_end][y_end]);
	return memo[x_start][y_start][x_end][y_end];
}

int main(int argc, char const *argv[])
{

	int T; scanf("%d",&T);
	for (int t=0;t<T;t++){
		int N,M; scanf("%d %d",&N,&M);
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++){
				scanf("%d",&board[i+1][j+1]);
			}

		// util sum
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++)
				sum[i+1][j+1] = board[i+1][j+1] + sum[i+1][j] + sum[i][j+1] - sum[i][j];

		// initialize memo to -1
		for (int i=0;i<N;i++){
			for (int j=0;j<M;j++){
				for (int k=0;k<N;k++){
					for (int l=0;l<M;l++){
						memo[i+1][j+1][k+1][l+1] = -1; 
						// actually except i<k and j<l not needed but now important
					}
				}
			}
		}

		// memo - base condition
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++)
				memo[i+1][j+1][i+1][j+1] = 0;

		printf("#%d %lld\n",t+1,dfs(1,1,N,M));

	}

	return 0;
}