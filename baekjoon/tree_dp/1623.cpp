#include <stdio.h>
#include <vector>
#include <iostream>
//#include <algorithm>

using namespace std;

//  vector<int> res[2];

int max(int x,int y){
	return x>y?x:y;
}

int dp[200010][2];
int save[200010];
bool visit[200010];
vector<int> child[200010];

bool who_added[200010][2];

int dfs(int now, bool status, int round)
{

	// if(dp[now][status])
	// 	return dp[now][status];

	visit[now] = true;

    int ret = 0;

    for (int i=0;i<child[now].size();i++)
    {
    	int next = child[now][i];
    	if(visit[next])
    		continue;
    	if(status)
    	{
    		// me on
    		// 밑에 직원들 false, Ret 에 더해준다.
        	ret += dfs(next,false,round);
    	}
	    else
	    {
         	// 밑에 직원 있어도 없어도 됨 최대값이면 됨
            int this_child_yes = dfs(next,true,round);
            int this_child_no = dfs(next,false,round);
            if(this_child_yes > this_child_no)
            {
            	ret += this_child_yes;
            	// res[round].push_back(next);
            	who_added[next][round] = true;
            }
            else
            	ret += this_child_no;
	    }
    }
    
	visit[now] = false;
    return dp[now][status] = ret;


	if(status)
	{

		ret = save[now];

		// me, on
        for(int i=0 ; i<child[now].size() ; i++){
            int next = child[now][i];

            // 밑에 직원들 false, Ret 에 더해준다.
        	ret += dfs(next,false,round);
        }

	     // res[round].push_back(now);
	    return dp[now][status] = ret;
	}
	else
	{
		// me not.
        for(int i=0 ; i<child[now].size() ; i++){
            int next = child[now][i];

            // 밑에 직원 있어도 없어도 됨 최대값이면 됨
            int this_child_yes = dfs(next,true,round);
            int this_child_no = dfs(next,false,round);
            if(this_child_yes > this_child_no)
            {
            	ret += this_child_yes;
            	// res[round].push_back(next);
            	who_added[next][round] = true;
            }
            else
            	ret += this_child_no;
            // ret += max(dfs(next,false,round), dfs(next,true,round));
        }
        return dp[now][status] = ret;
	}

	visit[now] = false;


}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf("%d",&save[i+1]);
	for (int i=0;i<N-1;i++)
	{
		int parent; scanf("%d",&parent);
		child[parent].push_back(i+2);
	}

	int res1 = 	dfs(1,0,0);
	int res2 = dfs(1,1,1);

	// sorting 해준후에 추가해주자.
	// sort(res[0].begin(),res[0].end());
	// sort(res[1].begin(),res[1].end());


	if(res2<0)
		printf("0 ");
	else
		printf("%d ",res2);

	if(res1<0)
		printf("0");
	else
		printf("%d",res1);

	printf("\n");

	if(res2>0)
	{
		printf("1 ");
		for (int i=1;i<N;i++)
			if(who_added[i+1][1])
				printf("%d ",i+1);
	}
	printf("-1\n");

	if(res1>0)
	{
		for (int i=1;i<N;i++)
			if(who_added[i+1][0])
				printf("%d ",i+1);
	}
	printf("-1");

	/*
	for (int i=0;i<res[1].size();i++)
		printf("%d ",res[1][i]);
	printf("-1\n");

	for (int i=0;i<res[0].size();i++)
		printf("%d ",res[0][i]);
	printf("-1\n");
	*/	

	return 0;
}