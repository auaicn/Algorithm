#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

#define MAX_TEXT_SIZE (1000010)
#define MAX_PATTERN_SIZE (1000010)

vector<int> result;

char textString[MAX_TEXT_SIZE];
char patternString[MAX_PATTERN_SIZE];

int failure[MAX_PATTERN_SIZE];

int main(int argc, char const *argv[])
{
	
	// cin.tie(NULL);

 	fgets(textString + 1, MAX_TEXT_SIZE, stdin);
 	fgets(patternString + 1, MAX_PATTERN_SIZE, stdin);

 	int lengthText = strlen(textString + 1) - 1;
 	int lengthPattern = strlen(patternString + 1) - 1;

 	textString[lengthText + 1] = '\0';
 	patternString[lengthPattern + 1] = '\0';

 	// make failure function
	// 공백을 문자로 인정한다는데, pattern 이나 text 둘다에 들어올것. 그냥 같은지 확인하는거니까 생각안해도 될듯.
	int i = 0;
	// failure[1] = 0; 1 to 1 은 원래 1인것 같지만, KMP 알고리즘에서는 0이라고 하고 풀더라.
	for (int j = 2; j <= lengthPattern;j++)
	{
		while(i && patternString[j] != patternString[i+1]) i = failure[i];
		if(patternString[j] == patternString[i+1]) i++;
		failure[j] = i;
	}

	// for (int i=0;i<lengthPattern;i++)
	// 	printf("%3d",failure[i+1]);
	// printf("\n");


	// KMP algorithm
	i = 0;
	for (int textIndex = 1; textIndex <= lengthText; textIndex++)
	{
		while(i && textString[textIndex] != patternString[i+1]) i = failure[i];
		if(textString[textIndex] == patternString[i+1]) i++;
		if(i == lengthPattern)
		{
			// Found
			// 이제와서 찾은거긴한데, 마지막이 같은거니까, 시작 index 는 textIndex 에다가 (patternLength - 1)을 빼준게 되겠다.
			// printf("Found at Idx(LAST) : %d\n",textIndex);
			result.push_back(textIndex - (i-1));
			// 이상태에서 실패함수를 한번 더 돌려줘야하나봐
			// i 를 저렇게 크게 가져가면, 다음 cycle 의 pattern String [i+1] 는 사실상 runtime error 를 만들겠지. 지금이야 배열 초기화되어있고 크기가 충분히 커서 안터지겠지만.
			i = failure[i];
		}
	}

	// result print
	printf("%lu\n",result.size());
	for (int i=0;i<result.size();i++)
	{
		printf("%d ",result[i]);
	}
	printf("\n");

	return 0;
}
