#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

char temp[1010];

int board[110][110];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,M; scanf("%d %d",&N,&M);
		for (int i=0;i<N;i++){
			scanf(" %s",temp+1);
			for (int j=0;j<M;j++)
				if(temp[j+1] == '1')
					board[i+1][j+1] = true;
				else
					board[i+1][j+1] = false;
		}

		vector<vector<int> > result;

		for (int i=1;i<=N;i++){
			for (int j=1;j<=M;j++){
				if(board[i][j] == true){
					// lets turn it off
					int x0 = i;
					int y0 = j;
					int x3 = i+1 <= N?i+1:i-1;
					int y3 = j+1 <= M?j+1:j-1;
					int x1 = x0;
					int y1 = y3;
					int x2 = x3;
					int y2 = y0; // crossed
					// printf("elements : [%d,%d] [%d,%d] [%d,%d] [%d,%d]\n",x0,y0,x1,y1,x2,y2,x3,y3);
					// x0 y0 포함하게 3번 부르면 된다.
					// vector<int> v0;
					int temp_1[] = {x0,y0,x1,y1,x2,y2};
					int temp_2[] = {x0,y0,x2,y2,x3,y3};
					int temp_3[] = {x0,y0,x1,y1,x3,y3};
					result.push_back(vector<int>(temp_1,temp_1+sizeof(temp_1)/sizeof(int)));
					result.push_back(vector<int>(temp_2,temp_2+sizeof(temp_2)/sizeof(int)));
					result.push_back(vector<int>(temp_3,temp_3+sizeof(temp_3)/sizeof(int)));
					// printf("%d %d %d %d %d %d")
				}
			}
		}
		printf("%d\n",result.size());
		for (int i=0;i<result.size();i++){
			vector<int> temp = result[i];
			for (int j=0;j<temp.size();j++)
				printf("%d ",temp[j]);
			printf("\n");
			temp.clear();
		}
		result.clear();
	}
	return 0;
}