#include <stdio.h>
#include <vector>

using namespace std;

int main(){
  int N; scanf("%d",&N);

  vector<int> moves;
  for (int i=0;i<N;i++){
    int move; scanf("%d",&move);

    moves.push_back(move);
  }

  vector<int> v;

  for (int i=0;i<N;i++) v.push_back(i);

  vector<int> result;
  int popIndex = 0;
  for (int i=0;i<moves.size();i++){
    result.push_back(v[popIndex]);

    int move = moves[v[popIndex]];

    // 우선 우측에 있던 애를 기준으로 바꾼다.
    // move 가 1 인경우, 0 이 되어야 한다.
    // move 가 음수인 경우 유지한다.
    // 새로운 size 가 4 인 경우, move -1 은 move 3 과 동일하다.
    // size 자체가 작은 경우 나가지 않도록 size 로 나머지 연산을 진행한다.

    vector<int> next;

    for (int i=popIndex + 1; i<v.size();i++) next.push_back(v[i]);
    for (int i=0; i<popIndex;i++) next.push_back(v[i]);

    int nextSize = next.size();

    if (nextSize == 0) break;

    popIndex = ((move > 0 ? move - 1 : move) + nextSize * N) % nextSize; // now in 0 to v.size() - 1 // fit ! // 0 이 적혀있지는 않은가본데

    v = next;
  }

  for (int i=0;i<result.size();i++){
    printf("%d ",result[i] + 1);
  }
}