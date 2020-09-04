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

double distance(point left, point right)
{
	return sqrt((left.x - right.x) * (left.x - right.x) + (left.y - right.y) * (left.y - right.y));
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

double area(point criteria, point A, point B)
{
	return 0.5 * abs(cross_itself(A.x - criteria.x, A.y - criteria.y, B.x - criteria.x, B.y - criteria.y));
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

	
	// previous version
	// angle CMP 랑 비슷한디
	// regarding to std,
	// it can be on same line 
	if (linear(std,left,right)){
		printf("linear\n");
		// printf("std : [%d, %d]\n",std.x,std.y);
		// printf("left : [%d, %d]\n",left.x,left.y);
		// printf("right : [%d, %d]\n",right.x,right.y);
		return distance(std,left) > distance(std, right);
	}
	double dxLeft = left.x - std.x, dyLeft = left.y - std.y;
	double dxRight = right.x - std.x, dyRight = right.y - std.y;

	return atan2(dyLeft,dxLeft) > atan2(dyRight,dxRight);
	
}

int main(int argc, char const *argv[])
{
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

		// for (int j=0;j<s.size();j++);
		// 	printf("[%d,%d] ",s[j].x,s[j].y);
		// printf("\n");
	}

	// for (int i=0;i<s.size();i++)
	// 	printf("[%d,%d] ",s[i].x,s[i].y);
	// printf("\n");

	double result = 0;

	point cri = s[0];
	for (int i = 0;i<s.size()-2;i++)
		result += area(cri,s[i+1],s[i+2]);
	// printf("result : %Lf\n",result / 50.0l);
	// printf("%f\n",result);
	// printf("result : %d\n",result/50);
	// printf("%d\n",result);
	// printf("%f\n",result/50.0);
	// printf("%d\n",result/50.0);
	// printf("result : %Lf\n",result / 50.0l);
	// printf("%lu\n",s.size());
	int integer = (int)result;
	printf("%d\n",integer/50);


	return 0;
}






























