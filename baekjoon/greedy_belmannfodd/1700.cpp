#include <stdio.h>
#include <iostream>

using namespace std;

#define INF (1987654321)

int save[110];
int table[110];
int dist_to_next[110];

int main(int argc, char const *argv[])
{
	int N,K; scanf("%d %d",&N,&K);
	for (int i=0;i<K;i++)
		scanf("%d",&save[i+1]);
	for (int i=0;i<K;i++)
		dist_to_next[i+1] = INF;

	int res = 0;
	for (int i=0;i<K;i++){
		// save[i+1] has device num

		for (int j=0;j<K;j++)
			if(dist_to_next[j+1]!=INF)
				dist_to_next[j+1]--;
		//lookup N times 
		int index_ = -1;
		int value_ = -1;
		for (int j=0;j<N;j++){
			// table에서 j+1번째 element를 보고 있음

			if(!table[j+1]){
				index_ = j+1;
				res--;
				break;
			}else if (table[j+1]==save[i+1]){
				//printf("%d\n",save[i+1]);
				index_ = j+1;
				res--;
				break;
			}else{
				if(value_<dist_to_next[table[j+1]]){
					value_=dist_to_next[table[j+1]];
					index_ = j+1;
				}
			}
		}

		res++;
		table[index_] = save[i+1];
		dist_to_next[table[index_]] = INF;
		for (int j=i+1;j<K;j++){
			if(save[i+1]==save[j+1]){
				dist_to_next[table[index_]]=j-i;
				break;
			}
		}
		/*
		for (int j=0;j<N;j++)
			printf("%3d",table[j+1]);
		printf("\n");
		for (int j=0;j<K;j++){
			if(dist_to_next[j+1]==INF)
				printf("%3d",-1);
			else
				printf("%3d",dist_to_next[j+1]);
		}
		printf("\n");
		*/
	}
	printf("%d\n",res);
	return 0;
}