#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define CUTE_JUNGMINI (34)

vector<pair<int,long long> > v[10010];
long long dist[10010][CUTE_JUNGMINI];
//bool visit[10010][CUTE_JUNGMINI];

long long min(long long x, long long y){
	return x<y?x:y;
}

int main(int argc, char const *argv[])
{
	int N,M,K; scanf("%d %d %d",&N,&M,&K);
	for (int i=0;i<M;i++){
		int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
		v[left].push_back({right,weight});
		v[right].push_back({left,weight});
	}

	for (int i=0;i<=K;i++)
		for (int j=0;j<N;j++)
			dist[j+1][i] = LLONG_MAX;

	priority_queue<pair<long long,pair<int,int> > > pq;
	pq.push({0,{1,0}});  // dist num depth
	dist[1][0] = 0; // num depth
	while(!pq.empty()){
		pair<long long, pair<int,int> > top_ = pq.top(); pq.pop();
		long long distance = -top_.first;
		int now = top_.second.first;
		int depth = top_.second.second;
		for (int i=0;i<v[now].size();i++){
			pair<int,int> temp = v[now][i];
			int next = v[now][i].first;
			long long weight = v[now][i].second;
			if(dist[next][depth]>dist[now][depth]+weight){
				dist[next][depth] = dist[now][depth] + weight;
				pq.push({-dist[next][depth],{next,depth}});
			}
			if(depth<K){
				if(dist[next][depth+1]>dist[now][depth]){
					dist[next][depth+1] = dist[now][depth];
					pq.push({-dist[next][depth+1],{next,depth+1}});
				}
			}
		}
	}
	long long min_ = LLONG_MAX;
	for (int i=0;i<=K;i++){
		min_ = min(min_,dist[N][K]);
	}
	/*
	for (int i=0;i<=K;i++){
		printf("%4d: ",i);
		if(dist[N][i]==LLONG_MAX)
			printf("-1\n");
		else
			printf("%5lld\n",dist[N][i]);
	}
	*/
	if(min_==LLONG_MAX)
		printf("AUAICN");
	else
		printf("%lld\n",min_);

	return 0;
}