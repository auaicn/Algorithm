#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long indegree[500010];

bool letter[500010];

long long accumulated[500010];

//connection
int left_[500010];
int right_[500010];

long long N; int M; 
char temp; 

int left_index;
int right_index;

int main(int argc, char const *argv[])
{

	scanf("%lld %d",&N,&M);
	for (int i=0;i<M;i++){
		scanf(" %c",&temp);
		if(temp=='R')
			letter[i+1] = true;

		scanf("%d %d",&left_[i+1],&right_[i+1]);
		indegree[left_[i+1]]++;
		indegree[right_[i+1]]++;
	}

	//indegree[0] = -1;

	queue<int> q;
	q.push(1); accumulated[1] = N;

		
	while(!q.empty()){
		int pos = q.front(); q.pop();

		left_index = left_[pos];
		indegree[left_index]--;
		accumulated[left_index]+=accumulated[pos]/2;
		if(!indegree[left_index])
			q.push(left_index);

		right_index = right_[pos];
		indegree[right_index]--;
		accumulated[right_index]+=accumulated[pos]/2;
		if(!indegree[right_index])
			q.push(right_index);

		if(accumulated[pos]%2){
			if(letter[pos])
				accumulated[right_index]++;
			else
				accumulated[left_index]++;
			letter[pos] = !letter[pos];
		}

	}

	for (int i=0;i<M;i++){
		if(letter[i+1])
			printf("R");
		else
			printf("L");
	}
	printf("\n");

	return 0;
}
