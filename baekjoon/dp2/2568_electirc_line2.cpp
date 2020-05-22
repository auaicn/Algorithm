#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int> > save;
vector<int> res;
vector<int> not_to_cut;
vector<int>::iterator it;

int right_to_left[500010];
int previous[500010];
bool auaicn[500010];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int left,right; scanf("%d %d",&left,&right);

		// LIS를 위해 넣어줌
		save.push_back({left,right});

		// B전봇대에서 A전봇대로 연결된 정보를 저장함.
		right_to_left[right] = left;

		// 일단 A전봇대중 B전봇대랑 연결되어있으면 A에 대해 true로 만들어줌. 
		// 나중에 지울녀석들은 그대로 true, LIS구성하는 애들은 false가 됨. 출력할 때 사용할것.
		auaicn[left] = true;
	}

	sort(save.begin(),save.end());

	res.push_back(0);

	for (int i=0;i<N;i++){
		pair<int,int> temp = save[i];
		int left = temp.first;
		int right = temp.second;

		// 보통 LIS
		it = lower_bound(res.begin(),res.end(),right);
		int previous_index = it-res.begin();
		if(it == res.end())
			res.push_back(right);
		else
			*it = right;

		if(it != res.end())
			previous_index--;
		//printf("%d\n",previous_index);
		previous[left] = right_to_left[res[previous_index]];
	}

	//printf("%d\n",N-(res.size()-1));
	// lis 마지막 원소의 A전봇대 친구번호를 시작으로
	int last_left = right_to_left[res[res.size()-1]];
	while(last_left){
		// previous를 돌면서 LIS의 그전 A전봇대를 찾음
		not_to_cut.push_back(last_left);
		last_left = previous[last_left];
	}

	// LIS 구성했던 애 말고 다른애들을 출력해야되서 false로 만들어줌.
	// LIS 구성하지 않은 잘라야 하는애들만 true로 남음
	printf("%d\n",N-not_to_cut.size());
	for (int i=0;i<not_to_cut.size();i++)
		auaicn[not_to_cut[i]] = false;

	for (int i=1;i<=500000;i++)
		if(auaicn[i])
			printf("%d\n",i);
	return 0;
}