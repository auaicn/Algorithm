#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char save[200010];
bool board[200010];

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		scanf(" %s",save);
		int len = strlen(save);

		for (int i=0;i<len;i++){
			board[i+1] = false;
			if(save[i]=='R')
				board[i+1] = true;
		}
		board[0] = true;
		board[len+1] = true;
		//for (int i=0;i<=len+1;i++)
			//printf("%2d",board[i]);

		int res = 1;
		int cnt_consecutive_false = 0;
		for (int i=0;i<=len+1;i++){
			if(board[i]){
				res = max(res,cnt_consecutive_false+1);
				cnt_consecutive_false = 0;
			}else{
				cnt_consecutive_false++;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}