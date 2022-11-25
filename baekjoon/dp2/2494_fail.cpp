#define INF (1987654321)

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char currentString[10010];
char toBeString[10010];

int current[10010];
int toBe[10010];

int dp[10010][10];
pair<int,int> route[10010][10];

/*
그래서 dp 배열을 정의를 어떻게 했는가 하면

dp[N][i] 는
N개의 블록을 가지런하게 정렬하되, 가장 위, 정면에 보이는 숫자가 i 이도록 만드는데 드는 최소 비용으로 설정한 것 같다.
그래서 마지막에 답은 dp[1][입력받은 첫번째 원소] 가 되도록 한것이다. 아주 난해하게 한 것 같긴한데 완성 코드는 가장 짧은 것 같다.
하지만, 시간복잡도는 다른 사람들이 훨씬 짧은것으로 보인다.
*/

int min(int x, int y){
  return x<y?x:y;
}

int main(){
  int N; scanf("%d", &N);

  scanf(" %s", currentString);
  scanf(" %s", toBeString);

  for (int i=0;i<strlen(currentString); i++){
    current[i+1] = currentString[i] - '0';
    toBe[i+1] = toBeString[i] - '0';
  }

  // N = 1 일 때 초기화
  int lastNumber = toBe[N];
  for (int i=0;i<10;i++){
    int left = (lastNumber + 10 - i) % 10; left = left > 0 ? left : -left;
    int right = (10 - left) % 10; right = right > 0 ? right : -right;

    if (left < right){
      dp[N][i] = left;
      route[N][i] = {left, 0};
    }else{
      dp[N][i] = right;
      route[N][i] = {0, right};
    }
  }

  for (int i=N-1;i>0;i--){
    int target = toBe[i];
    for (int currentFront = 0; currentFront < 10; currentFront ++){
      // 현재 앞이 currentFront 라고 해보자
      // 만들어야 할 값은 target 이다.
      // 왼쪽으로 돌리거나 오른쪽으로 돌리거나

      dp[i][currentFront] = INF;

      // go left then right, 결국에는 target을 맞추기는 해야한다는 것을 명심하자.
      for (int left=0; left<10; left++){
        int leftTurnedFront = (currentFront + left) % 10; // 오른쪽으로 돌려서 target 을 맞춰야 한다. // left 도 cost 에 포함된다. // 결과는 0-20
        int right = ((leftTurnedFront + 10) - target) % 10;

        int cost = dp[i+1][(current[i+1] + (currentFront - current[i]) + 100 + left) % 10] + left + right;

        if (cost < dp[i][currentFront]){
          dp[i][currentFront] = cost;
          route[i][currentFront] = {left, right};
        }
      }
    }
  }

  // for (int i=0;i<10;i++){
  //   for (int j=0;j<N;j++){
  //     printf("%3d", dp[j+1][i]);
  //   }
  //   printf("\n");
  // }

  // for (int i=0;i<10;i++){
  //   for (int j=0;j<N;j++){
  //     printf("(%3d, %3d) ", route[j+1][i].first, route[j+1][i].second);
  //   }
  //   printf("\n");
  // }

  // printf("%d\n", dp[1][current[1]]);

  int offset = 0;
  for (int i=1;i<=N;i++){
    int lookup = (current[i] + offset) % 10;

    // printf("%d [%d]", i, lookup);

    pair<int,int> move = route[i][lookup];

    int left = move.first;
    int right = move.second;

    if (left) printf("%d %d\n", i, left);
    if (right) printf("%d %d\n", i, -right);

    offset = (offset + 100 + left - right) % 10;
  }
}