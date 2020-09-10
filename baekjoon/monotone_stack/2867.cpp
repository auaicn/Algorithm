#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

#define MAX_ARRAY_SIZE (300010)

using namespace std;

long long save[MAX_ARRAY_SIZE];
long long saveReverse[MAX_ARRAY_SIZE];

stack<int> s;
long long leftLower[MAX_ARRAY_SIZE];
long long rightLower[MAX_ARRAY_SIZE];

long long leftMore[MAX_ARRAY_SIZE];
long long rightMore[MAX_ARRAY_SIZE];

long long result;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		scanf("%lld",&save[i+1]);
		saveReverse[N+1 - (i+1)] = save[i+1];
	}

	for (int i=0;i<N;i++){
		leftLower[i+1] = 1;
		rightLower[i+1] = N;
		leftMore[i+1] = 1;
		rightMore[i+1] = N;
	}

	// FINDMIN
	for (int i=0;i<N;i++){
		while(!s.empty() && save[i+1] <= save[s.top()]){
			int sTop = s.top(); s.pop();
			rightLower[sTop] = i+1 - 1;
		}
		s.push(i+1);
	}

	while(!s.empty())
		s.pop();

	for (int i=0;i<N;i++){
		while(!s.empty() && saveReverse[i+1] < saveReverse[s.top()]){
			int sTop = s.top(); s.pop();
			leftLower[N+1 - sTop] = N + 1 - (i + 1) + 1;
		}
		s.push(i+1);
	}

	// FIND MAX
	while(!s.empty())
		s.pop();

	for (int i=0;i<N;i++){
		while(!s.empty() && save[i+1] >= save[s.top()]){
			int sTop = s.top(); s.pop();
			rightMore[sTop] = i+1 - 1;
		}
		s.push(i+1);
	}

	while(!s.empty())
		s.pop();

	for (int i=0;i<N;i++){
		while(!s.empty() && saveReverse[i+1] > saveReverse[s.top()]){
			int sTop = s.top(); s.pop();
			leftMore[N+1 - sTop] = N + 1 - (i + 1) + 1;
		}
		s.push(i+1);
	}



	for (int i=0;i<N;i++){
		// OOXOOO 모양이면
		// 3 * 4가되어야한다.
		// i+1 이 7이면음.
		result += 1L * (rightMore[i+1] - (i+1) + 1) * ((i+1) - leftMore[i+1] + 1) * save[i+1];
		result -= 1L * (rightLower[i+1] - (i+1) + 1) * ((i+1) - leftLower[i+1] + 1) * save[i+1];

	}
	printf("%lld\n",result);

	return 0;
}
