#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

char save[200010];
int sum[200010][30];

int main(int argc, char const *argv[])
{
	scanf("%s",save+1);
	save[0]='_';

	//printf("%d",strlen(save+1));
	int len_ = strlen(save+1);

	for (int i=0;i<len_;i++){
		// looking for i+1 th element
		for (int j=0;j<26;j++)
			sum[i+1][j] = sum[i][j];
		sum[i+1][save[i+1]-'a']++;
	}

	int Q; scanf("%d",&Q);
	while(Q--){
		char letter; scanf(" %c",&letter);
		int left,right; scanf("%d %d",&left,&right);
		printf("%d\n",sum[right+1][letter-'a']-sum[left+1-1][letter-'a']);
	}
	return 0;
}