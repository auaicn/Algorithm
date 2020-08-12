#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class segtree{
public:
	vector<ll> tree;
	int size;

	// 생성자
	segtree(int N){
		// 입력받은 N 으로부터 필요한 size 를 구한다.
		// tree vector, 사실상 array 인데, 이 크기는 "N 미만의 가장 큰 2의 제곱수" 의 2배가 된다.
		// 한번더 두배해줘야 할 것 같은 느낌인데
		for (size = 1; size < N; size *= 2)
			tree.resize(4*size);
		// printf("tree size [%lu]\n",tree.size());
		// printf("size [%d]\n",size);
	}

	// update 함수
	void update(int pos, ll value){
		int index = size + pos - 1;
		int diff = value - tree[index];

		while(index){
			tree[index] += diff;
			index /= 2;
		}
	}

	// get range sum with idx [left:right+1]
	ll getsum(int pos, int left, int right, int start, int end){
		if(right < start || end < left)
			return 0L;
		else if (left <= start && end <= right)
			return tree[pos];
		else{
			int mid = (start + end) / 2;
			return getsum(pos*2, left, right, start, mid) + getsum(pos*2+1, left, right, mid+1, end);
		}
	}
};


int main(int argc, char const *argv[])
{
	int N,M,K; scanf("%d %d %d",&N,&M,&K);
	//segtree my_segtree = segtree(N);
	segtree my_segtree(N);

	/*
	vector<ll>::iterator it = my_segtree.tree.begin();
	for (;it!=my_segtree.tree.end();it++){
		printf("%4lld",*it);
	}
	*/

	for (int i=0;i<N;i++){
		ll temp; scanf("%lld",&temp);
		my_segtree.tree[i + my_segtree.size] = temp;
	}
	for (int i=my_segtree.size-1;i>0;i--)
		my_segtree.tree[i] = my_segtree.tree[i*2] + my_segtree.tree[i*2+1];
	

	for (int i=0;i<M+K;i++){
		int cmd; scanf("%d",&cmd);
		if(cmd == 1){
			// change
			int pos; ll value; scanf("%d %lld",&pos,&value);
			my_segtree.update(pos,value);

		}else{
			int left,right; scanf("%d %d",&left,&right);
			printf("%lld\n",my_segtree.getsum(1, left, right, 1, my_segtree.size));
		}
	

	}

	return 0;
}















