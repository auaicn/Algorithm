#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<long long,int> > pq;

int main(int argc, char const *argv[])
{
	int L,N; scanf("%d %d",&L,&N);
	long long Farmer,Bessie; scanf("%lld %lld",&Farmer,&Bessie);

	for (int i=0;i<N;i++){
		int x; long long taste; scanf("%d %lld",&x,&taste);
		pq.push({taste,x});
	}

	long long res = 0;

	int now = 0;

	while(!pq.empty()){
		pair<int,int> pos = pq.top(); pq.pop();
		int x_ = pos.second;
		long long taste = pos.first;

		if(x_<=now)
			continue;
		else{
			res+=(x_-now)*(Farmer-Bessie)*taste;
			now = x_;
		}

	}


	printf("%lld\n",res);
	return 0;
}