#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int indegree[32010];
vector<int> v[32010];

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M); // N upto 32,000 and M upto 100,000
	for (int i=0;i<M;i++){
		int front_, next_; scanf("%d %d",&front_,&next_);
		v[front_].push_back(next_);
		indegree[next_] ++;
	}

	queue<int> q;

	for (int i=0;i<N;i++)
		if(!indegree[i+1])
			q.push(i+1);

	while(!q.empty()){
		int pos = q.front(); q.pop(); printf("%d ",pos);
		for (int i=0;i<v[pop].size();i++){
			int next = v[pop][i];
			indegree[next]--;
			if(!indegree[next]){
				q.push(next);
			}
		}
	}

	return 0;
}