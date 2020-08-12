#include <stdio.h>
#include <iostream>
#include <queue>
#include <unistd.h>

using namespace std;

#define DENOMINATOR (1000000007)

char save[3010][3010];
int trans[3010];
int adjust[3010];

queue<pair<int,int> > q;

vector<int> v[26];

long long res = 1;
long long fact[30];

int main(int argc, char const *argv[])
{
	int N; scanf("%d", &N);

	fact[0] = 1;
	fact[1] = 1;
	for (int i=1;i<30;i++){
		fact[i+1] = (i+1)* fact[i];
		fact[i+1] %= DENOMINATOR;
	}

	for (int i=0;i<N;i++){
		scanf(" %s",save[i+1]+1);
		trans[i+1] = i+1;
		adjust[i+1] = 1;
	}

	q.push({1,N});

	while(!q.empty()){

		pair<int,int> pos = q.front(); q.pop();
		int left = pos.first;
		int right = pos.second;


		if (left == right)
			continue;

		long long to_mult = 0;
		for (int i=left;i<=right;i++){
			int str_no = trans[i];
			char lookup = save[str_no][adjust[str_no]];
			if(lookup=='\0'){
				// leaf in Trie
				// only enter once
				to_mult++; 
				trans[left++] = str_no;
			}else{
				adjust[str_no]++;
				v[lookup-'A'].push_back(str_no);
			}
		}

		int left_cpy = left;
		// renew trans[left:right]
		for (int i=0;i<26;i++){
			if(v[i].empty())
				continue;
			to_mult++; // num_child ++
			int save_left = left_cpy;
			for (int j=0;j<v[i].size();j++)
				trans[left_cpy++] = v[i][j];
			q.push({save_left,left_cpy-1});
			v[i].clear();
		}

		res *= fact[to_mult];
		res %= DENOMINATOR;
		//printf("[%d:%d]to_mult[%2lld] res[%lld]\n",left,right,to_mult,res);
		//sleep(1);
	}
	printf("%lld\n",res);

	return 0;
}