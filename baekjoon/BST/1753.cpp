#define INF (1987654321)

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

priority_queue<pair<int,int> > pq;

vector<pair<int,int> > v[20010];
int dist[20010];
bool visit[20010];

int min (int x, int y){
  return x<y?x:y;
}

int main(){
  int V,E; scanf("%d %d", &V,&E);
  int S; scanf("%d", &S);

  for (int i=0;i<V;i++) dist[i+1] = INF;


  // 여러개의 간선이 존재할 수도 있다.
  // 간선 개수 30만, V 2만 > 배열은 안된다.
  // 정점은 1-base
  // u v w
  for (int i=0;i<E;i++){
    int left, right, weight; scanf("%d %d %d", &left, &right, &weight);

    v[left].push_back({right, weight});
  }

  pq.push({-0, S});
  dist[S] = 0;

  while(!pq.empty()){
    pair<int,int> top = pq.top(); pq.pop();

    int distanceSoFar = -top.first;
    int node = top.second;

    if (visit[node]) continue;

    visit[node] = true;

    for (int i=0;i<v[node].size();i++){
      pair<int,int> next = v[node][i];

      int destination = next.first;
      int weight = next.second;

      int newDistance = distanceSoFar + weight;

      dist[destination] = min(dist[destination], newDistance);

      pq.push({-dist[destination], destination});
    }
  }

  for (int i=0;i<V;i++){
    int destination = i+1;

    if (dist[destination] == INF){
      printf("INF\n");
    }else{
      printf("%d\n", dist[destination]);
    }
  }
}