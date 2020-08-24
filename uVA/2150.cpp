#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <algorithm>

//using namespace std;


int dfsn[10010];
//bool finished[10010];

//stack<int> s;

//vector<int> v[10010];
//vector<vector<int> > res;

//int global_num = 1;

//const bool operator<()
/*
void scc_(int x){
	dfsn[x] = global_num++;
	s.push(x);
	bool sw = false;
	for (int i=0;i<v[x].size();i++){
		int next = v[x][i];
		if(!dfsn[next]){
			// next not visited then recursive call
			scc(next);
		}else if(!finished[next]){
			// reverse edge
			sw = true;
		}else
			continue;
	}
	if(sw)
		return;
	else{
		// no reverse edge found
		sw = true;
		vector<int> tmp;
		while(sw){
			int temp = s.top(); s.pop();
			tmp.push_back(temp); finished[temp] = true;
			if(temp==x)
				sw = false;
		}
		res.push_back(tmp);
	}
	return;
}
*/
int main(int argc, char const *argv[])
{
	

	return 0;
}
/*

int main(int argc, char const *argv[])
{
	int V,E; scanf("%d %d",&V,&E);
	for (int i=0;i<E;i++){
		int left,right; scanf("%d %d",&left,&right);
		v[left].push_back(right);
	}

	for (int i=0;i<N;i++)
		if(!finished[i+1])
			scc(i+1);

	//for (int i=0;i<N;i++)

	printf("%d\n",res.size());
	for (int i=0;i<res.size();i++){
		vector<int> temp = res[i];
		for (int j=0;j<temp.size();j++){
			printf("%d \n",temp[j]);
		}
		printf("-1\n");
	}

	return 0;
}
*/

