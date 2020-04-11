#include <stdio.h>
#include <iostream>

using namespace std;

int min(int x, int y){
	return x<y?x:y;
}

int num_block[30];

int dfs(int x, int y, int z){
	int min_ = min(x,min(y,z));

}

int main(int argc, char const *argv[])
{
	int len,height,width; scanf("%d %d %d",&len,&height,&width);
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int left,right; scanf("%d %d",&left,&right);
		num_block[left] = right;
	}
	printf("%d\n",dfs(len,height,width));
	return 0;
}