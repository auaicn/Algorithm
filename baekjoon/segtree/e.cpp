#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	priority_queue<int> both;
	priority_queue<int> alice;
	priority_queue<int> bob;
	priority_queue<int> neither;
	int N,K; scanf("%d %d",&N,&K);
	for (int i=0;i<N;i++){
		int cost,alice_like,bob_like; scanf("%d %d %d",&cost,&alice_like,&bob_like);
		if(alice_like && bob_like)
			both.push(-cost);
		else if (alice_like)
			alice.push(-cost);
		else if (bob_like)
			bob.push(-cost);
		else
			neither.push(-cost);
	}
	int result = 0;
	if(both.size()+bob.size() < K || both.size()+alice.size() < K){
		printf("-1\n");
		return 0;
	}else{
		while(K--){
			int both_top = 1987654321;
			if(!both.empty()){
				both_top = both.top(); both_top *= -1;
			}
			int sum = 1987654321;
			if(!alice.empty() && !bob.empty()){
				sum = alice.top() + bob.top(); sum *= -1;
			}
			if(both_top < sum){
				result += both_top;
				both.pop();
			}
			else{
				result += sum;
				alice.pop();
				bob.pop();
			}
		}
	}
	printf("%d\n",result);
	return 0;
}