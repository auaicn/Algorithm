#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

pair<int,int> edge[100010];
bool visit[100010];
int parent[100010];
int volume[100010];

long long res = 0;

int find(int x){
	if(x==parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

int union_(int x, int y){
	int parent_x = find(x);
	int parent_y = find(y);
	if(parent_x==parent_y)
		return 0;
	else{
		parent[parent_x] = parent_y;
		int temp = volume[parent_y]*volume[parent_x];
		volume[parent_y] += volume[parent_x];
		return temp;
	}
}

int main(int argc, char const *argv[])
{

	int N,M,Q; scanf("%d %d %d",&N,&M,&Q);
	for (int i=0;i<M;i++){ // up to 200,000
		int left,right; scanf("%d %d",&left,&right);
		edge[i+1] = {left,right};
	}

	stack<int> s;

	for (int i=0;i<Q;i++){
		int temp; scanf("%d",&temp); visit[temp] = true; s.push(temp);
	}

	for (int i=0;i<N;i++){
		volume[i+1] = 1;
		parent[i+1] = i+1;
	}

	for (int i=0;i<M;i++){
		if(!visit[i+1]){
			pair<int,int> p = edge[i+1];
			int left = p.first;
			int right = p.second;
			union_(left,right);
		}
	}

	while(!s.empty()){
		int pos = s.top(); s.pop();
		pair<int,int> p = edge[pos];
		int left = p.first;
		int right = p.second;
		res+=union_(left,right);
	}

	printf("%lld\n",res);

	return 0;
}