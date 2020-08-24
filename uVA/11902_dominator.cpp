#include <stdio.h>
#include <iostream>

using namespace std;

int board[110][110];
bool visit[110];

int main(int argc, char const *argv[])
{
	/*
	X dominates Y if every path from some start node (unique and predefined) to Y contains node X.
	if destination Y not reachable from start node, Y has no dominator.
	by definition every node reachable from start node itself has itself as dominator

	*/
	int start_node = 1;

	int T; scanf("%d",&T);
	for (int t=0;t<T;t++){
		int N; scanf("%d",&N);
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				scanf("%d",&board[i+1][j+1]);

		visit[start_node] = true;

		

		printf("Case %d:\n",t+1);
	}
	return 0;
}
/*
2
5
0 1 1 0 0
0 0 0 1 0
0 0 0 1 0
0 0 0 0 1
0 0 0 0 0
1
1
*/