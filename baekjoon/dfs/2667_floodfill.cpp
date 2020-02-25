#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int cnt_;

char save[40][40];
bool visit[40][40];
vector<int> v;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x, int y){
	visit[x][y] = true;
	cnt_++;
	for (int i=0;i<4;i++){
		int x_ = x+dx[i];
		int y_ = y+dy[i];
		if(save[x_][y_]=='1'&&!visit[x_][y_])
			dfs(x_,y_);
	}

}

int main(int argc, char const *argv[])
{
	scanf("%d ",&N);

	char temp;
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++)
			scanf("%c",&save[i+1][j+1]);
		scanf("%c",&temp);
	}

	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			// start from (i+1,j+1)
			if(save[i+1][j+1]=='1'&&!visit[i+1][j+1]){
				dfs(i+1,j+1);
				v.push_back(cnt_);
				cnt_=0;
			}
		}
	}


	sort(v.begin(),v.end());
	printf("%lu\n",v.size());
	for (long unsigned int i=0;i<v.size();i++)
		printf("%d\n",v[i]);

	return 0;
}