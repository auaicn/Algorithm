#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>
#define INF 1000000000000
using namespace std;

vector<pair<int, int>> arr[501];

long long dist[501];
long long s_dist[501];
bool visit[501];

int main()
{
	while (1)
	{
		int n, m; scanf("%d %d", &n, &m);
		if (!n && !m) break;
		int s, d; scanf("%d %d", &s, &d);
		for (int i = 0; i <= n; i++) arr[i].resize(0);
		fill(dist, dist + n + 1, INF);
		fill(s_dist, s_dist + n + 1, INF);

		while (m--)
		{
			int u, v, p; scanf("%d %d %d", &u, &v, &p);
			arr[u].push_back({ v,p });
		}

		priority_queue<pair<long long, int>> pq;
		pq.push({ 0,s });
		dist[s] = 0;

		while (!pq.empty())
		{
			int now = pq.top().second; pq.pop();

			int vsize = arr[now].size();

			for (int i = 0; i < vsize; i++)
			{
				int next = arr[now][i].first;
				int val = arr[now][i].second;

				long long tmp = dist[now] + val;

				if (tmp < dist[next])
				{
					s_dist[next] = dist[next];
					dist[next] = tmp;
					pq.push({ -dist[next], tmp });
				}

				if (tmp > dist[next]&&s_dist[next]>tmp)
				{
					s_dist[next] = tmp;
				}
			}
		}
		//for (int i = 0; i <= n; i++) cout << dist[i] << " " << s_dist[i] << endl;
		if (s_dist[d] == INF) printf("-1\n");
		else printf("%lld\n", s_dist[d]);
	}
}