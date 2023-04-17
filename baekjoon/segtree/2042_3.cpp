/*
N 개의 수, 변경이 빈번하다.
1. 부분 합을 구한다.
2. 특정 위치 값을 주어진 값으로 변경한다.

Seg Tree 는 4배 크기의

// 원소가 4개일 떄 이런식인데
10
3 7
1 2 3 4

원소가 3개일 때 필요한 개수 : 1 + 2 + 4 = 7

처음 start end 는 끝 까지 유지하는 듯

6(1)
3(2)  3(3)
1(4) 2 3(6) (0)

left right index 접근이 꽤 쉬워야 한다.
2배

*/

#include <stdio.h>

using namespace std;

long long board[1000010];

long long sumUp(int left, int right){
  // linear never
  // mid

  int mid = (left + right) / 2
}

int main(){
  int N,M,K; scanf("%d %d %d", &N,&M,&K);

  for (int i=0;i<N;i++){
    scanf("%d", &board[i+1]); // 1-base
  }

  for (int i=0;i<M+K;i++){
    int command; scanf("%d",&command);

    switch(command){
      case 1: // update
        int position, value; scanf("%d %d", &position, &value);
        break;
      case 2: // sum up
        int left, right; scanf("%d %d", &left, &right);
        pritnf("%d\n", sumUp(left, right));
        break;
    }
  }
}