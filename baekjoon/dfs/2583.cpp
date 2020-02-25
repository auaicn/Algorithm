#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> v;
int save[110][110];
bool visit[110][110];
int cnt_;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x, int y){
	visit[x][y] = true;
	cnt_++;
	for (int i=0;i<4;i++){
		int x_ = x+dx[i];
		int y_ = y+dy[i];
		if(save[x_][y_]&&!visit[x_][y_])
			dfs(x_,y_);
	}
}


int main(int argc, char const *argv[])
{
	int N,M,K; scanf("%d %d %d",&M,&N,&K);

	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)
			save[i+1][j+1] = 1;

	while(K--){
		int x,y,x_,y_; scanf("%d %d %d %d",&x,&y,&x_,&y_);
		for (int i=x;i<x_;i++){
			for (int j=y;j<y_;j++){
				save[i+1][j+1] = 0;
			}
		}
	}

	for (int i=0;i<N+2;i++)
		save[i][0] = save[i][M+1] = 0;
	for (int j=0;j<M+2;j++)
		save[0][j] = save[N+1][j] = 0;

	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++)
			printf("%2d",save[i+1][j+1]);
		printf("\n");
	}

	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			if(save[i+1][j+1]&&!visit[i+1][j+1]){
				dfs(i+1,j+1);
				v.push_back(cnt_);
				cnt_ = 0;
			}
		}
	}

	sort(v.begin(),v.end());
	printf("%d\n",v.size());
	for (int i=0;i<v.size();i++)
		printf("%d ",v[i]);

	return 0;
}