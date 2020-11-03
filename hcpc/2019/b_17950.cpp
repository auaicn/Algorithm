#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define DIV (1000000007)

vector<long long> v;

int main(int argc, char const *argv[])
{
	// H 1 : 106
	// x 1 to 100
	int H; scanf("%d",&H);
	long long x; scanf("%lld",&x);

	for (int i=0;i<H;i++){
		long long temp; scanf("%lld",&temp);
		v.push_back(temp);
	}

	long long result = 0;
	for (int i=H-1;i>=0;i--){
		result += v[i];
		result *= x;
		result %= DIV;
	}

	// initially 1
	// 4cm 	4	4
	// 3cm 	2	20		2	
	// 2cm 	3	100		10	3
	// 1cm 	1	500		50	15	1
	// 0cm		2500	250	75	5
	// sum 
	// 		ci up to 100

	printf("%lld\n",result);

	return 0;
}
