#include <stdio.h>
#include <iostream>

using namespace std;

#define UNVISITED (-1)
#define VISITED (0)
#define ABLE (1)

bool isprime[1000010];
int sangeun[1000010];

int recursive_fn(int now){
	//printf("now[%d]\n",now);
	int now_cpy = now;
	if(sangeun[now]==ABLE)
		return ABLE;
	else if (sangeun[now] == VISITED)
		return VISITED;
	else{
		int sum = 0;
		while(now_cpy){
			int mod = now_cpy%10;
			sum += mod*mod;
			now_cpy /= 10;
		}
		sangeun[now] = VISITED;
		return sangeun[now] = recursive_fn(sum);
	}
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=2;i<1000010;i++)
		isprime[i] = true;

	for (int i=2;i<1000010;i++){
		if(!isprime[i])
			continue;
		for (int j=i*2;j<1000010;j+=i)
			isprime[j] = false;
	}

	for (int i=2;i<1000010;i++)
		sangeun[i] = UNVISITED;

	sangeun[1] = ABLE;
	for (int i=2;i<=N;i++){
		int ret = recursive_fn(i);
		if(ret == ABLE && isprime[i])
			printf("%d\n",i);
		else
			continue;
	}

	return 0;
}
