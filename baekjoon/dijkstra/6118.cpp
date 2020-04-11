#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

vector<int> v[20010];
int dist[20010];
int cnt_;
int global_track;
int res;

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<M;i++){
		int left,right; scanf("%d %d",&left,&right);
		v[left].push_back(right);
		v[right].push_back(left);
	}

	queue<int> q;
	q.push(1); dist[1] = 1; cnt_ = 1; global_track = 0; 
	while(!q.empty()){
		int now = q.front(); q.pop();
		if(dist[now]!=global_track){
			cnt_ = 1;
			global_track = dist[now];
			res = now;
		}else {
			cnt_++;
			if(res>now){
				res = now;
			}
		}

		for (int i=0;i<v[now].size();i++){
			int next = v[now][i];
			if(!dist[next]){
				dist[next] = dist[now] +1;
				q.push(next);
			}
		}

	}
	printf("%d %d %d\n",res,global_track-1,cnt_);

	return 0;
}