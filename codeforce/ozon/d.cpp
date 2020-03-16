#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

bool global_visit[1010];
bool visit[1010];
vector<int> connection[1010];
//int connection[1010][1010];

int main(int argc, char const *argv[])
{

	scanf("%d",&N);

	for (int i=0;i<N;i++){
		int left,right; scanf("%d %d",&left,&right);
		connection[left].push_back(right);
		connection[right].push_back(left);
	}

	bool sw = true;

	while(true){

		int start;
		// pick what to ask
		if(sw){
			start = 1;
			sw = false;
		}else
			scanf("%d",&start);

		int end;

		queue<int> q;
		q.push(start); visit[start] = true;
		while(!q.empty()){
			int pos = q.front(); q.pop(); end = pos;
			for (int i=0;i<connection[pos].size();i++){
				int next = connection[pos][i];
				if(!visit[next]){
					q.push(next);
					visit[next] = true;
				}
			}
		}


		for (int i=0;i<N;i++)
			visit[i+1] = false;
		start = end;

		//queue<int> q;
		q.push(start); visit[start] = true;
		while(!q.empty()){
			int pos = q.front(); q.pop(); end = pos;
			for (int i=0;i<connection[pos].size();i++){
				int next = connection[pos][i];
				if(!visit[next]){
					q.push(next);
					visit[next] = true;
				}
			}
		}

		if(start == end ){
			printf("! %d\n",start);
			fflush(stdout);
			break;
		}else{
			printf("? %d %d",start,end);
			fflush(stdout);
		}
	}

	return 0;
}

/*
6
1 4
4 2
5 3
6 3
2 3

3

4

4


*/