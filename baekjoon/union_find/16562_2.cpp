#include <stdio.h>

int group[10010];
int minimumCostToBeFriend[10010];

int min(int x, int y){
  return x<y?x:y;
}

int find(int x){
  if (x == group[x]) return x;
  else {
    return group[x] = find(group[x]);
  }
}

int main(){
  int N,M,K; scanf("%d %d %d",&N,&M,&K);

  for (int i=0;i<N;i++){
    int cost; scanf("%d",&cost);
    group[i+1] = i+1;
    minimumCostToBeFriend[i+1] = cost;
  }

  while(M--){
    int one, another; scanf("%d %d", &one, &another);

    int oneGroup = find(one);
    int anotherGroup = find(another);

    if (oneGroup == anotherGroup) continue;
    else {
      group[oneGroup] = anotherGroup;

      minimumCostToBeFriend[anotherGroup] = min(minimumCostToBeFriend[oneGroup], minimumCostToBeFriend[anotherGroup]);
      minimumCostToBeFriend[oneGroup] = 0;
    }
  }

  int totalCost = 0;
  for (int i=0;i<N;i++) totalCost += minimumCostToBeFriend[i+1];

  if (totalCost > K) {
    printf("Oh no\n");
  }else{
    printf("%d\n", totalCost);
  }
}