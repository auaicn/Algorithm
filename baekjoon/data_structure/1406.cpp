#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

struct Node {
  char letter;
  Node* previous;
  Node* next;
};

char input[100010];

Node* root;

int main(){
  scanf("%s",input);

  int inputLen = strlen(input);

  root = new Node{'.',NULL,NULL};

  Node* cursor = root;

  for (int i=0;i<inputLen;i++){
    char c = input[i];

    cursor -> next = new Node{c, cursor, NULL};

    cursor = cursor -> next;
  }

  int M; scanf("%d", &M);

  while(M--){
    char command; scanf(" %c", &command);

    switch(command){
      case 'L':{
        // go left
        if (cursor -> previous == NULL) break;

        cursor = cursor -> previous;

        break;
      }
      case 'D':{
        // go right
        if (cursor -> next == NULL) break;

        cursor = cursor-> next;

        break;
      }
      case 'B':{
        if (cursor -> previous == NULL) break;

        cursor -> previous -> next = cursor -> next;

        if (cursor -> next) cursor -> next -> previous = cursor -> previous;

        cursor = cursor -> previous;
        break;
      }
      case 'P':{
        // insert here
        char c; scanf(" %c", &c);

        if (cursor -> next == NULL){
          cursor -> next = new Node{c, cursor, NULL};
        }else{
          cursor -> next -> previous = new Node{c, cursor, cursor -> next};
          cursor -> next = cursor -> next -> previous;
        }

        cursor = cursor -> next;

        break;
      }
    }
  }

  Node* p = root -> next;

  while(p){
    printf("%c",p -> letter);

    p = p -> next;
  }
  printf("\n");
}