#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int civilizationBoard [2010][2010];
bool pushed [2010][2010];

int group [100010];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int find(int x){
  if (x==group[x]) return x;
  else return group[x] = find(group[x]);
}

queue<pair<pair<int,int>, pair<int,int> > > q;

int main(){
  int N,numberOfCivilizations; scanf("%d %d",&N,&numberOfCivilizations);

  for (int i=0;i<N+2;i++){
    civilizationBoard[i][N+1]
    = civilizationBoard[i][0]
    = civilizationBoard[N+1][i]
    = civilizationBoard[0][i] = -1;
  }


  for (int i=0;i<numberOfCivilizations;i++){
    int x, y; scanf("%d %d", &x, &y);

    int depth = 0;
    int civilization = i+1;

    group[civilization] = civilization;

    q.push(make_pair(make_pair(depth, civilization), make_pair(x,y))); pushed[x][y] = true;
  }

  while(!q.empty()){
    pair<pair<int,int>, pair<int,int> > front = q.front(); q.pop();

    int depth = front.first.first;
    int civilization = front.first.second;

    pair<int,int> position = front.second;
    int x = position.first;
    int y = position.second;

    civilizationBoard[x][y] = civilization;

    // printf("%10s%10d%10d(%d,%d)\n", "now", depth, civilization, x, y);

    for (int i=0;i<4;i++){
      int x_ = x+dx[i];
      int y_ = y+dy[i];

      int nearbyCivilization = civilizationBoard[x_][y_];

      if (nearbyCivilization == -1) continue;
      // if (depth != 0 && pushed[x_][y_]) continue;

      int hasCivilization = nearbyCivilization > 0;

      // printf("%10s%10d%10d(%d,%d)\n", "looking", depth, nearbyCivilization, x_, y_);

      if (hasCivilization){
        // try union
        int civilizationGroup = find(civilization);
        int nearbyCivilizationGroup = find(nearbyCivilization);

        if (civilizationGroup != nearbyCivilizationGroup){
          // union
          // printf("merging %d with %d\n", civilizationGroup, nearbyCivilizationGroup);
          group[civilizationGroup] = nearbyCivilizationGroup;
          numberOfCivilizations -= 1;

          if (numberOfCivilizations == 1){
            printf("%d\n", depth);
            return 0;
          }
        }
      } else {
        if (!pushed[x_][y_]){
          q.push(make_pair(make_pair(depth+1,civilization),make_pair(x_,y_))); pushed[x_][y_] = true;
        }
      }

    }
  }

  return 0;
}