#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX_ARRAY_SIZE (100010)

using namespace std;

int save[MAX_ARRAY_SIZE];
int right_[MAX_ARRAY_SIZE];
int left_[MAX_ARRAY_SIZE];

stack<int> nxt;

long long max(long long x, long long y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	while(true){
		int N; scanf("%d",&N);
		if(!N)
			break;

		for (int i=0;i<N;i++)
			scanf("%d",&save[i+1]);

		for (int i=0;i<N;i++)
			left_[i+1] = right_[i+1] = -1;

		while(!nxt.empty())
			nxt.pop();

		// fill right_[]
		for (int i=0;i<N;i++){
			while(!nxt.empty() && save[i+1] < save[nxt.top()]){
				int nxtTop = nxt.top(); nxt.pop();
				right_[nxtTop] = i + 1 - 1;
			}
			nxt.push(i+1);
		}

		while(!nxt.empty())
			nxt.pop();

		for (int i=0;i < (N+1)/2;i++){
			int temp = save[i+1];
			save[i+1] = save[N+1 - (i+1)];
			save[N+1 - (i+1)] = temp;
		}

		// fill left[]
		for (int i=0;i<N;i++){
			while(!nxt.empty() && save[i+1] < save[nxt.top()]){
				int nxtTop = nxt.top(); nxt.pop();
				left_[N + 1 - nxtTop] = N + 1 - (i + 1) + 1;
			}
			nxt.push(i+1);
		}

		long long result = 0;
		for (int i=0;i<N;i++){
			int left = left_[i+1];
			if(left == -1)
				left = 1;
			int right = right_[i+1];
			if(right == -1)
				right = N;
			long long length = right - left + 1;
			long long height = save[(N+1) - (i+1)];
			result = max(result, length * height);
		}

		printf("%lld\n",result);
	}

	return 0;
}
