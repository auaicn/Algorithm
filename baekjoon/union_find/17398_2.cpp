/* -------------------------------------------------------------------------- */
/*                                   Problem                                  */
/* -------------------------------------------------------------------------- */

/*
통신회사, 통신망 관리 지사를 분리하려고 한다. 통신망을 분리하려고 한다.
통신망 분할 할 때 비용이 든다.

N 개의 통신 탑, M 개의 연결
총 Q 개의 통신탑 연경를 제거해서 나누고자 한다. 제거 비용은 나누어진다면! 나누어진 두 통신망의 모든 통신탑 개수 합이다. 나누어지지 않는다면 0이다.
*/

/* -------------------------------------------------------------------------- */
/*                                 Improvement                                */
/* -------------------------------------------------------------------------- */

/*

생각없이, initialization 하지 말고, N 에 붙을지, M 에 붙을지 생각하기
예전보다, set 을 쓴 visit check 방식은 떠올리기를 잘한 것 같다.
틀렸다고 나왔을 때, 확실하게 문제 없는 부분은 괜히 들여다 보지 않기.

*/

#include <stdio.h>
#include <vector>
#include <stack>
#include <set>

using namespace std;

int group[100010];
long long groupSize[100010];
bool connectionVisit[100010];
long long cost;

vector<pair<int,int> > connections;
set<int> initiallyIncludeConnection;
stack<int> s;

int find(int x){
  if (x==group[x]) return x;
  else return group[x] = find(group[x]);
}

int main(){
  int N,M,Q; scanf("%d %d %d", &N,&M,&Q);

  for (int i=0;i<N;i++) {
    group[i+1] = i+1;
    groupSize[i+1] = 1;
  }

  for (int i=0;i<M;i++){
    initiallyIncludeConnection.insert(i+1);
  }

  while(M--){
    int left, right; scanf("%d %d", &left, &right);

    connections.push_back({left,right});
  }

  while(Q--){
    int connectionToDelete; scanf("%d",&connectionToDelete); // unique

    s.push(connectionToDelete);
    initiallyIncludeConnection.erase(connectionToDelete);
  }

  set<int>::iterator it = initiallyIncludeConnection.begin();
  while(it != initiallyIncludeConnection.end()){
    int connectionIndex = *it;
    connectionIndex--;

    pair<int,int> connection = connections[connectionIndex];

    int left = connection.first;
    int right = connection.second;

    int leftAncestor = find(left);
    int rightAncestor = find(right);

    if (leftAncestor != rightAncestor){
      group[leftAncestor] = rightAncestor;
      groupSize[rightAncestor] += groupSize[leftAncestor];
    }

    it++;
  }

  while(!s.empty()){
    int connectionIndex = s.top(); s.pop();
    connectionIndex--;

    if (connectionVisit[connectionIndex])  continue;

    connectionVisit[connectionIndex] = true;

    pair<int,int> connection = connections[connectionIndex];

    int left = connection.first;
    int right = connection.second;

    int leftAncestor = find(left);
    int rightAncestor = find(right);

    if (leftAncestor != rightAncestor){
      cost += groupSize[rightAncestor] * groupSize[leftAncestor];

      group[leftAncestor] = rightAncestor;
      groupSize[rightAncestor] += groupSize[leftAncestor];
    }
  }
  printf("%lld\n", cost);
}