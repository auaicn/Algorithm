#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int max(int x,int y){
	return x>y?x:y;
}

int min(int x, int y){
	return x<y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,K; scanf("%d %d",&N,&K);

		int res = 1;
		if(N<=K){
			printf("1\n");
			continue;
		}else{
			for (int i=1;i<=40010;i++){
				if(N%i)
					continue;
				else{
					if(N/i <= K)
						res = max(res,N/i);
					if(i <= K)
						res = max(res,i);
				}
			}
		}
		printf("%d\n",N/res);
	}
	return 0;
}