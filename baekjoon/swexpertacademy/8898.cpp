#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v_left;
vector<int> v_right;

int abs(int x){
	if(x>0)
		return x;
	else
		return -x;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	for (int t=0;t<T;t++){
		int N,M; scanf("%d %d",&N,&M);
		int l,r; scanf("%d %d",&l,&r); int distance = abs(l-r);

		v_left.clear();
		v_right.clear();

		int res = 1987654321;
		for (int i=0;i<N;i++){
			int temp; scanf("%d",&temp);
			v_left.push_back(temp);
		}
		for (int i=0;i<M;i++){
			int temp; scanf("%d",&temp);
			v_right.push_back(temp);
		}

		sort(v_left.begin(),v_left.end());
		sort(v_right.begin(),v_right.end());

		int cnt_=0;

		int left_index = 0;
		int right_index = 0;

		bool sw = false;

		while(true){

			if(left_index>=v_left.size()-1&&right_index>=v_right.size()-1){
				sw = true;
			}
			else if(left_index>v_left.size()-1){
				left_index--;
				right_index++;
			}else if(right_index>v_right.size()-1){
				right_index--;
				left_index++;
			}

			int left_value = v_left[left_index];
			int right_value = v_right[right_index];
			int dist = abs(left_value-right_value);

			if(dist<res){
				res = dist;
				cnt_ = 1;
			
			}else if(dist==res)
				cnt_++;
			
			if(left_value<right_value)
					left_index++;
				else
					right_index++;

			if(sw)
				break;
		}

		printf("#%d %d %d\n",t+1,distance+res,cnt_);
	}
	return 0;
}