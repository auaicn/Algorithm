#include <stdio.h>
#include <iostream>
#include <stack>

#define MAX_ARRAY_SIZE (1000010)
#define MAX_ELEMENT (1000010)

using namespace std;

int appear[MAX_ELEMENT];
int save[MAX_ARRAY_SIZE];
int result[MAX_ARRAY_SIZE];

stack<pair<int,int> > s;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		scanf("%d",&save[i+1]); 
		appear[save[i+1]]++;
	}

	for (int i=0;i<N;i++)
		result[i+1] = -1;

	for (int i=0;i<N;i++){
		// stack 에서 monotone 으로 유지하고 싶은 속성은 무엇인가?
		// top 의 appear value 가 lowest 하도록 유지하고 싶다.
		while(!s.empty() && s.top().first < appear[save[i+1]]){
			pair<int,int> sTop = s.top(); s.pop();
			int appearValue = sTop.first;
			int idx = sTop.second;
			result[idx] = save[i+1];
		}
		// anyway stack 에 남아있는 애들은 나보다 idx 는 작으면서, 
		s.push({appear[save[i+1]], i+1});
	}

	for (int i=0;i<N;i++)
		printf("%d ",result[i+1]);
	printf("\n");

	return 0;
}