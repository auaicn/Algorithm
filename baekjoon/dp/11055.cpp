#include <stdio.h>
#include <iostream>

using namespace std;

int save[1010];
int sum[1010];

int max(int x,int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N); // N upto 1000

	for (int i=0;i<N;i++)
		scanf("%d",&save[i+1]);

	for (int i=0;i<N;i++){
		// looking for i+1 th element
		for (int j=i+1-1;j>=0;j--){
			if(save[i+1]>save[j])
				sum[i+1] = max(sum[i+1],sum[j]+save[i+1]);
		}
	}

	int res = 0;
	for (int i=0;i<N;i++)
		res = max(res,sum[i+1]);
	printf("%d\n",res);

	return 0;
}
