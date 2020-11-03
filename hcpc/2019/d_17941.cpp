#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int save[510][510];

int max(int x, int y){
	return x>y?x:y;
}

int dx[] ={0,-1,1,0,0};
int dy[] ={0,0,0,-1,1};

int segtree[510][510*8];

// left, right not changed
int find(int x_idx, int now, int search_start, int search_end, int left, int right){
	if(search_start <= left && right <= search_end)
		return segtree[x_idx][now];
	else if(right < search_start || search_end < left)
		return 0;
	else{
		int mid = (left + right) / 2;
		return max(
			find(x_idx,now*2,search_start,search_end,left,mid),
			find(x_idx,now*2 + 1,search_start,search_end,mid+1,right));
	}
}

int main(int argc, char const *argv[])
{
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)
			scanf("%d",&save[i+1][j+1]);

	// constructing segment Tree
	int height = ceil(log2(M));
	int segTreeSize = 1 << height;
	// printf("height: %d\n",height);
	// printf("segTreeSize: %d\n",segTreeSize);
	
	for (int i=0;i<N;i++){
		//initialization
		for (int j=0;j<segTreeSize;j++)
			segtree[i+1][segTreeSize + j] = save[i+1][j+1];
		for (int j = segTreeSize - 1; j>0;j--)
			segtree[i+1][j] = max(segtree[i+1][j*2],segtree[i+1][j*2+1]);
	}

	// printf("auaicn\n");
	int Q; scanf("%d",&Q);
	while(Q--){
		int x,y,r,c,k,d; scanf("%d %d %d %d %d %d",&x,&y,&r,&c,&k,&d);
		int result = 0;
		// while(k--){
		for (int day = 0; day < k; day++){

			// 1 base
			// x to x + r - 1
			// y to y + c - 1
			int max_ = -1;
			for (int i = x; i < x + r; i++){
				// 
				int temp = find(i ,1 ,y , y + c - 1, 1, segTreeSize);
				max_ = max(max_, temp);
				// result ^= find(i,1,y,y+c-1,1,segTreeSize);
			}

			// shifting
			// d = 1 상 인경우, x-- y그대로 겠지.
			// 카메라 크기인 r,c 는 그대로 두고, x,y가 움직인다.

			// 내가 가진 정보가, 가장 큰 양의 save 라면,
			// x1 to x2, y1 to y2 범위 내의 가장 큰 양의 정보가 있다면 바로 xor 하면 되겠지만,
			// 그런경우 1E10 공간이 필요하니깐,

			// 쿼리가 5만개니까. N 정도 안에 하면 됤것 같은데, N log N 이나
			// 세그먼트 트리를 사용하긴하는데,
			// 세그트리가 i to j max 값을 가지고 있을 수 있잖아.
			// 그런데 2차원이니까
			// segtree[idx] 가 가질 정보가 무엇이있을까.
			// idx = i%1000 +

			// seg tree 510개
			// 나눠서 하면 될 것 같기도
			// query * day * row * log(numColumn)
			// 

			// sifting camera to the opposite direction
			printf("day[%d] max %3d\n", day + 1, max_);
			// printf("day[%d] range : [%d,%d] to [%d,%d]\n",day+1,x,y,x+r-1,y+c-1);

			x -= dx[d];
			y -= dy[d];

			x = max(x,1);
			x = min(x,N);
			y = max(y,1);
			y = min(y,N);
			result ^= max_;
		}

		printf("%d\n",result);
	}
	return 0;
}
/*
3 3
1 2 3
4 5 6
7 8 9
4
2 2 1 1 2 1
2 2 1 1 2 2
2 2 1 1 2 3
2 2 1 1 2 4

2 2 2 2 2 1
2 2 2 2 2 2
2 2 2 2 2 3
2 2 2 2 2 4

5 5
2 6 12 2 11
20 9 10 6 10
8 18 4 18 15
10 14 11 10 3
17 11 15 13 16
2
2 2 2 2 2 4
1 1 1 2 5 1


5 5
2 6 12 2 11
20 9 10 6 10
8 18 4 18 15
10 14 11 10 3
17 11 15 13 16
1
2 2 2 2 2 4

*/