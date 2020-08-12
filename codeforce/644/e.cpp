#include <stdio.h>
#include <iostream>

using namespace std;

char save[110][110];
int board[110][110];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);

	for (int i=0;i<100;i++)
		for (int j=0;j<100;j++)
			save[i][j] = '1';
	while(T--){
		int N; scanf("%d",&N);
		for (int i=0;i<N;i++){
			scanf(" %s",save[i+1]+1);
			save[i+1][N+1] = '1';
		}
		for (int i=0;i<N;i++)
			save[N+1][i+1] = '1';

		for (int i=0;i<N+2;i++){
			for (int j=0;j<N+2;j++)
				if(save[i][j]=='1')
					board[i][j] = 1;
				else
					board[i][j] = 0;
		}

		bool sw = true;
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				int temp = board[i+1][j+1];
				if(!temp)
					continue;
				else
					if(!board[i+2][j+1]&&!board[i+1][j+2])
						sw = false;

			}
		}
		if(sw)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}