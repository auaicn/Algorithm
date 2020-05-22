#include <stdio.h>
#include <iostream>

using namespace std;

int save[1000010][2];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);

	save[1][0] = 0;
	save[1][1] = 1;

	save[2][1] = 1;
	save[2][0] = 1;

	for (int i=2;i<N;i++){
		save[i+1][0] = save[i-1][0]+save[i-1][1];
		save[i+1][1] = save[i][0]+save[i][1];
		save[i+1][0] %= 10007;
		save[i+1][1] %= 10007;
	}

	printf("%d\n",(save[N][0]+save[N][1])%10007);

	return 0;
}