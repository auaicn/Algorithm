#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct point{
	int x;
	int y;
} pivot;

vector<point> v; // for scan
vector<point> s; // for stack

int cross(int, int, int, int);

double square_distance(point left, point right)
{
	return 1.0l * (left.x - right.x) * (left.x - right.x) + 1.0l * (left.y - right.y) * (left.y - right.y);
}

double distance(point left, point right)
{
	return sqrt(1.0l * (left.x - right.x) * (left.x - right.x) + 1.0l * (left.y - right.y) * (left.y - right.y));
}

bool linear(point std, point left, point right)
{
	switch(cross(left.x - std.x, left.y - std.y, right.x - std.x, right.y - std.y))
	{
		case 0: // case parallel
			return true;
		default: // case CCW | CW
			return false;

	}
}

bool angleCmp(point left, point right)
{
	// regarding to pivot,
	// it can be on same line 
	if (linear(pivot,left,right)){
		return distance(pivot,left) < distance(pivot, right);
	}
	double dxLeft = left.x - pivot.x, dyLeft = left.y - pivot.y;
	double dxRight = right.x - pivot.x, dyRight = right.y - pivot.y;

	return atan2(dyLeft,dxLeft) < atan2(dyRight,dxRight);
}

int cross(int x1, int y1, int x2, int y2)
{
	// 부호만 중요시하자.
	int temp = 1LL*x1*y2 - 1LL*x2*y1;
	if (temp > 0L)
		return 1; // CCW yes
	else if (temp < 0L)
		return -1;
	else
		return 0;
}

int cross_itself(int x1, int y1, int x2, int y2)
{
	// 값 그자체
	return 1LL*x1*y2 - 1LL*x2*y1;
}

bool ccw(point std, point left, point right)
{
	switch(cross(left.x - std.x, left.y - std.y, right.x - std.x, right.y - std.y))
	{
		case 1: // case CCW
			return true;
		default: // case Parallel & CW
			return false;

	}

}

double max(double x, double y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	// int N; scanf("%d",&N);
	int N; scanf("%d",&N);

	for (int i=0;i<N;i++){
		struct point temp; scanf("%d %d",&temp.x,&temp.y);
		v.push_back(temp);
	}

	// 한바퀴 무식하게 돌면서, right most, lowest y 의 값만 배껴온다.
	// initially set as v[0]
	pivot = v[0];
	int pivot_idx = 0;
	for (int i=0;i<N;i++)
	{
		struct point lookup = v[i];
		int xLookup = lookup.x;
		int yLookup = lookup.y;
		if (pivot.y > yLookup){
			pivot = lookup;
			pivot_idx = i;
		}
		else if (pivot.y == yLookup)
			if(xLookup > pivot.x){
				pivot = lookup;
				pivot_idx = i;
			}
			// if(pivot.x < xLookup){
			// 	pivot = lookup;
			// 	pivot_idx = i;
			// }
	}

	// 아 sorting 을 pivot 빼고 시키는구나 안전하게
	// printf("pivot : [%d, %d]\n",pivot.x,pivot.y);

	point temp;
	temp = v[0];
	v[0] = v[pivot_idx];
	v[pivot_idx] = temp;

	sort(++v.begin(),v.end(),angleCmp);
	// printf("AFTER SORTING\n");
	for (int i=0;i<v.size();i++)
	{
		// printf("[%d,%d]\n",v[i].x,v[i].y);
	}
	// printf("\n");

	// s.push_back(v[N-1]);
	s.push_back(v[0]); // it would be pivot itself
	s.push_back(v[1]);

	int i = 2; // 우리는 현재 3개를 넣었음.
	while(i < N)
	{
		point lookup = v[i];

		while(s.size() >= 2)
		{
			point first, second;
			first = s.back();
			// s.pop(); // 일단 pop 하네?
			s.pop_back();
			second = s.back();

			// escape condition
			if(ccw(second,first,v[i]) > 0){
				s.push_back(first); // again insert
				break;
			}
		}

		s.push_back(v[i++]);
	}

	double result = -1;

	for (int i=0;i<s.size();i++){
		for (int j=0;j<s.size();j++){
			result = max(result,square_distance(s[i],s[j]));
		}
	}

	printf("%lf",sqrt(result));

	return 0;
}

















// 로버트 후드는 로빈 후드의 동생이다. 로버트 후드는 자신의 형처럼 전설적인 인물이 되기 위해 활 쏘기를 연습하고 있다.

// 이번에 노팅엄에서 열린 활 쏘기 대회는 현대에 열리는 양궁과 규칙이 다르다. 양궁은 더 많은 점수를 쏜 사람이 승리하는 방식이다. 하지만, 노팅엄 활 쏘기 대회에서는 과녁에 맞은 화살 사이의 거리 중 최댓값이 가장 큰 사람이 승리한다.

// 로버트 후드는 총 C발을 발사했고, 모든 화살은 과녁에 적중했다. 과녁을 이차원 평면으로, 화살은 점으로 나타낸다. 화살의 좌표가 주어졌을 때, 가장 먼 화살의 거리를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 로버트 후드가 발사한 화살의 수 C (2 ≤ C ≤ 100,000)가 주어진다. 다음 C개 줄에는 화살의 좌표가 주어진다. 좌표는 정수이고, 절댓값은 1,000을 넘지 않는다.

// 출력
// 가장 먼 두 화살의 거리를 출력한다. 상대/절대 오차가 10-6 이내인 경우에만 정답이다.

// 예제 입력 1 
// 2
// 2 2
// -1 -2
// 예제 출력 1 
// 5.0
// 예제 입력 2 
// 5
// -4 1
// -100 0
// 0 4
// 2 -3
// 2 300
// 예제 출력 2 
// 316.86590223
