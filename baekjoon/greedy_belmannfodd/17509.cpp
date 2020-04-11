#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int save[110];
vector<int> v;

int main(int argc, char const *argv[])
{

	int right_sum = 0;
	for (int i=0;i<11;i++){
		int left,right; scanf("%d %d",&left,&right);
		right_sum+=right;
		v.push_back(left);
	}
	sort(v.begin(),v.end());
	for (int i=0;i<11;i++)
		save[i+1] = v[i];
	for (int i=1;i<11;i++)
		save[i+1]+=save[i];
	int save_sum = 0;
	for (int i=0;i<11;i++)
		save_sum+=save[i+1];

	printf("%d\n",save_sum+20*right_sum);
	/* code */
	return 0;
}