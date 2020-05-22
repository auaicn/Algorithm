#include <stdio.h>
#include <iostream>
#include <climits>

using namespace std;

int save[130000][10];

long long min(long long x, long long y){
	return x < y ? x : y;
}

int main(int argc, char const *argv[])
{
	int N; long long HATK; scanf("%d %lld",&N,&HATK);
	for (int i=0;i<N;i++)
		scanf("%d %d %d",&save[i+1][1],&save[i+1][2],&save[i+1][3]);

	long long low = 0; 
	long long high = LLONG_MAX;

	while(high != low+1){

		long long mid = (low + high) / 2L;

		bool success = true;

		long long cur_HP = mid;
		long long cur_ATK = HATK;
		for (int i=0;i<N;i++){
			switch(save[i+1][1]){
				case 1 :
				{
					long long turn_to_kill = save[i+1][3] / cur_ATK;
					if (save[i+1][3]%cur_ATK)
						turn_to_kill ++;

					long long turn_to_be_killed = cur_HP / save[i+1][2];
					if (cur_HP % save[i+1][2])
						turn_to_be_killed ++;

					if(turn_to_kill <= turn_to_be_killed)
						// win
						cur_HP -= (turn_to_kill-1) * save[i+1][2];
					else
						success = false;

					break;
				}
				case 2 :
					cur_ATK += save[i+1][2];
					cur_HP = min(mid, cur_HP + save[i+1][3]);
					break;
			}

		}

		//printf("Final[%5lld - %5lld] mid[%5lld] cur_HP %lld cur_ATK %lld\n",low,high,mid,cur_HP,cur_ATK);
		if (success) // try hardmode
			high = mid;
		else
			low = mid;
	}

	printf("%lld\n",high);
	return 0;
}