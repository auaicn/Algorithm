#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int> > v;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int left,right; scanf("%d %d",&left,&right);
		v.push_back({right,left});
	}
	sort(v.begin(),v.end());

	int available = -1;
	int res = 0;

	for (int i=0;i<N;i++){
		pair<int,int> lookup = v[i];
		int time_start = lookup.second;
		int time_end = lookup.first;
		if(time_start>=available){
			available = time_end;
			res++;
		}
	}
	printf("%d\n",res);
	return 0;
}