#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int save[110];

int main(int argc, char const *argv[])
{

	int T; scanf("%d",&T);
	while(T--){

		//init
		for (int i=0;i<100;i++)
			save[i+1] = 0;

		//scan
		int N,D;scanf("%d %d",&N,&D);

		for (int i=0;i<N;i++)
			scanf("%d",&save[i+1]);
		save[N+1] = 1;

		for (int i=1;i<N;i++){
			// looking for i+1th element
			
			if(!save[i+1])
				continue;

			else{
				// save[i+1] positive.
				int distance = i+1-1;

				if (distance > D)
					break;

				if (distance * save[i+1] <= D){
					D-= distance * save[i+1];
					save[1]+=save[i+1];
				}else{
					save[1]+=D/distance;
					break;
				}

			}

		}

		printf("%d\n",save[1]);
	}
	return 0;
}
/*
3
4 5
1 0 3 2
2 2
100 1
1 8
0

*/