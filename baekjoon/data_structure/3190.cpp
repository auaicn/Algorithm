/*
사과를 먹으면 뱀의 길이가 늘어난다.
뱀이 이리저리 기어다니다 벽 또는 자기 자신의 몸과 부딪히면 게임이 끝난다.
NxN 보드 위에서 시작한다. 뱀은 1,1 에 위치해있고, 뱀의 길이는 1이다. 뱀은 오른쪽을 향한다.

매 초마다 이동한다.
1. 몸 길이를 늘려 다음칸에 위치시킨다.

뱀의 이동 경로가 주어진다.
몇초만에 게임이 끝나는지?
*/

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

#define SIZE (110)

#define UP (0)
#define DOWN (1)
#define LEFT (2)
#define RIGHT (3)

bool apple[SIZE][SIZE];
bool visit[SIZE][SIZE];

// directions: UDLR
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main(){
  int N; scanf("%d", &N);
  int K; scanf("%d", &K);

  while(K--){
    int x, y; scanf("%d %d", &x, &y);
    apple[x][y] = true;
  }

  queue<pair<int,char> > q;
  int L; scanf("%d", &L);
  int lastElapsedTime = 0;
  while(L--){
    int X; char C; scanf("%d %c", &X, &C); // X 초후 C 가 L 이면 왼쪽 D 이면 오른쪽으로 방향을 튼다.
    q.push({X-lastElapsedTime, C});
    lastElapsedTime = X;
    // X 는 10,000 이하의 정수, 방향 전환 정보 X 는 증가하는 순으로 주어진다. 순서대로이다.
  }

  int direction = 3;
  int elapsedTime = 0;
  int x = 1, y = 1;

  // visit array
  for (int i=0;i<N+2;i++) visit[i][0] = visit[i][N+1] = visit[0][i] = visit[N+1][i] = true;

  // foot-print queue
  queue<pair<int,int> > footPrint;
  footPrint.push({x,y});

  while(true){
    elapsedTime ++;

    visit[x][y] = true;

    // move
    int x_ = x + dx[direction];
    int y_ = y + dy[direction];

    // printf("current position: %4d %4d\n", x, y);
    // printf("next position: %4d %4d\n", x_, y_);
    // printf("\n");

    // bound check (border)
    // bound check (crash)

    if (visit[x_][y_]) break;

    visit[x_][y_] = true;

    footPrint.push({x_,y_});
    // not bound -> apple check
    if (apple[x_][y_]){
      apple[x_][y_] = false;
    }else{
      // clear visit
      pair<int,int> front = footPrint.front();
      footPrint.pop();

      visit[front.first][front.second] = false;
    }

    // head turn check
    if (!q.empty()){
      q.front().first--;
      pair<int,char> front = q.front();
      if(front.first == 0) {
        q.pop();
        switch(direction){
          case UP:
            direction = front.second == 'L' ? LEFT : RIGHT;
            break;
          case DOWN:
            direction = front.second == 'L' ? RIGHT : LEFT;
            break;
          case LEFT:
            direction = front.second == 'L' ? DOWN : UP;
            break;
          case RIGHT:
            direction = front.second == 'L' ? UP : DOWN;
            break;
        }
      }
    }

    x = x_;
    y = y_;
  }

  printf("%d\n", elapsedTime);
}