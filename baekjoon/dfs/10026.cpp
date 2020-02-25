#include <stdio.h>
#include <iostream>

using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int N;
char save[110][110];
bool visit[110][110];

char to_compare;

void dfs(int x, int y){
	visit[x][y] = true;
	for (int i=0;i<4;i++){
		int x_ = x+dx[i];
		int y_ = y+dy[i];
		if((save[x_][y_]==to_compare)&&!visit[x_][y_])
			dfs(x_,y_);
	}
}

int main(int argc, char const *argv[])
{

	scanf("%d ",&N);

	char temp;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++)
			cin >> save[i+1][j+1];
	}

	/* check
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++)
			printf("%c ",save[i+1][j+1]);
		printf("\n");
	}
	*/

	// strict corner processing
	for (int i=0;i<N+2;i++)
		save[0][i]=save[i][0]=save[i][N+1]=save[N+1][i] = 'K';

	// normal

	int cnt_=0;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			// start from (i+1,j+1)
			if(!visit[i+1][j+1]){
				cnt_++;
				to_compare = save[i+1][j+1];
				dfs(i+1,j+1);
			}
		}
	}

	printf("%d ",cnt_);


	//R=G
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			visit[i+1][j+1] = false;
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			if(save[i+1][j+1] =='R')
				save[i+1][j+1] ='G';
	
	cnt_=0;
	// again cc cv
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			// start from (i+1,j+1)
			if(!visit[i+1][j+1]){
				cnt_++;
				to_compare = save[i+1][j+1];
				dfs(i+1,j+1);
			}
		}
	}

	printf("%d\n",cnt_);


	return 0;
}