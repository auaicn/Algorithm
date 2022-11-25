#include <stdio.h>
#include <vector>

using namespace std;

// given graph, count tree

bool visit[510];
vector<int> v[510];

bool isTree(int now, int previous){
  // printf("now %d\n", now);
  visit[now] = true;

  bool yes = true;
  for (int i=0;i<v[now].size();i++){
    int next = v[now][i];

    if (visit[next]){
      if (now == previous) continue;
      if (next == previous) continue;

      yes = false;
    }else{
      yes &= isTree(next, now);
    }
  }

  return yes;
}

int main(){
  int caseNumber = 0;

  while(++caseNumber){
    int n; scanf("%d", &n); if (n == 0) break;
    int m; scanf("%d", &m);

    for (int i=0;i<n;i++) {
      visit[i+1] = false;
      v[i+1].clear();
    }

    int numTrees = 0;
    while(m--){
      int left, right; scanf("%d %d", &left, &right);

      v[left].push_back(right);
      v[right].push_back(left);

    }

    for (int i=0;i<n;i++){
      int start = i+1;

      if (visit[start]) continue;

      numTrees += isTree(start, start);
    }

    printf("Case %d: ", caseNumber);
    if(numTrees>1){
      printf("A forest of %d trees.", numTrees);
    }else if (numTrees == 1){
      printf("There is one tree.");
    }else if (numTrees == 0){
      printf("No trees.");
    }
    printf("\n");
  }
}