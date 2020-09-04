#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>

#define MAX_VERTEX (100010)

using namespace std;

struct point{
	int x;
	int y;
} pivot;

int result[MAX_VERTEX];
vector<point> save;
vector<int> v; // 
vector<int> s;

long long cross(int x1, int y1, int x2, int y2)
{
	return 1LL*x1*y2 - 1LL*x2*y1;
}

// 그 외적한 값 자체를 리턴하는 함수야!!! 양수면 CCW, 0 이면 0, 음수면 CW
long long cross3(point std, point left, point right)
{
	return cross(left.x - std.x, left.y - std.y, right.x - std.x, right.y - std.y);
}

long long square_distance(point left, point right)
{
	return 1LL * (left.x - right.x) * (left.x - right.x) + 1LL * (left.y - right.y) * (left.y - right.y);
}

double distance(point left, point right)
{
	return sqrt(1.0l * (left.x - right.x) * (left.x - right.x) + 1.0l * (left.y - right.y) * (left.y - right.y));
}

bool angleCmp(int first, int second)
{

	point left = save[first];
	point right = save[second];

	if (cross3(pivot,left,right) == 0){
		// return distance(pivot,left) < distance(pivot, right);
		return square_distance(pivot,left) < square_distance(pivot, right);
	}

	double dxLeft = left.x - pivot.x, dyLeft = left.y - pivot.y;
	double dxRight = right.x - pivot.x, dyRight = right.y - pivot.y;

	return atan2(dyLeft,dxLeft) < atan2(dyRight,dxRight);
}

int main(int argc, char const *argv[])
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; scanf("%d",&N);
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
		point pivotCandidate = save[pivot_idx];

		for (int i=0;i<v.size();i++){
			struct point now = save[v[i]];
			int xLookup = now.x;
			int yLookup = now.y;

			if (pivotCandidate.y > yLookup){
				// find lowest
				pivotCandidate = now;
				pivot_idx = i;
			}
			else if (pivotCandidate.y == yLookup){
				// find right most
				if(pivotCandidate.x < xLookup){
					pivotCandidate = now;
					pivot_idx = i;
				}
			}
		}

		int temp = v[0];
		v[0] = v[pivot_idx];
		v[pivot_idx] = temp;

		pivot.x = save[v[0]].x;
		pivot.y = save[v[0]].y;

		sort(++v.begin(),v.end(),angleCmp);

		s.clear();
		s.push_back(v[0]);
		s.push_back(v[1]);

		int i = 2;
		while(i < v.size())
		{
			int now = v[i];

			while(s.size() >= 2)
			{
				int first = s.back(); s.pop_back(); // 일단 pop
				int second = s.back();

				// escape condition
				int crossValue = cross3(save[second],save[first],save[v[i]]);
				if(crossValue > 0){
					// CCW 겠네
					s.push_back(first);
					break;
				}
			}
			s.push_back(v[i++]);
		}

		// need not further discussion
		if(s.size() < 3)
			break;

		for (int i=0;i<s.size();i++)
			result[s[i]] = floor;

		floor++;
		v.clear();

		for (int i=0;i<N;i++)
			if(!result[i])
				v.push_back(i);
	}

	for (int i=0;i<N;i++)
		printf("%d ",result[i]);
	printf("\n");

	return 0;
}