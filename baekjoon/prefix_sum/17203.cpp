#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int save[1010];
int sum[1010];

int main(int argc, char const *argv[])
{
	int N,Q; scanf("%d %d",&N,&Q);

	scanf("%d",&save[1]);

	for (int i=1;i<N;i++){
		scanf("%d",&save[i+1]);
		sum[i+1]+=sum[i];
		sum[i+1]+=abs(save[i+1]-save[i]);
	}

	for (int i=0;i<Q;i++){
		int left,right; scanf("%d %d",&left,&right);
		if(left<right)
			printf("%d\n",sum[right]-sum[left]);
		else
			printf("0\n");
	}

	return 0;
}