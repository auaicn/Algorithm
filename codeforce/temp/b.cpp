#include <stdio.h>
#include <iostream>

using namespace std;

int save[5010];
int cmp[5010];
int temp[5010][5010];

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N; scanf("%d",&N);
		for (int i=0;i<N;i++){
			scanf("%d",&save[i+1]);
			cmp[N-i] = save[i+1];
		}

		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				if(save[j+1]==cmp[i+1])
					temp[i+1][j+1] = temp[i][j]+1;
				else
					temp[i+1][j+1] = max(temp[i][j+1],temp[i+1][j]);
			}
		}

		/*
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++)
				printf("%2d",temp[i+1][j+1]);
			printf("\n");
		}
		*/

		if(temp[N][N]>=3)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}