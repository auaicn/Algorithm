#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

bool save[1010];
vector<long long> v;

int main(int argc, char const *argv[])
{
	long long N,M; scanf("%lld %lld",&N,&M);
	for (long long i=0;i<N;i++){
		long long temp; scanf("%lld",&temp);
		long long check =temp%M;
		if(save[check]){
			printf("0\n");
			return 0;
		}else{
			save[check]=true;
			v.push_back(temp);
		}
	}
	
	long long result = 1;
	
	for (int i=0;i<v.size();i++){
		for (int j=i+1;j<v.size();j++){
			// looking for i+1 and j+1 th element
			result*=abs(v[i]-v[j]);
			result%=M;
		}
	}	

	printf("%lld\n",result);
	return 0;
}