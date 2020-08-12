#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int x,int y){
	return x>y?x:y;
}

int min(int x, int y){
	return x<y?x:y;
}

vector<int> v;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N; scanf("%d",&N);
		for (int i=0;i<N;i++){
			int temp ; scanf("%d",&temp);
			v.push_back(temp);
		}
		sort(v.begin(),v.end());

		int min_ = 1987654321;
		int left;
		int right;
		for (int i=0;i<v.size()-1;i++)
			min_ = min(v[i+1]-v[i],min_);
		printf("%d\n",min_);
		v.clear();
	}
	return 0;
}