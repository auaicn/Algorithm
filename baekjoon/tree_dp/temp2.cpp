#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int dp[10010][2];
int save[10010];
int visited[10010];

vector<int> v[10010];
vector<int> v2[10010];

vector<int> result;

void dfs(int now,int parent)
{
    visited[now] = 1;
    if (now != 1)
        v2[parent].push_back(now);

    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i];
        if (!visited[next])
        {
            dfs(next,now);
        }
    }
}

int func(int now,int check)
{
    int &ret = dp[now][check];
    if (ret != -1)return ret;

    ret = 0;

    if (check == 1) {
        ret = save[now];
        for (int i = 0; i < v2[now].size(); i++)
        {
            int next = v2[now][i];
            ret += func(next, 0);
        }
    }
    else
    {
        for (int i = 0; i < v2[now].size(); i++)
        {
            int next = v2[now][i];
            ret += max(func(next,1), func(next, 0));
        }
    }

    return ret;
}

void trace_back(int now, int status)
{
    if (status)
    {
        result.push_back(now);
        for (int i = 0; i < v2[now].size(); i++)
        {
            int next = v2[now][i];
            trace_back(next, 0);
        }
    }
    else
    {
        for (int i = 0; i < v2[now].size(); i++)
        {
            int next = v2[now][i];
            if (dp[next][1] >= dp[next][0])
                trace_back(next, 1);
            else
                trace_back(next, 0);
        }
    }
}
int main()
{

    memset(dp, -1, sizeof(dp));
    int N; scanf("%d", &N);
    for (int i=0;i<N;i++)
        scanf("%d",&save[i+1]);
    
    for (int i = 0; i < N - 1; i++)
    {
        int left,right; scanf("%d %d", &left, &right);
        v[left].push_back(right);
        v[right].push_back(left);
    }

    dfs(1,0);

    int result1 = func(1, 0);
    int result2 = func(1, 1);

    if (result1 >= result2)
        trace_back(1, 0);
    else
        trace_back(1, 1);

    printf("%d\n", max(result1,result2));

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
        printf("%d ", result[i]);
    printf("\n");
}