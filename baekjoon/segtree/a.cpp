#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int x,y,n; scanf("%d %d %d",&x,&y,&n);
		int k = ((n-y)/x)*x + y;
		while(k + x <= n){
			k += x;
		}
		printf("%d\n",k);
	}
	return 0;
}