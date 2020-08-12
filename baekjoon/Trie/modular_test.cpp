#include <stdio.h>
#include <iostream>

using namespace std;

//#define DENOMINATOR 1000003;
#define DENOMINATOR 10

int mod(int x){
	if(x >= 0)
		return x % DENOMINATOR;
	else{
		if(x%DENOMINATOR)
			return x % DENOMINATOR + DENOMINATOR;
		else
			return 0;
	}
}

int main(int argc, char const *argv[])
{
	printf("%d\n",mod(-1));
	printf("%d\n",mod(-2));
	printf("%d\n",mod(-10));
	printf("%d\n",mod(-7));
	return 0;
}