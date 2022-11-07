/*
2명
키로거, 키보드를 누른 명령을 모두 기록한다. 화살표나 백스페이스를 입력할 수도 있다.
알파벳 대소문자, 숫자, 백스페이스 화살표를 입력할 수 있다. 화살표는 좌우가 가능하다. 백스페이스는 - 로 인풋이 들어온다.
비밀번호의 길이는 항상 0보다 크다.
백스페이스를 통해서 지울 때, 커서의 위치가 줄의 마지막이 아니라면, 커서와 커서 오른쪽의 모든 문자는 오른쪽으로 한 칸 이동한다. < 이거 해석이 조금 애매하다. 영어로 이해했음 입력시 하나씩 오른쪽으로 밀린다구
길이는 10E6 까지 가능하다.
*/

#include <stdio.h>
#include <string.h>

#define SIZE (1000010)

char log[SIZE];

struct Node{
  char data;
  Node* previous;
  Node* next;
};

Node* root;
Node* cursor;

int main(){
  int T; scanf("%d",&T);

  while(T--){
    memset(log, SIZE, '\0');

    scanf(" %s", log);

    int len = strlen(log);

    root = new Node{'.', NULL, NULL};
    cursor = root;

    for (int i=0;i<len;i++){
      char key = log[i];

      if (key == '-'){
        if (cursor -> previous){
          cursor -> previous -> next = cursor -> next;
          if (cursor -> next) cursor -> next -> previous = cursor -> previous;

          cursor = cursor -> previous;
        }
      } else if (key == '<'){
        if (cursor -> previous) cursor = cursor -> previous;
      } else if (key == '>'){
        if (cursor -> next) cursor = cursor -> next;
      } else {
        Node* newNode = new Node{key, cursor, cursor->next}; // safe connection (new node 의 전 후만 설정해주기 때문에)

        if (newNode -> previous) newNode -> previous -> next = newNode;
        if (newNode -> next) newNode -> next -> previous = newNode;

        cursor = cursor->next;
      }

    }

    root = root -> next;
    while(root){
      printf("%c", root->data);

      root = root -> next;
    }
    printf("\n");
  }
}

/*
복기

node 기준으로, data 가 어디에 있는지 확실히 알아야 한다.

root node 를 시작점으로 할 거면 root node 는 데이터가 없으므로
node 의 data 는 커서 왼쪽에 위치한 문자가 된다.

*/