#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> res;
vector<int>::iterator it;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int box_size; scanf("%d",&box_size);
		v.push_back(box_size);
	}

	res.push_back(0);
	for (int i=0;i<N;i++){
		int box_size = v[i];
		it = lower_bound(res.begin(),res.end(),box_size);
		if(it==res.end())
			res.push_back(box_size);
		else{
			*it = box_size;
		}
	}

	printf("%lu\n",N-(res.size()-1));
	return 0;
}
