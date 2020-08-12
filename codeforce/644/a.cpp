#include <stdio.h>
#include <iostream>

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
		int A,B; scanf("%d %d",&A,&B);
		int min_ = min(A,B);
		min_*=2;
		int max_ = max(min_,max(A,B));
		printf("%d\n",max_*max_);

	}
	return 0;
}