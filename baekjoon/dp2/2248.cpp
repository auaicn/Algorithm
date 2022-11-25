/*
N (1-31) 자리의 이진수가 있다.

이러한 이진수 중에서 L 개 이하의 비트만 1인 것을 크기순으로 나열했을 때 I 번째로 오는 이진수를 구해내라.
*/

#include <stdio.h>
#include <vector>

using namespace std;

vector<char> result;

long long board[40][40];

int main(){
  int N, numBits; long long order; scanf("%d %d %lld", &N, &numBits, &order);

  for (int i=0;i<=N;i++){
    board[i][0] = 1;
  }

  for (int i=1;i<=N;i++){
    for (int j=1;j<=N;j++){
      board[i][j] = board[i-1][j] + board[i-1][j-1];
    }
  }

  int length = N; // 길이는 최대 N 일수 있다.
  int leftOne = numBits; // 1을 최대 numBits 개 사용할 수 있다.

  // printf("%lld\n", board[31][16]);
  // printf("%lld\n", board[10][2]);

  // printf("%lld\n", 1 << 2);
  // printf("%lld\n", 1 << 31);

  while(length){
    if (leftOne == 0) { // fill 0 to the right
      int leftZero = length - leftOne;

      while(leftZero--){
        result.push_back('0');
      }

      break;
    }

    long long gap = 0;
    for (int i=0;i<=leftOne;i++){
      gap += board[length -1][i]; // okay
    }

    if (order <= gap){
      result.push_back('0');
    }else{
      order -= gap;
      leftOne--;
      result.push_back('1');
    }

    length--;
  }

  for (int i=0;i<result.size();i++) {
    printf("%c", result[i]);
  }
  printf("\n");

  // order 번째 이진수가 무조건 존재한다.
  // N 은 중요하지 않은 것 같다. 나열순서는 언제나 같기 때문에. 우측 몇개를 출력하냐의 차이로 보인다.
  // 00000 도 있을 것이다.
  // 문제는 비트가 1 - L 개 이하인 것만 세야 한다

  // order 를 깎아 내려갈 것이다.
  // 00000 부터니까
  // 앞이 0일지 1일지를 판단해나간다.
  // N 개중에 첫번째가 0이라면 뒤에 1이 최대 L 개 등장할 수 있다.

}