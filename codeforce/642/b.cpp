#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> save;
vector<int> compare;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,M; scanf("%d %d",&N,&M);

		save.clear();
		for (int i=0;i<N;i++){
			int temp; scanf("%d",&temp);
			save.push_back(temp);
		}

		compare.clear();
		for (int i=0;i<N;i++){
			int temp; scanf("%d",&temp);
			compare.push_back(temp);
		}
		sort(save.begin(),save.end());
		sort(compare.begin(),compare.end());

		for (int i=0;i<M;i++){
			if(save[i]<compare[(N-1)-i])
				save[i] = compare[(N-1)-i];
			else
				break;
		}
		int res = 0;
		for (int i=0;i<N;i++)
			res+=save[i];
		printf("%d\n",res);
	}
	return 0;
}