#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

#define NUM_RECTANGLE (110)

float result;
int segmentTree[8 * NUM_RECTANGLE];
int idxSegmentTree = 0;

struct Line{
	float key; 		// x 값
	float bottom; 	// 낮은 y 값
	float top; 		// 높은 y 값 
	bool end;

	Line(float key, bool end, float bottom, float top) : key(key), end(end), bottom(bottom), top(top) {};
};

struct Node{
	float ysum;
	float rangeBottom;
	float rangeTop;
	int count;

	Node(){
		ysum = 0f;
		count = 0;
	}

	Node(float rangeBottom, float rangeTop){
		Node();
		rangeBottom = rangeBottom;
		rangeTop = rangeTop
	}
}

bool LineCmp(Line one, Line another){
	return one.key < another.key;
}

vector<Line> verticalLines;
vector<int> parallelLines;

int find(int nodeNumber, int start, int end, int left, int right){
	// left right 값은 재귀돌리면서도 변하지 않음.
	// start, end 값이 바뀌면서 분할 정복을 실행함.
	if (end < left || right < start)
		return 0; // out of range
	if (left <= start && end <= right)
		return segTree[nodeNumber];

}


int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		float xLeft, yLeft, width, height; scanf("%f %f %f %f",&xLeft,&yLeft,&width,&height);
		verticalLines.push_back(Line(xLeft, false, yLeft, yLeft + height));
		verticalLines.push_back(Line(xLeft+width, true, yLeft, yLeft + height));
		parallelLines.push_back(yLeft);
		parallelLines.push_back(yLeft + height);
	}

	sort(verticalLines.begin(),verticalLines.end(),cmp);
	for (int i=0;i<verticalLines.size();i++){
		Line temp = verticalLines[i];
		printf("key[%f] end[%d] Bottom[%f] Top[%f]\n", Line.key, Line.end, Line.bottom, Line. top);
	}

	// segment Tree
	// 처음에는 공간만 있구, 아무것도 없음.
	// update 를 하면서 채워줄 것입니다.

	sort(parallelLines.begin(),parallelLines.end());
	segmentTree[++idxSegmentTree] = parallelLines[0];
	// segmentTree[++idxSegmentTree].top = parallelLines[1];
	for (int i=0;i<parallelLines.size()-1;i++)
		if()

	for (int i=0;i<verticalLines.size();i++){
		Line now = verticalLines[i];
		float key; 		// x 값
		float bottom; 	// 낮은 y 값
		float top; 		// 높은 y 값 
		bool end;

		
	}


	printf("%f\n",result);
	return 0;
}

// 밑변이 모두 x축에 평행한 N개의 직사각형이 주어질 때, 이 N개의 직사각형들이 차지하는 면적을 구하는 프로그램을 작성하시오. 여기서 주어진 직사각형들은 서로 겹칠 수도 있으며, 변이나 꼭짓점을 공유할 수도 있다.

// 입력
// 첫째 줄에 직사각형의 개수 N(1 ≤ N ≤ 30)이 주어지고 그 다음 N줄에는 각각의 직사각형에 대한 자료가 주어진다. 이 자료는 4개의 숫자로 표시되는데 첫째, 둘째 숫자는 직사각형의 왼쪽 아래 모서리의 x좌표, y좌표이고 셋째 숫자는 폭, 넷째 숫자는 높이를 나타낸다. 각 수는 최대 소수점 이하 한 자리까지 주어지며, 1000.0보다 작거나 같은 양의 실수이다.

// 출력
// 첫째 줄에 N개의 직사각형이 차지하는 면적을 소수점 이하 2자리까지 출력한다. 단, 값이 소수 부분이 없이 정수로 맞아떨어지는 경우는 정수 부분만 출력한다.

// 예제 입력 1 
// 4
// 52.7 22.9 27.3 13.3
// 68.8 57.6 23.2 8.0
// 20.0 48.0 37.0 23.5
// 41.5 36.2 27.3 21.4
// 예제 출력 1 
// 1853.61
