#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

vector<pair<int,int> > v[100010];
bool visit[100010];
int dist[100010];

int max(int x, int y){
	return x>y?x:y;
}

queue<int> q;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int left; scanf("%d",&left);
		while(true){
			
			int right; scanf("%d",&right);
			if(right == -1)
				break;
			
			int weight; scanf("%d",&weight);
			v[left].push_back({right,weight});

		}
	}

	int start = 1;
	int max_ = -1;
	int max_index = 1;

	// start 로 부터 가장 멀리에 있는 녀석을 찾겠다.
	q.push(start); visit[start] = true; dist[start] = 0;
	while(!q.empty()){
		int pos = q.front(); q.pop();
		for (int i=0;i<v[pos].size();i++){
			pair<int,int> temp = v[pos][i];
			int next = v[pos][i].first;
			int weight = v[pos][i].second;
			if(visit[next])
				continue;
			q.push(next);
			visit[next] = true;
			dist[next] = dist[pos] + weight;
			if(dist[next]>max_){
				max_ = dist[next];
				max_index = next;
			}
		}
	}

	for (int i=0;i<N;i++){
		visit[i+1] = false;
		dist[i+1] = 0;
	}

	start = max_index;
	max_ = -1;
	// start 로 부터 가장 멀리에 있는 녀석을 찾겠다.
	q.push(start); visit[start] = true; dist[start] = 0;
	while(!q.empty()){
		int pos = q.front(); q.pop();
		for (int i=0;i<v[pos].size();i++){
			pair<int,int> temp = v[pos][i];
			int next = v[pos][i].first;
			int weight = v[pos][i].second;
			if(visit[next])
				continue;
			q.push(next);
			visit[next] = true;
			dist[next] = dist[pos] + weight;
			max_ = max(max_,dist[next]);
		}
	}

	printf("%d\n",max_);

	return 0;

}








