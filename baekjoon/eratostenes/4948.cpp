#include <stdio.h>
#include <iostream>

using namespace std;

bool isprime[1000010];
int num_prime[1000010];

int main(int argc, char const *argv[])
{
	for (int i=2;i<1000010;i++)
		isprime[i] = true;


	for (long long i=2;i<1000010L;i++){
		if(!isprime[i])
			continue;
		for (long long j = i*i; j < 1000010L; j += i){
			isprime[j] = false;
		}
	}

	//int temp; scanf("%d",&temp);
	for (int i=2;i<1000010;i++){
		num_prime[i] = num_prime[i-1];
		if(isprime[i])
			num_prime[i]++;
	}

	while(1){
		int temp; scanf("%d",&temp);
		if(!temp)
			break;
		printf("%d\n",num_prime[temp*2]-num_prime[temp]);
	}

	return 0;
}