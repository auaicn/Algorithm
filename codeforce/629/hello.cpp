#include <iostream>
#include <queue>

#define pii pair<int,int>
#define mp make_pair
#define INF 1234567890
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

priority_queue<pair<pii, pii> > qu;
int map[126][126];
int dist[126][126];

int main() {
   int N, cnt = 1;
   while (1) {
      cin >> N;
      if (N == 0) break;
      for (int i = 0; i < N; i++) {
         for (int j = 0; j < N; j++) {
            cin >> map[i][j];
         }
      }

      bool visited[126][126];
      for (int i = 0; i <= N; i++) {
         fill(dist[i], dist[i] + N + 1, INF);
         fill(visited[i], visited[i] + N + 1, false);
      }

      
      // 순서대로 최소검은루피, 덤프, x좌표, y좌표
      qu.push(mp(mp(-map[0][0],0), mp(0, 0)));
      dist[0][0] = map[0][0];
      
      while (!qu.empty()) {
         pii now = qu.top().second;
         int dis = -qu.top().first.first;
         qu.pop();
         if (visited[now.first][now.second]) continue;
         visited[now.first][now.second] = true;

         if (now.first == N - 1 && now.second == N - 1) break;
         
         for (int i = 0; i < 4; i++) {
            int x = now.first + dx[i];
            int y = now.second + dy[i];
            pii next = mp(x, y);
            if (x < 0 || y < 0 || x >= N || y >= N) continue;
            // map밖으로 나가면 패스
            
            if (map[x][y] + dis < dist[x][y]) {
               dist[x][y] = map[x][y] + dis;
               qu.push(mp(mp(-dist[x][y], 0), mp(x, y)));
            }
         }
      }

      cout << "Problem " << cnt++ << ": " << dist[N-1][N-1] << endl;
   }
   return 0;
}