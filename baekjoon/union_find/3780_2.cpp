/* -------------------------------------------------------------------------- */
/*                                   Problem                                  */
/* -------------------------------------------------------------------------- */

/*
N 개의 기업, 자체적인 통신센터
서비스 개선을 위해 각 기업의 서버를 네트워크로 연결, 단일 통신센터에서 관리 가능한 클러스터 형태로 변경

클러스터 A 를 제공하는 기존에 존재하는 센터 I 를 고른다.
클러스터 B 를 제공하는 기업 J 를 고른다. B != A, J 는 센터가 아닐 수 있다?
I J 를 통신 라인으로 연결한다.
클러스터는 B 의 센터에 의해 제공된다.

클러스터를 제공하는 기업이라는 말이 조금 이상하긴 한데, 라인의 길이 총합을 구한다.
*/

/* -------------------------------------------------------------------------- */
/*                                 Improvement                                */
/* -------------------------------------------------------------------------- */

/*

bool whetherToBreak = false;

에서 = false 초기화를 안해준 탓으로 시간이 많이 소모되었다.
이런 문제 유형은 disjoint-set 이라고 하는 것 같다.
union-find 는 최적화 과정 중, 모두가 root 를 보게 만드는데, 얘는 중간에 끼어드는 느낌.

*/


#include <stdio.h>
#include <iostream>

using namespace std;

int group[20010];
long distanceToCenter[20010];

pair<int,int> getDistance(int x){
  if (x == group[x]) return {0, x};
  else {
    pair<int,int> parentDistanceWithGroup = getDistance(group[x]);

    int parentDistance = parentDistanceWithGroup.first;
    int parentGroup = parentDistanceWithGroup.second;

    group[x] = parentGroup; // next time be faster O(1)
    distanceToCenter[x] += parentDistance;

    return {distanceToCenter[x], group[x]};
  }
}

int main(){
  int T; scanf("%d", &T);

  while(T--){
    int N; scanf("%d", &N); // 4 - 2X10E4

    for (int i=0;i<N;i++) {
      group[i+1] = i+1;
      distanceToCenter[i+1] = 0;
    }

    bool whetherToBreak = false;

    while(true){
      char command; scanf(" %c", &command);

      switch(command){
        case 'O':
          whetherToBreak = true;
          break;
        case 'E': // output
          int company; scanf("%d", &company);

          printf("%d\n", getDistance(company).first);
          break;
        case 'I': // connect up to 20000
          int oneCenter, anotherCompany; scanf("%d %d", &oneCenter, &anotherCompany);
          // one is center
          // another may be, not be a center

          int distance = oneCenter - anotherCompany;
          distance = distance > 0 ? distance : -distance;
          distance %= 1000;

          group[oneCenter] = anotherCompany;
          distanceToCenter[oneCenter] = distance;

          break;
      }

      if (whetherToBreak) break;
    }
  }
}