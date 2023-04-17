/*

*/

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;

string name[100010];
unordered_map<string, int> num;

// char name[100010][30];
// char command[30];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // int N,M; scanf("%d %d", &N, &M); // up to 10E5
  int N,M; cin >> N >> M;

  for (int i=0;i<N;i++){
    // memset(command, 30 ,'\0');
    int pokemonNumber = i+1;
    string temp; cin >> temp;
    // scanf(" %s", command);

    name[pokemonNumber] = temp;
    num[temp] = pokemonNumber;
  }

  for (int i=0;i<M;i++){
    string command; cin >> command;
    // memset(command, 30 ,'\0');
    // scanf(" %s", command);

    // bool isNumber = '0' <= command[0] && command[0] <= '9';

    if (isdigit(command[0])){
      int number = stoi(command);

      // for (int j=0;j<strlen(command);j++){
      //   number *= 10;
      //   number += command[j] - '0';
      // }

      // printf("%s\n", name[number]);
      cout << name[number] << endl;
    }else {
      cout << num[command] << endl;
    }
  }
}