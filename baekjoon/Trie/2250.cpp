#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define LEFT (0)
#define RIGHT (1)

int save[10010][2];
int assigned[10010];

int assign_cnt;
void assign(int now){
	if(now == -1)
		return;
	assign(save[now][LEFT]);
	assigned[now] = ++assign_cnt;
	assign(save[now][RIGHT]);

}

int min(int x, int y){
	return x<y?x:y;
}

int max(int x, int y){
	return x>y?x:y;
}


bool referenced_as_child[10010];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++)
		referenced_as_child[i+1] = false;

	for (int i=0;i<N;i++){
		int parent; scanf("%d",&parent);
		int left,right; scanf("%d %d",&left,&right);
		save[parent][LEFT] = left;
		save[parent][RIGHT] = right;
		referenced_as_child[left] = true;
		referenced_as_child[right] = true;
	}

	int root;
	for (int i=0;i<N;i++)
		if(!referenced_as_child[i+1])
			root = i+1;
	assign(root);
	
	int max_level = 1;
	int max_width = 0;

	queue<int> q;
	vector<int> temp;
	q.push(root);
	for (int lev = 1;;lev++){

		int min_ = 1987654321;
		int max_ = -1;
		while(!q.empty()){
			int pos = q.front(); q.pop();
			int left = save[pos][LEFT];
			int right = save[pos][RIGHT];
			if(left!=-1)
				temp.push_back(left);
			if(right!=-1)
				temp.push_back(right);
			min_ = min(min_,assigned[pos]);
			max_ = max(max_,assigned[pos]);

		}
		int width = max_-min_+1;
		if(width>max_width){
			max_level = lev;
			max_width = width;
		}
		
		if(temp.empty())
			break;
		for (int i=0;i<temp.size();i++){
			//printf("%d ",temp[i]);
			q.push(temp[i]);
		}
		//printf("\n");
		temp.clear();
	}
	printf("%d %d\n",max_level,max_width);
	return 0;
}
/*
예제 입력 1 
19
1 2 3
2 4 5
3 6 7
4 8 -1
5 9 10
6 11 12
7 13 -1
8 -1 -1
9 14 15
10 -1 -1
11 16 -1
12 -1 -1
13 17 -1
14 -1 -1
15 18 -1
16 -1 -1
17 -1 19
18 -1 -1
19 -1 -1
예제 출력 1 
3 18
*/