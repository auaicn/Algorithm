#include <stdio.h>
#include <iostream>
using namespace std;

int max(int x, int y){
	return x>y?x:y;
}

int save[110][110];
bool board[110][110];
bool visit[110][110];

int cnt_;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void dfs(int x, int y){
	visit[x][y] = true;
	for (int i=0;i<4;i++)
	{
		int x_ = x+ dx[i];
		int y_ = y+ dy[i];
		if(board[x_][y_]&&!visit[x_][y_])
			dfs(x_,y_);
	}
}


int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			scanf("%d",&save[i+1][j+1]);
			board[i+1][j+1] = true;
		}
	}

	int result = 1;
	for (int h=1;h<=100;h++){

		cnt_ = 0;
		// h '이하' 는 모두 잠긴다.
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){

				// 겸사겸사 initialization
				visit[i+1][j+1] = false;

				// 	새로이 잠기게 된 영역들 
				if(save[i+1][j+1]<=h)
					board[i+1][j+1] = false;
			}
		}

		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++){
				if(board[i+1][j+1]&&!visit[i+1][j+1]){
					cnt_++;
					dfs(i+1,j+1);
				}
			}
		
		result = max(result,cnt_);
	}

	printf("%d\n",result);

	return 0;
}