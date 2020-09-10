#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define MAX_ARRAY_SIZE (100010)

using namespace std;

int save[MAX_ARRAY_SIZE];
int right_[MAX_ARRAY_SIZE];
int left_[MAX_ARRAY_SIZE];

stack<int> prv;
stack<int> nxt;

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf("%d",&save[i+1]);

	for (int i=0;i<N;i++)
		left_[i+1] = right_[i+1] = -1;

	// fill right_[]
	for (int i=0;i<N;i++){
		while(!nxt.empty() && save[i+1] < save[nxt.top()]){
			int nxtTop = nxt.top(); nxt.pop();
			right_[nxtTop] = i + 1 - 1;
		}
		nxt.push(i+1);
	}

	// printf("SAVE\n");
	// for (int i=0;i<N;i++)
	// 	printf("%3d",save[i+1]);
	// printf("\n");

	while(!nxt.empty())
		nxt.pop();
	for (int i=0;i < (N+1)/2;i++){
		int temp = save[i+1];
		save[i+1] = save[N+1 - (i+1)];
		save[N+1 - (i+1)] = temp;
	}

	// printf("SAVE\n");
	// for (int i=0;i<N;i++)
	// 	printf("%3d",save[i+1]);
	// printf("\n");

	// fill left[]
	for (int i=0;i<N;i++){
		while(!nxt.empty() && save[i+1] < save[nxt.top()]){
			int nxtTop = nxt.top(); nxt.pop();
			left_[N + 1 - nxtTop] = N + 1 - (i + 1) + 1;
		}
		nxt.push(i+1);
	}

	// //check
	// printf("LEFT\n");
	// for (int i=0;i<N;i++)
	// 	if(left_[i+1] == -1)
	// 		// printf("%3c",'-');
	// 		printf("%3d",1);
	// 	else
	// 		printf("%3d",left_[i+1]);
	// printf("\n");

	// printf("RIGHT\n");
	// for (int i=0;i<N;i++)
	// 	if(right_[i+1] == -1)
	// 		printf("%3d",N);
	// 		// printf("%3c",'-');
	// 	else
	// 		printf("%3d",right_[i+1]);
	// printf("\n");

	int result = 0;
	for (int i=0;i<N;i++){
		int left = left_[i+1];
		if(left == -1)
			left = 1;
		int right = right_[i+1];
		if(right == -1)
			right = N;
		int length = right - left + 1;
		int height = save[(N+1) - (i+1)];
		result = max(result, length * height);
	}
	// printf("RESULT : %d\n",result);

	printf("%d\n",result);

	return 0;
}


// 히스토그램에 대해서 알고 있는가? 히스토그램은 아래와 같은 막대그래프를 말한다.
// 각 칸의 간격은 일정하고, 높이는 어떤 정수로 주어진다. 위 그림의 경우 높이가 각각 2 1 4 5 1 3 3이다.

// 이러한 히스토그램의 내부에 가장 넓이가 큰 직사각형을 그리려고 한다. 아래 그림의 빗금 친 부분이 그 예이다. 이 직사각형의 밑변은 항상 히스토그램의 아랫변에 평행하게 그려져야 한다.



// 주어진 히스토그램에 대해, 가장 큰 직사각형의 넓이를 구하는 프로그램을 작성하시오.

// 입력
// 첫 행에는 N (1 ≤ N ≤ 100,000) 이 주어진다. N은 히스토그램의 가로 칸의 수이다. 다음 N 행에 걸쳐 각 칸의 높이가 왼쪽에서부터 차례대로 주어진다. 각 칸의 높이는 1,000,000,000보다 작거나 같은 자연수 또는 0이다.

// 출력
// 첫째 줄에 가장 큰 직사각형의 넓이를 출력한다. 이 값은 20억을 넘지 않는다.

// 예제 입력 1 
// 7
// 2
// 1
// 4
// 5
// 1
// 3
// 3
// 예제 출력 1 
// 8
