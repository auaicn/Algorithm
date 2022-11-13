/*
초기 N+1 개의 집합
1. 합집합 연산
2. 두 원소가 같은 집합에 포함되어 있는지 확인하는 연산

parent 만 비교하도록 한다.
*/

#include <stdio.h>

#define SIZE (1000010)

int group[SIZE];

int find(int x){
  if (x == group[x]) return x;
  else return group[x] = find(group[x]);
}

int main(){
  int N,M; scanf("%d %d",&N,&M); // N 10E6 M 10E5

  for (int i=0;i<N+1;i++){
    group[i] = i;
  }

  while(M--){
    int command, one, another; scanf("%d %d %d", &command, &one, &another);

    if (command){
      // check
      if (find(one) == find(another)) {
        printf("YES\n");
      }else{
        printf("NO\n");
      }
    }else{
      // union
      int ancestor = find(one);
      int anotherAncestor = find(another);

      if (ancestor != anotherAncestor) {
        group[ancestor] = anotherAncestor;
      }
    }
  }
}