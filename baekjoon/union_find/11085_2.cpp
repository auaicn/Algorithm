/*
p 개의 지점 w 개의 길 (양방향), 길마다 너비가 존재한다.
지점에서 지점으로 가는데, 경로를 따라서 간다.

군사를 최대한 많이 보내기 위해서? 경로상에 있는 길 중 너비가 가장 좁은 길의 너비를 최대화 하는 경로를 택했다.
병사를 몇명 보냈는지 같은 건 없다.

*/

#define INF (1987654321)

#include <stdio.h>
#include <queue>

using namespace std;

int group[1010];
int minimumWeight[1010];

int min(int x, int y){
  return x<y?x:y;
}

int find(int x){
  if(x==group[x]) return x;
  else return group[x] = find(group[x]);
}

typedef struct Edge {
  int left;
  int right;
  int weight;

  bool operator<(Edge another) const {
    return weight < another.weight;
  }
} Edge;

priority_queue<Edge> pq;

int main(){
  int numberOfPoints, numberOfWays; scanf("%d %d",&numberOfPoints, &numberOfWays);

  for (int i=0;i<numberOfPoints;i++) {
    group[i] = i;
    minimumWeight[i] = INF;
  }

  int baekjoon, cube; scanf("%d %d", &baekjoon, &cube);

  for (int i=0;i<numberOfWays; i++){
    int left, right, weight; scanf("%d %d %d", &left, &right, &weight);

    pq.push(Edge{left,right,weight});
  }

  while(!pq.empty()){
    Edge current = pq.top(); pq.pop();

    int left = current.left;
    int right = current.right;
    int weight = current.weight;

    int leftAncestor = find(left);
    int rightAncestor = find(right);

    if (leftAncestor == rightAncestor) continue;

    group[leftAncestor] = rightAncestor;

    minimumWeight[rightAncestor] = min(min(minimumWeight[leftAncestor], minimumWeight[rightAncestor]), weight);

    // test
    int baekjoonGroup = find(baekjoon);
    int cubeGroup = find(cube);

    if (baekjoonGroup == cubeGroup){
      printf("%d\n", minimumWeight[rightAncestor]);
      return 0;
    }
  }
}