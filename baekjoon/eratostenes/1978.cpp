#include <stdio.h>
#include <iostream>

using namespace std;

bool isprime[1000010];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=2;i<1010;i++)
		isprime[i] = true;
	for (int i=2;i<1010;i++){
		if (!isprime[i])
			continue;
		for (int j=i*i;j<1010;j+=i){
			isprime[j] = false;
		}
	}
	int res = 0;
	for (int i=0;i<N;i++){
		int temp; scanf("%d",&temp);
		if(isprime[temp])
			res++;
	}
	printf("%d\n",res);
	return 0;
}