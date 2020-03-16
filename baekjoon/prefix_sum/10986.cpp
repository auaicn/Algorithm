#include <stdio.h>
#include <iostream>

using namespace std;

int save[1000100];

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<N;i++){
		int temp; scanf("%d",&temp);
		temp %= M;
		save[i+1] = temp;
	}
	
	return 0;
}