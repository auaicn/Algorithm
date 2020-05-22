#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int save[1010][1010];

char pattern_a[1010];
char pattern_b[1010];

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	scanf("%s",pattern_a+1);
	scanf(" %s",pattern_b+1);

	int length_a = strlen(pattern_a+1);
	int length_b = strlen(pattern_b+1);

	for (int i=0;i<length_a;i++){
		for (int j=0;j<length_b;j++){
			if(pattern_a[i+1]==pattern_b[j+1])
				save[i+1][j+1] = save[i][j]+1;
			else if (save[i][j+1]>save[i+1][j])
				save[i+1][j+1] = max(save[i][j+1],save[i+1][j]);
		}		
	}

	stack<char> s;
	while(length_a || length_b){
		if(save[length_a][length_b]==save[length_a-1][length_b-1]+1){
			s.push(pattern_a[length_a]);
			length_a--;
			length_b--;
		}else if (save[length_a][length_b-1]>save[length_a-1][length_b]){
			length_b--;
		}else
			length_a--;
	}

	printf("%d\n",save[length_a][length_b]);
	while(!s.empty()){
		char top_ = s.top(); s.pop();
		printf("%c",top_);
	}
	printf("\n");

	return 0;
}