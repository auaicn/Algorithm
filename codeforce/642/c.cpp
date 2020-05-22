#include <stdio.h>
#include <iostream>

using namespace std;

long long table[500020];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	for (int i=1;i<500010;i+=2){
		long long temp = i;
		temp+=1;
		temp/=2;
		table[temp] = table[temp-1] + 8*(temp-1)*(temp-1);
	}

	while(T--){
		int N; scanf("%d",&N); N+=1; N/=2;
		printf("%lld\n",table[N]);
	}
	return 0;
}