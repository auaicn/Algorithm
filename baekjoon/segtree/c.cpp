#include <stdio.h>
#include <iostream>

using namespace std;

char board[110];
int level[110];

int min(int x, int y){
	return x<y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int len; scanf("%d",&len);
		for (int i=0;i<len;i++)
			scanf(" %c",&board[i+1]);
		for (int i=0;i<len;i++){
			//printf("%3c",board[i+1]);
			if(board[i+1]=='(')
				board[i+1] = board[i]+1;
			else
				board[i+1] = board[i]-1;
		}
		//printf("\n");
		int res = 0;
		for (int i=0;i<len;i++)
			if(board[i+1]<0)
				res = min(res,board[i+1]);
		printf("%d\n",-res);
			//printf("%3d",board[i+1]);
		//printf("\n");

	}
	return 0;
}