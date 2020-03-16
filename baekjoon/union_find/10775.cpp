#include <stdio.h>
#include <iostream>

using namespace std;

int parent[100010];

int find(int x){
	if(!parent[x]||x==parent[x])
		return x;
	else 
		return parent[x] = find(parent[x]);
}

int main(int argc, char const *argv[])
{
	int G,P; scanf("%d %d",&G,&P);
	int res = 0;
	for (int i=0;i<P;i++){
		int temp; scanf("%d",&temp);

		int root = find(temp); 

		if(root==1){
			if(parent[root]){
				printf("%d\n",res);
				return 0;
			}
			else{
				res++;
				parent[root] = root; //parent[1] = 1;
			}
		}
		// root not 1
		else if(!parent[root]){
			parent[root] = root-1;
			res++;
		}
	}
	return 0;
}