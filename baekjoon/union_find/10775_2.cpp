/*
G 개의 게이트, 1-base
P 개의 비행기, 순서대로 도착 에정, 비행기를 도킹해야한다. 도킹할 데 없으면 공항이 폐쇄,
1 - 입력값 인덱스의 게이트에 넣는것이 가능하다.
최대 몇 대를 도킹시킬 수 있는가?
*/

#include <stdio.h>

int parent[100010];
bool visit[100010];

int findGateToPut(int x){
  if (visit[x] == false) return x;
  else if (x==1) return -1;
  else return parent[x] = findGateToPut(parent[x]);
}

int main(){
  int numGates, numPlains; scanf("%d %d", &numGates, &numPlains);

  parent[1] = 1;
  for (int i=1;i<numGates;i++) parent[i+1] = i;

  bool done = false;
  int numInsertedPlains = 0;

  // input 은 끝까지 받아야 한다.
  for (int i=0;i<numPlains;i++){
    int maximumIndex; scanf("%d", &maximumIndex);

    if (done) continue;

    int gateToPut = findGateToPut(maximumIndex);

    if (gateToPut == -1){
      done = true;
      continue;
    }

    numInsertedPlains += 1;
    visit[gateToPut] = true;
  }

  printf("%d\n", numInsertedPlains);
}