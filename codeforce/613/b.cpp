#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min(int x, int y){ return x<y?x:y;}
int max(int x, int y){ return x>y?x:y;}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		
		int N,M; scanf("%d %d",&N,&M);
		int save[110];
		for (int i=0;i<N;i++)
			scanf("%d",&save[i+1]);
		save[0] = save[N+1] = 0;

		vector<int> index;
		for (int i=0;i<M;i++){
			int temp; scanf("%d",&temp);
			index.push_back(temp);
		}
		sort(index.begin(),index.end());

		//

		int group[110];
		int j = 0;
		group[1] = 1;
		for (int i=0;i<N;i++){
			if(index[j]==i+1&&j<M){
				group[i+2] = group[i+1];
				j++;
			}else
				group[i+2] = group[i+1] + 1;
		}

		/*
		for (int i=0;i<N;i++)
			printf("%4d",group[i+1]);
		printf("\n");
		*/

		bool sw = false;
		group[N+1] = group[0] = 0;

		for (int i=1;i<N;i++){
			if(group[i]!=group[i+1]){
				int left_max = -1;
				for (int j=i;;j--){
					if(group[j]!=group[i])
						break;
					left_max = max(left_max,save[j]);
				}
				int right_min = 999;
				for (int j=i+1;;j++){
					if(group[j]!=group[i+1])
						break;
					right_min = min(right_min,save[j]);
				}
				if(left_max>right_min){
					sw = true;
					break;

				}
			}
		}

		if(sw)
			printf("NO\n");
		else 
			printf("YES\n");

	}
	return 0;
}