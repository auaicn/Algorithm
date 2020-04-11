#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <float.h>
#include <math.h>
#include <stack>

using namespace std;

double get_distance(double x_left,double y_left,double x_right,double y_right){
	return sqrt(pow(x_left-x_right,2)+pow(y_left-y_right,2));
}

vector<pair<double,double> > location;
vector<pair<int,double> > v[110];

double min(double x, double y){
	return x<y?x:y;
}

double dist[110];
int track[110];

int main(int argc, char const *argv[])
{
	double x_start,y_start; scanf("%lf %lf",&x_start,&y_start);
	double x_end,y_end; scanf("%lf %lf",&x_end,&y_end);
	location.push_back({x_start,y_start});
	location.push_back({x_end,y_end});

	int N; scanf("%d",&N);

	for (int i=0;i<N;i++){
		double x_each,y_each; scanf("%lf %lf",&x_each,&y_each);
		location.push_back({x_each,y_each});
	}

	for (int i=0;i<location.size();i++){
		//printf("%d\n",i);
		for (int j=i+1;j<location.size();j++){
			pair<double,double> left = location[i];
			pair<double,double> right = location[j];
			double distance = get_distance(left.first,left.second,right.first,right.second);
			if(i>0)
				distance = min(fabs(distance-50)/5+2,distance/5);
			else
				distance/=5.0;

			if(i!=1)
				v[i].push_back({j,distance});

			if(i)
				v[j].push_back({i,distance});
		}
	}

	for (int i=0;i<N+2;i++)
		dist[i] = DBL_MAX;

	priority_queue<pair<double,int> > pq;
	pq.push({0.0,0}); dist[0] = 0;

	while(!pq.empty()){
		pair<double,int> pos = pq.top(); pq.pop();
		double for_now = pos.first; for_now *= -1.0;
		int now = pos.second;

		if(now == 1)
			break;

		for (int i=0;i<v[now].size();i++){
			pair<int,double> next_ = v[now][i];
			int next = next_.first;
			double weight = next_.second;

			if(dist[next]>dist[now]+ weight){
				dist[next] = dist[now] + weight;
				pq.push({-dist[next],next});
				track[next] = now;
			}
		}
	}

	printf("%lf\n",dist[1]);

	return 0;
}