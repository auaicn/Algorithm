#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int max(int x,int y){return x>y?x:y;};
int min(int x,int y){return x<y?x:y;};

long long v[1000010];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int temp; scanf("%d",&temp);
		v[temp-(i+1)+200000]+= temp;
	}

	long long result = -1;
	for (int i=0;i<1000010;i++)
		result = max(result,v[i]);

	printf("%lld\n",result);
	/* code */
	return 0;
}