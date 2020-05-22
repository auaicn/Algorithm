#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int gcd(int x,int y){
	if(x%y==0)
		return y;
	else
		return gcd(y,x%y);
}

int main(int argc, char const *argv[])
{
	int N,K; scanf("%d %d",&N,&K);
	for (int i=0;i<N;i++)
		v.push_back(i+1);
	for (int i=0;i<K;i++){
		int temp = i+1;
		for (int j=0;j<N;j++){
			if(v[j]==1)
				continue;
			else{
				int gcd_ = gcd(temp,v[j]);
				temp/=gcd_;
				v[j]/=gcd_;
			}
			if(temp==1)
				break;
		}
	}
	for (int i=0;i<N-K;i++){
		int temp = i+1;
		for (int j=0;j<N;j++){
			if(v[j]==1)
				continue;
			else{
				int gcd_ = gcd(temp,v[j]);
				temp/=gcd_;
				v[j]/=gcd_;
			}
			if(temp==1)
				break;
		}
	}
	int res = 1;
	for (int i=0;i<N;i++){
		res*=v[i];
		res%=10007;
	}
	printf("%d\n",res);

	return 0;
}