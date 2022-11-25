/*
N 개의 빌딩
i 번째 빌딩의 키가 h_i 모든 빌딩은 일렬로 서있고 오른쪽으로만 볼 수 있다.
i 번째 빌딩 관리인이 볼 수 있는 ~~
자기보다 같거나 크면 그 뒤에 있는 빌딩 옥상은 못본다
관리인들이 옥상정원 확인할 수 있는 총수를 구하자
*/

#define INF (1987654321)

#include <stdio.h>
#include <stack>

using namespace std;

long long totalDistance;

/*
first: height
second: index

order doesn't matter
*/
stack<pair<int,int> > s;

void clearLTEMeAndSumUp (int height, int index){
  while(!s.empty()){
    pair<int,int> top = s.top();

    int topHeight = top.first;
    int topIndex = top.second;

    int distance = index - topIndex - 1;

    if (topHeight <= height){
      // printf("\n%d (%d) is lower than %d (%d) found + %d\n", topIndex, topHeight, index, height, distance);
      s.pop();
      totalDistance += distance;
    }else{
      // greater than me
      break;
    }
  }
}

void registerHeight (int height, int index){
  s.push({height,index});
}

int main(){
  int N; scanf("%d", &N);

  for (int i=0;i<N;i++){
    int height; scanf("%d", &height);

    clearLTEMeAndSumUp(height, i);

    registerHeight(height, i);
  }

  clearLTEMeAndSumUp(INF, N);

  printf("%lld\n", totalDistance);
}