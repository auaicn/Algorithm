#include <iostream>
#include <vector>
#include <vector>

using namespace std;

int M,N;

int save[60][60];
bool visit[60][60];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x, int y){

	visit[x][y] = true;

	for (int i=0;i<4;i++){
		int x_ = x+dx[i];
		int y_ = y+dy[i];
		if(save[x_][y_]&&!visit[x_][y_])
			dfs(x_,y_);
	}

	return ;
}

int main(){
	
	int Q; scanf("%d",&Q);
	while(Q--){

		int K; scanf("%d %d %d",&M,&N,&K);
		for (int i=0;i<M;i++)
			for (int j=0;j<N;j++)
				save[i+1][j+1] = 0;

		while(K--){
			int x,y; scanf("%d %d",&x,&y);
			save[x+1][y+1] = 1;

		}

		// strict initailization
		for (int i=0;i<N+2;i++)
			save[0][i] = save[M+1][i] = 0;
		for (int i=0;i<M+2;i++)
			save[i][0] = save[i][N+1] = 0;
		for (int i=0;i<M;i++)
			for (int j=0;j<N;j++)
				visit[i+1][j+1] = false;

		int cnt_ = 0;
		for (int i=0;i<M;i++){
			for (int j=0;j<N;j++){
				// start from i+1, j+1
				if(save[i+1][j+1]&&!visit[i+1][j+1]){
					cnt_++;
					dfs(i+1,j+1);
				}
			}
		}
		printf("%d\n",cnt_);

	}



	return 0;
}