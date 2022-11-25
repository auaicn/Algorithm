/*
1-base N teams.
작년에 참가했던 팀과 동일하다.
작년에는 순위를 발표했다
올해는 최종 순위를 발표하지 않기로 했다. 대신에 작년에 비해서 상대적인 순위가 바뀐 팀의 목록만 발표하려고 한다.

누가 누구보다 높은지만 알려주려고 한다. 그것도, 순위가 뒤바뀐 팀에 한해서
작년 순위와, 순위가 바뀐 팀의 목록이 주어졌을 때, 올해 최종 순위를 만들어보려고 한다.
*/

/* -------------------------------------------------------------------------- */
/*                                 Enhancement                                */
/* -------------------------------------------------------------------------- */

/*
- Cycle Detection 은 topological sort 가 끝난 이후에 size check 하는 것으로 충분하다. visit 을 도입할 이유가 없다.
- 또 어렵게 생각하면 안되는 것이, 간선을 vector 에 유지하려고 하지 않아도 된다는 점이다. 그 보다 쉬운 방법은 board 에 연결 관계를 표시하는 것이다.
- vector 를 사용해서 표시를 하면, 간선 방향이 바뀌었을 때 찾는 것이 어렵다. 이것을 유의하자.
*/

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int lastYearTeamByRank[510];
int inDegree[510];
bool visit[510];

bool board[510][510];

vector<int> ranks;
queue<int> q;

int main(){
  int T; scanf("%d", &T);

  while(T--){
    int numberOfTeams; scanf("%d", &numberOfTeams);

    ranks.clear();
    while(!q.empty()) q.pop();

    for (int i=0;i<numberOfTeams;i++){
      lastYearTeamByRank[i+1] = 0;
      inDegree[i+1] = 0;
      visit[i+1] = false;

      for (int j=0;j<numberOfTeams;j++){
        board[i+1][j+1] = false;
      }
    }

    for (int i=0;i<numberOfTeams; i++){
      int lastYearRank = i+1;;
      int teamNumber; scanf("%d", &teamNumber); // unique
      lastYearTeamByRank[lastYearRank] = teamNumber;

      for (int j=0;j<lastYearRank-1;j++){
        // 앞선 애들임
        int higherRank = j+1;
        int higherRankTeam = lastYearTeamByRank[higherRank];

        // printf("higherRankTeam %d won %d\n", higherRankTeam, teamNumber);

        board[higherRankTeam][teamNumber] = true;
        inDegree[teamNumber]++;
      }
    }

    int numberOfChangedRanks; scanf("%d", &numberOfChangedRanks); // 0 to 3* 10E4

    for (int i=0;i<numberOfChangedRanks;i++){
      int oneTeam, anotherTeam; scanf("%d %d", &oneTeam, &anotherTeam); // pair unique one < another

      if (board[oneTeam][anotherTeam]){
        board[oneTeam][anotherTeam] = false;
        board[anotherTeam][oneTeam] = true;
        inDegree[anotherTeam]--;
        inDegree[oneTeam]++;
      }else{
        board[oneTeam][anotherTeam] = true;
        board[anotherTeam][oneTeam] = false;
        inDegree[anotherTeam]++;
        inDegree[oneTeam]--;
      }
    }

    for (int i=0;i<numberOfTeams;i++){
      if(inDegree[i+1] == 0) q.push(i+1);
    }

    bool ambiguous = false;
    bool abused = false;

    while(!q.empty()){
      if (q.size() > 1) {
        ambiguous = true;
        break;
      }

      int teamNumber = q.front(); q.pop();

      ranks.push_back(teamNumber);
      visit[teamNumber] = true;

      for (int i=0;i<numberOfTeams;i++){
        int nextTeamNumber = i+1;

        if (board[teamNumber][nextTeamNumber]){
          // if (visit[nextTeamNumber]) {
          //   abused = true;
          //   break;
          // }else{
            inDegree[nextTeamNumber]--;

            if (inDegree[nextTeamNumber] == 0){
              q.push(nextTeamNumber);
            }
          // }
        }
      }

      if (abused) break;
    }

    // printf("auaicn\n");

    if (ranks.size() != numberOfTeams){
      printf("IMPOSSIBLE\n");
    } else if (ambiguous){
      printf("?\n");
    }else {
      for (int i=0;i<ranks.size();i++){
        printf("%d ", ranks[i]);
      }
      printf("\n");
    }
  }
}