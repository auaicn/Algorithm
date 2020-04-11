#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

long long distance[100010];
long long  height[100010];
vector<pair<long long ,long long >> v[100010];
bool visit[100010];

long long  from_home[100010];
long long  to_school[100010];

long long max(long long x, long long y){
	return x>y?x:y;
}

int  main(int argc, char const *argv[])
{

	long long  N,M,D,E; scanf("%lld %lld %lld %lld",&N,&M,&D,&E);
	for (long long  i=0;i<N;i++)
		scanf("%lld",&height[i+1]);
	for (long long  i=0;i<M;i++){
		long long  left,right,weight; scanf("%lld %lld %lld",&left,&right,&weight);
		v[left].push_back({right,weight});
		v[right].push_back({left,weight});
	}

	// from home
	for (long long  i=0;i<N;i++)
		from_home[i+1] = LLONG_MAX;
	priority_queue <pair<long long ,long long >> pq;
	pq.push({0,1}); from_home[1] = 0;

	while(!pq.empty()){
		long long  now;
		do{
			pair<long long ,long long > pos = pq.top(); pq.pop();
			now = pos.second;
		}while(!pq.empty()&&visit[now]);

		if(visit[now])
			break;
		else
			visit[now] = true;

		for (long long  i=0;i<v[now].size();i++){
			long long  next = v[now][i].first;
			long long  weight = v[now][i].second;
			if(height[now]<height[next])
				if(from_home[next]>from_home[now]+weight){
					from_home[next] = from_home[now]+weight;
					pq.push({-from_home[next],next});
				}
		}
	}

	for (long long  i=0;i<N;i++)
		visit[i+1] = false;
	// to school
	for (long long  i=0;i<N;i++)
		to_school[i+1] = LLONG_MAX;
	pq.push({0,N}); to_school[N] = 0;

	while(!pq.empty()){

		long long  now;
		do{
			pair<long long ,long long > pos = pq.top(); pq.pop();
			now = pos.second;
		}while(!pq.empty()&&visit[now]);

		if(visit[now])
			break;
		else
			visit[now] = true;

		for (long long  i=0;i<v[now].size();i++){
			long long  next = v[now][i].first;
			long long  weight = v[now][i].second;
			if(height[now]<height[next])
				if(to_school[next]>to_school[now]+weight){
					to_school[next] = to_school[now]+weight;
					pq.push({-to_school[next],next});
				}
		}
	}	

	long long res = LLONG_MIN;

	for (long long  i=1;i<N-1;i++){
		// looking for i+1 th element
		if(from_home[i+1]!=LLONG_MAX&&to_school[i+1]!=LLONG_MAX){
			long long temp = from_home[i+1] + to_school[i+1];
			temp*=-D;
			temp+=E*height[i+1];
			//printf("%lld\n",temp);
			res = max(res,temp);
		}
	}

	if(res==-LLONG_MIN)
		printf("Impossible\n");
	else
		printf("%lld\n",res);

	return 0;
}