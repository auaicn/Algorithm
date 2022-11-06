#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <vector>

using namespace std;

int main(){
  int N,M; scanf("%d %d\n", &N,&M);

  vector<int> v;

  for (int i=0;i<N;i++) v.push_back(i+1);

  int cost = 0;

  while(M--){
    // for (int i=0;i<v.size();i++) printf("%4d", v[i]);
    // printf("\n");

    int value; scanf("%d", &value);

    int index = -1;
    for (int j=0;j<v.size();j++){
      if (v[j] == value) {
        index = j + 1;
        break;
      }
    }

    // i th trial
    int costLeft = index - 1;
    int costRight = v.size() - index + 1;

    if (costLeft < costRight){
      // printf("cost left %d\n",costLeft);
      cost += costLeft;
    }else{
      // printf("cost right %d\n",costRight);
      cost += costRight;
    }

    vector<int> next;

    for (int i = index; i<v.size(); i++){
      next.push_back(v[i]);
    }

    for (int i = 0; i < index - 1; i++){
      next.push_back(v[i]);
    }

    v = next;
  }

  printf("%d\n",cost);
}
