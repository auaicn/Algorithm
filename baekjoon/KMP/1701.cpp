#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX_TEXT_LENGTH (5010)

char text[MAX_TEXT_LENGTH];
int textLength;

int failure[MAX_TEXT_LENGTH];
char subText[MAX_TEXT_LENGTH];

int max(int x,int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	fgets(text + 1, MAX_TEXT_LENGTH, stdin);
	textLength = strlen(text + 1) - 1;
	text[textLength + 1] = '\0';

	int result = -1;

	for (int startIndex = 1; startIndex <= textLength; startIndex++)
	{

		int subTextLength = textLength - startIndex + 1;
		memset(subText, '\0', MAX_TEXT_LENGTH);
		memcpy(subText + 1, text + startIndex, subTextLength);

		// printf("sub Text Length : %d\n",subTextLength);
		// printf("sub Text : %s\n",subText + 1);
		// get failure

		int i = 0;
		failure[1] = 0;
		for (int idx = 2; idx <= subTextLength; idx++)
		{
			failure[idx] = 0;
			while(i && subText[idx] != subText[i+1]) i = failure[i];
			if(subText[idx] == subText[i+1]) i++;
			failure[idx] = i;
			result = max(result, failure[idx]);
		}

		// for (int i=0;i<subTextLength;i++)
			// printf("%d ",failure[i+1]);
		// printf("\n");
	}
	printf("%d\n",result);
	return 0;
}

// 문제
// Cubelover는 프로그래밍 언어 Whitespace의 코딩을 도와주는 언어인 Cubelang을 만들었다. Cubelang을 이용해 코딩을 하다보니, 점점 이 언어에 맞는 새로운 에디터가 필요하게 되었다. 오랜 시간 고생한 끝에 새로운 에디터를 만들게 되었고, 그 에디터의 이름은 Cubeditor이다.

// 텍스트 에디터는 찾기 기능을 지원한다. 대부분의 에디터는 찾으려고 하는 문자열이 단 한 번만 나와도 찾는다. Cubelover는 이 기능은 Cubelang에 부적합하다고 생각했다. Cubelang에서 필요한 기능은 어떤 문자열 내에서 부분 문자열이 두 번 이상 나오는 문자열을 찾는 기능이다. 이때, 두 부분 문자열은 겹쳐도 된다.

// 예를 들어, abcdabc에서 abc는 두 번 나오기 때문에 검색이 가능하지만, abcd는 한 번 나오기 때문에 검색이 되지를 않는다.

// 이렇게 어떤 문자열에서 두 번 이상 나오는 부분 문자열은 매우 많을 수도 있다. 이러한 부분 문자열 중에서 가장 길이가 긴 것을 구하는 프로그램을 작성하시오.

// 예를 들어, abcabcabc에서 abc는 세 번 나오기 때문에 검색할 수 있다. 또, abcabc도 두 번 나오기 때문에 검색할 수 있다. 하지만, abcabca는 한 번 나오기 때문에 검색할 수 없다. 따라서, 두 번 이상 나오는 부분 문자열 중에서 가장 긴 것은 abcabc이기 때문에, 이 문자열이 답이 된다.

// 입력
// 첫째 줄에 문자열이 주어진다. 문자열의 길이는 최대 5,000이고, 문자열은 모두 소문자로만 이루어져 있다.

// 출력
// 입력에서 주어진 문자열의 두 번이상 나오는 부분문자열 중에서 가장 긴 길이를 출력한다.

// 예제 입력 1 
// abcdabcabb
// 예제 출력 1 
// 3
// 이 사이트는 ACM 또는 ICPC 대회와 무관하며, ACM으로부터 승인이나 지원을 받지 않고 있습니다.