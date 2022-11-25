// #define INF (1987654321)

/*
건물을 짓는 순서가 정해져 있지 않다.
매 게임 시작 시 건물을 짓는 순서가 정해진다.
모든 건물은 완성이 될 때까지 걸리는 시간이 있다.
선행 건물이 있다. 1번 이 완료되어야 2번, 3번을 시작할 수 있다.
동시에 여러 건물의 건설을 시작할 수 있다. 선행 건물의 제한이 없는 한

특정 건물만 짓는다면 승리할 수 있다.
특정 건물을 가장 빨리 지을 때 까지 걸리는 최소시간을 알아내자
*/

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int cost[1010];
int totalCost[1010];

queue<int> q;
vector<int>v[1010];
int inDegree[1010];

int max(int x, int y){
  return x>y?x:y;
}

int main(){
  int T; scanf("%d",&T);

  while(T--){
    // N up to 1000, numRules up to 10E5
    // 건물 번호는 1번부터 N 번이다.
    int N, numRules; scanf("%d %d", &N, &numRules);

    while(!q.empty()) q.pop();

    for (int i=0;i<N;i++){
      v[i+1].clear();
      inDegree[i+1] = 0;
      totalCost[i+1] = 0;
    }

    // 각 건물당 건설에 걸리는 시간
    for (int i=0;i<N;i++){
      scanf("%d", &cost[i+1]);
    }

    // 건설 순서 (모든 건물이 건설 가능하도록 주어진다.)
    for (int i=0;i<numRules;i++){
      int left, right; scanf("%d %d", &left, &right);

      v[left].push_back(right);
      inDegree[right]++;
    }

    int winTower; scanf("%d", &winTower);

    for (int i=0;i<N;i++){
      if (inDegree[i+1] == 0) q.push(i+1);
    }

    while(!q.empty()){
      int currentTower = q.front(); q.pop();

      totalCost[currentTower] += cost[currentTower];

      if (currentTower == winTower){
        printf("%d\n", totalCost[winTower]); // 걸리는 시간 10E5 타워 10E3 일렬이래도 10E8 safe
        break;
      }

      for (int i=0;i<v[currentTower].size();i++){
        int nextTower = v[currentTower][i];

        totalCost[nextTower] = max(totalCost[nextTower], totalCost[currentTower]);

        inDegree[nextTower]--;
        if (inDegree[nextTower] == 0){
          q.push(nextTower);
        }
      }
    }
  }
}