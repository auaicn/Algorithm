#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int,int> > edge[110];

//vector<pair<int,int> > v[110];
int v[110][110];
bool ord[110];

int indegree[110];
int result[110];

int main(int argc, char const *argv[])
{

	// scan
	int num_node,num_edge; scanf("%d %d",&num_node,&num_edge);
	for (int i=0;i<num_edge;i++)
	{
		int to, from, weight; scanf("%d %d %d",&to,&from,&weight);
		edge[from].push_back( {to,weight} );
		indegree[to]++;
	}	

	//solution

	queue<int> q;

	for (int i=0;i<num_node;i++){
		if(!indegree[i+1]){
			// normal node
			//v[i+1].push_back({i+1,1});
			v[i+1][i+1] = 1;
			ord[i+1] = true;
			q.push(i+1);
		}
	}

	while(!q.empty()){

		int pos = q.front(); q.pop(); 

		for (unsigned long i=0;i<edge[pos].size();i++){

			int next = edge[pos][i].first;
			int weight = edge[pos][i].second;

			for (unsigned long j=0;j<num_node;j++){
				// next = j+1th element
				if(ord[j+1]&&v[pos][j+1]){
					v[next][j+1] += weight * v[pos][j+1];
				}

				//v[next].push_back({v[pos][j].first,v[pos][j].second * weight});
			}

			indegree[next]--;

			if(!indegree[next])
				q.push(next);

		}

	}

	//

	/*
	for (int i=0;i<v[num_node].size();i++){
		pair<int,int> temp = v[num_node][i];
		result[temp.first]+=temp.second;
	}
	*/

	// print

	for (int i=0;i<num_node;i++)
		if(ord[i+1])
			printf("%d %d\n",i+1,v[num_node][i+1]);

		//if(result[i+1])
			//printf("%d %d\n",i+1,result[i+1]);

	return 0;
}