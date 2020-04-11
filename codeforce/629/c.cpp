#include <stdio.h>
#include <iostream>

using namespace std;

char temp[50010];
char result1[50010];
char result2[50010];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N; scanf("%d",&N);
		bool broken = false;
		scanf(" %s",temp+1);
		for (int i=0;i<N;i++){
			char lookup = temp[i+1];
			if(lookup=='2'){{
				if(!broken)
					result1[i+1] = result2[i+1] = '1';
				else{
					result1[i+1] = '2';
					result2[i+1] = '0';
				}
			}
			}else if (lookup=='1'){
				if(!broken){
					result1[i+1] = '0';
					result2[i+1] = '1';
					broken = true;
				}else{
					// 2 bigger
					result1[i+1] = '1';
					result2[i+1] = '0';
				}
			}else{
				result1[i+1] = '0';
				result2[i+1] = '0';
			}

		}

		result1[N+1] = '\0';
		result2[N+1] = '\0';
		printf("%s\n",result1+1);
		printf("%s\n",result2+1);

	}

	return 0;
}