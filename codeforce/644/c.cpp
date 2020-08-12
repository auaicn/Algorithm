#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int x,int y){
	return x>y?x:y;
}

int min(int x, int y){
	return x<y?x:y;
}

vector<int> save;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N;scanf("%d",&N);
		for(int i=0;i<N;i++){
			int temp; scanf("%d",&temp);
			save.push_back(temp);
		}
		sort(save.begin(),save.end());
		int num_even = 0;
		int num_odd = 0;
		for (int i=0;i<N;i++){
			if(save[i]%2)
				num_odd++;
			else
				num_even++;
		}
		if(num_odd%2){
			// both od
			bool sw = false;
			for (int i=0;i<N-1;i++){
				if(save[i+1]-save[i]==1)
					sw = true;
			}
			if(sw)
				printf("YES\n");
			else
				printf("NO\n");
		}else
			printf("YES\n");
		save.clear();
	}
	return 0;
}