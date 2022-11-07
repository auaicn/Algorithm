/*
바퀴에 같은 글자는 두 번 이상 등장하지 않는다.
바퀴는 시계방향으로만 돌아간다
화살표는 한 곳을 가리키고 있다.
바퀴를 연속해서 K 번 굴린다.
굴릴 때마다 글자가 변하는 횟수와 어느 글자에서 멈추었는지 종이에 적는다.
화원이가 종이를 발견해서 바퀴에 적은게 무엇인지 알아내려 한다.

칸 수도 준다.

어떤 글자인지 결정하지 못할 수도 있다.
충돌나면, 즉 말 안되면 !
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

#define filling ('?')

int main(){
  int N,K; scanf("%d %d ",&N,&K); // N up to 25

  set<char> visit;
  vector<char> result(N, filling);

  stack<pair<int,char>> s;

  for (int i=0;i<K;i++){
    int S; char c; scanf("%d %c", &S, &c);

    s.push({S,c});
  }

  int index = 0;

  while(!s.empty()){
    pair<int,int> top = s.top();
    s.pop();

    int move = top.first;
    int letter = top.second;

    if (result[index] == filling){
      if (visit.find(letter) != visit.end()){
        // found
        printf("!\n");
        return 0;
      }else{
        visit.insert(letter);
        result[index] = letter;
      }
    } else if (result[index] == letter){
      // pass
    } else {
      printf("!");
      return 0;
    }

    index += move; // 0 > -2 move 좀 클 수 있음
    // index += N*101; // -2 > 3 // 원하는건 2인데
    index %= N; // 3

    // for (auto i:result) cout <<i;{
    //   cout<<endl;
    // }
  }

  for (int i=0;i<result.size();i++) printf("%c", result[i]);
}