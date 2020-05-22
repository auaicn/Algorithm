#include <stdio.h>
#include <iostream>

using namespace std;

int save[10];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<10;i++)
		save[i] = 1;
	for (int i=1;i<N;i++){
		for (int j=1;j<10;j++){
			save[j] += save[j-1];
			save[j] %= 10007;
		}
	}
	int res = 0;
	for (int i=0;i<10;i++){
		res += save[i];
		res %= 10007;
	}
	printf("%d\n",res);
	return 0;
}
