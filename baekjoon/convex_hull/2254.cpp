#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>

#define MAX_VERTEX (1010)

using namespace std;

struct point{
	int x;
	int y;
} global_pivot,start_point;

int result[MAX_VERTEX];
vector<point> save;
vector<int> v; // 
vector<int> s;

int cross_sign(int x1, int y1, int x2, int y2)
{
	// 부호만 중요시하자.
	long long temp = 1LL*x1*y2 - 1LL*x2*y1;
	if (temp > 0L)
		return 1; // CCW yes
	else if (temp < 0L)
		return -1;
	else
		return 0;
}

double distance(point left, point right)
{
	return sqrt(1.0l * (left.x - right.x) * (left.x - right.x) + 1.0l * (left.y - right.y) * (left.y - right.y));
}

bool linear(point std, point left, point right)
{
	switch(cross_sign(left.x - std.x, left.y - std.y, right.x - std.x, right.y - std.y))
	{
		case 0: // case parallel
			return true;
		default: // case CCW | CW
			return false;
	}
}

bool angleCmp(int first, int second)
{

	point left = save[first];
	point right = save[second];
	// regarding to global_pivot,
	// it can be on same line 

	if (linear(global_pivot,left,right)){
		return distance(global_pivot,left) < distance(global_pivot, right);
	}

	double dxLeft = left.x - global_pivot.x, dyLeft = left.y - global_pivot.y;
	double dxRight = right.x - global_pivot.x, dyRight = right.y - global_pivot.y;

	return atan2(dyLeft,dxLeft) < atan2(dyRight,dxRight);
}

bool ccw(point std, point left, point right)
{
	switch(cross_sign(left.x - std.x, left.y - std.y, right.x - std.x, right.y - std.y))
	{
		case 1: // case CCW
			return true;
		default: // case Parallel & CW
			return false;
	}
}

int signWrapper(point std, point left, point right)
{
	return cross_sign(left.x - std.x, left.y - std.y, right.x - std.x, right.y - std.y);
}

int main(int argc, char const *argv[])
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; scanf("%d",&N);
	int left,right; scanf("%d %d",&left,&right);
	start_point.x  = left;
	start_point.y  = right;
	for (int i=0;i<N;i++){
		struct point temp; scanf("%d %d",&temp.x,&temp.y);
		save.push_back(temp);
	}

	// initially, push all idx
	for (int i = 0; i < N; i++)
		v.push_back(i);

	int floor;
	for (floor = 1;;)
	{
		// 3개가 안된다면, 시작할 이유가 없다.
		// printf("now v size : %d\n",v.size());
		if(v.size() < 3)
			break;

		// v 는 소팅안된, 몇개의 점은 빠진 상태이다.
		int pivot_idx = v[0];
		point pivot = save[pivot_idx];

		for (int i=0;i<v.size();i++){
			struct point lookup = save[v[i]];
			int xLookup = lookup.x;
			int yLookup = lookup.y;

			if (pivot.y > yLookup){
				// find lowest
				pivot = lookup;
				pivot_idx = i;
			}
			else if (pivot.y == yLookup){
				// find right most
				if(pivot.x < xLookup){
					pivot = lookup;
					pivot_idx = i;
				}
			}
		}

		int temp = v[0];
		v[0] = v[pivot_idx];
		v[pivot_idx] = temp;

		global_pivot.x = save[v[0]].x;
		global_pivot.y = save[v[0]].y;

		sort(++v.begin(),v.end(),angleCmp);

		s.clear();
		s.push_back(v[0]);
		s.push_back(v[1]);

		int i = 2;
		while(i < v.size())
		{
			int lookup = v[i];

			while(s.size() >= 2)
			{
				int first = s.back(); s.pop_back(); // 일단 pop
				int second = s.back();

				// escape condition
				int isCCW = signWrapper(save[second],save[first],save[v[i]]);
				if(isCCW >= 0){
					s.push_back(first);
					break;
				}else if (isCCW == 0)
				{
					// printf("CCW zero with second[%d] first[%d] lookup[%d]\n",second,first,v[i]);
					result[v[i]] = 1;
					// remove it from v 
				}

			}
			s.push_back(v[i++]);
		}

		// need not further discussion
		if(s.size() < 3)
			break;

		// 2개로 시작했는데, 3개가 있긴한데 일직선일경우 이렇게 됨.
		// 그경우 걔네는 0인채로 break 하고 출력
		// 더 이상 무언가 생길 가능성도 없음.

		// printf("s size: %d\n",s.size());

		// for (int i=0;i<s.size();i++)
			// printf("[%d,%d] ",save[s[i]].x,save[s[i]].y);
		// printf("\n");

		bool whetherCount = true;
		int initialDirection = signWrapper(save[s[0]],save[s[1]],start_point);

		for (int i=0;i<s.size();i++)
		{
			point left = save[s[i]];
			point right = save[s[(i+1) % s.size()]];
			// left - right 벡터랑
			// 새로운 점이랄까 

			if(signWrapper(left,right,start_point)!=initialDirection)
				whetherCount = false;
		}

		if(whetherCount){
			for (int i=0;i<s.size();i++)
			result[s[i]] = floor;
			floor++;

			// clear & if not visited push again
			v.clear();
			for (int i=0;i<N;i++)
				if(!result[i])
					v.push_back(i);
		}
		else
			break;

	}

	printf("%d\n",floor - 1);
	return 0;

	for (int i=0;i<N;i++)
		// printf("%d ",result[i]);

	return 0;
}