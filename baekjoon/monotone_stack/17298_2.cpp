/*
수열 N 개
각 원소에 대해서 오큰수를 구하려 한다.
오른쪽에 있으면서 큰수중에 가장 왼쪽에 있는 수
없는 경우에는 -1 < 맨 오른쪽 애는 무조건 -1 이겠다.
3 5 2 7 > 5 7 7 -1
10E6
*/

#include <stdio.h>
#include <stack>

using namespace std;

stack<pair<int,int> > s;

int result[1000010];

void clearLTAndWriteResult(int value, int idx){
  while(!s.empty()){
    pair<int,int> top = s.top();

    int topValue = top.first;
    int topIdx = top.second;

    if (topValue >= value) break;

    result[topIdx] = value;
    s.pop();
  }
}

void registerValue(int value,int idx){
  s.push({value, idx});
}

int main(){
  // 값과 인덱스를 넣고
  // 방금 들어온 값이 제일 크면, 왼쪽 애들은 clear 될 것이다. (답이 정해질 것이다.)
  // 가장 큰 애랑 같았으면, 그 경우에는 큰건 아니니까 clear 가 되지는 않을 것이다.
  // 나보다 작은 애들에 대해서 답이 정해진다는 것.
  // 빼면서 result[index] = 현재 내 값 으로 유지하면 되겠다.
  // 작은 애들이 빠져야 하니까
  // 나머지 남아있는 애들은 다 -1 처리해주면 될 것 같다.

  int N; scanf("%d", &N);

  for (int i=0; i<N; i++){
    int value; scanf("%d", &value);
    clearLTAndWriteResult(value, i);
    registerValue(value,i);
  }

  while(!s.empty()){
    pair<int,int> top = s.top(); s.pop();

    int value = top.first;
    int idx = top.second;

    result[idx] = -1;
  }

  for (int i=0;i<N;i++){
    printf("%d ", result[i]);
  }

  printf("\n");
  return 0;
}