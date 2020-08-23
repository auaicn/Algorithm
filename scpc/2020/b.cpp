#include <stdio.h>
#include <iostream>

#define Initial_value (-1)
#define null_state (99)
#define win_state (97)
#define lose_state (12)

using namespace std;

int board[3010][3010];
int x_numbers[3010];
int y_numbers[3010];

int num_win_state;
int num_lose_state;

int main(int argc, char const *argv[])
{
	setbuf(stdout, NULL);

	int T; scanf("%d",&T);
	for(int t = 0; t < T; t++)
	{

		num_win_state = num_lose_state = 0;

		int N,K; scanf("%d %d",&N,&K);
		for (int i=0;i<N;i++)
			scanf("%d",&x_numbers[i]);
			// scanf("%d",&x_numbers[i+1]);
		for (int i=0;i<N;i++)
			scanf("%d",&y_numbers[i]);
			// scanf("%d",&y_numbers[i+1]);

		for (int i=-1;i<N;i++)
			for(int j=-1;j<N;j++)
				board[i+1][j+1] = Initial_value;

		board[0][0] = win_state; num_win_state ++;

		for (int i=-1;i<N;i++)
		{
			for (int j=-1;j<N;j++)
			{
				if (board[i+1][j+1] != Initial_value)
					continue;
				
				// if (i == -1 && j == -1)
				// 	continue;

				// looking for i+1, j+1 th element
				// 필승법이 있는지 하나라도 있는지 checking.
				bool must_win = false;
				bool must_lose = true;

				// printf("At [%d][%d]\n",i+1,j+1);

				// 위에를 본다. x 축 기준
				for (int lookup_idx = i, K_cpy = K - x_numbers[lookup_idx]; lookup_idx >= 0 && K_cpy >= 0;lookup_idx--, K_cpy -= x_numbers[lookup_idx])
				{
					int lookup_state = board[lookup_idx][j+1];
					if(lookup_state == lose_state)
					{
						must_win = true;
						break;
					}else if(lookup_state == null_state)
					{
						must_lose = false;
					}
				}

				if(must_win){
					board[i+1][j+1] = win_state;
					num_win_state++;
					// break;
					continue;
				}

				// 왼쪽을 본다.
				for (int lookup_idx = j, K_cpy = K - y_numbers[lookup_idx]; lookup_idx >= 0 && K_cpy >= 0; lookup_idx--, K_cpy -= y_numbers[lookup_idx])
				{
					int lookup_state = board[i+1][lookup_idx];
					if(lookup_state == lose_state)
					{
						must_win = true;
						break;
					}else if(lookup_state == null_state)
					{
						must_lose = false;
					}
				}

				// 필승법이 하나라도 있었는지,
				// 즉 움직일 수 있는 칸중에, 상대방이 무조건 지는 상황이 하나라도 있는지.
				if(must_win){
					board[i+1][j+1] = win_state;
					num_win_state++;
					// break;
					continue;
				}

				//전부다, 애매한 상황없이 상대방이 모두 이기기만하는 경우였을때.
				if(must_lose)
				{
					board[i+1][j+1] = lose_state;
					num_lose_state++;
					// LOSE 판정이 나면, 전파를 해줄 수 있겠다.

					// printf("down\n");
					// 아래로 전파
					for (int lookup_idx = i+2, K_cpy = K - x_numbers[lookup_idx-1]; lookup_idx <= N && K_cpy >= 0; K_cpy -= x_numbers[lookup_idx], lookup_idx++)
					{
						// printf("Bypassing [%d][%d], K : %d\n",lookup_idx,j+1,K_cpy);
						if(board[lookup_idx][j+1] != Initial_value)
							continue;
						board[lookup_idx][j+1] = win_state;
						num_win_state++;
					}

					// printf("to the right\n");
					// 우로 전퍼
					for (int lookup_idx = j+2, K_cpy = K - y_numbers[lookup_idx-1]; lookup_idx <= N && K_cpy >= 0; K_cpy -= y_numbers[lookup_idx],lookup_idx++)
					{
						// printf("Bypassing [%d][%d], K : %d\n",i+1,lookup_idx,K_cpy);
						if(board[i+1][lookup_idx] != Initial_value)
							continue;
						board[i+1][lookup_idx] = win_state;
						num_win_state++;
					}
					// break;
					continue;
				}

				// 이도 저도 아닌 경우
				// initial 값은 벗겨주자.
				board[i+1][j+1] = null_state;
				// never called

			}
		}

		// #define Initial_value (-1)
		// #define null_state (99)
		// #define win_state (97)
		// #define lose_state (12)

		// for (int i=-1;i<N;i++){
		// 	for(int j=-1;j<N;j++)
		// 	{
		// 		switch(board[i+1][j+1])
		// 		{
		// 			case Initial_value:
		// 				printf("%2c",'I');
		// 				break;

		// 			case null_state:
		// 				printf("%2c",'N');
		// 				break;

		// 			case win_state:
		// 				printf("%2c",'W');
		// 				break;

		// 			case lose_state:
		// 				printf("%2c",'L');
		// 				break;
		// 		}
		// 	}
		// 	printf("\n");
		// }

		printf("Case #%d\n",t+1);
		printf("%d %d\n",num_win_state,num_lose_state);
	}
	return 0;
}




// 2
// 2 3
// 3 3
// 3 3
// 2 3
// 1 2
// 1 2
// 출력
// Case #1
// 5 4
// Case #2
// 6 3