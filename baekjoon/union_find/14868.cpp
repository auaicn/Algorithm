#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

#define CORNER (-1)

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int N = 0,K = 0; 
int res = 0;

int board[2020][2020];

pair<int,int> parent[2020][2020];

pair<int,int> find(pair<int,int> now){
	int x = now.first;
	int y = now.second;

	pair<int,int> parent_ = parent[x][y];
	int parent_x = parent_.first;
	int parent_y = parent_.second;

	if(x==parent_x&&y==parent_y)
		return parent_;
	else
		return parent[x][y] = find({parent_x,parent_y});
}

void union_(pair<int,int> left,pair<int,int> right){
	pair<int,int> left_parent = find(left);
	pair<int,int> right_parent = find(right);

	// already same group
	if(left_parent==right_parent)
		return;

	// another group -> union
	parent[right_parent.first][right_parent.second]=left_parent;

	// num cilvilization decreases
	K--;
	if(K==1){
		printf("%d\n",res);
		exit(0);
	}

	return;
}

int main(int argc, char const *argv[]) {

	queue<pair<int,int> > q;

	scanf("%d %d",&N,&K);

	// set corner for exception
	for (int i=0;i<N+2;i++)
		board[0][i]=board[N+1][i]=board[i][0]=board[i][N+1] = CORNER;

	// initialize group
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			parent[i+1][j+1]={i+1,j+1};


	// scan and handle first grouping	
	int save_K = K;
	for (int i=0;i<save_K;i++){
		int x,y; scanf("%d %d",&x,&y);
		q.push({x,y});
		board[x][y] = 1;
		// first group handle
		for (int j=0;j<4;j++){
			int x_ = x+dx[j];
			int y_ = y+dy[j];
			if(board[x_][y_]==CORNER){
				continue;
			}

			if(board[x][y]==board[x_][y_])
				union_({x,y},{x_,y_});
		}

	}

	// always there is answer so there is break as well. if K not outside the board(abnormal input)

	while(true){
		pair<int,int> pos = q.front(); q.pop();
		int x = pos.first;
		int y = pos.second;
		if(res<board[x][y]){
			res = board[x][y];

			/* check
			printf("%d\n",K);
			for (int i=0;i<N;i++){
				for (int j=0;j<N;j++)
					printf("%2d",board[i+1][j+1]);
				printf("\n");
			}
			printf("\n"); */
			
		}

		for (int i=0;i<4;i++){
			int x_ = x+dx[i];
			int y_ = y+dy[i];
			
			// corner case skip
			if(board[x_][y_]==CORNER)
				continue;

			// not corner 
			if(board[x][y]<board[x_][y_]){
				union_({x,y},{x_,y_});
			}else if(board[x_][y_]==0){
				// this is not union
				board[x_][y_] = board[x][y]+1;
				q.push({x_,y_});
				parent[x_][y_] = find({x,y});
				for (int j=0;j<4;j++){
					int x__ = x_+dx[j];
					int y__ = y_+dy[j];
					if(board[x__][y__]==CORNER)
						continue;

					if(board[x_][y_]==board[x__][y__]){
						union_({x_,y_},{x__,y__});
					}
				}
			}
		}

	}
	return 0;
}