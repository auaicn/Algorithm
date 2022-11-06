#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> v;
bool isprime[10000010];
int res = 0;

int main(int argc, char const *argv[])
{
	for (int i=2;i<10000010;i++)
		isprime[i] = true;
	for (long long i=2;i<10000010;i++){
		if(!isprime[i])
			continue;
		v.push_back(i);
		for (int j=i*2;j<10000010;j+=i)
			isprime[j] = false;
	}

	long long left,right; scanf("%lld %lld",&left,&right);	

	for (int i=0;i<v.size();i++){
		long long temp = v[i]*v[i];
		if(temp > right)
			break;
		if(left<=temp && temp<=right)
			res++;
		
	}

	for (int i=0;i<v.size();i++){
		long long temp = v[i];
		if(temp >= 50000)
			break;
		temp*=v[i];
		while(true){
			temp *= v[i];
			if(temp > right)
				break;
			if(left<=temp && temp<=right)
				res++;
		}
	}

	printf("%d\n",res);

	return 0;
}