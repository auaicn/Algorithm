#include <stdio.h>
#include <iostream>

using namespace std;

char save[100];

int main(int argc, char const *argv[])
{
	while(scanf("%*[ \t\n\r]%[^\n]",save+1)){
		printf("%s\n",save+1);
	}
	return 0;
}