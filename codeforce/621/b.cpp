#include <stdio.h>
#include <iostream>

using namespace std;

int max(int x, int y){
	return x>y?x:y;
}

int save[100010];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){

		int N,X; scanf("%d %d",&N,&X);

		int max_ = -1;
		bool sw = false;
		for (int i=0;i<N;i++){
			scanf("%d",&save[i+1]);
			if(save[i+1]==X)
				sw = true;
			max_ = max(max_,save[i+1]);
		}

		if(sw){
			printf("1\n");
			continue;
		}

		if(X%max_){
			// 나누어 떨어지지 않는 경우.

			int mok = X/max_-1;
			mok = max(0,mok);
			printf("%d\n",mok+2);

		}else{
			// 가장 큰 수로 나누어 떨어지는 경우.
			printf("%d\n",X/max_);

		}
	}
	return 0;
}