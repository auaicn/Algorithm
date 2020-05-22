#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int> > v;
vector<int> lis;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int left,right; scanf("%d %d",&left,&right);
		v.push_back({left,right});
	}
	sort(v.begin(),v.end());

	lis.push_back(0);
	vector<int>::iterator it;
	for (int i=0;i<N;i++){
		it = lower_bound(lis.begin(),lis.end(),v[i].second);
		if(it==lis.end())
			lis.push_back({v[i].second});
		else
			*it = v[i].second;
	}
	printf("%d\n",N-(lis.size()-1));
	return 0;
}