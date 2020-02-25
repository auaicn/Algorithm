#include <stdio.h>
#include <iostream>
using namespace std;

int save[300010];
int save2[300010];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	for (int t=0;t<T;t++){
		int N; scanf("%d",&N);// N up to 3 * 10 ^ 5
		for(int i=0;i<N;i++){
			scanf("%d",&save[i+1]); // each element up to 10 ^ 9
		}

		int left = 0,right = 0;
		for (int i=0;i<N;i++){
			// looking for i+1 th element
			if(save[i+1]<=i-1){
				break;
			}
			left++;
		}

		// reverse
		for (int i=0;i<N;i++){
			save2[i+1] = save[N-i];
		}
		for (int i=0;i<N;i++){
			// looking for i+1 th element
			if(save2[i+1]<=i-1){
				break;
			}
			right++;
		}
		//printf("%d left : %d, right : %d\n",t+1,left,right);
		if(left+right>N)
			printf("Yes\n");
		else
			printf("No\n");

	}


	return 0;
}