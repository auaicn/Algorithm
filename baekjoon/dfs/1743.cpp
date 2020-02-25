#include <stdio.h>
#include <iostream>
using namespace std;

int N,M;
int cnt_;

int save[110][110];
bool visit[110][110];

int max(int x, int y){
	return x>y?x:y;
}

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x, int y){
	visit[x][y] = true;
	cnt_++;
	for (int k=0;k<4;k++){
		int x_ = x+ dx[k];
		int y_ = y+ dy[k];
		if(save[x_][y_]&&!visit[x_][y_])
			dfs(x_,y_);
	}
}

int main(){

	int K;
	scanf("%d %d %d",&N,&M,&K);

	while(K--){
		int left, right; scanf("%d %d",&left,&right);
		save[left][right] = 1;
	}

	int result = -1;
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			// start from (i+1,j+1)
			if(save[i+1][j+1]&&!visit[i+1][j+1]){
				dfs(i+1,j+1);
				result = max(result, cnt_);
				cnt_=0;
			}
		}
	}
	printf("%d\n",result);

	return 0;
}