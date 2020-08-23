#include <stdio.h>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
 
int n;
int price[10001];
bool visited[10001];
vector<int> map[10001];
 
ll dfs(int v, bool flag) {
    int ans = 0;
    visited[v] = true;
 
    for (int i = 0; i < map[v].size(); i++) {
        int next = map[v][i]; //다음 마을
        if (visited[next]) continue; //이미 방문했으면 continue
        //현재마을이 우수마을인 경우
        if (flag) {
            ans += dfs(next, 0);
        }
        //현재마을이 우수마을이 아닌 경우
        else {
            ans += max(dfs(next, 0), dfs(next, 1) + price[next]);
        }
    }
 
    visited[v] = false;
    return ans;
}
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &price[i]);
    n--;
 
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        map[x].push_back(y);
        map[y].push_back(x);
    }
 
    printf("%lld\n", max(dfs(1, 0), dfs(1, 1) + price[1]));
}
