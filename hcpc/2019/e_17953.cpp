#include <stdio.h>
#include <iostream>

using namespace std;

int board[110][100010];

int result[110][2];

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	// one des one day
	// satisfaction
	// dessert plan
	// 계속 먹으면 질림
	// 전날먹은거 먹으면 만족감 절반

	// 디저트 종류 10개 M
	// 디저트마다 j (N개) 번째날에 먹으면 얻는 만족감 
	// 날의 수 10만 N

	// N,M
	// N * M
	int N,M; scanf("%d %d",&N,&M);
	for (int i=0;i<M;i++)
		for (int j=0;j<N;j++)
			scanf("%d",&board[i+1][j+1]);
	// for (int i=0;i<M;i++){
	// 	for (int j=0;j<N;j++)
	// 		printf("%3d",board[i+1][j+1]);
	// 	printf("\n");
	// }

	for (int i=0;i<N;i++){
		// i + 1th day
		int today = (i+1)%2;
		int yesterday = i%2;

		for (int j=0;j<M;j++){
			// j + 1 eaten today
			if(i == 0){
				result[j+1][today] = board[j+1][i+1];
				continue;
			}

			result[j+1][today] = 0;
			for (int k = 0; k < M; k++){
				// previous day, k + 1 eaten
				if(k!=j)
					result[j+1][today]  = max(result[j+1][today], result[k+1][yesterday] + board[j+1][i+1]);
				else
					result[j+1][today]  = max(result[j+1][today], result[k+1][yesterday] + board[j+1][i+1] / 2);
			}
		}

		// for (int j=0;j<M;j++)
		// 	printf("%d\n",result[j+1][today]);
		// printf("\n");
	}
	int max_ = 0;
	for (int i = 0; i < M; i++)
		max_ = max(max_,result[i+1][N%2]);
	printf("%d\n",max_);
	return 0;
}

// 창호는 매일 점심마다 디저트를 먹는다. 그런데 같은 디저트라도 매일 느끼는 맛이 달라진다. 어떤 날에는 마카롱을 먹고 매우 행복함을 느끼는 반면 어떤 날에는 ‘차라리 케이크를 먹는게 나았지 않았을까’ 하는 식이다. 이럴 때 케이크를 다시 먹으면 좋겠지만, 창호는 건강을 위해 디저트는 하루에 한 가지만 먹기로 정해 놓았다. 어느 날 창호는 이런 ‘만족감’에 패턴이 있는 것을 알아냈다. 특정 주기마다 n번째 날에 먹는 특정 디저트의 만족감이 정해져 있는 것이다. 창호는 이 사실을 알아내고 최고의 만족감을 느낄 수 있도록 디저트 계획을 짜기 시작했다. 하지만 문제가 하나 있다. 아무리 맛있는 것이라도 계속해서 먹으면 질리게 마련이다. 따라서 디저트를 먹을 때 전날에 먹었던 것과 같은 것을 먹으면 만족감이 반으로 감소한다.

//  	1번째 날	2번째 날	3번째 날
// 마카롱	2	6	7
// 케이크	3	8	5
// 만약 만족감의 패턴이 위와 같다면, 3일 내내 케이크를 먹었을 때의 만족감은 3 + (8 / 2) + (5 / 2) = 9이고, (각 만족도의 소수점 아래는 버린다.) 가장 큰 만족감을 얻을 수 있는 조합은 마카롱-케이크-마카롱으로 2 + 8 + 7 = 17이다.

// 이러한 패턴이 주어졌을 때, 창호의 만족감의 최댓값을 찾아주자.

// 입력
// 첫 번째 줄에 한 주기의 날짜 수 N (1 ≤ N ≤ 100,000), 디저트 종류의 수 M(1 ≤ M ≤ 10)이 정수로 주어진다.

// 두 번째 줄부터 M개의 줄에 N개의 자연수 Vij (0 ≤ Vij ≤ 100)가 주어진다.

// j (2 ≤ j ≤ M + 1)번째 줄의 i (1 ≤ i ≤ N)번째 자연수 Vij는 i번째 날에 (j – 1)번째 디저트의 만족감을 나타낸다.

// 출력
// 한 주기마다 얻을 수 있는 만족감의 최댓값을 출력한다.

// 단, 각 주기의 첫 날의 만족감은 이전 주기의 마지막 날에 영향을 받지 않으며, 하루에 한 가지의 디저트는 반드시 먹는다.

// 예제 입력 1 
// 3 2
// 2 6 7
// 3 8 5
// 예제 출력 1 
// 17
// 1-2-1 순으로 2 + 8 + 7 = 17이 최댓값이 된다.

// 예제 입력 2 
// 4 3
// 8 12 3 8
// 1 2 6 10
// 1 5 4 5
// 예제 출력 2 
// 28
// 1-1-2-1 순으로 8 + (12 / 2) + 6 + 8 = 28이 최댓값이 된다.
