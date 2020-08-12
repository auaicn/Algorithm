#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v;

int min(int x,int y){
	return x<y?x:y;
}

priority_queue<pair<int,int>> both;
priority_queue<pair<int,int>> alice;
priority_queue<pair<int,int>> bob;
priority_queue<pair<int,int>> neither;

int main(int argc, char const *argv[])
{
	int N,M,K; scanf("%d %d %d",&N,&M,&K);
	for (int i=0;i<N;i++){
		int cost,alice_like,bob_like; scanf("%d %d %d",&cost,&alice_like,&bob_like);
		if(alice_like && bob_like)
			both.push({-cost,i+1});
		else if (alice_like)
			alice.push({-cost,i+1});
		else if (bob_like)
			bob.push({-cost,i+1});
		else
			neither.push({-cost,i+1});
	}
	int result = 0;
	if(both.size()+bob.size() < K || both.size()+alice.size() < K){
		printf("-1\n");
		return 0;
	}else{
		while(K--){

			// 여기서 원래 K 는 K + 1 이겠지,
			// M - K 가 1이상이어야지만, 2개를 택하는 것이 가능하다.
			// printf("%d\n",M - (K+1));
			if((M - (K+1) > 0) && (M >= 2)){
				pair<int,int> both_top = {1987654321,0};
				if(!both.empty()){
					both_top = both.top(); 
					both_top.first *= -1;
				}
				int sum = 1987654321;
				pair<int,int> alice_top = {1987654321,0};
				pair<int,int> bob_top = {1987654321,0};
				if(!alice.empty() && !bob.empty()){
					alice_top = alice.top();
					bob_top = bob.top();
					sum = alice_top.first + bob_top.first;
					sum *= -1;
				}
				if(both_top.first == 1987654321 && sum == 1987654321){
					printf("-1\n");
					return 0;
				}

				if(both_top.first < sum){
					result += both_top.first;
					both.pop();
					M -= 1;
					v.push_back(both_top.second);
				}
				else{
					result += sum;
					alice.pop();
					bob.pop();
					M -= 2;
					v.push_back(alice_top.second);
					v.push_back(bob_top.second);
				}
			}else{
				// 무조건 both 택한다.
				// 근데 empty 일 수가 있나? 애초에 걸러졌어야함. 여기서 runtime error 나는것도 신기한데.
				// 그럴 수 있다. M 을 고려하지 않고 지금 K 로만 걸럿기 때문에, M이 작으면 그럴수도 있는것. 런타임에서 걸러지는것이 맞겠다.
				if(both.empty()){
					printf("-1\n");
					return 0;
				}
				pair<int,int> both_top = both.top(); both_top.first *= -1;
				result += both_top.first;
				both.pop();
				M -= 1;
				v.push_back(both_top.second);
			}
		}

		/*
		if(M < 0){
			// 애초에 여기에 걸리는 일이 생기면 안됨.
			printf("-1\n");
			return 0;
		}
		*/

		while(M--){
			// printf("_\n");
			// min cost just read.
			pair<int,int> both_top; 
			if (!both.empty()) { 
				both_top = both.top();
				both_top.first = -1 * both_top.first;
			} else 
				both_top.first = 1987654321;
			pair<int,int> alice_top; 
			if (!alice.empty()) { 
				alice_top = alice.top();
				alice_top.first = -1 * alice_top.first;
			} else 
				alice_top.first = 1987654321;
			pair<int,int> bob_top; 
			if (!bob.empty()) { 
				bob_top = bob.top();
				bob_top.first = -1 * bob_top.first;
			} else 
				bob_top.first = 1987654321;
			pair<int,int> neither_top; 
			if (!neither.empty()) { 
				neither_top = neither.top();
				neither_top.first = -1 * neither_top.first;
			} else 
				neither_top.first = 1987654321;
			/*
			printf("%d\n",both_top.first);	
			printf("%d\n",alice_top.first);	
			printf("%d\n",bob_top.first);	
			printf("%d\n",neither_top.first);	
			printf("_\n");
			*/
			int min_value = min(both_top.first,alice_top.first);
			min_value = min(min_value,bob_top.first);
			min_value = min(min_value,neither_top.first);
			// printf("min_value[%d]\n",min_value);
			result += min_value;
			if(min_value == both_top.first){
				both.pop();
				v.push_back(both_top.second);
			}
			else if(min_value == bob_top.first){
				bob.pop();
				v.push_back(bob_top.second);
			}
			else if(min_value == alice_top.first){
				alice.pop();
				v.push_back(alice_top.second);
			}
			else if(min_value == neither_top.first){
				neither.pop();
				v.push_back(neither_top.second);
			}
			/*
			if(min_value == 1987654321){
				printf("-1\n");
				return 0;
				// 애초에 불릴수가 없긴 하지만..
			}
			*/
		}
	}
	printf("%d\n",result);
	vector<int>::iterator it = v.begin();
	for (;it!=v.end();it++)
		printf("%d ",*it);
	printf("\n");
	return 0;
}