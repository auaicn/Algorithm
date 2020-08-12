#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

char input_[500010];

int suffix_array[500010];
int prefix[500010];

int min(int x, int y){
	return x<y?x:y;
}

vector<int> v[26];

queue<pair<int,int> > q;

int main(int argc, char const *argv[])
{
	scanf("%s",input_+1);
	int N = strlen(input_+1);
	for (int i=0;i<N;i++){
		suffix_array[i+1] = i+1;
		prefix[i+1] = 0;
	}

	int s = -1;
	q.push({1,N});
	while(!q.empty()){
		
		pair<int,int> pos = q.front(); q.pop();
		int left = pos.first;
		int right = pos.second;
		if (left==right){
			continue;
		}

		if(s!=prefix[suffix_array[left]]){
			printf("\n");
			for (int i=0;i<N;i++)
				printf("%3d",suffix_array[i+1]);
			printf("\n");

			for (int i=0;i<N;i++)
				printf("%3d",prefix[suffix_array[i+1]]);
			printf("\n");
			//printf("\n");
			//printf("\n");

			s = prefix[suffix_array[left]];
		}
		//printf("[%d:%d] \n",left,right);
		int cnt_ = 0;

		// traverse suffix_array[left:right]
		for (int i=left;i<=right;i++){
			int index = suffix_array[i];
			index += prefix[suffix_array[i]];
			prefix[suffix_array[i]]++;
			if(index > N){
				suffix_array[left++] = suffix_array[i];
				continue;
				// need not to enter queue
			}
			v[input_[index]-'a'].push_back(suffix_array[i]);
		}

		// push partition
		for (int i=0;i<26;i++){
			if(v[i].empty())
				continue;
			int save = cnt_;
			for (int j=0;j<v[i].size();j++){
				printf("[%d]",v[i][j]);
				suffix_array[left + cnt_++] = v[i][j];
			}
			printf("    ");
			q.push({left+save,left+cnt_-1});
			v[i].clear();
		}
		printf("\n");

	}

	printf("\n");
	for (int i=0;i<N;i++)
		printf("%d ",prefix[suffix_array[i+1]]);


	printf("\n");
	for (int i=0;i<N;i++)
		printf("%d ",suffix_array[i+1]);
	printf("\n");

	printf("x ");
	for (int i=0;i<N-1;i++)
		printf("%d ",min(prefix[suffix_array[i+1]],prefix[suffix_array[i+2]])-1);
	printf("\n");
	return 0;
}