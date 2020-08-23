#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define UNVISITED (-1)

// connection
vector<int> v[1000010]; 

// connection, in regard to root set to node number '1'
vector<int> child[1000010];

// dp
int dp[1000010][2];
bool visit[1000010];

int min(int x, int y){
	return x<y?x:y;
}

void get_child_with_root_number(int now){
    visit[now] = true;
    for(int i=0 ; i<v[now].size() ; i++){
        int next = v[now][i];
        if(!visit[next]){
        	// not visited
            child[now].push_back(next);
            get_child_with_root_number(next);
        }
    }
}

int dfs(int now, bool status)
{
	// memoization
	if(dp[now][status])
		return dp[now][status];

    int ret = 0;
	if(status)
	{
		// status true
		// then no matter what children's status are
		// + 1 해준다.
        for(int i=0 ; i<child[now].size() ; i++){
            int next = child[now][i];
            ret += min(dfs(next,false), dfs(next,true));
        }
        return dp[now][status] = ret + 1;
	}
	else
	{
		// status false
		// then children must be all early-adopter
		// 그들의 합만 필요하지 + 1 해주지는 않는다.
        for(int i=0 ; i<child[now].size() ; i++){
            int next = child[now][i];
            ret += dfs(next,true);
        }
        return dp[now][status] = ret;
	}

}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N-1;i++)
	{
		int left,right; scanf("%d %d",&left,&right);
		v[left].push_back(right);
		v[right].push_back(left);
	}

	get_child_with_root_number(1);

	printf("%d\n",min(dfs(1,false),dfs(1,true)));

	return 0;
}