#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <string.h>

#define MAX_TEXT_LENGTH (1000010)

using namespace std;

char text[MAX_TEXT_LENGTH];
char pattern[MAX_TEXT_LENGTH];
int failure[MAX_TEXT_LENGTH];
int lengthText;
int lengthRepeating;

int main(int argc, char const *argv[])
{
	while(true){
		memset(text,'\0',MAX_TEXT_LENGTH);
		memset(pattern,'\0',MAX_TEXT_LENGTH);
		memset(failure,0,MAX_TEXT_LENGTH);

		fgets(text+1, MAX_TEXT_LENGTH, stdin);

		if(text[1] == '.')
			break;

		lengthText = strlen(text+1);
		text[lengthText] = '\0';
		lengthText--;
		// printf("len[%d] %s\n",lengthText,text + 1);

		failure[1] = 0;
		
		for(int idx = 2, i = 0; idx <= lengthText; idx++)
		{
			while(i && text[idx] != text[i+1]) i = failure[i];
			if(text[idx] == text[i+1]) i++;
			failure[idx] = i;
		}

		// for (int i=0;i<lengthText;i++)
		// 	printf("%3d",failure[i+1]);
		// printf("\n");

		lengthRepeating = lengthText - failure[lengthText];

		// void * memcpy ( void * destination, const void * source, size_t num );
		memcpy(pattern + 1, &text[failure[lengthText]+1],lengthText - failure[lengthText]);
		// printf("reapeating Pattern should be : %s\n", pattern + 1);

		if(lengthRepeating == lengthText)
		{
			printf("1\n");
			continue;
		}

		if(lengthText % lengthRepeating )
		{
			// printf("cannot repeat\n");
			printf("1\n");
			continue;
		}

		int result = 2;
		bool no_answer = false;
		int lengthLeft = lengthText - lengthRepeating;
		while(lengthRepeating < lengthLeft)
		{
			// looking for text[1:lengthLeft]
			int temp_repeat_length = lengthLeft - failure[lengthLeft];
			if(temp_repeat_length != lengthRepeating)
			{
				no_answer = true;
				break;
			}else{
				lengthLeft -= lengthRepeating;
				result++;
			}
		}

		if(no_answer)
			printf("1\n");
		else
			printf("%d\n",result);

	}

	return 0;
}


// 문제
// 알파벳 소문자로 이루어진 두 문자열 a와 b가 주어졌을 때, a*b는 두 문자열을 이어붙이는 것을 뜻한다. 예를 들어, a="abc", b="def"일 때, a*b="abcdef"이다.

// 이러한 이어 붙이는 것을 곱셈으로 생각한다면, 음이 아닌 정수의 제곱도 정의할 수 있다.

// a^0 = "" (빈 문자열)
// a^(n+1) = a*(a^n)
// 문자열 s가 주어졌을 때, 어떤 문자열 a에 대해서 s=a^n을 만족하는 가장 큰 n을 찾는 프로그램을 작성하시오.

// 입력
// 입력은 10개 이하의 테스트 케이스로 이루어져 있다. 각각의 테스트 케이스는 s를 포함한 한 줄로 이루어져 있다. s의 길이는 적어도 1이며, 백만글자를 넘지 않는다. 마지막 테스트 케이스의 다음 줄은 마침표이다.

// 출력
// 각각의 테스트 케이스에 대해, s=a^n을 만족하는 가장 큰 n을 찾은 뒤 출력한다.

// 예제 입력 1 
// abcd
// aaaa
// ababab
// .
// 예제 출력 1 
// 1
// 4
// 3