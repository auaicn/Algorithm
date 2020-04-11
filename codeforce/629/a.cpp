#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int A,B; scanf("%d %d",&A,&B);
		if(A%B)
			printf("%d\n",B-A%B);
		else
			printf("0\n");
	}
	return 0;
}