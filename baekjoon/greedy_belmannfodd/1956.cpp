#include <stdio.h>
#include <iostream>

using namespace std;

#define INF (1987654321)

int min(int x,int y){
	return x<y?x:y;
}

int dist[500][500];

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);

	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			dist[i+1][j+1] = INF;
		}
	}
	for (int i=0;i<M;i++){
		int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
		dist[left][right] = weight;
	}

	for (int k=0;k<N;k++){
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				if(dist[i+1][k+1]==INF||dist[k+1][j+1]==INF)
					continue;
				else if (dist[i+1][j+1]>dist[i+1][k+1]+dist[k+1][j+1])
					dist[i+1][j+1] = dist[i+1][k+1]+dist[k+1][j+1];

			}
		}
	}
	int min_ = INF;

	for (int i=0;i<N;i++)
		min_ = min(min_,dist[i+1][i+1]);

	if(min_==INF)
		printf("-1\n");
	else
		printf("%d\n", min_);
	return 0;
}