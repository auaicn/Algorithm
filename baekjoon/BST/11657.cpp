#define INF (1987654321)

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int dist[20010];

vector<pair<pair<int,int>, int> > edges;

int min (int x, int y){
  return x<y?x:y;
}

int main(){
  int V,E; scanf("%d %d", &V,&E);
  int S = 1;

  for (int i=0;i<V;i++) dist[i+1] = INF;

  for (int i=0;i<E;i++){
    int left, right, weight; scanf("%d %d %d", &left, &right, &weight);

    edges.push_back({{left,right}, weight});
  }

  dist[S] = 0;
  for (int loop=0;loop<V-1;loop++){
    for (int i=0;i<edges.size();i++){
      pair<pair<int,int>, int> edge = edges[i];

      int weight = edge.second;
      int left =edge.first.first;
      int right = edge.first.second;

      dist[right] = min(dist[right], dist[left] + weight);
    }
  }

  // detect cycle
   for (int i=0;i<edges.size();i++){
      pair<pair<int,int> ,int> edge = edges[i];

      int weight = edge.second;
      int left =edge.first.first;
      int right = edge.first.second;

      if (dist[right] > dist[left] + weight){
        printf("-1\n");
        return 0;
      }
    }

  for (int i=1;i<V;i++){
    int destination = i+1;

    if (dist[destination] == INF){
      printf("-1\n");
    }else{
      printf("%d\n", dist[destination]);
    }
  }
}