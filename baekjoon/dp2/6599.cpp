#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int indegree[200];
int sum[200];

struct node{
	int x;
	int y;
	int z;
	int node_no;
	node(int x_, int y_, int z_, int node_no_){
		x = x_;
		y = y_;
		z = z_;
		node_no = node_no_;
		connected_size = 0;
	};
	node(){
		x = 0;
		y = 0;
		z = 0;
		node_no = 0;
		connected_size = 0;

	};
	int connected_size;
	struct node* connection[180];
};

struct node ntable[180];

int max(int x, int y){
	return x>y?x:y;
}

queue<int> q;

int main(int argc, char const *argv[])
{
	int N;
	int T = 0;
	while(true){
		scanf("%d",&N);

		if(N==0)
			break;
		for (int i=0;i<N;i++){
			int left,right,height; scanf("%d %d %d",&left,&right,&height);
			ntable[6*i+0] = node(left,right,height,6*i+0);
			ntable[6*i+1] = node(right,left,height,6*i+1);
			ntable[6*i+2] = node(left,height,right,6*i+2);
			ntable[6*i+3] = node(height,left,right,6*i+3);
			ntable[6*i+4] = node(right,height,left,6*i+4);
			ntable[6*i+5] = node(height,right,left,6*i+5);
		}

		for (int i=0;i<N*6;i++){
			struct node* now = &ntable[i];
			for (int j=0;j<N*6;j++){
				struct node* compare = &ntable[j];
				if(now->x > compare->x && now->y > compare->y){
					now->connection[(now->connected_size)++] = compare;
					indegree[compare->node_no]++;
				}
			}
		}

		int res = 0;

		for (int i=0;i<N*6;i++)
			if(!indegree[i]){
				q.push(i);
			}

		while(!q.empty()){
			int idx = q.front(); q.pop();
			sum[idx] += ntable[idx].z;
			res = max(res,sum[idx]);

			for (int i=0;i<ntable[idx].connected_size;i++){
				int next = ntable[idx].connection[i]->node_no;
				sum[next] = max(sum[next],sum[idx]);
				indegree[next]--;
				if(!indegree[next])
					q.push(next);
			}	
		}
		printf("Case %d: maximum height = %d\n",++T,res);
		
		for (int i=0;i<N*6;i++)
			indegree[i] = sum[i] = 0;
	}
	return 0;
}

















