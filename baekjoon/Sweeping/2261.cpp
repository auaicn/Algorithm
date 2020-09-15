#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
	int x;
	int y;
	point(int x, int y): x(x),y(y){};
};

vector<point> nodes;

int dist(point one, point another){
	return (one.x-another.x) * (one.x-another.x) + (one.y-another.y) * (one.y-another.y);
}

bool cmp(point one, point another){
	if(one.x == another.x)
		return one.y < another.y;
	else
		return one.x < another.x;
}

bool cmpY(point one, point another){
	return one.y < another.y;
}

int min(int x, int y){
	return x<y?x:y;
}

int closesetDistance(vector<point>::iterator it, int numNode){

	if(numNode == 2)
		return dist(it[0], it[1]);

	if(numNode == 3)
		return min(min(dist(it[0],it[1]), dist(it[1],it[2])), dist(it[0],it[2]));

	int d = min(closesetDistance(it, numNode / 2), closesetDistance(it + numNode / 2, numNode - numNode / 2));
	int line = (it[numNode/2 - 1].x + it[numNode/2].x) / 2;

	vector<point> mid;
	mid.reserve(numNode);

	for (int i=0;i<numNode;i++){
		int x_diff = line - it[i].x;
		if(x_diff * x_diff < d)
			mid.push_back(it[i]);
	}

	sort(mid.begin(),mid.end(),cmpY);

	int mid_sz = mid.size();
	for (int i = 0; i < mid_sz - 1; i++)
		for (int j = i + 1; j < mid_sz && (mid[j].y - mid[i].y) * (mid[j].y - mid[i].y) < d; j++)
			d = min(d, dist(mid[i],mid[j]));

	return d;
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++)
	{
		int left,right; scanf("%d %d",&left,&right);
		nodes.push_back(point(left,right));
	}

	sort(nodes.begin(),nodes.end(),cmp); // x 기준

	printf("%d\n",closesetDistance(nodes.begin(),N));

	return 0;
}