#include <stdio.h>
#include <iostream>

using namespace std;

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,X; scanf("%d %d",&N,&X);
		int num_even = 0;
		int num_odd = 0;
		for (int i=0;i<N;i++){
			int temp; scanf("%d",&temp);
			if(temp%2)
				num_odd++;
			else
				num_even++;
		}
		bool found = false;
		for (int i=0;i<=num_odd;i++){
			// odd i 개
			// even : X-num_odd개 쓸건데
			// odd개수는 0이상인데
			// even 개수도 0이상이어야하지
			if(X-i<0)
				break;
			else
				if(i%2){
					found = true
					break;
				}
		}
		if(found)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}