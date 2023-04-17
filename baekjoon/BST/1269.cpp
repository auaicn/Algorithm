/*
자연수를 원소로 가지는 공집합이 아닌 두 집합 A, B 가 있다.

대칭 차집합의 원소의 개수를 출력해라. Union - Intersection
*/

#include <stdio.h>
#include <set>

using namespace std;

set<int> s;

int main(){
  int N,M; scanf("%d %d", &N, &M);

  for (int i=0;i<N;i++){
    int value; scanf("%d", &value);
    s.insert(value);
  }

  for (int i=0;i<M;i++){
    int value; scanf("%d", &value);
    if (s.find(value) != s.end()){
      // found
      s.erase(value);
    }else {
      s.insert(value);
    }
  }

  printf("%lu\n", s.size());
}