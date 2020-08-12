#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

map<int,long long> m;

long long max(long long x, long long y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		m.clear();
		int N; long long K; scanf("%d %lld",&N,&K);
		for (int i=0;i<N;i++){
			int temp; scanf("%d",&temp);
			if(temp%K == 0)
				continue;
			if(m.find(K-(temp%K)) == m.end())
				m[K-(temp%K)] = 1L;
			else 
				m[K-(temp%K)]++;
		}

		if(m.size() == 0){
			printf("0\n");
			continue;
		}
		int max_round = -1;
		long long max_value = -1L;
		map<int,long long>::iterator it = m.begin();
		for (;it != m.end();it++){
			if(it->second < max_round)
				continue;
			else if(it->second > max_round){
				max_round = it->second;
				max_value = it->first;
			}else
				max_value = max(it->first,max_value);
		}
		printf("%lld\n" , (max_round-1) * K + max_value + 1);
	}	
	return 0;
}