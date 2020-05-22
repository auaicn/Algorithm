#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int save[510];
int save2[510];

int res[510][510];

vector<int> lis;

int max(int x,int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf("%d",&save[i+1]);

	int M; scanf("%d",&M);
	for (int i=0;i<M;i++)
		scanf("%d",&save2[i+1]);

	for (int i=0;i<M;i++){
		for (int j=0;j<N;j++){
			if(save[i+1]==save[j+1]){

			}else
				res[i+1][j+1] = max(res[i+1][j],res[i][j+1]);

		}
	}
	printf("%d\n",res[N][M]);
	return 0;
}