/* -------------------------------------------------------------------------- */
/*                                   Problem                                  */
/* -------------------------------------------------------------------------- */

/*

N haybales 10E5
haybale has
- Flavor F_i 10E9
- Spiciness S_i 10E9

would like the determine 'minimum' spiciness that his course could achieve, total flavor of at least M 10E18

*/

/* -------------------------------------------------------------------------- */
/*                                 Improvement                                */
/* -------------------------------------------------------------------------- */

/*

right = left + 1 임이 보장된다. pair<int, pair<int,int>> 를 pair<int,int> 로 변경할 수 있을 것이다.
pq 를 사용하자마자 가정되는 것은, 두개 이상의 meal 가지고 답을 내겠다는 것이다. 이 때, single meal result 와의 비교를 꼭 해줄 필요가 있는데 발견하기 어려웠다.

*/

#define INF (1987654321)

#include <stdio.h>
#include <queue>

using namespace std;

int min (int x, int y){
  return x<y?x:y;
}

int max (int x, int y){
  return x>y?x:y;
}

int group[100010];
int maxSpiciness[100010];
long long totalFlavor[100010];

priority_queue<pair<int, pair<int, int> > > pq;

int find(int x){
  if (x==group[x]) return x;
  else return group[x] = find(group[x]);
}

int main(){
  int N; long long M; scanf("%d %lld", &N, &M);

  int singleMealResult = INF;

  for (int i=0;i<N;i++){
    int flavor, spiciness; scanf("%d %d", &flavor, &spiciness);

    if (flavor >= M) {
      singleMealResult = min(singleMealResult, spiciness);
    }

    group[i+1] = i+1;
    maxSpiciness[i+1] = spiciness;
    totalFlavor[i+1] = flavor;
    // 연결은 전후로 있음.

    if (i > 0){
      int left = i;
      int right = i+1;

      pq.push({-max(maxSpiciness[left], maxSpiciness[right]),{left, right}});
    }
  }

  int multipleMealResult;

  while(!pq.empty()){
    pair<int,pair<int,int> > top = pq.top(); pq.pop();

    int weight = -top.first;

    int left = top.second.first;
    int right = top.second.second;

    int leftAncestor = find(left);
    int rightAncestor = find(right);

    if (leftAncestor != rightAncestor){
      group[leftAncestor] = rightAncestor;

      maxSpiciness[rightAncestor] = max(maxSpiciness[leftAncestor], maxSpiciness[rightAncestor]);
      totalFlavor[rightAncestor] = totalFlavor[leftAncestor] + totalFlavor[rightAncestor];
    }

    if (totalFlavor[rightAncestor] >= M) {
      multipleMealResult = maxSpiciness[rightAncestor];
      break;
    }
  }

  printf("%d\n", min(singleMealResult, multipleMealResult));
}