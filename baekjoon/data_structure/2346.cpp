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

    int move = moves[popIndex];

    // 이제는 v.size() - 1 개
    // move : -N to N

    // -3 은 무엇과 같을까
    // 1 2 3 4 5
    // 3 터드렷는데 + 1이면
    // 1 2 4 5 에서
    // 4가 나와야 하는데
    // - 3 과 같은것
    // -3 은 + 1 과 같다.

    // 1 2 3 4 5
    // 1 2 4 5

    // + 1 이었으면 4
    // -3 이랑 같다.

    // 4 기준 시작으로 하면 +1 이 상쇄 되어야 하니까

    int size = v.size() -1;

    if (size == 0) break;

    move = (((move > 0 ? move - 1 : move + 1)) + size) % size; // now in 0 to v.size() - 1 // fit ! // 0 이 적혀있지는 않은가본데

    vector<int> next;

    for (int i=popIndex + 1; i<v.size();i++) next.push_back(v[i]);
    for (int i=0; i<popIndex;i++) next.push_back(v[i]);

    v = next;

    popIndex = move;
  }

  for (int i=0;i<result.size();i++){
    printf("%d ",result[i] + 1);
  }
}