#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> res;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		v.clear();
		res.clear();

		int N; scanf("%d",&N);
		for (int i=0;i<N;i++){
			int temp; scanf("%d",&temp);
			v.push_back(temp);
		}
		sort(v.begin(),v.end());
		int s = v.size()-1;
		s/=2;
		bool sw = false;
		for (int i=0;i<v.size();i++){
			sw = sw ^ true;
			if (sw)
				res.push_back(v[s-((i+1)/2)]);
			else
				res.push_back(v[s+((i+1)/2)]);

		}
		for (int i=0;i<res.size();i++)
			printf("%d ",res[i]);
		printf("\n");

	}
	return 0;
}