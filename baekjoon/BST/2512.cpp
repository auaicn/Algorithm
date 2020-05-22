#include <stdio.h>
#include <iostream>

using namespace std;

int save[10010];

int min(int x, int y){
	return x<y?x:y;
}

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	int temp = 0;
	int max_ = -1;

	for (int i=0;i<N;i++){
		scanf("%d",&save[i+1]);
		temp += save[i+1];
		max_ = max(max_, save[i+1]);
	}

	int M; scanf("%d",&M);
	if(temp <= M){
		printf("%d\n",max_);
		return 0;
	}

	int low = 0;
	int high = 1000000000;

	while(low + 1 < high){
		int mid = (low+high)/2;

		long long sum_ = 0;
		for (int i=0;i<N;i++)
			sum_ += min(save[i+1],mid);

		if (sum_ <= M)
			// 지급 가능
			low = mid;
		else
			// 지급 불가능 high 
			high = mid;

	}
	printf("%d\n",low);

	/* code */
	return 0;
}