#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;scanf("%d",&T);
	while(T--){
		long long N,K; scanf("%lld %lld",&N,&K);
		// length N kth lexicographical string 
		long long temp = N*(N-1)/2+1-K;
		long long auaicn = 0;
		while(true){
			if(temp <= (N-1)-auaicn)
				break;
			temp-=(N-1)-auaicn;
			auaicn++;
		}
		//printf("temp :%d\n",temp);
		//printf("auaicn :%d\n",auaicn);
		for (int i=0;i<N;i++){
			if(i==auaicn||i==auaicn+temp)
				printf("b");
			else
				printf("a");
		}
		printf("\n");
	}
	return 0;
}