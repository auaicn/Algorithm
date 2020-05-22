#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,M; scanf("%d %d",&N,&M);
		if (N==1){
			printf("0\n");
			continue;
		}else if (N==2){
			printf("%d\n",M);
			continue;
		}else{
			printf("%d\n",2*M);
			continue;
		}
	}

	return 0;
}

/*
5
1 100
2 2
5 5
2 1000000000
1000000000 1000000000

0
2
10
1000000000
2000000000
*/
