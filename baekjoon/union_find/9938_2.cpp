/*
술병 N 개 서랍 L 개

서랍에는 술병이 하나 들어갈 수 있다.
각 술병은 서랍 두개중 하나에 들어갈 수 있다.

서랍에 몇번 술이 들어가 있는지는 중요하지 않다.
1번 룰에 의해서 비어있다고 넣는 거랑, 3번이랑 다를 게 없는 것 같은데?

1. A-B union 할 거면, 규칙 무시하고 B 에 넣어주거나, 나중에 B 에 넣으려는 애가 있어서 대신에 A 넣는거랑
2. A 넣었다가 B 에 넣어주는 거랑 결과가 같다.

나중에 한번 제출해보자 ab 임의로 바꿔서

근데, 조금 주의해야 할 점은 나중에 B 넣을수가 없다는 거구나. 그래서
A group size 봐야한다는 거고,

아냐 다른애들중 A 에 들어갈 수 있었던 애면
*/

#include <stdio.h>

int parent[300010];

int size[300010];
int space[300010];

int find (int x){
  if (x==parent[x]) return x;
  else return parent[x] = find (parent[x]);
}

int main(){
  int N,L; scanf("%d %d",&N,&L);

  for (int i=0;i<L;i++) {
    parent[i+1] = i+1;
    space[i+1] = 1;
    size[i+1] = 1;
  }

  for (int i=0;i<N;i++){
    int one, another; scanf("%d %d", &one, &another);

    int oneAncestor = find(one);
    int anotherAncestor = find(another);

    if(oneAncestor != anotherAncestor){
      parent[oneAncestor] = anotherAncestor;

      size[anotherAncestor] += size[oneAncestor];
      space[anotherAncestor] += space[oneAncestor];
    }

    if (space[anotherAncestor]){
      printf("LADICA\n");
      space[anotherAncestor]--;
    }else{
      printf("SMECE\n");
    }
  }
}