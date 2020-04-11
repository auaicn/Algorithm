#include <stdio.h>
#include <iostream>

using namespace std;

#define INF (1987654321)

int min(int x,int y){
	return x<y?x:y;
}

int board[510][510];

int main(int argc, char const *argv[])
{
	int T;scanf("%d",&T);
	while(T--){

		int N,M,W; scanf("%d %d %d",&N,&M,&W);

		//init
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++){
				board[i+1][j+1] = INF;
				if(i==j)
					board[i+1][j+1] = 0;
			}

		for (int i=0;i<M;i++){
			int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
			board[left][right] = min(board[left][right],weight);
			board[right][left] = min(board[right][left],weight);
		}

		for (int i=0;i<W;i++){
			int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
			board[left][right] = min(board[left][right],-weight);
		}

		for (int k=0;k<N;k++){
			for (int i=0;i<N;i++){
				for (int j=0;j<N;j++){
					if(board[i+1][k+1]!=INF && board[k+1][j+1]!=INF)
						board[i+1][j+1] = min(board[i+1][j+1],board[i+1][k+1]+board[k+1][j+1]);
				}
			}
			/*
			printf("\n");
			for (int i=0;i<N;i++){
				for (int j=0;j<N;j++){
					if(board[i+1][j+1]==INF)
						printf("%4d",-1);
					else
						printf("%4d",board[i+1][j+1]);
				}
				printf("\n");
			}
			*/

		}

		bool sw = false;
		for (int i=0;i<N;i++)
			if(board[i+1][i+1]<0)
				sw = true;
		if(sw)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}