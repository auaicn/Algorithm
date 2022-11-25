// 0-base

#include <stdio.h>
#include <vector>

using namespace std;

int nodeToDeleted;

vector<int> v[60];

int countLeafNode(int now){
  if (now == nodeToDeleted) return -1;

  bool isLeafNode = v[now].size() == 0;

  if (isLeafNode){
    return 1;
  }else{
    int sum = 0;

    for (int i=0;i<v[now].size();i++){
      int next = v[now][i];

      int childLeafNodeCount = countLeafNode(next);

      if (childLeafNodeCount == -1) {
        if (v[now].size() == 1){
          return 1;
        }else {
          sum += 0;
        }
      }else{
        sum += countLeafNode(next);
      }
    }

    return sum;
  }
}

int main(){
  int N; scanf("%d", &N); // up to 50

  int root;

  for (int i=0;i<N;i++){
    int parent; scanf("%d", &parent);

    if (parent == -1) {
      root = i;
    } else{
      v[parent].push_back(i);
    }
  }

  scanf("%d", &nodeToDeleted);

  int leafNodeCount = countLeafNode(root);

  printf("%d\n", leafNodeCount == -1 ? 0 : leafNodeCount);
}