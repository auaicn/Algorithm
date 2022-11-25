#define INF (1987654321)

#include <stdio.h>
#include <vector>

using namespace std;

vector<char> result;

long long board[210][210];

int main(){
  int N, M; scanf("%d %d", &N, &M);
  int K; scanf("%d", &K);

  int length = N+M;

  for (int i=0;i<N+M+1;i++){
    board[i][0] = 1;
  }

  for (int i=1;i<=length;i++){
    for (int j=1;j<=i;j++){
      long long value = board[i-1][j] + board[i-1][j-1];

      if (value > INF) board[i][j] = INF;
      else board[i][j] = value;
    }
  }

  if(board[N+M][M] < K) {
    printf("-1\n");
    return 0;
  }

  int leftA = N;
  int leftZ = M;

  while(K){
    // printf("A [%d] Z [%d]\n", leftA, leftZ);
    if (leftA == 0){
      for (int i=0;i<leftZ;i++) result.push_back('z');
      break;
    }

    if (leftZ == 0){
      for (int i=0;i<leftA;i++) result.push_back('a');
      break;
    }

    int standard = board[leftA-1 + leftZ][leftZ];

    if (K <= standard){
      // a
      result.push_back('a');
      leftA--;
    }else{
      // k
      leftZ--;
      result.push_back('z');
      K-=standard;
    }
  }

  for (int i=0;i<result.size();i++){
    printf("%c", result[i]);
  }
  printf("\n");

  return 0;
}