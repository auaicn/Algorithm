#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v[30];

int main(int argc, char const *argv[])
{
	int N; cin>>N;

	string cmp;
	printf("%lu\n",cmp.size());

	for (int i=0;i<N;i++){
		string temp; cin>> temp;
		if(!cmp.size())
			cmp = temp;

		// solution
		for (int i=0;i<cmp.size();i++)
			if(cmp[i]==temp[i])
				continue;
			else{
				v[cmp[i]-'a'].push_back[]
				indegree[cmp]
			}





		cmp = temp;
	}
	return 0;
}