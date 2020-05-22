#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<pair<int,int> > pq;

int save[200010];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N; scanf("%d",&N);
		for (int i=0;i<N;i++)
			save[i+1] = 0;

		pq.push({N,-1});
		int loop_ = N;
		for (int i=0;i<N;i++){
			pair<int,int> top_ = pq.top(); pq.pop();
			int len = top_.first;
			int left = -(top_.second);
			int right = left+len-1;
			if(len%2){
				save[(left+right)/2] = i+1;
				pq.push({(len-1)/2,-left});
				pq.push({(len-1)/2,-((left+right)/2+1)});
			}else{
				save[(left+right-1)/2] = i+1;
				pq.push({len/2-1,-left});
				pq.push({len/2,-((left+right+1)/2)});
			}
		}
		for (int i=0;i<N;i++)
			printf("%d ",save[i+1]);
		printf("\n");
	}
	return 0;
}