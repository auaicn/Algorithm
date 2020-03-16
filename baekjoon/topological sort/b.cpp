#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> result;

int main(int argc, char const *argv[])
{
	string temp; cin>>temp;

	int left = -1;
	int right = temp.size();
	int cnt_ = 0;

	while(true){
		for (left = left+1;left<temp.size();left++){
			if(temp[left]=='(')
				break;
		}
		for (right = right-1;right>0;right--){
			if(temp[right]==')')
				break;
		}
		if(left<right){
			result.push_back(left+1);
			result.push_back(right+1);
			cnt_++;
		}else
			break;

	}	
	if(cnt_){
		printf("1\n");
		printf("%lu\n",result.size());
		sort(result.begin(),result.end());
		for (int i=0;i<result.size();i++)
			printf("%d ",result[i]);
		printf("\n");

	}
	else
		printf("0\n");

	return 0;
}