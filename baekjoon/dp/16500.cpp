#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

char sentence[110];
char pattern[110][110];
int able[110];

int lengthSentence;
int lengthPattern[110];

int main(int argc, char const *argv[])
{
	scanf("%s",sentence+1);
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf(" %s",pattern[i+1]+1);

	lengthSentence = strlen(sentence+1);
	for (int i=0;i<N;i++)
		lengthPattern[i+1] = strlen(pattern[i+1]+1);

	able[0] = 1;

	for (int i=1;i<=lengthSentence;i++){

		for (int j=1;j<=N;j++){
			if(lengthPattern[j]>i)
				continue;
			if(able[i-lengthPattern[j]]){
				bool same = true;
				for (int k=1;k<=lengthPattern[j];k++){
					if (pattern[j][k]!= sentence[i-lengthPattern[j]+k]){
						same = false;
						break;
					}
				}
				if(same){
					able[i] = true;
					break;
				}
			}

		}

	}

	printf("%d\n",able[lengthSentence]);
	return 0;
}
