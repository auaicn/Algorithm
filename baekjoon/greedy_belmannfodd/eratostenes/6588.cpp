#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isprime[1000010];
vector<int> odd_prime;
vector<int>::iterator it;

int main(int argc, char const *argv[])
{
	for (int i=2;i<1000010;i++)
		isprime[i] = true;
	for (int i=2;i<1000010;i++){
		if(!isprime[i])
			continue;
		for (int j=i*2;j<1000010;j+=i){
			isprime[j] = false;
		}
	}
	for (int i=3;i<1000010;i++)
		if(isprime[i])
			odd_prime.push_back(i);

	while(true){
		int temp ;scanf("%d",&temp);
		if(!temp)
			break;
		for (int i=0;i<odd_prime.size();i++){
			int left = odd_prime[i];
			int right = temp - left;
			it = lower_bound(odd_prime.begin(),odd_prime.end(),right);
			if(*it == right){
				// found
				printf("%d = %d + %d\n",temp,left,right);
				break;
			}

		}
	}
	return 0;
}
