#include <stdio.h>
#include <iostream>

using namespace std;

int save[110];

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N; scanf("%d",&N);
		int max_ = -1;
		for (int i=0;i<N;i++){
			scanf("%d",&save[i+1]);
			max_ = max(max_,save[i+1]);
		}
		bool able = true;
		if(max_%2){
			for (int i=0;i<N;i++){
				if(save[i+1]%2)
					continue;
				else{
					able = false;
					break;
				}
			}
		}else{
			for (int i=0;i<N;i++){
				if(save[i+1]%2){
					able = false;
					break;
				}
				else continue;
			}
		}
		if(able)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}