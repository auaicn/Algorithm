#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int max(int x,int y){
	return x>y?x:y;
}

char save[110];
char save2[110];
char save3[110];

int res[110][110][110];

int main(int argc, char const *argv[])
{
	scanf(" %s",save+1);
	scanf(" %s",save2+1);
	scanf(" %s",save3+1);

	int len_1 = strlen(save+1);
	int len_2 = strlen(save2+1);
	int len_3 = strlen(save3+1);

	for (int i=0;i<len_1;i++){
		for (int j=0;j<len_2;j++){
			for (int k=0;k<len_3;k++){
				if(save[i+1]==save2[j+1]&&save2[j+1]==save3[k+1])
					res[i+1][j+1][k+1] = res[i][j][k] +1;
				else
					res[i+1][j+1][k+1] = max(res[i+1][j+1][k],max(res[i][j+1][k+1],res[i+1][j][k+1]));
			}	
		}
	}
	printf("%d\n",res[len_1][len_2][len_3]);
	return 0;
}