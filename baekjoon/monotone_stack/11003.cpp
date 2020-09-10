#include <stdio.h>
#include <iostream>
#include <deque>
#include <vector>

#define MAX_ARRAY_SIZE (5000010)

using namespace std;

int save[MAX_ARRAY_SIZE];

deque<int> dq;
vector<int> result;

int min(int x, int y){
	return x<y?x:y;
}

int main(int argc, char const *argv[])
{
	int N,L; scanf("%d %d",&N,&L);
	for (int i=0;i<N;i++)
		scanf("%d",&save[i+1]);

	for (int i=0;i<N;i++){

		// for (int i=0;i<dq.size();i++)
		// 	printf("%3d",dq[i]);
		// printf("\n");
		while(!dq.empty() && dq.front() + L - 1 < i + 1)
			dq.pop_front();

		while(!dq.empty() && save[dq.back()] > save[i+1])
			dq.pop_back();

		dq.push_back(i+1);
		// result.push_back(save[dq.front()]);
		printf("%d ",save[dq.front()]);
	}

	// printf("RESULT\n");
	// for (int i=0;i<result.size();i++)
	// 	printf("%3d",result[i]);
	printf("\n");

	return 0;
}
