#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

	setbuf(stdout, NULL);

	int T; scanf("%d",&T);
	for (int t = 0; t < T; t++)
	{
		int N,K,m; scanf("%d %d %d",&N,&K,&m);
		for (int i=0;i<K;i++){
			int left,right; scanf("%d %d",&left,&right);
			// connection
		}
		for (int i=0;i<m;i++)
		{
			int start,end; scanf("%d %d",&start,&end);
		}

		printf("Case #%d\n",t+1);
		printF("%d\n",result);
	}

	// 만약 출발점에서 도착점으로 연결되는 방법이 없을 경우 -1을 더하면 된다.

	return 0;
}

// 3
// 3 4 4
// 1 2
// 2 3
// 1 2
// 1 3
// 1 1
// 1 2
// 2 3
// 3 2
// 4 6 5
// 1 2
// 2 3
// 3 4
// 1 3
// 2 4
// 1 4
// 1 3
// 1 4
// 3 3
// 3 4
// 4 4
// 4 2 4
// 1 2
// 2 3
// 1 1
// 1 2
// 1 3
// 1 4
// 출력
// Case #1
// 3
// Case #2
// 6
// Case #3
// 1