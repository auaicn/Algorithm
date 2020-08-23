#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

#define MOD (1000000007)
#define MAX_ARRAY_SIZE (1000010)

using namespace std;

int min(int x, int y){
	return x<y?x:y;
}

int max(int x, int y){
	return x>y?x:y;
}

vector<int> v[MAX_ARRAY_SIZE];
int indegree[MAX_ARRAY_SIZE];
// int color[MAX_ARRAY_SIZE];

queue<int> q;

vector<int>::iterator it;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	for (int testCase = 0; testCase < T; testCase++)
	{
		long long res = 1;
		
		// scan
		int N,K; scanf("%d %d",&N,&K);

		// initialize
		for (int i=0;i<N;i++){
			v[i+1].clear();
			indegree[i+1] = 0;
		}

		// make connection
		for (int i=0;i<N;i++){
			
			int j; scanf("%d",&j);
			
			if(i+1 == j)
				continue;

			int low = min(i+1,j);
			int high = max(i+1,j);

			it = lower_bound(v[low].begin(),v[low].end(),high);
			if(it!=v[low].end())
				continue;
			v[min(i+1,j)].push_back(max(i+1,j));
			indegree[max(i+1,j)]++;
		}

		for (int i=0;i<N;i++)
		{
			res *= K - indegree[i+1];
			res %= MOD;
		}

		printf("Case #%d\n",testCase+1);
		printf("%lld\n",res);

	}
	return 0;
}



