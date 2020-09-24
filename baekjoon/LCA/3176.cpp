#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>

#define MAX_NODE_NUMBER (100010)

using namespace std;

vector<pair<int,int> > v[MAX_NODE_NUMBER];
int segmentTree[8*MAX_NODE_NUMBER];
int depth[MAX_NODE_NUMBER];
bool visit[MAX_NODE_NUMBER];

int find(int node, int start, int end, int left, int right){
	if(right < end || start < left)
		// return {0,0};
		return 0;
	if(left <= start && end <= right)
		return segmentTree[node];
	return 
		min(find(node*2,start,(start + end)/2, left, right),
			find(node*2 + 1,(start + end)/2 + 1, end, left, right));
}

int idxTraversal = 1;
int firstAppearance[MAX_NODE_NUMBER];

int currentDepth = 1;
int dfs(int now){
	segmentTree[idxTraversal] = now;
	firstAppearance[now] = idxTraversal++;
	visit[now] = true;
	depth[now] = currentDepth++;
 	for (int i=0;i<v[now].size();i++){
		pair<int,int> pos = v[now][i];
		int next = pos.first;
		int weight = pos.second;
		if(visit[next])
			continue;
		dfs(next);
		segmentTree[idxTraversal++] = now;
		// idxTraversal++;
	}
	currentDepth--;
	return 0;
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N); // 10E5
	for (int i=0;i<N-1;i++){
		int A,B,C; scanf("%d %d %d",&A,&B,&C); // C upto 10E6
		v[A].push_back({B,C});
		v[B].push_back({A,C});
	}	

	// segmentTree 구성
	dfs(1);
	printf("DEPTH\n");
	for (int i=0;i<N;i++)
		printf("%3d",depth[i+1]);
	printf("\n");

	printf("firstAppearance\n");
	for (int i=0;i<N;i++)
		printf("%4d:%3d\n",i+1,firstAppearance[i+1]);
	printf("\n");

	printf("idxTraversal : %d\n",idxTraversal);
	int height = ceil(log2(idxTraversal));
	printf("height : %d\n",height);
	int segTreeSize = 1 << height;
	printf("segTreeSize : %d\n",segTreeSize);

	for (int i = segTreeSize - 1; i >= 0 ; i--)
		segmentTree[i+segTreeSize] = firstAppearance[i+1];

	for (int i = segTreeSize - 1; i > 0; i--){
		if(!segmentTree[i*2])
			segmentTree[i] = 0;
		else if (!segmentTree[i*2+1])
			segmentTree[i] = segmentTree[i*2];
		else{
			// 난 idx 를 저장하잖아.
			int depthLeft = depth[segmentTree[i*2]];
			int depthRight = depth[segmentTree[i*2 + 1]];
			if(depthLeft < depthRight)
				segmentTree[i] = segmentTree[i*2];
			else
				segmentTree[i] = segmentTree[i*2]+1;
		}
	}

	printf("SEGTREE\n");
	for (int i=0;i<2*segTreeSize;i++){
		if (i %  8 == 0)
			printf("\n");
		printf("%3d",segmentTree[i+1]);
	}
	printf("\n");

	printf("RESULT\n");
	int K; scanf("%d",&K); // 10E5
	for (int i=0;i<K;i++){
		// D, E 를 연결하는 경로에서 가장 짧은 도로의 길이, 가장 긴 도로의 길이
		// segment Tree 를 pair 로 만들어서 구간사이 가장짧은 길이, 가장 긴길이 저장해놓으면 될듯
		int left,right; scanf("%d %d",&left,&right);
		printf("%d\n",find(1,1,segTreeSize,left,right));
	}

	return 0;
}



















