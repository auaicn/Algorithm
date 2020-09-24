#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define MAX_NODE_NUMBER (100010)
#define INF (1987654321)

vector<int> v[MAX_NODE_NUMBER];
bool visit[MAX_NODE_NUMBER];
int depth[MAX_NODE_NUMBER];
int first_appearance[MAX_NODE_NUMBER];

int numSegtree;
int segTreeSize;
int segtree[8 * MAX_NODE_NUMBER];

int min(int x, int y){
	return x<y?x:y;
}

int max(int x, int y){
	return x>y?x:y;
}

// left right not changing
// left right 가 내가 구하는거고
// start end 가 처음에 1 , segtree Size 로 들어가는거다 바보야.
int find(int now, int start, int end, int left, int right){
	// printf("%d: [S[%d]-E[%d]] L[%d] R[%d]\n",now,start,end,left,right);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return segtree[now];
    }
    int left_idx = find(now*2, start, (start+end)/2, left, right);
    int right_idx = find(now*2+1, (start+end)/2+1, end, left, right);

    if(!left_idx)
    	return right_idx;

    if(!right_idx)
    	return left_idx;

    return depth[left_idx] < depth[right_idx] ? left_idx : right_idx;
}

int dfs(int now){
	visit[now] = true;
	first_appearance[now] = ++numSegtree;
	segtree[numSegtree] = now;

	for (int i=0;i<v[now].size();i++){
		int next = v[now][i];
		if(visit[next])
			// way back 방지
			continue;
		dfs(next);
		segtree[++numSegtree] = now;
	}
	return 0;
}

int main(int argc, char const *argv[])
{

	int N; scanf("%d",&N);
	for (int i=0;i<N-1;i++){
		int left,right; scanf("%d %d",&left,&right);
		v[left].push_back(right);
		v[right].push_back(left);
	}

	depth[0] = INF;

	queue<int> q;
	q.push(1); depth[1] = 1; visit[1] = true;
	while(!q.empty()){
		int pos = q.front(); q.pop();
		for (int i=0;i<v[pos].size();i++){
			int next = v[pos][i];
			if(visit[next])
				continue;
			q.push(next);
			visit[next] = true;
			depth[next] = depth[pos] + 1;
		}
	}

	for (int i=0;i<N;i++)
		visit[i+1] = false;

	dfs(1);

    int height = (int)ceil(log2(numSegtree));
    int segTreeSize = (1 << height);

    // printf("%d\n",height);
    // printf("%d\n",segTreeSize);

	for (int i = numSegtree - 1; i >= 0; i--){
		segtree[segTreeSize + i] = segtree[i+1];
	}

	for (int i = segTreeSize - 1; i > 0; i--)
	{
		if(segtree[i*2] && segtree[i*2 + 1]){
			if(depth[segtree[i*2]] < depth[segtree[i*2+1]])
				segtree[i] = segtree[i*2];
			else
				segtree[i] = segtree[i*2 + 1];
		}else if (segtree[i*2])
			segtree[i] = segtree[i*2];
		else
			segtree[i] = 0;
	}

	int M; scanf("%d",&M);
	for (int i=0;i<M;i++){
		int left,right; scanf("%d %d",&left, &right);
		int augmentedLeft = min(first_appearance[left],first_appearance[right]);
		int augmentedRight = max(first_appearance[left],first_appearance[right]);
		printf("%d\n",find(1,1,segTreeSize,augmentedLeft,augmentedRight));
	}

	return 0;
}

