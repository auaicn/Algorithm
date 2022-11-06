#include <stdio.h>
#include <vector>

using namespace std;

// 시작 인덱스를 무조건 0으로 둔다.

int main(){
  int N,K; scanf("%d %d", &N,&K);

  vector<int> result;
  vector<int> v;

  for (int i=0;i<N;i++){
    v.push_back(i);
  }

  for (int i=0;i<N;i++){

    int index = (K - 1) % v.size();

    result.push_back(v[index]);

    vector<int> next;

    for (int i=index+1;i<v.size();i++) next.push_back(v[i]);
    for (int i=0;i<index;i++) next.push_back(v[i]);

    v = next;
  }

  printf("<");
  for (int i=0;i<result.size();i++){

    bool isLastElement = i == result.size() -1;

    if (isLastElement){
    printf("%d",result[i] + 1);

    }else{

    printf("%d, ",result[i] + 1);
    }

  }
  printf(">\n");
}