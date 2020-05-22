#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(int argc, char const *argv[])
{
	int N,C; scanf("%d %d",&N,&C);
	for (int i=0;i<N;i++){
		int temp; scanf("%d",&temp);
		v.push_back(temp);
	}

	sort(v.begin(),v.end());

	int low = 0; // Possible...
	int high = 1000000000; // Fail
	
	while(high != low + 1){

		int mid = (low + high) / 2;

		int cnt_ = 1;
		int sum = 0;
		for (int i=1;i<N;i++){
			if (sum + (v[i]-v[i-1]) >= mid){
				sum = 0;
				cnt_++;
			}else
				sum += v[i]-v[i-1];
		}
		// printf("[%d-%d] mid[%d] cnt %d \n",low,high,mid,cnt_);

		if (cnt_ < C)
			// fail
			high = mid;
		else
			low = mid;

	}

	printf("%d\n",low);

	return 0;


}