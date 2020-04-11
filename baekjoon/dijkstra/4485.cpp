#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF (1987654321)

int board[220][220];
int dist[220][220];
bool visit[220][220];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main(int argc, char const *argv[])
{
	int cnt_ = 0;
	while(true){
		cnt_++;
		int N; scanf("%d",&N);
		if(!N)
			break;
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++){
				visit[i+1][j+1] = false;
				dist[i+1][j+1] = INF;
				scanf("%d",&board[i+1][j+1]);
			}

		for (int i=0;i<N+2;i++)
			visit[i][0] = visit[i][N+1] = visit[0][i] = visit[N+1][i] = true;

		priority_queue<pair<int,pair<int,int> > > pq;
		pq.push({-board[1][1],{1,1}}); dist[1][1] = board[1][1];

		while(!pq.empty()){
			pair<int,pair<int,int> > pos = pq.top(); pq.pop();

			int distance = pos.first; distance *= -1;
			int x = pos.second.first;
			int y = pos.second.second;

			if(visit[x][y])
				continue;
			else
				visit[x][y] = true;

			if (x==N&&y==N)
				break;

			for (int i=0;i<4;i++){
				int x_ = x+dx[i];
				int y_ = y+dy[i];
				int weight = board[x_][y_];
				if(visit[x_][y_])
					continue;
				else if(dist[x_][y_]>distance+weight){
					dist[x_][y_] = distance+weight;
					pq.push({-dist[x_][y_],{x_,y_}});
				}
			}

		}
		printf("Problem %d: %d\n",cnt_,dist[N][N]);
	}
	return 0;
}