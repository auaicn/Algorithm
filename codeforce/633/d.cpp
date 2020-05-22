#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[100010];
int degree[100010];
int visit[100010];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int left,right; scanf("%d %d",&left,&right);
		v[left].push_back(right);
		v[right].push_back(left);
		degree[left]++;
		degree[right]++;
	}

	for (int i=0;i<N;i++)
		depth[i+1] = -1;

	// N-1 times 
	queue<int> q;
	for (int i=0;i<N;i++)
		if(degree[i+1]==1){
			q.push_back(i+1);
			visit[i+1] = 0;
			depth[i+1] = 0;
		}

	int max_ = 1;
	while(!q.empty()){
		int pos = q.front(); q.pop();
		for (int i=0;i<v[pos].size();i++){
			int next = v[pos][i];
			if(visit[next]){
				continue;
			}


			degree[next]--;
			if(degree[next]==1)
				q.push(next);


		}
		visit[pos] = max_;

	}

}