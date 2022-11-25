#define SIZE (10010)

/*
레벨이 있는 이진트리
한 열에는 한 노드만 존재한다.
레벨의 너비라는 것이 있다. 2 10 이면 10 - 2 + 1 = 9 열에 있는 숫자 기준으로
루트 레벨이 1
넓이가 가장 넓은 레벨과 그 레벨의 너비를 구하라 두 개 이상인 경우 번호가 작은 레벨
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// find root
// connection (child) 그대로 유지하면 될듯
// bfs leveling
// column mapping (left, self, right) 과 동시에 level 별 노드 수집

int columnNumber = 1;

int level[SIZE];
int column[SIZE];
int parent[SIZE];

pair<int,int> connection[SIZE];
vector<int> nodeNumbersByLevel[SIZE];

int findRoot(int now) {
  if (parent[now] == 0) return now;
  else return findRoot(parent[now]);
}

void leveling(int now, int currentLevel){
  pair<int,int> children = connection[now];

  int left = children.first;
  int right = children.second;

  level[now] = currentLevel;
  if (left != -1) leveling(left, currentLevel + 1);
  if (right != -1) leveling(right, currentLevel + 1);
}

void labeling(int now){
  pair<int,int> children = connection[now];
  int left = children.first;
  int right = children.second;

  if (left != -1) labeling(left);
  column[now] = columnNumber++;
  nodeNumbersByLevel[level[now]].push_back(column[now]);
  // printf("%d 's column number is %d\n", now, column[now]);
  if (right != -1) labeling(right);
}

int max(int x, int y){
  return x>y?x:y;
}

int main(){
  int N; scanf("%d", &N); // 10E4

  int someNodeNumber;
  for (int i=0;i<N;i++){
    int nodeNumber, left, right; scanf("%d %d %d", &nodeNumber, &left, &right); // can be -1

    someNodeNumber = nodeNumber;

    connection[nodeNumber] = {left, right};

    parent[left] = nodeNumber;
    parent[right] = nodeNumber;
  }

  int rootNodeNumber = findRoot(someNodeNumber);

  // printf("found root %d\n", rootNodeNumber);

  leveling(rootNodeNumber, 1);
  labeling(rootNodeNumber);

  int result = -1, resultLevel;
  for (int i=0;i<N;i++){
    int currentLevel = i+1;

    if (nodeNumbersByLevel[currentLevel].size() == 0) break;

    sort(nodeNumbersByLevel[currentLevel].begin(), nodeNumbersByLevel[currentLevel].end());

    int distance =  (nodeNumbersByLevel[currentLevel].back()) - (nodeNumbersByLevel[currentLevel].front()) + 1;

    // printf("level %d distance %d\n", currentLevel, distance);

    if (distance > result){
      result = distance;
      resultLevel = currentLevel;
    }
  }

  printf("%d %d\n", resultLevel, result);
}