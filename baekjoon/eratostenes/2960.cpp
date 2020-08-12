#include <stdio.h>
#include <iostream>

using namespace std;

bool isprime[1000010];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	int K ; scanf("%d",&K);

	for (int i=2;i<1010;i++)
		isprime[i] = true;

	int res = 0;
	for (int i=2;i<=N;i++){
		if (!isprime[i])
			continue;

		for (int j=i;j<=N;j+=i){
			if(!isprime[j])
				continue;
			else{
				res++;
				isprime[j] = false;
				if(res == K){
					printf("%d\n",j);
					return 0;
				}
			}
		}
	}
	return 0;
}