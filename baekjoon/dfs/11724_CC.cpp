#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool visit[1010];
vector<int> v[1010];

void dfs(int present){
	visit[present] = true;
	for (int i=0;i<v[present].size();i++){
		int next = v[present][i];
		if(!visit[next])
			dfs(next);
	}
}

int main(){
	int V,E; scanf("%d %d",&V,&E);
	for (int i=0;i<E;i++){
		int left, right; scanf("%d %d",&left,&right);
		v[left].push_back(right);
		v[right].push_back(left);
	}

	int cnt_=0;
	for (int i=0;i<V;i++){
		if(!visit[i+1]){
			cnt_++;
			dfs(i+1);
		}

	}
	printf("%d\n",cnt_);
	return 0;
}