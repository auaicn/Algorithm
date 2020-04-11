#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF (1987654321)

vector<pair<int,int> > v[510];
vector<int> reverse_[510];
int dist[510];
bool board[510][510];
bool visit[510];

int main(int argc, char const *argv[])
{
	while(true){

		int N,M; scanf("%d %d",&N,&M);
		if(!N&&!M)
			break;

		int S,E; scanf("%d %d",&S,&E); S++,E++;

		for (int i=0;i<M;i++){
			int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
			left++; right++;
			v[left].push_back({right,weight});
			//v[right].push_back({left,weight});
		}

		for (int i=0;i<N;i++)
			dist[i+1] = INF;

		priority_queue<pair<int,int> > pq;
		pq.push({0,S}); dist[S] = 0;
		while(!pq.empty()){
			pair<int,int> temp = pq.top(); pq.pop();
			int now = temp.second;
			if(now==E)
				break;
			for (int i=0;i<v[now].size();i++){
				pair<int,int> pos = v[now][i];
				int next = pos.first;
				int weight = pos.second;
				if(dist[next]>dist[now]+weight){
					dist[next] = dist[now] + weight;
					reverse_[next].clear();
					reverse_[next].push_back(now);
					pq.push({-dist[next],next});
				}else if(dist[next]==dist[now]+weight)
					reverse_[next].push_back(now);
			}
		}

		queue<int> q;
		q.push(E); visit[E] = true;
		while(!q.empty()){
			int pos = q.front(); q.pop();
			for (int i=0; i<reverse_[pos].size();i++){
				int next = reverse_[pos][i];
				//printf("%d %d\n",next,pos);
				board[next][pos] = true;
				if(!visit[next]){
					q.push(next);
					visit[next] = true;
				}
			}
		}

		// pq may not be empty
		while(!pq.empty())
			pq.pop();

		for (int i=0;i<N;i++)
			dist[i+1] = INF;

		/*
		for (int i=0;i<N;i++){
			printf("%2d: ",i+1);
			for (int j=0;j<reverse_[i+1].size();j++)
				printf("%3d",reverse_[i+1][j]);
			printf("\n");
		}


			printf("\n");

		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++)
				printf("%3d",board[i+1][j+1]);
			printf("\n");
		}
		*/

		// start again without shortest path edge.
		pq.push({0,S}); dist[S] = 0;
		while(!pq.empty()){
			pair<int,int> tmp = pq.top(); pq.pop();
			int now = tmp.second;
			if(now==E)
				break;
			for (int i=0;i<v[now].size();i++){
				pair<int,int> pos = v[now][i];
				int next = pos.first;
				int weight = pos.second;
				if(board[now][next])
						continue;
				if(dist[next]>dist[now]+weight){
					dist[next] = dist[now] + weight;
					pq.push({-dist[next],next});
				}
			}
		}

		while(!pq.empty())
			pq.pop();

		if(dist[E]==INF)
			printf("-1\n");
		else
			printf("%d\n",dist[E]);

		//initialize
		for (int i=0;i<N;i++){
			v[i+1].clear();
			reverse_[i+1].clear();
			visit[i+1] = false;
		}

		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				board[i+1][j+1] = false;

	}
	return 0;
}