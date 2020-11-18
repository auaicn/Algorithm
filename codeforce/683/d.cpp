#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

char A[5010];
char B[5010];

int board[5010][5010];

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	scanf(" %s",A+1);
	scanf(" %s",B+1);
	printf("%s\n",A+1);
	printf("%s\n",B+1);

	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			if(A[i+1]==B[j+1])
				board[i+1][j+1] = board[i][j] +1;
			else
				board[i+1][j+1] = max(board[i+1][j],board[i][j+1]);
		}
	}

	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			printf("%3d",board[i+1][j+1]);
		}
		printf("\n");
	}

	printf("LCS length %d\n",board[N][M]);
	// 얘의 substring 을 전부다 돌거임

	int result = 0; // basicially 0 empty empty string then 0

	for (int start = 1; start <= board[N][M]; start++){
		for (int end = start; end <= board[N][M]; end++){
			// substring start to end 를 보는데,
			// start 놈의 A랑 B 값이랑 end 놈의 
			result = max(result,4*(end-start+1) - ()-() );
		}
	}

	printf("%d\n",result);

	return 0;
}