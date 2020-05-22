#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char save[210];
char save2[210];

int lcs[210][210];

int main(int argc, char const *argv[])
{
	while(!feof(stdin)){
		scanf(" %s",save+1);
		if(feof(stdin))
			return 0;
		scanf(" %s",save2+1);
		int len_1 = strlen(save+1);
		int len_2 = strlen(save2+1);

		for (int i=0;i<200;i++)
			for (int j=0;j<200;j++)
				lcs[i+1][j+1] = 0;

		for (int i = 0; i < len_1; ++i){
			for (int j = 0; j < len_2; ++j){
				if (save[i+1]==save2[j+1])
					lcs[i+1][j+1] = lcs[i][j]+1;
				else
					lcs[i+1][j+1] = max(lcs[i+1][j],lcs[i][j+1]);
			}
		}
		printf("%d\n",lcs[len_1][len_2]);
	}
	return 0;
}