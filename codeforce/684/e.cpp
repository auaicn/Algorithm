#include <stdio.h>
#include <iostream>

using namespace std;

int save[100010];

int main(int argc, char const *argv[])
{
	int N,Q; scanf("%d %d",&N,&Q);
	for (int i=0;i<N;i++){
		// each up to 10^9 segtree sum would exceed integer range
		scanf("%d",save[i+1]);
	}
	while(Q--){
		int cmd,x,y; scanf("%d %d %d",&cmd,&x,&y);
		if(cmd == 1){
			// update
			// if y is bigger than original a[1],a[2]....a[x] range update.
			// lazy propagation?

		}else {
			// cmd equals 2
			// 오른족으로 가면서, 최대한 많이 사용하려고 하는건데,
			// parent 가 있어서, right 에 있다면, 타고 올라가면 될듯
			// left 에 parent 가 있다면 right sibling 으로 가면 될것 같다.
			// 노드 들에는, lazy_propagated range sum 이 유지 될것인데, 현재 그만큼 먹을게 없다면, 
			// leaf 노드로 들어가야할것이다. 좌측으로 내려가면됨. top-bottom 밖에 나는 할 줄 몰라왔는데,
			// bottom up 도 할줄 알아야할것 같네. 맨 밑단에서 시작해서 한번 올라갔다가 밑으로 내려오나?
			// 그런데 밑에서부터 보면 lazy 가 불가능한거 아닌가?

		}

	}
	return 0;
}

1 x y: for each shop 1≤𝑖≤𝑥 set 𝑎𝑖=𝑚𝑎𝑥(𝑎𝑖,𝑦).
2 x y: let's consider a hungry man with 𝑦 money. He visits the shops from 𝑥-th shop to 𝑛-th and if he can buy a meal in the current shop he buys one item of it. Find how many meals he will purchase. The man can buy a meal in the shop 𝑖 if he has at least 𝑎𝑖 money, and after it his money decreases by 𝑎𝑖.
inputCopy
10 6
10 10 10 6 6 5 5 5 3 1
2 3 50
2 4 10
1 3 10
2 2 36
1 4 7
2 2 17
outputCopy
8
3
6
2