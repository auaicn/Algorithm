#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N); //1000
	int P,T; scanf("%d %d",&P,&T); // turn upto 1000만
	T %= 4*N; // now up to 4000
	bool able = false;

	// 2N 명의 사람. 휘수가 2*P - 1,  2*P 를 담당.
	// T 번째 턴에 트롤링이 가능한지 보는건데,
	// let's see range

	int left;
	int right = -1;
	int num_arm = 1;
	int arm_direction = 1;
	for (int i=0;i<T;i++){
		// do shifting
		left = right +1;
		right += num_arm;
		left %= 2*N;
		right %= 2*N;
		// printf("\n");
		// if(left<=right){
		// 	printf("p[%d] to p[%d]\n",left/2+1,right/2+1);
		// }else{
		// 	printf("p1 to p[%d] and p[%d] to p[%d]\n",right/2+1,left/2+1,N);
		// }
		// printf("[%3d-%3d]\n",left,right);
		// printf("[%3d-%3d]\n",left,right);

		// renew
		if(arm_direction){
			if (num_arm < 2*N)
				num_arm ++;
			else{
				// now 2*N
				arm_direction = 0;
				num_arm --;
			}
		}
		else{
			// reveresed
			if (num_arm > 1)
				num_arm--;
			else{
				arm_direction = 1;
				num_arm++;
			}
		}
	}

	int P1 = 2*P-2;
	int P2 = 2*P-1;

	if(left<=right){
		if(left <= P1 && P1 <= right)
			able = true;
		if(left <= P2 && P2 <= right)
			able = true;
		if(left == right)
			able = false;
		if(left + 1 == right){
			if(left == P1)
				able = false;
		}

	}else{

		if(left <= P1 || left <= P2)
			able = true;
		if(P1 <= right || P2 <= right)
			able = true;
	}


	if(able)
		printf("Dehet YeonJwaJe ^~^\n");
	else
		printf("Hing...NoJam\n");

	return 0;
}

// 문제
// 퐁당퐁당은 술게임 중 팀워크가 가장 중요한 MT 단골 게임이다. 매 차례마다 지정된 수의 팔을 동시에 들어야 하는데, 이를 실패하면 팔을 들어야했던 사람과 실수로 팔을 든 사람 모두 연좌제로 마셔야 하기 때문이다. 퐁당퐁당 게임의 규칙은 아래와 같다.

// 1번 사람부터 N번 사람까지 순서대로 총 N명의 사람들이 원 모양을 이루어 반시계방향으로 둘러앉는다. 이 때 모든 사람들은 원의 중앙을 바라보고 앉는다.
// 게임은 1번 사람의 왼팔부터 시작하여 원의 바깥에서 보았을 때 왼쪽에서 오른쪽으로 진행한다. 
// 첫 번째 차례 이후 매 차례마다 가장 오른쪽 사람이 들었던 팔의 다음 팔부터 진행하고, 순서대로 지정된 수만큼의 팔을 들어올린다.
// 게임을 시작할 때 들어야 하는 팔의 갯수는 1개이다. 시작하여 차례가 지날 때마다 들어야 하는팔의 개수는 1씩 증가한다.
// 들어야 하는 팔의 갯수가 2 × N 개가 되었다면 다음 차례부터 1씩 감소시킨다.
// 들어야 하는 팔의 갯수가 1개가 되었다면 다음 차례부터 다시 1씩 증가시킨다.
// 즉, 매 차례에 들어야 할 팔의 갯수는 1 이상 2 × N 이하로 유지된다.
// 엠티에서 퐁당퐁당 게임을 하던 휘수는 친구들이 너무 잘하는 것을 보고 재미가 없어져, 최대한 많은 사람을 먹이기 위해 자기가 해당하는 차례에 일부러 팔을 들지 않으려고 한다. 휘수는 매 차례마다 자기가 트롤을 해서 사람들과 다 같이 술을 먹을 수 있을지 알고 싶어 한다. 여러분이 휘수를 도와주자!

// 입력
// 첫 번째 줄에 게임에 참여하는 사람수 N이 정수로 주어진다. (2 ≤ N ≤ 1,000)

// 두 번째 줄에는 휘수의 위치 P와 차례 T가 정수로 주어진다. (1 ≤ P ≤ N, 1 ≤ T ≤ 10,000,000)

// 출력
// 만약 T번째 차례에 휘수가 팔을 들어야 해서, 휘수가 트롤을 성공할 수 있다면 “Dehet YeonJwaJe ^~^”을 출력하고, 휘수가 트롤을 할 수 없는 위치라면 “Hing…NoJam”을 출력한다.

// 예제 입력 1 
// 4
// 3 3
// 예제 출력 1 
// Dehet YeonJwaJe ^~^
// 이 경우에 사람이 4명이고 휘수가 3번에 위치한다. 1번 사람부터 왼팔로 시작하여 3번째 턴에서는 2번사람이 오른팔, 3번사람이 양팔을 들어야 하지만 휘수는 팔을 들지 않기 때문에 트롤에 성공한다.

// 예제 입력 2 
// 5
// 4 5
// 예제 출력 2 
// Hing...NoJam
// 이 경우에 입력 예시의 경우 사람이 5명이고 휘수는 4번에 위치한다. 5번째 턴에서 1번사람 양팔, 2번사람 양팔, 3번사람의 왼팔이 필요한데 휘수가 끼어들 수 없기 때문에 트롤에 실패한다.

