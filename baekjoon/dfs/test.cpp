#include <stdio.h>
#include <iostream>
using namespace std;

char save[3010];

int main(int argc, char const *argv[])
{
		
	int T; scanf("%d",&T);
	while(T--){
		for (int i=0;i<3010;i++)
			save[i]='\0';
		int a = 0;
		int b = 0;
		int N; scanf("%d",&N);
		save[0] = save[N+1] = 'F';

		char temp; scanf("%c",&temp);
		int cnt_ = 0;
		int sum = 0;
		for (int i=0;i<N;i++){
			scanf("%c",&save[i+1]);
			sum+=(save[i+1]-'0');
			if(save[i+1]%2)
				cnt_++;
		}
		if(cnt_<2){
			printf("-1\n");
			continue;
		}
		/*
		for (int i=0;i<N;i++)
			printf("%c",save[i+1]); printf("\n");
		*/


		for (int i=N;i>0;i--){
			if((save[i]-'0')%2) // 홀수 만족 끝.
				break;
			else{ // 짝수 제거.
				sum-=(save[i]-'0');
				save[i]='F';
				b++;
			}
		}

		bool sum_even = !(sum%2);
		int j;
		
		if(!sum_even){
			for (int i=0;i<N;i++){
				// looking for i+1 th element
				if(save[i+1]%2){ // to eliminate
					save[i+1]='F'; a++;
					//if(i+2=='F') break;
					if(save[i+2]=='0'){
						j=i+2; //printf("j : %d\n",j);
						while(save[j]=='0'){
							//printf("hello");
							save[j]='F';
							a++;
							j++;
						}
					}
					break;
				}
				//	
			}
		}
		//printf("a : %d b : %d\n",a,b);
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