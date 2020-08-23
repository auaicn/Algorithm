#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define SIZE (10010)

// connection
vector<int> v[SIZE]; 

// dp
int save[SIZE];
bool visit[SIZE];
bool res[2][SIZE];

int dp[SIZE][2];

int max(int x, int y){
	return x>y?x:y;
}

int dfs(int now, bool status, int round)
{
	// if(dp[now][status])
	// 	return dp[now][status];

	visit[now] = true;
    int ret = 0;

    for(int i=0; i<v[now].size(); i++){

		int next = v[now][i];
            if(visit[next])
    			continue;

		if(status)
			// me on, child all false
            ret += dfs(next,false,round);
		else{
			// me off, child maybe either be true or false
			int result1 = dfs(next, false, round);
			int result2 = dfs(next, true, round) + save[next];
			if(result1>result2)
				// next off is bigger
				ret += result1;
			else
			{
				// next used(on) is bigger
				ret += result2;
            	res[round][next] = true;
			}
		}

    }

	visit[now] = false;
	//return dp[now][status] = ret;
	return ret;
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);

	for (int i=0;i<N;i++)
		scanf("%d",&save[i+1]);

	for (int i=0;i<N-1;i++)
	{
		int left,right; scanf("%d %d",&left,&right);
		v[left].push_back(right);
		v[right].push_back(left);
	}

	// root off
	int result1 = dfs(1,false,0);
	// for (int i=0;i<N;i++)
	// 	dp[i+1][0] = dp[i+1][1] = 0;

	// root on
	int result2 = dfs(1,true,1) + save[1];

	if(result1>result2)
	{
		// root off bigger
		// round value is 0
		printf("%d\n",result1);
		for (int i=1;i<N;i++)
			if(res[0][i+1])
				printf("%d ",i+1);
	}
	else
	{
		// root on is bigger
		// round value is 1
		printf("%d\n",result2);
		printf("1 ");
		for (int i=1;i<N;i++)
			if(res[1][i+1])
				printf("%d ",i+1);
	}
	printf("\n");
	return 0;
}