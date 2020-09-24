#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ONE (33)
#define ANOTHER (44)

long long result;

long long distance(long long x, long long y){
	return x>y?x-y:y-x;
}

long long max(long long x, long long y){
	return x>y?x:y;
}

long long min(long long x, long long y){
	return x<y?x:y;
}

vector<long long> one;
vector<long long> another;
vector<pair<long long, long long> > part;

int main(int argc, char const *argv[])
{

    setbuf(stdout, NULL);

	int T; scanf("%d",&T);
	for(int testcase = 0; testcase < T; testcase++)
	{
		// printf("Case #%d\n",testcase + 1);

		// initialization
		result = 0L;
		one.clear();
		another.clear();
		part.clear();

		// scan
		int N; scanf("%d",&N);
		for (int i=0;i<N;i++){
			long long temp; scanf("%lld",&temp);
			one.push_back(temp);
		}

		for (int i=0;i<N;i++){
			long long temp; scanf("%lld",&temp);
			another.push_back(temp);
		}

		sort(one.begin(),one.end());
		sort(another.begin(),another.end());

		// printf("vector 'one'\n");
		for (int i=0;i<one.size();i++){
			// printf("%lld ",one[i]);
		}
		// printf("\n");

		// printf("vector 'another'\n");
		for (int i=0;i<another.size();i++){
			// printf("%lld ",another[i]);
		}
		// printf("\n");

		for (int i=0;i<N;i++){
			result += distance(one[i],another[i]);
		}

		// printf("initial result : %lld\n",result);

		int turn = ONE;
		int idx = 0;
		long long min_value;
		long long max_value;
		bool during = false;

		// while(idx != N - 1)
		while(idx < N)
		{
			// pick small one
			if(one[idx] < another[idx])
				turn = ONE; // one is picked
			else
				turn = ANOTHER;

			if(during == false){
				min_value = min(one[idx],another[idx]);
				max_value = max(one[idx],another[idx]); // need not maybe
				during = true;
			}

			// printf("min_value so far %lld\n", min_value);
			// printf("max_value so far %lld\n", max_value);
			int indexLb = -1;

			// printf("%s\n",turn == ONE ? "one" : "another");

			switch(turn){
				case ONE:
					// one 이 smaller
					// another 을가지고, lowerbound 를 one 에서 돌린다.
					while(true){
						// printf("index LB : %d\n",indexLb);
						// printf("idx : %d\n",idx);
						max_value = another[idx];
						indexLb = upper_bound(one.begin(),one.end(),another[idx]) - one.begin() - 1;
						// printf("%s\n",turn == ONE ? "one" : "another");
						// printf("calculated index is %d\n",indexLb);
						if(indexLb == idx)
							break;
						else if(indexLb == idx + 1 && another[idx] == one[idx + 1]){
							// printf("auaicn\n");
							idx ++;
						}
						else
							idx = indexLb;

					}
					idx++;
					// printf("something to push\n");
					part.push_back({min_value, max_value});
					during = false;
					break;
					
				case ANOTHER:
					while(true){
						max_value = one[idx];
						indexLb = upper_bound(another.begin(),another.end(),one[idx]) - another.begin() - 1;
						// printf("calculated index is %d\n",indexLb);
						if(indexLb == idx)
							break;
						else if(indexLb == idx + 1 && one[idx] == another[idx + 1]){
							// printf("auaicn\n");
							idx ++;
						}
						else 
							idx = indexLb;
					}
					idx++;
					// printf("something to push\n");
					part.push_back({min_value, max_value});
					during = false;
					break;
			}
		}

		// printf("PARTITION\n");
		for (int i=0;i<part.size();i++){
			printf("[%lld,%lld]\n",part[i].first,part[i].second);
		}

		long long loss = 0; // loss 얘는 커야함.
		for (int i=0;i<part.size()-1;i++){
			// long long check = (part[i+1].second - part[i].first) - 2 * (part[i+1].first - part[i].second);
			// printf("check : %lld\n",check);
			loss = max(loss, (part[i+1].second - part[i].first) - 2 * (part[i+1].first - part[i].second));
		}

		// printf("loss : %lld",loss);
		printf("Case #%d\n",testcase + 1);
		printf("%lld\n",result - loss);
		// printf("%lld\n",result);
	}
	/* code */
	return 0;
}




















