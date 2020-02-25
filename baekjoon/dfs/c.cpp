#include <stdio.h>
#include <iostream>

using namespace std;

#define INF (1987654321)

int save[4000];
int save2[4000];

int min(int x, int y){
	return x<y?x:y;
}

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	
	int T; scanf("%d",&T);
	while(T--){
		//printf("---------------------\n");

		for (int i=0;i<4000;i++)
			save[i]=save2[i]=0;

		int N,M,K; scanf("%d %d %d",&N,&M,&K); // M <= N , K < N , N upto 3500
		for (int i=0;i<N;i++)
			scanf("%d",&save[i+1]);

		if(M-1<=K){
			// M 번째 작은 수를 주변에서 구하면 됨 걍 시발.
			int max_ = -1;
			for (int i=0;i<=M-1;i++)
				max_ = max(max_,max(save[i+1],save[N-i]));

			printf("%d\n",max_);
			//printf("skipped\n");
			continue;
		}

		// here, K is smaller than M. K<M-1	최소 하나의 arbi 가 있음? ㅇㅇ.
		int left = 1, right = N;
		for (int i=0;i<K;i++){
			// K times
			if(save[left]>save[right]){
				// left bigger then right will be fixed.
				right--;
			}else
				left++;

		}

		int temp=0;
		for (int i=left;i<=right;i++){
			temp++;
			save2[temp] = save[i];
		}

		// save2 it's size is N-K. arbitarily select left is 나머지 전부지 머. 
		// 내 pos 는 M에서 M-K가 되었고 그 전까지는 모두 arbi.
		// 그래서 M-K-1번의 arbi가 남은거야. 나는 arbi이후에는 최선의 선택을 하겠지. 최선들의 최솟값을 구하자.

		int save2_size = N-K;
		int min_ = INF;
		int select_left = M-K-1;

		for (int left = 0;left<=select_left;left++){
			int right = select_left - left;
			min_ = min(min_,max(save2[left+1],save2[save2_size-right]));
		}

		printf("%d\n",min_);

	}

	return 0;
}