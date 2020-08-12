#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

#define INF (2000000007)

int segtree[100010][3];

int max(int x,int y){
	return x>y?x:y;
}

int min(int x, int y){
	return x<y?x:y;
}

int lookup(int x, int y, int now){

}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){

		int N; scanf("%d",&N);
		int width = log2(N);
		if(N == 1<<width)
			width--;
		width++;
		int size = 1<<width;
		printf("size [%d]\n",size);
		for (int i=0; i<size; i++){
			if(i < N){
				scanf("%d %d",&segtree[i + size][0],&segtree[i + size][1]);
				segtree[i + size][2] = 1;
			}
			else{
				segtree[i+size][0] = -INF;
				segtree[i+size][1] = INF;
				segtree[i+size][2] = 0;
			}
		}

		for (int i=size-1; i>0; i--){
			segtree[i][0] = min(segtree[i*2][0],segtree[i*2+1][0]);
			segtree[i][1] = max(segtree[i*2][1],segtree[i*2+1][1]);
			segtree[i][2] = segtree[i*2][2] + segtree[i*2+1][2];
		}

		long long res = 0;
		for (int i=0;i<N;i++){
			int x = segtree[size + i][0];
			int y = segtree[size + i][0];
			res += lookup(x,y,1);
		}

		printf("%lld\n",res);


	}
	return 0;
}