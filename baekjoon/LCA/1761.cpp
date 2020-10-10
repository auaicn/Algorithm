#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

#define MAX_NODE_NUMBER (40010)
#define INF (1987654321)

vector<pair<int,int> > v[MAX_NODE_NUMBER];

int depth[MAX_NODE_NUMBER];
bool visit[MAX_NODE_NUMBER];
int distanceToRoot[MAX_NODE_NUMBER];
int segmentTree[8 * MAX_NODE_NUMBER];
int first_appearance[MAX_NODE_NUMBER];

int segTreeSize = 0;

int find(int nodeNo, int start, int end, int left, int right){
	if(left <= start && end <= right)
		return segmentTree[nodeNo];
	else if (end < left || right < start)
		return 0L;
	int mid = (start + end) / 2;
	int leftIdx = find(nodeNo * 2, start, mid, left, right);
	int rightIdx = find(nodeNo * 2 + 1, mid + 1, end, left, right);
	if(depth[leftIdx] < depth[rightIdx])
		return leftIdx;
	else
		return rightIdx;
}

int depth_now = 1;
void dfs(int now, int weight_so_far){
	depth[now] = depth_now;
	visit[now] = true; // way back blocking
	distanceToRoot[now] = weight_so_far;
	segmentTree[++segTreeSize] = now;
	first_appearance[now] = segTreeSize;

	for (int i=0;i<v[now].size();i++){
		pair<int,int> lookup = v[now][i];
		int next = lookup.first;
		int weight = lookup.second;

		if(visit[next])
			continue;

		depth_now++;
		dfs(next,weight_so_far + weight);
		segmentTree[++segTreeSize] = now;
		depth_now--;
	}
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0 ;i < N-1; i++){
		int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
		v[left].push_back({right,weight});
		v[right].push_back({left,weight});
	}

	dfs(1,0);
	depth[0] = INF;

	int height = ceil(log2(segTreeSize));
	int segTreeRealSize = 1 << height;

	for (int i=segTreeRealSize-1; i>= 0; i--){
		if(i<segTreeSize)
			segmentTree[segTreeRealSize+i] = segmentTree[i+1];
		else
			segmentTree[segTreeRealSize+i] = 0;
	}
	
	for (int i=segTreeRealSize-1; i>0; i--){
		if(depth[segmentTree[2*i]] < depth[segmentTree[2*i + 1]])
			segmentTree[i] = segmentTree[2*i];
		else
			segmentTree[i] = segmentTree[2*i + 1];
	}

	int M; scanf("%d",&M);
	for (int i=0;i<M;i++){
		int left,right; scanf("%d %d",&left,&right);
		int LCA = find(1, 1, segTreeRealSize, first_appearance[left], first_appearance[right]);
		printf("%d\n",distanceToRoot[left] + distanceToRoot[right] - 2 * distanceToRoot[LCA]);
	}

	return 0;
}








