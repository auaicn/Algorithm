#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool board[110][110];
int res[110][110];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&M,&N);
	for (int i=0;i<N;i++){
		char temp[110];
		scanf(" %s",temp);
		for (int j=0;j<M;j++){
			if(temp[j]=='0')
				board[i+1][j+1] = false;
			else
				board[i+1][j+1] = true;
		}
	}

	for (int i=0;i<N+2;i++)
		res[i][0] = res[i][M+1] = 1;
	for (int i=0;i<M+2;i++)
		res[0][i] = res[N+1][i] = 1;

	queue<pair<int,int> > q;
	q.push({1,1}); res[1][1] = 1;

	while(!q.empty()){
		pair<int,int> pos = q.front(); q.pop();
		int x = pos.first;
		int y = pos.second;
		for (int i=0;i<4;i++){
			int x_ = x+dx[i];
			int y_ = y+dy[i];
			if(res[x_][y_]){
				if(board[x_][y_]){
					if(res[x_][y_]>res[x][y]+1){
						res[x_][y_] = res[x][y]+1;
						q.push({x_,y_});
					}

				}else{
					if(res[x_][y_]>res[x][y]){
						res[x_][y_] = res[x][y];
						q.push({x_,y_}); //again
					}
				}

			}
			else if(board[x_][y_]){
				res[x_][y_] = res[x][y]+1;
				q.push({x_,y_});
			}else{
				res[x_][y_] = res[x][y];
				q.push({x_,y_});
			}
		}
	}

	/*
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++)
			printf("%3d",res[i+1][j+1]);
		printf("\n");
	}
	*/

	printf("%d\n",res[N][M]-1);

	return 0;
}