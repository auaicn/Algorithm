#include <stdio.h>
#include <iostream>

using namespace std;

int max(int x,int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N; scanf("%d",&N);
		int save[1010]; save[0] = 0;

		int res = -1987654321;

		for (int i=0;i<N;i++){
			int temp; scanf("%d",&temp); res = max(res,temp);
			save[i+1] = save[i]+temp;
		}

		for (int i=0;i<N;i++)
			for (int j=i+1;j<N;j++)
				res = max(res,save[j+1]-save[i+1-1]);

		printf("%d\n",res);
	}
	return 0;
}