#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int save[2010];

vector<int> res;
vector<int>::iterator lo_it;
vector<int>::iterator up_it;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf("%d",&save[i+1]);

	//res.push_back(0);
	res.push_back(save[N]);
	for (int i=N-2;i>=0;i--){
		int weight = save[i+1];
		lo_it = lower_bound(res.begin(),res.end(),weight);
		if(it==res.begin()){
			res.push_back(0);
			for (int j=1;j<res.size();j++){
				res[j] = res[j-1];
			}
			res[0] = weight;
		}else
			*it = weight;
		up_it = upper_bound(res.begin(),res.end(),weight);
		if(it==res.end())



	}

	return 0;
}