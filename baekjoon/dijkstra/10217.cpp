#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,pair<int,int> > > v[110];
int _time[110];
int money[110];

#define INF (1987654321)

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,M,K; scanf("%d %d %d",&N,&K,&M);
		for (int i=0;i<M;i++){
			int left,right,money_cost,time_cost; scanf("%d %d %d %d",&left,&right,&money_cost,&time_cost);
			v[left].push_back({right,{money_cost,time_cost}});
		}

		for (int i=0;i<N;i++){
			money[i+1] = INF;
			_time[i+1] = INF;
		}

		priority_queue<pair<pair<int,int>,int > > pq;
		pq.push({{0,0},1}); _time[1] = 0; money[1] = 0;
		while(!pq.empty()){
			
			pair<pair<int,int>,int> top_ = pq.top(); pq.pop();
			
			int now = top_.second;

			_time[now] = -top_.first.first;
			money[now] = top_.first.second;

			if(now==N)
				break;

			for (int i=0;i<v[now].size();i++){

				pair<int,pair<int,int> > pos = v[now][i];
				int next = pos.first;
				int money_cost = pos.second.first;
				int time_cost = pos.second.second;

				if(_time[next]>_time[now]+time_cost){
					//printf("auaicn\n");
					if(money_cost+money[now]>K)
						continue;
					_time[next] = _time[now]+time_cost;
					//money[next] = money[now] + money_cost;
					pq.push({{-_time[next],money[now]+money_cost},next});
				}
			}
		}

		while(!pq.empty())
			pq.pop();

		if(_time[N]==INF)
			printf("Poor KCM\n");
		else
			printf("%d\n",_time[N]);

		// init
		for (int i=0;i<N;i++)
			v[i+1].clear();
	}
	return 0;
}
/*
1
2 10 2
1 2 1 11
1 2 1 1

4
3 100 3
1 2 1 1
2 3 1 1
1 3 3 30
4 10 4
1 2 5 3
2 3 5 4
3 4 1 5
1 3 10 6
3 100 3
1 2 1 1
2 3 1 1
1 3 3 30
4 10 4
1 2 5 3
2 3 5 4
3 4 1 5
1 3 10 6
*/