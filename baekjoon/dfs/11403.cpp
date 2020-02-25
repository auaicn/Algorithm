#include <stdio.h>
#include <iostream>
using namespace std;

#define INF (987654321)

int dist[110][110];

int min(int x, int y){
	return x<y?x:y;
}

int N; 

int main(){
	scanf("%d",&N);


	for (int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			int temp; scanf("%d",&temp);
			dist[i+1][j+1] = temp?temp:INF;
		}

	for (int k=0;k<N;k++){
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				dist[i+1][j+1] = min(dist[i+1][j+1],dist[i+1][k+1]+dist[k+1][j+1]);
				dist[j+1][i+1] = min(dist[j+1][i+1],dist[j+1][k+1]+dist[k+1][i+1]);
			}
		}
	}

	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			if(dist[i+1][j+1]==INF)
				printf("0 ");
			else printf("1 ");
		}
		printf("\n");
	}

	return 0;
}