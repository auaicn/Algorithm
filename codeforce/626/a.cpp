#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N; scanf("%d",&N);
		int save[110];
		for (int i=0;i<N;i++)
			scanf("%d",&save[i+1]);
		vector<int> v;
		bool sw = false;
		for (int i=0;i<N;i++){
			if(save[i+1]%2)
				v.push_back(i+1);
			else{
				printf("1\n%d\n",i+1);
				sw = true;
				break;
			}
		}
		if(!sw){
			if(v.size()<2){
				printf("-1\n");
				continue;
			}else
			printf("2\n%d %d\n",v[0],v[1]);
		}
	}
	return 0;
}
