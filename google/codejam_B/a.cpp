#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

bool visit[2010][2010];
stack<char> s;
stack<char> res;
char temp[2010];

int X,Y; 

void dfs(int x,int y){
	
	visit[x][y] = true;

	if(x == 1000 + X && y == 1000 + Y){
		if((res.size()!=0&&res.size()>s.size())||res.size()==0){
			while(!res.empty())
				res.pop();
			int cnt_ =0;
			while(!s.empty()){
				temp[cnt_++] = s.top();s.pop();
			}
			for (int i=0;i<cnt_;i++){
				int to_push = temp[cnt_-1-i];
				s.push(to_push);
				res.push(to_push);
			}
			//cpy
		}
		visit[x][y] = false;
		return;
	}

	
	int increment = (1 << (int)s.size());
	//printf("increment : %d\n",increment);

	if(!visit[x+increment][y]){
		s.push('E');
		dfs(x+increment,y);
		s.pop();
	}

	if(!visit[x-increment][y]){
		s.push('W');
		dfs(x-increment,y);
		s.pop();
	}
	
	if(!visit[x][y+increment]){
		s.push('N');
		dfs(x,y+increment);
		s.pop();
	}

	if(!visit[x][y-increment]){
		s.push('S');
		dfs(x,y-increment);
		s.pop();
	}
	visit[x][y] = false;

}

stack<char> _temp;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);

	for (int i=0;i<2010;i++)
		for (int j=0;j<2010;j++)
			visit[i][j] = true;

	for (int t=0;t<T;t++){

		for (int i=0;i<201;i++){
			for (int j=0;j<201;j++){
				visit[900+i][900+j] = false;
			}
		}
		//printf("hello again\n");

		scanf("%d %d",&X,&Y); 

		dfs(1000,1000);

		printf("Case #%d: ",t+1);
		if(!res.empty()){
			while(!res.empty()){
				_temp.push(res.top()); res.pop();
			}
			while(!_temp.empty()){
				printf("%c",_temp.top()); _temp.pop();
			}
		}
		else
			// res emprty
			printf("IMPOSSIBLE");
		printf("\n");

	}
	return 0;
}