#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int parent[20010][2];

int find(int x){
	if(x==parent[x][0])
		return x;
		//return index
	else{
		int feedback = find(parent[x][0]);
		parent[x][1] += parent[parent[x][0]][1];
		parent[x][0] = feedback;
		return feedback;
	}
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){

		int N; scanf("%d",&N); // N up to 
		for (int i=0;i<N;i++){
			parent[i+1][0] = i+1;
			parent[i+1][1] = 0;
		}

		while(true){
			
			char cmd; scanf(" %c",&cmd);
			if(cmd=='O')
				break;

			if(cmd=='I'){
				int left,right; scanf("%d %d",&left,&right);
				parent[left][0] = right;
				parent[left][1] = abs(left-right)%1000;
				find(left);
			}else{
				int temp; scanf("%d",&temp); 
				find(temp); printf("%d\n",parent[temp][1]);
			}
		}
	}
	return 0;
}