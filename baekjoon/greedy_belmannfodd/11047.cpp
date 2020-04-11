#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(int argc, char const *argv[])
{
	int N,K; scanf("%d %d",&N,&K); // K up to 10E8
	for (int i=0;i<N;i++){
		int temp; scanf("%d",&temp);
		v.push_back(-temp);
	}
	int cnt_ = 0;
	sort(v.begin(),v.end());
	for (int i=0;i<N;i++){
		if(!K)
			break;
		int value = -v[i];
		cnt_+=K/value;
		K = K%value;
	}
	printf("%d\n",cnt_);
	return 0;
}