#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class fenwick{
public:
	vector<ll> tree;
	vector<ll> numbers;
	int size;
	fenwick(int N){
		for(size = 1; size < N; size *= 2);
		tree.resize(size+1);
		numbers.resize(size+1);
	}

	void update(int pos, ll value){
		long long diff = value - numbers[pos];
		numbers[pos] = value;

		while(pos <= size)
		{
			tree[pos] += diff;
			pos += (pos&(-pos));
		}
	}

	ll sum(int right){
		ll ret = 0;
		while(right){
			ret += tree[right];
			right -= (right&(-right));
		}
		return ret;
	}

	ll range_sum(int left, int right){
		return sum(right) - sum(left-1);
	}

};

int main(int argc, char const *argv[])
{
	int N,M,K; scanf("%d %d %d",&N,&M,&K);
	fenwick my_fenwick(N);
	for (int i=0;i<N;i++){
		long long temp; scanf("%lld",&temp);
		my_fenwick.update(i+1,temp);
	}
	for (int i=0;i<M+K;i++){
		int cmd; scanf("%d",&cmd);
		if(cmd == 1){
			// change
			int pos; long long value; scanf("%d %lld",&pos,&value);
			my_fenwick.update(pos,value);
		}else{
			// get range sum
			int left,right; scanf("%d %d",&left,&right);
			printf("%lld\n",my_fenwick.range_sum(left,right));
		}
	}

	return 0;
}