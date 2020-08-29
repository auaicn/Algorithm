#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX_TEXT_LENGTH (100010)
#define MAX_PATTERN_LENGTH (10010)
#define MAX_NUMBER_OF_PATTERNS (510)

char text[MAX_TEXT_LENGTH];
char patterns[MAX_NUMBER_OF_PATTERNS][MAX_PATTERN_LENGTH]; // 5 * 10E6 -> 20 MB
int lengthPatterns[MAX_NUMBER_OF_PATTERNS];

int lengthText;
int dp[MAX_TEXT_LENGTH];

vector<short> v[MAX_TEXT_LENGTH]; // Amorizely, 500 * 10 E 5 -> 5 * 10 E 7 5천만 -> 200MB

int max(int x, int y){
	return x>y?x:y;
}

int failure[MAX_PATTERN_LENGTH];

int main(int argc, char const *argv[])
{

	fgets(text + 1, MAX_TEXT_LENGTH, stdin);
	lengthText = strlen(text + 1) - 1;
	text[lengthText + 1] = '\0';

	int N; scanf("%d",&N);
	char temp; scanf("%c",&temp); // remove newline character

	for (int i=0;i<N;i++)
	{
		fgets(patterns[i+1] + 1,MAX_PATTERN_LENGTH,stdin);
		lengthPatterns[i+1] = strlen(patterns[i+1]+1) - 1;
		patterns[i+1][lengthPatterns[i+1] + 1] = '\0';
	}

	for (int idxPattern=0; idxPattern<N; idxPattern++)
	{
		// get failure
		int i = 0;
		for (int idx = 2; idx <= lengthPatterns[idxPattern + 1]; idx ++)
		{
			failure[idx] = 0;
			while(i && patterns[idxPattern + 1][i + 1] != patterns[idxPattern + 1][idx]) i = failure[i];
			if (patterns[idxPattern + 1][i + 1] == patterns[idxPattern + 1][idx]) i++;
			failure[idx] = i;
		}

		i = 0;
		for (int idx = 1; idx <= lengthText; idx++)
		{
			while(i && patterns[idxPattern + 1][i + 1] != text[idx]) i = failure[i];
			if (patterns[idxPattern + 1][i + 1] == text[idx]) i++;
			if (i == lengthPatterns[idxPattern + 1])
			{
				v[idx - (lengthPatterns[idxPattern + 1] - 1)].push_back(idxPattern + 1); // 패턴 번호를 넣어주자.
				i = failure[i];
			}
		}
	}

	int result = -1;
	for (int indexStart = lengthText; indexStart > 0; indexStart--)
	{
		dp[indexStart] = dp[indexStart + 1];
		for (int i=0;i<v[indexStart].size();i++)
		{
			int patternNumber = v[indexStart][i]; // pattern Number itself
			int indexEnd = indexStart + lengthPatterns[patternNumber] - 1;
			dp[indexStart] = max(dp[indexStart], dp[indexEnd + 1] + (indexEnd - indexStart + 1));
		}
		result = max(result,dp[indexStart]);
	}

	printf("%d\n",result);
	return 0;
}










































