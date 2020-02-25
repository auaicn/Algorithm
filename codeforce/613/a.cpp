#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

	int T; scanf("%d",&T);
	while(T--){
		int a,b; scanf("%d %d",&a,&b);
		if(a==b){
			printf("0\n");
			continue;
		}else if(a<b){
			if((b-a)%2){
				printf("1\n");
				continue;
			}else{
				printf("2\n");
				continue;
			}

		}else{
			if((a-b)%2)
				printf("2\n");
			else
				printf("1\n");

		}

	}

	return 0;
}