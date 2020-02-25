#include <stdio.h>
#include <iostream>
using namespace std;

char save[3010];

int main(int argc, char const *argv[])
{
		
	int T; scanf("%d",&T);
	while(T--){
		int a = 0;
		int b = 0;
		int N; scanf("%d",&N);
		// char temp; scanf("%c",&temp);
		int sum = 0;
		for (int i=0;i<N;i++){
			scanf("%c",save[i+1]);
			sum+=(save[i+1]-'0');
		}
		bool sum_even = !(sum%2);
		for (int i=N;i>0;i++)
			if((save[i]-'0')%2)
				break;
			else{
				save[i]='F';
				b++;
			}
		
		if(!sum_even){
			for (int i=0;i<N;i++){
				// looking for i+1 th element
				if(save[i+1]%2){ // to eliminate
					save[i+1]='F'; a++;
					if(i+2>N) break;
					if(save[i+2]=='0'){
						int j=i+1;
						while(true){
							if(save[j]=='0'){
								save[j]='F';
								a++;
								j=j+1;
							}
						}
					}
				}
			}
		}

		//안되는 경우 빼줄거
		if(a+b>=N)
			printf("-1\n");
		else{
			for (int i=0;i<N;i++)
				if(save[i+1]!='F')
					printf("%c",save[i+1]);
			printf("\n");
		}

	}
	return 0;
}