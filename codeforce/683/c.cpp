#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<long long,int> > v;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		v.clear();
		int N; long long W; scanf("%d %lld",&N,&W);
		long long left = W % 2? W / 2 + 1 : W / 2;
		// printf("\nleft[%lld]\n",left);
		// printf("left : %d\n",left);

		bool found = false;
		int found_idx = -1;
		for (int i=0;i<N;i++){
			long long temp; scanf("%lld",&temp);

			// already found
			if(found)
				continue;

			// 그냥 조건 만족하는애가 있어버림
			if(left <= temp && temp <= W){
				found = true;
				found_idx = i+1;
			}

			if(W < temp)
				// 넣어줄 필요가 없는 값들.
				continue;

			v.push_back({temp,i+1}); // to track
			// i +1 th item
			// value : temp
		}
		if(found){
			printf("1\n");
			printf("%d\n",found_idx);
			continue;
		}
		sort(v.begin(),v.end());

		long long sum = 0;
		int i = -1;
		for (i = 0;i<v.size();i++){
			sum+=v[i].first;
			if(sum > left){
				i++;
				break;
			}
		}

		// 끝까지 했는데, 다 더했는데 안된경우가 있음
		if(sum < left)
		{
			printf("-1\n");
			continue;
		}

		// well found
		printf("%d\n",i);
		for (int j=0;j<i;j++){
			printf("%d ",v[j].second);
		}

	}
	return 0;
}