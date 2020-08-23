#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int dp[10010][2];
int a[10010];
vector<vector<int>> vt;
vector<vector<int>> vt1;
vector<int> r;
int visited[10010];
void dfs(int here,int par)
{
    visited[here] = 1;
    if (here != 1)vt1[par].push_back(here);
    for (int i = 0; i < vt[here].size(); i++)
    {
        int next = vt[here][i];
        if (!visited[next])
        {
            dfs(next,here);
        }
    }
}
int func(int here,int ch)
{
    int &ret = dp[here][ch];
    if (ret != -1)return ret;
    ret = 0;
    if (ch == 1) {
        ret = a[here];
        for (int i = 0; i < vt1[here].size(); i++)
        {
            int next = vt1[here][i];
            ret += func(next, 0);
        }
    }
    else
    {
        for (int i = 0; i < vt1[here].size(); i++)
        {
            int next = vt1[here][i];
            ret += max(func(next,1), func(next, 0));
        }
    }
    return ret;
}
void ff(int here, int state)
{
    if (state)
    {
        r.push_back(here);
        for (int i = 0; i < vt1[here].size(); i++)
        {
            int next = vt1[here][i];
            ff(next, 0);
        }
    }
    else
    {
        for (int i = 0; i < vt1[here].size(); i++)
        {
            int next = vt1[here][i];
            if (dp[next][1] >= dp[next][0])
                ff(next, 1);
            else
                ff(next, 0);
        }
    }
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d", &n);
    vt.resize(n + 1);
    vt1.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int q, w;
        scanf("%d %d", &q, &w);
        vt[q].push_back(w);
        vt[w].push_back(q);
    }
    dfs(1,0);
    int xx = func(1, 0);
    int yy = func(1, 1);
    if (xx >= yy)
        ff(1, 0);
    else
        ff(1, 1);
    printf("%d\n", max(xx,yy));
    sort(r.begin(), r.end());
    for (int i = 0; i < r.size(); i++)
    {
        printf("%d ", r[i]);
    }
}