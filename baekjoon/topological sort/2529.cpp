#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char save[20];
int indegree[20];
int min_result[20];
int max_result[20];
vector<int> v[20];

int main(int argc, char const *argv[])
{
	int K; scanf("%d",&K);
	for (int i=0;i<K;i++)
		scanf(" %c",&save[i+1]);

	/*
	for (int i=0;i<K;i++)
		printf("%c ",save[i+1]); printf("\n");
	*/

	for (int i=0;i<K;i++)
		if(save[i+1]=='<'){
			indegree[i+1]++;
			v[i+2].push_back(i+1);
		}
		else{
			indegree[i+2]++;
			v[i+1].push_back(i+2);
		}

	priority_queue<int> pq;

	int cnt_ = 9;

	for (int i=0;i<K+1;i++)			
		if(!indegree[i+1])
			pq.push(-(i+1));

	while(!pq.empty()){
		int pos = -pq.top(); pq.pop();
		max_result[pos] = cnt_;
		cnt_--;

		for (int i=0;i<v[pos].size();i++){
			int next= v[pos][i];
			indegree[next]--;
			if(!indegree[next])
				pq.push(-next);
		}
	}

	// min soulution

	for (int i=0;i<20;i++){
		v[i].clear();
		indegree[i]=0;
	}

	for (int i=0;i<K;i++)
		if(save[i+1]=='<'){
			indegree[i+2]++;
			v[i+1].push_back(i+2);
		}
		else{
			indegree[i+1]++;
			v[i+2].push_back(i+1);
		}

	while(!pq.empty()){
		pq.pop();
	}

	for (int i=0;i<K+1;i++)
		if(!indegree[i+1])
			pq.push(-(i+1));

	cnt_ = 0;

	while(!pq.empty()){
		int pos = -pq.top(); pq.pop();
		min_result[pos] = cnt_; cnt_++;
		for (int i=0;i<v[pos].size();i++){
			int next = v[pos][i];
			indegree[next]--;
			if(!indegree[next])
				pq.push(-next);
		}
	}

	for (int i=0;i<K+1;i++)
		printf("%d",max_result[i+1]);
	printf("\n");

	for (int i=0;i<K+1;i++)
		printf("%d",min_result[i+1]);
	printf("\n");

	return 0;
}