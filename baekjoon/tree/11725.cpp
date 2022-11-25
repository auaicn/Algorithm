#include <stdio.h>
#include <vector>

using namespace std;

bool visit[100010];
int parent[100010];

vector<int> v[100010];

void getParent(int x){
  visit[x] = true;

  for (int i=0;i<v[x].size();i++){
    int next = v[x][i];

    if (!visit[next]){
      parent[next] = x;
      getParent(next);
    }
  }

}

int main(){
  int N; scanf("%d", &N);

  for (int i=0;i<N-1;i++){
    int left, right; scanf("%d %d", &left, &right);

    v[left].push_back(right);
    v[right].push_back(left);
  }

  getParent(1);

  for (int i=1;i<N;i++){
    printf("%d\n", parent[i+1]);
  }
}