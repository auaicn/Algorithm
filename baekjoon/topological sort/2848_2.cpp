/* -------------------------------------------------------------------------- */
/*                                 Enhancement                                */
/* -------------------------------------------------------------------------- */

/*
일단은 너무 어렵게 생각했다. 이게 아니다 싶으면 돌아가자. 애초에 어렵게 문제를 풀고 있을 수 있다.
충분히 입력이 불친절할 수 있다는 것을 생각하자. 내가 생각했을 때, 입력이 불가능하지만, 별 말이 없는 경우, 그리고 불가능한 경우 ! 를 출력하라고 하면
해당 입력도 가능은 한 입력임을 알아두자. 입력에 대해서 이야기가 없는 한, 제한이 없는 한 어떤 인풋이던 들어올 수 있다는 것을 염두에 두고 풀자.
그게 뒤 탈이 없는 것 같다. 문제는 전부 다 잘 읽었는데 조금 더 복잡한 문제가 들어온다고 해도 잘 읽을 수 있도록 하자.
*/

#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <queue>

using namespace std;

char previous[30];
char current[30];

bool visit[30];
int inDegree[30];
vector<int> v[30]; // char index 0 - 25
queue<int> q;

set<char> usedCharacter;
char result[30];

int min(int x, int y){
  return x<y?x:y;
}

int max(int x, int y){
  return x>y?x:y;
}

int main(){
  int N; scanf("%d", &N);

  for(int wordIndex = 0; wordIndex < N; wordIndex++){
    memset(current, 30,'\0');

    scanf(" %s", current);

    int currentLength = strlen(current);
    int previousLength = strlen(previous);
    int shorterLength = min(currentLength, previousLength);

    for (int i=0;i<currentLength;i++){
      usedCharacter.insert(current[i]);
    }


    if (wordIndex != 0){
      int diffPosition = 0;
      while(previous[diffPosition] == current[diffPosition]){
        diffPosition++;
      }

      if (previous[diffPosition] == '\0') {
        //pass
      }else if (current[diffPosition] == '\0'){
        printf("!\n");
        return 0;
      }else{
        v[previous[diffPosition] - 'a'].push_back(current[diffPosition] - 'a');
        inDegree[current[diffPosition] - 'a']++;
      }
    }

    memcpy(previous, current, 30);
  }

  for (auto c: usedCharacter){
    if (inDegree[c-'a'] == 0) q.push(c-'a');
  }

  bool ambiguous = false;

  int idx = 0;
  while(!q.empty()){
    if (q.size() > 1){
      ambiguous = true;
    }

    int front = q.front(); q.pop();
    visit[front] = true;
    result[idx++] = front+'a';

    for (int i=0;i<v[front].size();i++){
      int next = v[front][i];

      if(visit[next]) {
        ambiguous = true;
      }

      inDegree[next]--;

      if(inDegree[next] == 0){
        q.push(next);
      }
    }
  }

  if (strlen(result) < usedCharacter.size()){
    printf("!\n");
  } else if (ambiguous){
    printf("?\n");
  } else {
    printf("%s\n", result);
  }

  return 0;
}