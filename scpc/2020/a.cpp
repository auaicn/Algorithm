#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v; 
vector<int> rev;

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	for (int t=0;t<T;t++)
	//while()
	{
		v.clear();
		rev.clear();
		int N,K; scanf("%d %d",&N,&K);
		for (int i=0;i<N;i++)
		{
			int temp; scanf("%d",&temp);
			v.push_back(temp);
		}
		for (int i=0;i<N;i++)
		{
			int temp; scanf("%d",&temp);
			rev.push_back(temp);
		}
		sort(v.begin(),v.end());
		sort(rev.begin(),rev.end());
		// for (int i=0;i<v.size();i++)
		// 	printf("%3d",v[i]);
		// printf("\n");
		// for (int i=0;i<rev.size();i++)
		// 	printf("%3d",rev[i]);
		// printf("\n");

		int res = -1;
		for (int i=0;i<K;i++)
		{
			res = max(res,v[i] + rev[K-1-i]);
		}
		printf("Case #%d\n",t+1);
		printf("%d\n",res);
	}
	return 0;
}

// 2
// 2 2
// 1 2
// 4 2
// 3 2
// 6 3 1
// 1 4 3
// 출력
// Case #1
// 5
// Case #2
// 4