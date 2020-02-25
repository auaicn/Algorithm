#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int save[70];

int main(){

	int T;scanf("%d",&T);
	while(T--){

		//init
		for (int i=0;i<70;i++)
			save[i] = 0;

		//scan
		long long N; int M; scanf("%lld %d",&N,&M);
		for (int i=0;i<M;i++){
			int temp; scanf("%d",&temp);
			temp = log2(temp);
			save[temp]++;
		}

		int num_divison = 0;
		bool sw2 = false;


		// look for index
		int i = -1;
		while(N){
			i++;
			bool sw = false;
			int ith_bit_on = (N>>i)%2;

			if(ith_bit_on){
				//cout <<"hello"<<endl;
				if(save[i]){
					N = N-=pow(2,i);
					save[i]--;
				}else{
					for (int j=i+1;j<=60;j++){
						if(save[j]){
							save[j]--;
							for (int k=j-1;k>=i;k--)
								save[k]++;
							num_divison += j-i;
							sw = true;
							N = N-=pow(2,i);
							break;
						}
					}
					if(!sw){
						sw2 = true;
						break;
					}
				}
			}


			// regardless of ith save used, unused left to the next index
			save[i+1] += save[i]/2;

		}

		if(sw2)
			printf("-1\n");
		else
			printf("%d\n",num_divison);

	}

	return 0;
}