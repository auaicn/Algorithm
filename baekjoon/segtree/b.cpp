#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N; scanf("%d",&N);
		int res = 0;
		bool able = true;

		while(N%3 == 0){
			// able to divide by 3
			res++;
			N/=3;
			if(N%2){
				res++;
			}else
				N/=2;
		}
		if(N!=1)
			able = false;
		if(able)
			printf("%d\n",res);
		else
			printf("-1\n");
	}
	return 0;
}