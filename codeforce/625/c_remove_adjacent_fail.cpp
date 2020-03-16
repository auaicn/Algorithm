#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

char save[110];

bool adjacent(int now, int adj){
	if(save[now]-save[adj]==1)
		return true;
	else 
		return false;
}

int main(int argc, char const *argv[])
{
	
	int N; scanf("%d",&N);
	int save_N = N;
	scanf("%s",&save[1]);

	save[0] = save[N+1] = '\0';

	priority_queue<pair<int,int> > pq; // first, index
	int result = 0;

	for (int i=0;i<N;i++){
		//looking for i+1 th element
		if(adjacent(i+1,i)){
			if(adjacent(i,i+2)||adjacent(i+2,i)){
				// erase i+1
				pq.push_back({1,i+1});

			}
			else if(adjacent(i-1,i+1)){
				// erase i
				pq.push_back({1,i});

			}else{
				pq.push_back({0,i+1});
			}
		}else 
		if(adjacent(i+1,i+2)){
			if(adjacent(i,i+2)){
				// erase i+1
				pq.push({1,i+1});
			}else if(adjacent(i+1,i+3)){
				// erase i+2
				pq.push({1,i+2});
			}else
				pq.push({0,i+1});
		}
	}

	while(!pq.empty()){
		pair<int,int> pos = pq.top(); pq.pop();

		// priority not needed anymore!
		int now = pos.second; 

		result++;

		// lets shift first
		while(!pq.empty())
			pq.pop();

		for (int i=now;i<=N;i++){
			save[i] = save[i+1];
		}

		for (int i=0;i<N-result;i++){
			//looking for i+1 th element
			/*
			if(adjacent(i,i+1)){
				if(adjacent(i,i+2)){
					// erase i+1
					pq.push_back({1,i+1});
					continue;

				}else if(adjacent(i-1,i+1)){
					// erase i
					pq.push_back({1,i});

				}else{
					pq.push_back({0,})
				}
			}else 
			*/
			if(adjacent(i+1,i+2)){
				if(adjacent(i,i+2)){
					// erase i+1
					pq.push({1,i+1});
				}else if(adjacent(i+1,i+3)){
					// erase i+2
					pq.push({1,i+2});
				}else
					pq.push({0,i+1});
			}
		}

		printf("%s\n",save+1);
	}


	printf("%d\n",result);

	return 0;
}