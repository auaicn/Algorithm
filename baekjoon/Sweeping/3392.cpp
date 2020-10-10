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

vector<segment> segments;
vector<int> yValuesRaw;
vector<int> yValuesFiltered;

struct segTreeNode segmentTree[200010];

// start, end not changed
// also endSegment not changed
void updateTree(int nodeNumber, int start, int end, bool endSegment){

	struct segTreeNode temp = segmentTree[nodeNumber];

	int count = temp.count;
	int ySum = temp.ySum;
	int yBottom = temp.yBottom;
	int yTop = temp.yTop;

	if(yTop <= start || end <= yBottom)
		// 원하는 y 구간 밖으로 나간 경우.
		// 10-20 을 원하는데, 현재 nodeNumber 에 해당하는 구간이 20-30 으로 접한 경우도 바로 리턴 해주자.
		return;

	else if(start <= yBottom && yTop <= end){
		// main 문에서 넣어준 endSegment 의 True/False 를 보고
		// count 를 갱신해준다.
		if(endSegment)
			segmentTree[nodeNumber].count--;
		else
			segmentTree[nodeNumber].count++;

	}else {
		// recursive finding
		updateTree(nodeNumber * 2, start, end, endSegment);
		updateTree(nodeNumber * 2 + 1, start, end, endSegment);
	}

	// recursive call 이나, segment Tree 상에 값이 있었다면, 이제 다시 루트 노드로 올라가면서 현재 노드의 ySum 값을 갱신해준다. ppt 의 4-1, 4-2 규칙에 의해서!

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
		// 하나의 직사각형 입력을 두개의 선분의 입력으로 처리해주자.
		int xLeft,yLeft,xRight,yRight; scanf("%d %d %d %d",&xLeft,&yLeft,&xRight,&yRight);
		segments.push_back(segment(xLeft,yLeft,yRight,false)); // 시작 선분
		segments.push_back(segment(xRight,yLeft,yRight,true)); // 끝 선분 -> fourth element true
		yValuesRaw.push_back(yLeft);
		yValuesRaw.push_back(yRight);
	}
	sort(segments.begin(),segments.end(),cmp);

	// 중복 되는 y값들 필터링하기y
	// -1 은 문제 조건 간에 도달 불가능한 y 값이다.
	int previous = -1; 
	sort(yValuesRaw.begin(),yValuesRaw.end());
	for (int i = 0; i < yValuesRaw.size(); i++)
	{
		if(yValuesRaw[i] == previous)
			continue;
		else
			// i == 0 일때 push back 해준다.
			yValuesFiltered.push_back(yValuesRaw[i]);
		previous = yValuesRaw[i];
	}

	// 필터링 된 y 값들을 가지고 세그먼트 트리 구성하기
	int segTreeNodeNum = yValuesFiltered.size(); 
	segTreeNodeNum--; // 구간의 개수는 필터링 된 y 값의 개수보다 하나 적다.
	int height = ceil(log2(segTreeNodeNum));
	int segTreeSize = 1 << height;

	// 세그먼트 트리의 리프 노드 채우기
	for (int i=0;i<segTreeSize;i++){
		if( i < segTreeNodeNum){
			// segmentTree에 y 낮은값, 높은 값을 넣어 세그먼트 트리 리프노드를 초기화 한다.
			segmentTree[i+segTreeSize].yBottom = yValuesFiltered[i];
			segmentTree[i+segTreeSize].yTop = yValuesFiltered[i+1];
		}else{
			// 세그먼트 트리의 리프노드에서, 데이터 개수만큼 채우고 나서, 남은 노드들의 초기화
			// 인덱스가 하나 적은 노드의 구간의 높은 값을 그대로 넣어주자
			// 인덱스 10인 노드의 구간이 20-30 이고, 인덱스 11인 노드부터는 빈 노드라고 하면,
			// 인덱스 11인 노드의 구간을 30-30 으로 설정
			// 인덱스 12인 노드의 구간또한 30-30 으로 설정해 줄 것이다.
			segmentTree[i+segTreeSize].yBottom = segmentTree[i+segTreeSize - 1].yTop;
			segmentTree[i+segTreeSize].yTop = segmentTree[i+segTreeSize - 1].yTop;
		}
	}

	// 세그먼트 트리의 인터널 노드 채우기
	// 현재 노드의 인덱스 * 2, 인덱스 * 2 + 1, 즉 두 명의 child 를 이용하여 갱신한다.
	for (int i = segTreeSize - 1; i > 0; i--)
	{
		segmentTree[i].yBottom = segmentTree[i*2].yBottom;
		segmentTree[i].yTop = segmentTree[i*2 + 1].yTop;
	}

	// 결과값 초기화 & sweeping line 의 값을, 첫번째 선분의 x 좌표로 변경해준다.
	int result = 0;
	int sweepLine = segments[0].x;
	for (int i=0;i<segments.size();i++){
		
		// i번째 선분을 뽑아와서 now 라고 하자.
		struct segment now = segments[i]; 

		// 뽑아온 선분의 x 좌표를 가져와서 x라고 하자.
		int x = now.x;

		// 이전 선분과 현재 선분의 x 좌표 차이가 폭이 된다.
		int xDiff = x - sweepLine;

		// 결과값 갱신 (+= 폭 * 높이)
		result += xDiff * segmentTree[1].ySum;

		// 다음 loop 문을 위해, 현재 선분의 x 좌표로 변경해준다.
		sweepLine = x;

		// 현재 선분의 y좌표 낮은 값, 높은 값, 그리고 시작, 끝 선분인지 여부를 updateTree 함수에 전달한다.
		updateTree(1, now.bottom, now.top, now.end);
	}

	printf("%d\n",result);
	return 0;
}





















