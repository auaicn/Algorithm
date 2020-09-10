#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX_NUM_BUILDING (80010)

int height[MAX_NUM_BUILDING];
stack<int> s;
long long result;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf("%d",&height[i]);

	for (int i=0;i<N;i++){

		// 여기선 idx 가 아니라 value itself 이기 때문에 같을 수 있다.
		while(!s.empty() && s.top() <= height[i]){
			s.pop();
		}
		// no pop 인 경우 Result 가 안더해졌구
		result += (long long) s.size();
		s.push(height[i]);
	}

	printf("%lld\n",result);

	return 0;
}