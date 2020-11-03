#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int,int> > v[100010];
int board[100010];
// 노드 10만
// 에지 최대 10만
priority_queue<pair<int,int> > pq;
bool visit[100010];

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{

	int result = -1;
	int N,M; scanf("%d %d",&N,&M);

	for (int i=0;i<N;i++){
		int temp; scanf("%d",&temp);
		board[i+1] = temp;
		pq.push({-board[i+1],i+1});
	}

	int R; scanf("%d",&R);
	while(R--){
		int left,right,weight; scanf("%d %d %d",&left,&right,&weight);
		v[left].push_back({right,weight});
	}

	while(M--){

		// extract min
		pair<int,int> top_ = pq.top(); pq.pop();
 		int weight = -top_.first;
		int now = top_.second;

		// visitied then pass
		// restore M
		if(visit[now]){
			M++;
			continue;
		}

		// check
		// printf("now[%2d] weight[%3d]\n",now,weight);

		// check visit
		visit[now] = true;

		// renew result
		result = max(result,weight);

		// propagation
		for (int i=0;i<v[now].size();i++){
			// for each edge
			pair<int,int> temp = v[now][i];
			int next = temp.first;
			int loss = temp.second;

			// decrease neighbor
			board[next] -= loss;

			// not visited yet then push
			if(!visit[next])
				pq.push({-board[next],next});
		}

	}
	printf("%d\n",result);
	// 최소한의 시간투자
	// 최소한 M개의 알고리즘을 배우려고함
	// 그때의 공부량은?

	// 4 3 4개의 알고리즘 3개를 배우려고함
	// 18 20 77 82 의 시간이 필요함
	// 3개의 
	// 1 3 60 1을 배우면 3배우는데 60만큼 낮춤. 1배우면 3이 77->17 되는것
	// 1 4 3
	// 3 4 60
	// result : 19
	return 0;
}


// 문제
// 늘 돈이 부족한 희정이는 HCPC에 참가하여 좋은 성적을 거두어서 상금을 타기로 마음먹었다. 이를 위해 먼저 출제위원장인 정호의 노트북을 해킹하여 N개의 알고리즘을 출제 범위로 두고 문제가 출제된다는 사실을 알게 되었다. 출제 범위를 알았으니 이제 희정이에게 남은 것은 알고리즘을 공부하는 것이다. 알고리즘 공부에는 사실 특별한 규칙이 숨어있는데 이는 다음과 같다.

// 각 알고리즘들을 처음 배울 때에는 Ki만큼의 알고리즘 공부량이 필요하다. 그리고 몇몇 알고리즘은 서로 연관성이 있어 어느 한 알고리즘을 배우면 다른 특정한 알고리즘을 배울 때 필요한 공부량이 줄어드는 경우가 있다. 한 알고리즘을 배울 때 필요한 공부량이 여러 개의 다른 알고리즘에 의해서 줄어드는 경우는 그 감소량을 모두 합산해서 적용한다. 또한 알고리즘 공부량은 소모되지 않으며 누적된다. 예시로 처음 배울 때 3의 공부량이 필요한 알고리즘과 5의 공부량이 필요한 알고리즘을 모두 배우기 위해선 그 둘의 합 8이 아니라 그 둘의 최대값 5의 공부량이 필요하다.

// 그러나 막상 알고리즘 공부를 하려고 보니 벌써부터 중간고사가 닥쳐오고 있었기 때문에 모든 알고리즘을 배우기에는 시간이 부족했다. 희정이는 결국 최소한의 시간을 투자해 최소한 M개의 알고리즘만이라도 공부하기로 결심했다. 당신이 할 일은 알고리즘을 처음 배우는데 필요한 공부량과 각 알고리즘 사이의 연관성이 주어졌을 때, 최소 M개의 알고리즘 배우는데 필요한 알고리즘 공부량을 구하는 것이다.

// 입력
// 첫째 줄에는 출제 범위인 알고리즘의 개수를 나타내는 양의 정수 N, 최소한 배우고자 하는 알고리즘의 개수를 나타내는 양의 정수 M이 주어진다. ( 1 ≤ M ≤ N ≤ 100,000 )

// 둘째줄에는 각 알고리즘을 처음 배우는데 필요한 알고리즘 공부량을 나타내는 N개의 양의 정수 Ki가 사이에 공백을 두고 주어진다. (1 ≤ Ki ≤ 108)

// 셋째줄에는 서로 연관성이 있는 알고리즘 관계의 개수를 나타내는 양의 정수 R이 주어진다. ( 0 ≤ R ≤ 100,000 )

// 다음 K줄에 걸쳐서, 각 줄에 A, B, D가 주어지며 이는 A번 알고리즘을 배우면 B번 알고리즘을 배우는데 필요한 공부양이 D만큼 줄어듦을 의미한다. (1 ≤ A, B ≤ N, 1 ≤ D ≤ 108)

// A와 B의 쌍이 같은 관계가 여러 번 주어지지 않으며, A = B인 관계는 주어지지 않는다. 또한, 공부양이 아무리 줄어도 0 이하로 내려가지 않음이 보장된다.

// 출력
// 최소 M개의 알고리즘을 익히기 위해서 필요한 최소 알고리즘 공부량을 출력하여라.

// 예제 입력 1 
// 4 3
// 18 20 77 82
// 3
// 1 3 60
// 1 4 3
// 3 4 60
// 예제 출력 1 
// 19
// 1번 알고리즘을 공부하게 되면, 3번 알고리즘을 공부하는데 필요한 공부량이 17로, 4번 알고리즘을 공부하는데 필요한 공부량이 79로 줄게 된다. 또 이렇게 줄어든 3번 알고리즘을 공부하게 되면, 4번 알고리즘을 공부하는데 필요한 공부량이 19로 줄게 된다. 따라서 최소 3개의 알고리즘을 배우기 위해서 필요한 최소한의 공부량은 19이다.

