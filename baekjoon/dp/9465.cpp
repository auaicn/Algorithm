#include <stdio.h>
#include <iostream>

using namespace std;

int save[100010][2];

int max(int x,int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N; scanf("%d",&N);
		for (int i=0;i<N;i++)
			scanf("%d",&save[i+1][0]);
		for (int i=0;i<N;i++)
			scanf("%d",&save[i+1][1]);

		if(N==1){
			printf("%d\n",max(save[1][1],save[1][0]));
			continue;
		}

		save[2][1]+=save[1][0];
		save[2][0]+=save[1][1];

		for (int i=2;i<N;i++){
			save[i+1][1]+=max(max(save[i-1][1],save[i-1][0]),save[i][0]);
			save[i+1][0]+=max(max(save[i-1][1],save[i-1][0]),save[i][1]);
		}
		
		printf("%d\n",max(save[N][0],save[N][1]));

	}
	return 0;
}