#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct segTreeNode {
	int count;
	int ySum;
	int yBottom;
	int yTop;
};

struct segment {
	int x;
	int bottom;
	int top;
	bool end;
	segment(int x, int bottom, int top, bool end) : x(x), bottom(bottom), top(top), end(end){

	}
};

bool cmp( segment one, segment another){
	return one.x<another.x;
}

vector<segment> v;
vector<int> ys;
vector<int> filteredYs;

struct segTreeNode segmentTree[200010];

// start, end not changed
// also endSegment not changed
void updateTree(int nodeNumber, int start, int end, bool endSegment){

	struct segTreeNode temp = segmentTree[nodeNumber];

	// EXTRACT
	int count = temp.count;
	int ySum = temp.ySum;
	int yBottom = temp.yBottom;
	int yTop = temp.yTop;

	if(yTop <= start || end <= yBottom)
		return;

	else if(start <= yBottom && yTop <= end){
		// immediate return
		// cnt 갱신
		// printf("immediate return\n");
		if(endSegment)
			segmentTree[nodeNumber].count--;
		else
			segmentTree[nodeNumber].count++;

	}else {
		// recursive finding
		updateTree(nodeNumber * 2, start, end, endSegment);
		updateTree(nodeNumber * 2 + 1, start, end, endSegment);
	}

	if(segmentTree[nodeNumber].count == 0)
		segmentTree[nodeNumber].ySum = 
		segmentTree[nodeNumber * 2].ySum + segmentTree[nodeNumber * 2 + 1].ySum;
	else
		segmentTree[nodeNumber].ySum = yTop - yBottom; // itself

}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int xLeft,yLeft,xRight,yRight; scanf("%d %d %d %d",&xLeft,&yLeft,&xRight,&yRight);
		v.push_back(segment(xLeft,yLeft,yRight,false)); // Start
		v.push_back(segment(xRight,yLeft,yRight,true)); // End -> fourth element true
		ys.push_back(yLeft);
		ys.push_back(yRight);
	}

	sort(v.begin(),v.end(),cmp);
	ys.push_back(-1);
	sort(ys.begin(),ys.end());
	int track = ys[0];
	for (int i = 0; i < ys.size(); i++)
	{
		// printf("[%d]",ys[i]);
		if(ys[i]==track)
			continue;
		else
			filteredYs.push_back(ys[i]);
		track = ys[i];
	}

	printf("filtered size : %d\n",filteredYs.size());

	int segTreeNodeNum = filteredYs.size(); segTreeNodeNum--; // 구간의 개수는 3개이기 때문이다.
	int height = ceil(log2(segTreeNodeNum));
	int segTreeSize = 1 << height;

	// Rectangle 최대 10E4 개
	// y 좌표 최대 2 * 10E4 개. -> 구간 역시 최대 2만개
	// segTree 는 4배를 잡아주면 되니깐. 8만. 높게잡아 10만 잡으면 되겠다.
	// segTree each Node 가 가지고 있어야할 내용은,
	// Count. Initially 아무것도 필요없다. 공간 할당만 해주면 된다.
	// ySum 도 유지해주고 있으면 좋다. cnt 가 없어도 y Sum 값은 가지고 있어야 한다.


	// 처음에 노드 채우는것
	for (int i=0;i<segTreeSize;i++){
		// printf("%d\n",i+segTreeSize);
		if( i < segTreeNodeNum){
			segmentTree[i+segTreeSize].yBottom = filteredYs[i];
			segmentTree[i+segTreeSize].yTop = filteredYs[i+1];
		}else{
			// 빈 노드들.
			segmentTree[i+segTreeSize].yBottom = segmentTree[i+segTreeSize - 1].yTop;
			segmentTree[i+segTreeSize].yTop = segmentTree[i+segTreeSize - 1].yTop;
		}
	}

	// 그다음 노드들 채워주는 곳.
	for (int i = segTreeSize - 1; i > 0; i--)
	{
		segmentTree[i].yBottom = segmentTree[i*2].yBottom;
		segmentTree[i].yTop = segmentTree[i*2 + 1].yTop;
	}

	int result = 0;
	int sweepLine = v[0].x;
	for (int i=0;i<v.size();i++){
		struct segment now = v[i];
		int x = now.x;
		int xDiff = x - sweepLine;
		result += xDiff * segmentTree[1].ySum;
		sweepLine = x;

		int bottom = now.bottom;
		int top = now.top;
		bool end = now.end;

		updateTree(1, bottom, top, end);
	}

	printf("%d\n",result);
	return 0;
}





















