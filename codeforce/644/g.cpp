#include <stdio.h>
#include <iostream>

using namespace std;

int max(int x,int y){
	return x>y?x:y;
}

int min(int x, int y){
	return x<y?x:y;
}

int board[60][60];
int row[60];
int column[60];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,M,A,B; scanf("%d %d %d %d",&N,&M,&A,&B);
		if(N*A != M*B){
			printf("NO\n");
			continue;
		}
		for (int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				board[i+1][j+1] = 0;
		int div;
		for (div = 0; div < M; div++){
			if(!((N*(div+1))%M))
				break;
		}
		int div_save = div;
		for (int i=0;i<N;i++){
			int start = i+1 + (div*i);
			for (int j=0;j<A;j++){
				int lookat_idx = (start+j)%M;
				if(!lookat_idx)
					lookat_idx = M;
				board[i+1][lookat_idx] = 1;
			}
		}

		/*
		for (int i=0;i<N;i++)
			row[i+1] = A;
		for (int i=0;i<M;i++)
			column[i+1] = B;

		for (int i=0;i<N;i++){
			for (int j=0;j<M;j++){
				// looking for i+1,j+1
				if(row[i+1] && column[j+1]){
					board[i+1][j+1] = 1;
					row[i+1]--;
					column[j+1]--;
				}
			}
		}
		*/
		
		/*
		bool check = true;
		for (int i=0;i<N;i++)
			if(row[i+1])
				check = false;
		for (int i=0;i<M;i++)
			if(column[i+1])
				check = false;
		if(!check){
			printf("NO\n");
			continue;
		}
		*/

		printf("YES\n");
		for (int i=0;i<N;i++){
			for (int j=0;j<M;j++){
				if(board[i+1][j+1])
					printf("1");
				else
					printf("0");
			}
			printf("\n");
		}
	}
	return 0;
}

/*
5
3 6 2 1
2 2 2 1
2 2 2 2
4 4 2 2
2 1 1 2
*/
