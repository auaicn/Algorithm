#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int save[200010];
vector<int> v;
vector<int> v2;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf("%d",&save[i+1]);
	for (int i=0;i<N;i++){
		int temp; scanf("%d",&temp);
		save[i+1]-=temp;
		v.push_back(save[i+1]);
		v2.push_back(-save[i+1]);
	}
	sort(v.begin(),v.end());
	sort(v2.begin(),v2.end());

	int res = 0;
	vector<int>::iterator right;
	vector<int>::iterator left;
	for (int i=0;i<v.size();i++){
		right = lower_bound(v2.begin(),v2.end(),v[i]);
		left = lower_bound(v2.begin(),v2.end(),)
		res+=(it-v2.begin());
	}

	printf("%d\n",res/2);

	return 0;
}

/*
10
4 8 2 6 2 4 8 2 6 2
4 5 4 1 3 4 5 4 1 3
*/