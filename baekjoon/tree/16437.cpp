#define MAX_SIZE (130010)

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

enum AnimalType {
  sheep,
  wolf
};

bool visit[MAX_SIZE];
pair<AnimalType, int> islandInformation[MAX_SIZE];
vector<int> connection[MAX_SIZE];

long long max(long long x, long long y){
  return x>y?x:y;
}

long long countReachableSheep(int now){
  visit[now] = true;

  AnimalType type = islandInformation[now].first;
  int count = islandInformation[now].second;

  long long sum = (type == sheep) ? count : -count;
  for (int i=0;i<connection[now].size();i++){
    int nextIsland = connection[now][i];

    if (visit[nextIsland]) continue;
    else sum += countReachableSheep(nextIsland);
  }

  return max(0, sum);
}

int main(){
  int N; scanf("%d",&N); // 1-base

  for (int i=1;i<N;i++){
    char animal; int count, connectedIsland; scanf(" %c %d %d", &animal, &count, &connectedIsland);

    int islandNumber = i+1;

    connection[islandNumber].push_back(connectedIsland);
    connection[connectedIsland].push_back(islandNumber);

    islandInformation[islandNumber] = {(animal == 'S') ? sheep : wolf, count};
  }

  printf("%lld\n", countReachableSheep(1));
}