#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int parent[1010];

int find(int x){
	if (x==parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void union_(int x,int y){
	int parent_x = find(x);
	int parent_y = find(y);
	if(parent_y==parent_x)
		return;
	else{
		parent[parent_y] = parent_x;
	}
}

int main(int argc, char const *argv[])
{
	int P,W; scanf("%d %d",&P,&W);
	int C,V; scanf("%d %d",&C,&V);

	for (int i=0;i<P;i++)
		parent[i] = i;

	priority_queue< pair<int, pair<int,int> > > pq;

	for (int i=0;i<W;i++){
		int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
		pq.push({weight,{left,right}});
	}

	while(!pq.empty()){
		pair<int, pair<int,int> > pos = pq.top(); pq.pop();
		int weight = pos.first;
		int left = pos.second.first;
		int right = pos.second.second;
		union_(left,right);

		if(find(C)==find(V)){
			printf("%d\n",weight);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}


/*7 11
3 5
0 1 15
0 2 23
1 2 16
1 3 27
2 4 3
2 6 21
3 4 14
3 5 10
4 5 50
4 6 9
5 6 42*/