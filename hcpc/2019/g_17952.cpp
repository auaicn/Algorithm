#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int,int> > pq;

int cost[100010];
int group[100010];
int group_leftmost[100010];
int group_rightmost[100010];

int num_group;

int max(int x, int y){
	return x>y?x:y;
}

int min(int x, int y){
	return x<y?x:y;
}

int find(int x){
	if(x == group[x])
		return x;
	return group[x] = find(group[x]);
}

bool union_(int master, int slave){
	int root_x = find(slave);
	int root_y = find(master);
	if(root_x != root_y){
		group[root_x] = root_y;
		cost[root_y] += cost[root_x];
		group_leftmost[root_y] = min(group_leftmost[root_y],group_leftmost[root_x]);
		group_rightmost[root_y] = max(group_rightmost[root_y],group_rightmost[root_x]);
		return true;
	}else
		return false;
}

int main(int argc, char const *argv[])
{
	int N,K; scanf("%d %d",&N,&K);
	num_group = N;

	for (int i=0;i<N;i++){
		group_leftmost[i+1] = group_rightmost[i+1] = group[i+1] = i+1;
		int temp; scanf("%d",&temp);
		cost[i+1] = temp;
		pq.push({-temp,i+1});
	}
	int result = -1;
	while(num_group != K){
		printf("[in whild loop]\n");

		pair<int,int> top_ = pq.top(); pq.pop();
		int cost_sum = -top_.first;
		int idx = top_.second;
		int root_idx = find(idx);
		result = max(result,cost_sum);
		if(idx == root_idx){
			printf("	its root\n");

			// treated as group
			// now time to union
			int master_left = group_leftmost[root_idx] - 1;
			int master_left_group = find(master_left);
			int master_right = group_rightmost[root_idx] + 1;
			int master_right_group = find(master_right);
			int master_left_cost = cost[master_left_group];
			int master_right_cost = cost[master_right_group];
			int slave = master_left_cost > master_right_cost ? master_left_group : master_right_group;
			if(!slave)
				break;
			else{
				union_(root_idx,slave);
				pq.push({-cost[root_idx],root_idx});
				num_group--;
			}

		}else{
			// just pop
			// slave already in some group.
			// it's first value does not represent group anymore
			continue;
		}

	}
	for (int i=0;i<N;i++){
		printf("%3d",find(i+1));
	}
	printf("\n");
	// 순서 바뀐 시험지, 순서대로 내야됨
	// 조교인 주찬이가 하번의 기회를 줌
	// 현재 순서 그대로, 그룹으로 나누어서 각각 그룹에서 맞은 문제 개수의 합을 구해석 그중 최솟값 만을 시험점수로
	// min(partition 1, partiton 2 ...)
	// 받을수 있는 최대 점수는?
	// 파티션을 자ㅏㄹ 해야겠네

	// N K 시험지 개수, 그룹의수 시험지 : 10만 
	// 각시험지 마다 맞은 문제의 개수
	// 8 2
	// 12 7 19 20 17 14 9 10
	// 12 7 19 20				합 58
	// 17 14 9 10 으로 나누면		합 50
	// 맞은 문제 개수의 합의 최소는 50 이라는데
	// 밸런싱 문제인듯
	// i to j 
	// 순서대로 제출하는건 필요없어졌네.
	// K 를 주네. 무조건 그 개수로 나눠야 하는거. 엄청 크게 나눌 수도 있음. linear한 순서는 현재에서, 지켜져야함.

	// 최소인 group 이 있으면, 걔의 좌우를 봐주는게 최선일 것 같은데 일단 예시를 돌려보자면

	printf("%d\n",result);
	return 0;
}


// 넓은 시험 범위와 어려운 과제로 유명한 '운영체제로 보는 데이터베이스시스템 알고리즘' 수업은 시험지가 너무 많아 실내에서는 시험을 치를 수 없어서 야외에서 시험을 진행한다. 해당 수업의 수강생인 현수는 오랜 시간에 걸쳐 풀 수 있는 모든 문제를 풀었고 제출만을 남겨두고 있었다. 그러나 갑자기 불어오는 강풍에 현수의 시험지가 모두 날아가 버렸고, 날아간 시험지를 줍는 동안 남은 시간을 다 써버리고 말았다.

// 시험지에 명시된 규칙 중에는 채점하는 조교의 편의를 위해 시험지를 반드시 순서대로 제출하라는 규칙이 있는데, 이 규칙 때문에 현수는 힘들게 치른 시험이 0점 처리될 위기에 빠지게 되었다!

// 그러나, 마음씨 좋은 조교인 주찬이는 평소 수업에 열심히 참여한 현수에게 한 번의 기회를 주기로 했다. 규칙은 규칙이므로 많은 점수를 줄 수는 없고, 시험지를 현재 순서 그대로 K개의 그룹으로 나눈 뒤 각각의 그룹에서 맞은 문제 개수의 합을 구하여 그 중 최솟값을 시험 점수로 하기로 하였다. 현수가 이번 시험에서 받을 수 있는 최대 점수를 계산하는 프로그램을 작성하자.

// 현수는 모르는 문제를 아예 풀지 않기 때문에 현수가 푼 문제는 모두 맞았다고 생각할 수 있으며, 조교는 마음씨가 좋아서 자신이 줄 수 있는 최대한의 점수를 준다.

// 입력
// 첫 번째 줄에 시험지의 개수 N과 시험지를 나눌 그룹의 수 K가 정수로 주어진다. (1 ≤ K ≤ N ≤ 105)

// 두 번째 줄에 각 시험지마다 맞은 문제의 개수 x가 정수로 주어진다 (0 ≤ x ≤ 20)

// 출력
// 현수가 받을 수 있는 최대 점수를 출력한다.

// 예제 입력 1 
// 8 2
// 12 7 19 20 17 14 9 10
// 예제 출력 1 
// 50
// 시험지를 12, 7, 19, 20과 17, 14, 9, 10 으로 나누면 맞은 문제 개수의 합의 최소는 50이다.

