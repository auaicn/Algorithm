#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int x;
  int y;
  int group;
  int depth;
};

int board[1510][1510];
bool pushed[1510][1510];

vector<int> parent;
pair<int,int> swan, anotherSwan;

int R,C;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

queue<Node> q;

bool disableLogging = true;

void printBoard() {
  if (disableLogging) return;

  for (int i=0;i<R+2;i++){
    for (int j=0;j<C+2;j++){
      printf("%3d", board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int find(int x){
  if (x == parent[x]) return x;
  else return parent[x] = find(parent[x]);
}

void push(int x, int y){
  int group = q.size() + 1; // 이렇게 해도 처음에는 상관없다. 사이즈 똑같아서
  parent.push_back(group);
  q.push(Node{x,y,group,0}); pushed[x][y] = true;
}

bool checkWhetherSwansMet(){
  int swanAncestor = find(board[swan.first][swan.second]);
  int anotherSwanAncestor = find(board[anotherSwan.first][anotherSwan.second]);

  return swanAncestor == anotherSwanAncestor;
}

int main(){
  scanf("%d %d", &R, &C);

  parent.push_back(0); // make 1-base

  bool on = false;
  for (int i=0;i<R;i++){
    for (int j=0;j<C;j++){
      char c; scanf(" %c", &c);

      switch(c){
        case '.': // water
          push(i+1,j+1);
          break;
        case 'X': // ice
          break;
        case 'L': // swan
          if (on){
            anotherSwan = {i+1,j+1};
          }else{
            on = true;
            swan = {i+1,j+1};
          }

          push(i+1,j+1);
          break;
      }
    }
  }

  for (int i=0;i<R+2;i++) board[i][0] = board[i][C+1] = -1;
  for (int i=0;i<C+2;i++) board[0][i] = board[R+1][i] = -1;

  int currentDepth = 0;
  while(!q.empty()){
    printBoard();

    Node current = q.front(); q.pop();

    int x = current.x;
    int y = current.y;
    int group = current.group;
    int depth = current.depth;

    if (depth != currentDepth){
      if(checkWhetherSwansMet()){
        printf("%d\n", currentDepth);
        return 0;
      } else currentDepth = depth;
    }

    board[x][y] = group;

    for (int i=0;i<4;i++){
      int x_ = x+dx[i];
      int y_ = y+dy[i];

      int nextGroup = board[x_][y_];

      if (nextGroup == -1) continue;

      if (nextGroup == 0){
        if (pushed[x_][y_]) continue;

        q.push(Node{x_,y_,group,depth+1}); pushed[x_][y_] = true;
      }else{
        // union
        int ancestor = find(group);
        int nextAncestor = find(nextGroup);

        if (ancestor == nextAncestor) continue;

        parent[ancestor] = nextAncestor;
      }
    }
  }

  if(checkWhetherSwansMet()){
    printf("%d\n", currentDepth);
    return 0;
  }

  return 0;
}