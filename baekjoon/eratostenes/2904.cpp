#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool isprime[1000010];
vector<int> primes;

int save[100][100010];
int sum[100010];
int temp[100010];

int main(int argc, char const *argv[])
{
	for (int i=2;i<1000010;i++)
		isprime[i] = true;
	for (int i=2;i<1000010;i++){
		if(!isprime[i])
			continue;
		primes.push_back(i);
		for (int j=i*2;j<1000010;j+=i){
			isprime[j] = false;
		}
	}

	int res = 1;
	int cnt_ = 0;
	int N; scanf("%d",&N);
	for (int T=0;T<N;T++){
		int temp; scanf("%d",&temp);
		for (int i=0;i<primes.size();i++){
			int div = primes[i];
			while(temp%div == 0){
				temp/=div;
				save[T][i]++;
			}
		}
	}
	for (int i=0;i<100010;i++){
		for (int j=0;j<100;j++){
			sum[i] += save[j][i];
		}
		sum[i]/=N;
	}
	for (int i=0;i<100010;i++){
		if(!sum[i])
			continue;
		else{
			for (int j=0;j<N;j++){
				if(save[j][i]<sum[i])
					cnt_+= sum[i]-save[j][i];
			}
			for (int j=0;j<sum[i];j++)
				res *= primes[i];
		}
	}
	printf("%d %d\n",res,cnt_);

	return 0;
}