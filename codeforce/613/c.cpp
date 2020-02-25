#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){

		int N,M; scanf("%d %d",&N,&M);
		char save[200010]; scanf(" %s",save+1);
		save[N+1] = '\0';

		//printf("%s\n",save+1);

		int fail[200010];
		for (int i=0;i<N;i++)
			fail[i+1] = 0;

		for (int i=0;i<M;i++){
			int temp; scanf("%d",&temp);
			fail[temp]++;
		}

		fail[N] = 1;

		int st = fail[N];
		for (int i=N-1;i>0;i--){
			fail[i]+= st;
			st = fail[i];

		}

		long long result[30];
		for (int i=0;i<26;i++)
			result[i] = 0;
		
		for (int i=0;i<N;i++)
			result[save[i+1]-'a'] += fail[i+1];

		/*
		for (int i=0;i<N;i++)
			printf("%d ",fail[i+1]);
		printf("\n");
		*/

		for (int i=0;i<26;i++)
			printf("%lld ",result[i]); 	
		printf("\n");

	}
	return 0;
}

/*
3
4 2
abca
1 3
10 5
codeforces
2 8 3 2 9
26 10
qwertyuioplkjhgfdsazxcvbnm
20 10 1 2 3 5 10 5 9 4

*/