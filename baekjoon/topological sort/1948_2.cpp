#define SIZE (10010)

/*
일방통행, cycle 없다
무수한 사람이 시작 도시로부터 도착 도시까지 출발해 가능한 모든 경로를 탐색한다.

도착도시에서 다시 만나자 / 출발한 후 몇시간 후에 만날 수 있는가?
이런 사람들이 지나는 도로의 수를 카운트해라.

출발 도시는 들어오는 도로가 0개이고 도착도시는 나가는 도로가 0개이다.
*/

/* -------------------------------------------------------------------------- */
/*                                 Enhancement                                */
/* -------------------------------------------------------------------------- */

/*
### 배운점

- 오답일 때는, 값이 크게 나왔거나 작게 나왔거나이다. 당연한 것이지만, 생각하기 어려운 점은 값이 크게 나왔을 때는 "중복" 이 있을 것이라는 점이다. 다음부터는 염두에 두도록 하자.
- 테스트케이스는 완벽하지 않을 수 있기 때문에 섣불리 제출하는 것이 오히려 독이 되는 것 같다.
- 역시나 문제를 제대로 읽지 않아서, 시작점과 끝점이 주어지는지, 그리고 시작점으로부터 모든 점이 도달할 수 있다는 점, 끝점도 항상 어디서든지 도달할 수 있다는 내용을 보지 못했다.
- 문제를 잘 읽어서 쓸 데 없는 시간을 허비하지 않도록 하고, 그 시간을 오히려 정말 이 구현이 맞을지 생각해보는 데에 투자해보자.
- edge 에 번호를 매기는 것 대신, end, start pair 로 edge 를 특정할 수 있다는 아이디어는 좋았다.

*/

#include <stdio.h>
#include <queue>
#include <vector>
#include <set>

using namespace std;

queue<int> q;

vector<pair<int,int> > v[SIZE];

bool visit[SIZE];
int incoming[SIZE];
set<int> incomingExhaustiveEdges[SIZE];
int maxDistanceFromStartCity[SIZE];

int max(int x, int y){
  return x>y?x:y;
}

int main(){
  int N; scanf("%d", &N);
  int M; scanf("%d" ,&M);

  while(M--){
    int start, end, weight; scanf("%d %d %d", &start, &end, &weight);

    incoming[end]++;
    v[start].push_back({end, weight});
  }

  int startCity, endCity; scanf("%d %d", &startCity, &endCity);

  q.push(startCity);

  while(!q.empty()){
    int city = q.front(); q.pop();

    for (int i=0;i<v[city].size();i++){
      pair<int,int> route = v[city][i];

      int nextCity = route.first;
      int weight = route.second;

      int existingDistance = maxDistanceFromStartCity[nextCity];
      int distance = maxDistanceFromStartCity[city] + weight;

      if (distance == existingDistance){
        // routeWithoutRest[nextCity] += routeWithoutRest[city] + 1;
        incomingExhaustiveEdges[nextCity].insert(city);
      }else if (existingDistance < distance){
        // // routeWithoutRest[nextCity] = routeWithoutRest[city] + 1;
        maxDistanceFromStartCity[nextCity] = distance;
        incomingExhaustiveEdges[nextCity].clear();
        incomingExhaustiveEdges[nextCity].insert(city);
      }

      incoming[nextCity]--;
      if (incoming[nextCity] == 0){
        q.push(nextCity);
      }
    }
  }

  int numExhaustiveEdge = 0;
  queue<int> aq; aq.push(endCity);
  while(!aq.empty()){
    int now = aq.front(); aq.pop();

    if (visit[now]) continue;

    visit[now] = true;
    numExhaustiveEdge += incomingExhaustiveEdges[now].size();

    for (auto i : incomingExhaustiveEdges[now]){
      aq.push(i);
    }
  }

  printf("%d\n", maxDistanceFromStartCity[endCity]);
  printf("%d\n", numExhaustiveEdge);
}