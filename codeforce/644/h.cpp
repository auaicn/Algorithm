#include <stdio.h>
#include <iostream>

using namespace std;

int max(int x,int y){
	return x>y?x:y;
}

int min(int x, int y){
	return x<y?x:y;
}

int abs(int x){
	return x>0?x:-x;
}

char save[110][110];
char mid[110];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,M; scanf("%d %d",&N,&M);

		mid[0] = '0';
		for (int i=0;i<N-1;i++)
			mid[i+1] = '1';
		mid[N] = '\0';

		int left = 0;
		int right = 0;
		bool mid_erase = false;
		for (int i=0;i<N;i++){
			scanf(" %s",save[i]);
			if(save[i]<mid)
				left++;
			else if (save[i] > mid)
				right++;
			else
				mid_erase = true;

		}
		int incre = 0;

		int common = min(left,right);
		left -= common;
		right -= common;
		// at least one is zero
		for (int i=0;i<left/2;i++)
			incre++;
		// left one is ok.

		// assume mid is erased at last
		for (int i=0;i<right/2;i++)
			incre--;

		if (mid_erase){
			if(max(left,right)%2){
				// viased is by odd. now odd. be even
				incre--;
			}
		}

		// right one erased is ok
		for (int i=0;i<incre;i++){

		}


	}
	return 0;
}