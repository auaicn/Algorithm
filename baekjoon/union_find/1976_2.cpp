#include <stdio.h>

int parent[210];

int find (int x) {
  if (x == parent[x]) return x;

  else return parent[x] = find(parent[x]);
}

int main(){
  int N; scanf("%d", &N);
  int M; scanf("%d", &M);

  for (int i=0;i<N;i++) parent[i+1] =i+1;

  for (int i=0;i<N;i++){
    for (int j=0;j<N;j++){
      int routeExists; scanf("%d", &routeExists);

      if (i < j) continue;

      if (routeExists){
        int oneGroup = find(i+1);
        int anotherGroup = find(j+1);

        if (oneGroup == anotherGroup) continue;
        else parent[oneGroup] = anotherGroup;
      }
    }
  }

  int journeyGroup = -1;

  for (int i=0;i<M;i++){
    int city; scanf("%d", &city);
    int group = find(city);

    if (journeyGroup == -1) journeyGroup = group;
    else if (journeyGroup != group) {
      printf("NO\n");
      return 0;
    }
  }

  printf("YES\n");
  return 0;
}