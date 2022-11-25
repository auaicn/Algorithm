#include <stdio.h>
#include <iostream>

using namespace std;

int N;

pair<int,int> node[30];

void preOrderTraversal(int location){
  if (location == -1) return;

  printf("%c", 'A' + location);
  preOrderTraversal(node[location].first);
  preOrderTraversal(node[location].second);
}

void inOrderTraversal(int location){
  if (location==-1) return;

  inOrderTraversal(node[location].first);
  printf("%c", 'A' + location);
  inOrderTraversal(node[location].second);
}

void postOrderTraversal(int location){
  if (location==-1) return;

  postOrderTraversal(node[location].first);
  postOrderTraversal(node[location].second);
  printf("%c", 'A' + location);

}

int main(){
  scanf("%d", &N);

  for (int i=0;i<N;i++){
    char value, left, right;
    scanf(" %c %c %c", &value, &left, &right);

    node[value - 'A'] = {left == '.' ? -1 : left - 'A', right == '.' ? -1 : right - 'A'};
  }

  preOrderTraversal(0); printf("\n");
  inOrderTraversal(0); printf("\n");
  postOrderTraversal(0); printf("\n");

  return 0;
}