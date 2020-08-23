#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

#define INF (1987654321)

int dp[110];
int parent[110];
vector<int> edge[110];

int max(int x, int y){
    return x>y?x:y;
}

int dfs(int x)
{

    if(dp[x] != -1)
        return dp[x];

    int ret = -1;

    // ret 를 -1 이라고 하였기 때문에
    // 비어있는경우, 0 을 리턴할 수 있도록 하자.

    if(edge[x].empty())
        return 0;

    vector<int> temp;
    for(int i = 0;i<edge[x].size();i++)
    {
        int next = edge[x][i];
        temp.push_back(dfs(next));
    }

    sort(temp.begin(),temp.end(),greater<int>());

    for (int i=0;i<temp.size();i++)
    {
        ret = max(ret, temp[i] + i + 1);
    }

    return ret;
}
int main()
{
    int N; scanf("%d",&N);

    memset(dp,-1,sizeof(dp));

    if(N == 1)
    {
        printf("0\n");
        return 0;
    }

    for (int i=0;i<N;i++)
    {
        scanf("%d",&parent[i]);
        if(parent[i]!=-1)
            edge[parent[i]].push_back(i);
    }
    printf("%d\n",dfs(0));
    return 0;
}