#include <stdio.h>
#include <iostream>
#include <queue>

#define CORNER (-1)

using namespace std;

int board[2000][2000];
pair<int,int> parent[2000][2000];

int left_x,left_y;
int right_x,right_y;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

pair<int,int> find(pair<int,int> x){
	if(x==parent[x.first][x.second])
		return x;
	else
		return parent[x.first][x.second] = find(parent[x.first][x.second]);
}

void union_(pair<int,int> x, pair<int,int> y){
	pair<int,int> parent_x = find(x);
	pair<int,int> parent_y = find(y);
	if(parent_x==parent_y)
		return;
	else{
		parent[parent_x.first][parent_x.second] = parent_y;
		return;
	}
}

int main(int argc, char const *argv[])
{
	int R,C; scanf("%d %d",&R,&C);

	for (int i=0;i<R;i++)
		for (int j=0;j<C;j++)
			parent[i+1][j+1] = {i+1,j+1};

	for (int i=0;i<R+2;i++)
		board[i][0]=board[i][C+1] = CORNER;
	for (int i=0;i<C+2;i++)
		board[0][i]=board[R+1][i] = CORNER;

	queue<pair<int,int> > q;

	for (int i=0;i<R;i++){
		char tmp; scanf("%c",&tmp);
		for (int j=0;j<C;j++){
			scanf("%c",&tmp);
			if(tmp=='X'){
				//board[i+1][j+1] = 0;
				//continue;
			}
			else {
				board[i+1][j+1] = 1; q.push({i+1,j+1});
				if(tmp=='L'){
					if(left_x){
						right_x = i+1;
						right_y = j+1;
					}
					else{
						left_x = i+1;
						left_y = j+1;
					}
				}

				for (int k=0;k<4;k++){
					int x_ = i+1+dx[k];
					int y_ = j+1+dy[k];
					if(board[x_][y_]==1)
						union_({i+1,j+1},{x_,y_});
				}
			}
		}
	}

	pair<int,int> left = {left_x,left_y};
	pair<int,int> right = {right_x,right_y};

	int res = 0;
	while(!q.empty()){
		pair<int,int> pos = q.front(); q.pop();
		int x = pos.first;
		int y = pos.second;
		int val = board[x][y];

		if(val!=res){
			if(find(left)==find(right)){
				printf("%d\n",res);
				return 0;
			}else
				res = val;
		}

		for (int i=0;i<4;i++){
			int x_ = x+dx[i];
			int y_ = y+dy[i];
			if(board[x_][y_]==CORNER)
				continue;
			if(!board[x_][y_]){
				board[x_][y_] = val+1;
				q.push({x_,y_});
			}
			if(board[x_][y_]>=board[x][y])
				union_({x_,y_},{x,y});
			for (int j=0;j<4;j++){
				int x__=x_+dx[j];
				int y__=y_+dy[j];
				if(board[x__][y__]==CORNER)
					continue;
				if(board[x__][y__]==board[x_][y_])
					union_({x__,y__},{x_,y_});
			}
		}
	}

	return 0;
}