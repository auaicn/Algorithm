#include <stdio.h>
#include <iostream>

using namespace std;

bool selfnumber[10010];

int main(int argc, char const *argv[])
{
	for (int i=1;i<10010;i++)
		selfnumber[i] = true;
	for (int i=1;i<10010;i++){
		if(!selfnumber[i])
			continue;
		int next = i;
		while(true){
			int next_cpy = next;
			while(next_cpy){
				next+= next_cpy%10;
				next_cpy/= 10;
			}
			if(next>10010)
				break;
			if(!selfnumber[next])
				break;
			else
				selfnumber[next] = false;
		}
	}
	for (int i=0;i<10000;i++){
		if(selfnumber[i+1])
			printf("%d\n",i+1);
	}
	return 0;
}