#include <stdio.h>
#include <iostream>

using namespace std;

int parent[300010];

int find(int x){
	if(parent[x]&&parent[x]!=x)
		return parent[x] = find(parent[x]);
	return x;
}

int main(int argc, char const *argv[])
{
	int N,L; scanf("%d %d",&N,&L);

	for (int i=0;i<N;i++){
		int left,right; scanf("%d %d",&left,&right);
		if(!parent[left]){
			int right_root = find(right);
			if(right_root==left){
				parent[left] = left;
				printf("LADICA\n");
			}else if(!parent[right_root]){
				parent[left] = right_root;
				printf("LADICA\n");
			}else if(parent[right_root]==right_root){
				parent[left] = right_root;
				printf("LADICA\n");
			}
		}else{
			if(!parent[right]){
				int left_root = find(left);
				if(left_root==right){
					parent[right] = right;
					printf("LADICA\n");
				}else{
					parent[right] = left_root;
					printf("LADICA\n");
				}
			}else{
				int left_root = find(left);
				int right_root = find(right);

				if(!parent[left_root]){
					if(!parent[right_root])
						parent[left_root] = right_root;
					else
						parent[left_root] = left_root;
					printf("LADICA\n"); continue;
				}

				if(!parent[right_root]){
					parent[right_root] = right_root;
					printf("LADICA\n"); continue;
				}

				printf("SMECE\n");
			}
		}

	}
	return 0;
}