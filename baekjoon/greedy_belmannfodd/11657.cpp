#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

long long dist[510];
vector<pair<pair<int,int>,long long> > v;

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<M;i++){
		int left,right; long long weight; scanf("%d %d %lld",&left,&right,&weight);
		v.push_back({{left,right},weight});
	}

	for (int i=0;i<N;i++)
		dist[i+1] = LLONG_MAX;
	dist[1] = 0;

	int num = N-1;
	while(num--){
		for (int i=0;i<M;i++){
			pair<pair<int,int>,int> pos = v[i];
			int left = pos.first.first;
			int right = pos.first.second;
			long long weight = pos.second;
			if(dist[left]==LLONG_MAX)
				continue;
			else if (dist[right]>dist[left]+weight)
				dist[right] = dist[left] + weight;
		}
	}

	bool sw = false;
	for (int i=0;i<M;i++){
		pair<pair<int,int>,int> pos = v[i];
		int left = pos.first.first;
		int right = pos.first.second;
		long long weight = pos.second;
	
		if(dist[left]==LLONG_MAX)
			continue;
		else if (dist[right]>dist[left]+weight){
			sw = true;
			break;
		}
	}

	if(sw){
		printf("-1\n");
		return 0;
	}
	else{
		for (int i=1;i<N;i++){
			if(dist[i+1]==LLONG_MAX)
				printf("-1\n");
			else
				printf("%lld\n",dist[i+1]);
		}
	}
	return 0;
}