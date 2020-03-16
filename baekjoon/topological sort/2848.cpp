#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int max(int x,int y){
	return x>y?x:y;
}

bool check[30];

int indegree[30];

vector<int> v[30];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);

	char temp[20];	scanf(" %s",temp); for (int i=0;i<strlen(temp);i++){ check[temp[i]-'a']= true; }
	char next[20]; 

	bool prefix_ = false;

	while(--N){
		scanf(" %s",next);
		//printf("%s\n",temp);

		for (int i=0;i<strlen(next);i++)
			check[next[i]-'a'] = true;

		int max_ = max(strlen(next),strlen(temp));

		for (int i=0;i<max_;i++){

			// size mismatch
			// temp short
			if(i+1>strlen(temp))
				break;

			// next short
			if(i+1>strlen(next)){
				prefix_ = true;
				break;
			}
			// 이거때문에 아주아주 힘들었는데
			// next가 temp의 진 부분집합이면 자체로 불가능하기때문에 escape 해주어야한다.

			// looking for ith element 
			// temp -> next
			if(next[i]==temp[i])
				continue;
			else{
				v[temp[i]-'a'].push_back(next[i]-'a');
				indegree[next[i]-'a']++;
				break;
			}
		}

		// renew temp
		strcpy(temp,next);
	}

	if(prefix_){
		printf("!\n");
		return 0;
	}

	// check used alphabets
	int num_total_used_alphabets = 0;
	for (int i=0;i<26;i++)
		if(check[i])
			num_total_used_alphabets++;

	//printf("used alphabet : %d\n",num_total_used_alphabets);

	// solution starts
	queue<int> q;
	for (int i=0;i<26;i++)
		if(check[i]&&!indegree[i]) // using alphabet and it has inward edge
			q.push(i);

	// if queue size more than one
	// no exact sequence exists
	// case '?' ended
	bool sw = false;

	if(q.size()>1)
		sw = true;

	// case 'normal' and '!'

	vector<char> result;
	while(!q.empty()){
		int pos = q.front(); q.pop();


		if(q.size())
			sw = true;
		//printf("pos : %d\n",pos);
		result.push_back(pos+'a');
		for (int i=0;i<v[pos].size();i++){
			int next = v[pos][i];
			indegree[next]--;
			if(!indegree[next])
				q.push(next);
		}
	}

	// whether or not all alphabets checked used,
	// if there is cycle it's contradiction case ( '!' case )

	for (int i=0;i<26;i++)
			if(check[i])
				// among used alphabets
				// indegree left -> cycle detected
				if(indegree[i]!=0){
					printf("!\n");
					return 0;
				}

	// no cycle
	// if queue has ever had size more than one then no exact answer case
	if(sw)
		printf("?\n");
	else{
		for (int i=0;i<result.size();i++)
			printf("%c",result[i]);
		printf("\n");
	}

	return 0;
}