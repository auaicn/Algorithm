#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> primes;

bool isprime[1300010];
vector<int>::iterator it;


int main(int argc, char const *argv[])
{
	for (int i=2;i<1300010;i++)
		isprime[i] = true;
	for (int i=2;i<1300010;i++){
		if(!isprime[i])
			continue;
		for (int j=i*2;j<1300010;j+=i){
			isprime[j] = false;
		}
	}
	for (int i=2;i<1300010;i++){
		if(isprime[i])
			primes.push_back(i);
	}
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int temp; scanf("%d",&temp);
		if(isprime[temp]){
			printf("0\n");
			continue;
		}

		it = lower_bound(primes.begin(),primes.end(),temp);
		int left_idx = it - primes.begin(); left_idx --;
		int right_idx = left_idx + 1;
		printf("%d\n",primes[right_idx]-primes[left_idx]);
	}

	/* code */
	return 0;
}