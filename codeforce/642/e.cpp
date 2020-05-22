#include <stdio.h>
#include <iostream>

using namespace std;

char save[1000010];
int num_1[100010];
int first_1[100010];
int last_1[100010];


int left_[1000010];
int right_[1000010];
int temp[1000010];
bool flag_check[1000010];

bool flag_;

int min(int x, int y){
	return x<y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){

		int N,K; scanf("%d %d",&N,&K);
		for (int i=0;i<K;i++)
			left_[i+1] = right_[i+1] = temp[i+1] = 0;
		for (int i=0;i<K;i++)
			flag_check[i+1] = false;

		for (int i=0;i<K;i++)
			num_1[i+1] = first_1[i+1] = last_1[i+1] = 0;

		scanf(" %s",save+1);

		for (int i=0;i<K;i++){

			for (int jmp = 1;; jmp++){

				int idx = (i+1) + K * (jmp-1);
				if(idx<=N){
					if(save[idx]=='1'){
						num_1[i+1]++;
						last_1[i+1] = jmp;
						if(first_1[i+1] == 0)
							first_1[i+1] = jmp;
					}
				}else
					break;
			}
		}


		/*		
		for (int i=0;i<K;i++){
			// starting from i+1
			// jump by K
			flag_ = false;
			for (int jmp = 0;; jmp++){
				int idx = (i+1) + K * jmp;
				if(idx<=N){
					if(flag_){
						if(save[idx]=='1')
							left_[i+1]++;
						else
							right_[i+1]++;

					}else if(save[idx]=='1'){
						flag_check[i+1] = true;
						flag_ = true;
						left_[i+1]++;
					}


				}else{
					temp[i+1] = idx;
					break;
				}

			}
		}

		for (int i=0;i<K;i++){
			if(!flag_check[i+1])
				continue;
			for (int jmp = 1;; jmp++){
				int idx = temp[i+1] - K * jmp;
				if(idx<=0)
					break;
				if(save[idx]=='0')
					right_[i+1]--;
				else
					break;

			}
		}
		*/

		for (int i=0;i<K;i++){
			if(!first_1[i+1])
				continue;
			left_[i+1] = num_1[i+1];
			right_[i+1] = (last_1[i+1]-first_1[i+1]+1)-left_[i+1];
		}
		
		/*
		printf("[%6s]","left");
		for (int i=0;i<K;i++)
			printf("%3d",left_[i+1]);
		printf("\n");

		printf("[%6s]","right");
		for (int i=0;i<K;i++)
			printf("%3d",right_[i+1]);
		printf("\n");
	*/
		
		int left_sum = 0;
		for (int i=0;i<K;i++)
			left_sum+=left_[i+1];

		int right_minus_left_min = right_[1]-left_[1];
		for (int i=1;i<K;i++)
			right_minus_left_min = min(right_minus_left_min,right_[i+1]-left_[i+1]);

		printf("%d\n",left_sum+right_minus_left_min);
	}
	return 0;
}



/*
12
9 2
010001010
9 3
111100000
7 4
1111111
10 3
1001110101
1 1
1
1 1
0
9 2
010001010
9 3
111100000
7 4
1111111
10 3
1001110101
1 1
1
1 1
0

*/