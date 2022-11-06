#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool isprime[1000010];
bool visit[1000010];

vector<long long> squares;

int main(int argc, char const *argv[])
{
	for (int i=2;i<1000010;i++)
		isprime[i] = true;

	for (long long i=2;i<1000010;i++){
		if(!isprime[i])
			continue;
		if(i*i <= 1000001000000L)
			squares.push_back(i*i);
		//else
			//printf("%lld\n",i*i);
		for (int j=i*2;j<1000010;j+=i)
			isprime[j] = false;
	}

	for (int i=0;i<1000010;i++)
		visit[i] = true;

	// printf("%d\n",squares.size());
	// printf("%lld",squares[squares.size()-1]);
	long long left,right; scanf("%lld %lld",&left,&right);



	for (int i=0;i<squares.size();i++){
		long long div = squares[i];
		long long mul = left / div + 1;
		if(left % div == 0)
			mul--;
		for (long long j = mul * div ; j <= right; j += div){
			visit[j-left] = false;
		}

	}

	int res_ = 0;
	for (int i=0;i<right-left+1;i++){
		if (visit[i] == true)
			res_++;
	}

	printf("%d\n",res_);
	return 0;

	int res = 0;
	int right_idx = right - left; 

	// at most 10E6 times
	for (long long i = left; i <= right; i++){
		int arr_idx = i-left;
		if(!visit[arr_idx])
			continue;
		bool div_impossible = true;

		// at first about 10E6 times but later retrieved.
		for (int temp = 0; temp < squares.size(); temp++){
			long long div = squares[temp];
			if(i % div)
				continue;
			div_impossible = false;
			//printf("arr_idx : %d\n",arr_idx);
			//printf("%d divided by %d\n",i,div);
			for (int j = arr_idx + div; j <= right_idx; j += div){
				//printf("j[%d] handeld\n",j);
				if(!visit[j])
					break;
				visit[j] = false;
			}
		}
		if(div_impossible)
			res++;
	}
	printf("%d\n",res);
	return 0;
}