#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int strahler[1010];
int indegree[1010];
vector<int> v[1010];
bool visit[1010];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){

		//init
		for (int i=0;i<1010;i++){
			strahler[i] = indegree[i] = 0;
			visit[i] = false;
			v[i].clear();
		}

		//scan
		int num_T; scanf("%d",&num_T);
		int num_node,num_edge; scanf("%d %d",&num_node,&num_edge);

		for (int i=0;i<num_edge;i++){
			int left, right; scanf("%d %d",&left,&right);
			v[left].push_back(right);
			indegree[right]++;
		}

		//main
		queue<int> q;

		for (int i=0;i<num_node;i++)
			if(!indegree[i+1]){
				q.push(i+1);
				strahler[i+1] = 1;
			}

		while(!q.empty()){

			int pos = q.front(); q.pop(); if(visit[pos]) strahler[pos]++;
			//printf("%3d",pos);

			for (int i=0;i<v[pos].size();i++){
				int next = v[pos][i];
				indegree[next]--;
				if(!indegree[next])
					q.push(next);

				// visit first time.
				if(strahler[next]==0){
					strahler[next] = strahler[pos];
					continue;
				}

				// next is bigger then continue
				if (strahler[pos]<strahler[next]){
					continue;
				}

				// next is smaller than renew
				else if (strahler[pos]>strahler[next]){
					visit[next] = false;
					strahler[next] = strahler[pos];
				}

				// same then make visit true.
				else{
					visit[next] = true;
				}

			}
			//for (int k=0;k<num_node;k++)
				//printf("%3d",strahler[k+1]);
			//printf("\n");

		}


		//print
		printf("%d ",num_T);
		printf("%d\n",strahler[num_node]);

	}
	return 0;
}