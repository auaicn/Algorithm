#include <stdio.h>
#include <iostream>

using namespace std;

int save[100010];

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d", &N,&M);
	for (int i=0;i<N;i++)
		scanf("%d",&save[i+1]);

	int low = 0; // 말이안됨 불가능. 1은? M <= N 이니깐 같고 다 1이면 가능. 그니까 0으로 해줘야겠네.
	int high = 1000000000; // 쌉가능. N = 10E5 이고 M = 1인데 모든 element가 10E4 인 경우.
	while(high!=low+1){

		int mid = (low+high)/2;

		int sum = 0;
		int cnt_ = 1;
		bool sw = true;
		for (int i=0;i<N;i++){
			if(save[i+1] > mid){
				sw = false;
				break;
			}
			if(sum + save[i+1] > mid){
				sum = save[i+1];
				cnt_++;
			}else
				sum += save[i+1];
		}
		//printf("[%d-%d][mid %3d] sum : %3d, cnt %d\n",low,high,mid,sum,cnt_);

		if(sw && cnt_ <= M)
			// possible
			high = mid;
			//low = mid;
		else
			low = mid;
			//high = mid;

	}

	printf("%d\n",high);
	return 0;
}