#include <stdio.h>
#include <iostream>

using namespace std;

int weight[110];
int value[110];

int save[100010];

int max(int x,int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int N,K; scanf("%d %d",&N,&K);
	for (int i=0;i<N;i++)
		scanf("%d %d",&weight[i+1],&value[i+1]);
	for (int i=0;i<N;i++){
		for (int j=K;j>=weight[i+1];j--){
			// total value j
			// looking for i+1 elemnt in weight and value
			save[j] = max(save[j],save[j-weight[i+1]]+value[i+1]);
		}
	}

	/*
	int res = 0;
	for (int i=0;i<K;i++)
		res = max(res,save[i+1]);
	printf("%d\n",res);
	*/
	printf("%d\n",save[K]);

	return 0;
}