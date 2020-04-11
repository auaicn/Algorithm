#include <stdio.h>
#include <iostream>

using namespace std;

int save[10010];

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	for(int t=0;t<T;t++){
		int N,K; scanf("%d %d",&N,&K);

		for (int i=0;i<10000;i++)
			save[i+1] = 0;

		for (int i=0;i<N;i++){
			int temp; scanf("%d",&temp);
			save[temp]++;
		}

		for (int i=0;i<10000;i++)
			save[i+1]+=save[i];

		int res =-1;
		for (int i=K+1;i<10010;i++)
			res = max(res,save[i]-save[i-K-1]);

		printf("#%d %d\n",t+1,res);
	}
	return 0;
}