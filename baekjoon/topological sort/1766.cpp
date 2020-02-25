#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[32010];
int indegree[32010];

int main(int argc, char const *argv[])
{

	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<M;i++){
		int pre_quest, next_quest; scanf("%d %d",&pre_quest,&next_quest);
		v[pre_quest].push_back(next_quest);
		indegree[next_quest]++;
	}

	priority_queue<int> pq;

	for (int i=0;i<N;i++)
		if(!indegree[i+1])
			pq.push(-(i+1));

	while(!pq.empty()){
		int top_ = pq.top(); pq.pop(); 
		top_ *= -1; printf("%d ",top_);
		for (int i=0;i<v[top_].size();i++){
			int next_ = v[top_][i];
			indegree[next_]--;
			if(!indegree[next_])
				pq.push(-next_);
		}
	}

	return 0;
}