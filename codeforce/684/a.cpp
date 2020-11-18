#include <stdio.h>
#include <iostream>

using namespace std;

char board[1010];

int min(int x, int y){
	return x<y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,c0,c1,change_cost; scanf("%d %d %d %d",&N,&c0,&c1,&change_cost);
		scanf(" %s",board + 1);
		int num0 = 0;
		int num1 = 0;
		for (int i=0;i<N;i++){
			if(board[i+1]=='0')
				num0++;
			else
				num1++;
		}
		int result = num0 * c0 + num1 * c1;
		// 1 to 0
		result = min(result,c0*N + change_cost*num1);

		// 0 to 1
		result = min(result,c1*N + change_cost*num0);

		printf("%d\n",result);

	}
	return 0;
}