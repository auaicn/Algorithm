#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

priority_queue<pair<int,int> > pq;
vector<pair<int,int> > v;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int deadLine, score; scanf("%d %d",&deadLine,&score);
		v.push_back({deadLine,score});
	}

	sort(v.begin(),v.end());

	int date = 1010;
	int track = N-1;
	int res = 0;

	while(--date){
		for (;track>-1;track--){
			//printf("track : %d\n",track);
			pair<int,int> pos = v[track];
			int deadLine = pos.first;
			int score = pos.second;
			if(deadLine<date)
				break;
			pq.push({score,deadLine});
		}
		if(pq.empty())
			continue;
		pair<int,int> pos = pq.top();pq.pop();
		int deadLine = pos.second;
		int score = pos.first;
		res+=score;
		//printf("%4d: %d\n",date,score);
	}

	printf("%d\n",res);
	return 0;
}