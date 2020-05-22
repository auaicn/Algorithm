#include <stdio.h>
#include <iostream>

using namespace std;

int save[10010][10];

int max(int x,int y){
	return x>y?x:y;
}

int min(int x,int y){
	return x<y?x:y;
}

int main(int argc, char const *argv[])
{
	int N,R,K; scanf("%d %d %d",&N,&R,&K);
	for (int i=0;i<R;i++)
		scanf("%d %d %d",&save[i+1][1],&save[i+1][2],&save[i+1][3]);

	int low = 0;
	int high = 1000000;

	while(high != low + 1){

		int mid = (low+high)/2;

		long long sum = 0;
		for (int i=0;i<R;i++){
			if(save[i+1][1] > mid)
				continue;
			else{
				int right = min(save[i+1][2],mid);
				sum += (right-save[i+1][1])/save[i+1][3] + 1;
				//printf("%d\n",sum);
			}
		}
		//printf("[%5d - %5d], mid[%5d] sum %d\n",low,high,mid,sum);
		if(sum<K)
			// lack
			low = mid;
		else
			// sufficient
			high = mid;

	}

	printf("%d\n",high);
	return 0;
}