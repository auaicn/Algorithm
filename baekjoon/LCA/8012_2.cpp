#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_N (30001)
#define SWAP(a,b) {int t = b; b = a; a = t;}

vector<int> vec[MAX_N];
bool visit[MAX_N];
int depth[MAX_N];
int par[MAX_N][20];
int dis[MAX_N];
vector<int> m_vec;

void dfs(int now, int nowDepth, int prev) {
	visit[now] = true;
	depth[now] = nowDepth;
	par[now][0] = prev;
	for (int i = 0; i < vec[now].size(); i++) {
		if (visit[vec[now][i]] == false) {
			dfs(vec[now][i], nowDepth + 1, now);
		}
	}
}

int lca(int x, int y) {
	int ret = 0;
	if (depth[x] > depth[y]) SWAP(x, y);
	for (int i = 19; i >= 0; i--) {
		int diff = depth[y] - depth[x];
		if (diff >= (1 << i)) {
			y = par[y][i];
		}
	}
	if (x == y) return x;
	for (int i = 19; i >= 0; i--) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M; cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	dfs(1, 0, 1);
	
	for (int j = 1; j <= 19; j++) {
		for (int i = 1; i <= N; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	
	cin >> M;
	int prev, now;
	long long ret = 0;
	for (int i = 0; i < M; i++) {
		cin >> now;
		
	if (i) ret += depth[prev] + depth[now] - 2 * depth[lca(now, prev)];
		prev = now;
	}

	cout << ret << "\n";
}
