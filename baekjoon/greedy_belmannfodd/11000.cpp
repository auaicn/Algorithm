#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int,int> > v;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int left,right; scanf("%d %d",&left,&right);
		v.push_back({left,right});
	}
	int res = 1;
	priority_queue<int> pq; pq.push(1);
	sort(v.begin(),v.end());
	for (int i=0;i<N;i++){
		pair<int,int> lookup = v[i];
		int time_start = lookup.first;
		int time_end = lookup.second;
		int pos = -pq.top();
		if(pos<=time_start){
			pq.pop();
			pq.push(-time_end);

		}else{
			res++;
			pq.push(-time_end);
		}
	}
	printf("%d\n",res);
	return 0;
}