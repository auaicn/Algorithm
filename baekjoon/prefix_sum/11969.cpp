#include <stdio.h>
#include <iostream>

using namespace std;

int save[100010][10];

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<N;i++){
		int breed; scanf("%d",&breed);
		save[i+1][1] = save[i][1];
		save[i+1][2] = save[i][2];
		save[i+1][3] = save[i][3];
		save[i+1][breed]++;
	}
	for (int i=0;i<M;i++){
		int left,right; scanf("%d %d",&left,&right);
		printf("%d %d %d\n",save[right][1]-save[left-1][1],save[right][2]-save[left-1][2],save[right][3]-save[left-1][3]);
	}
	return 0;
}