#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int happy;
int sad;

#define MAX_TEXT_LENGTH (1010)
char text[MAX_TEXT_LENGTH];

string patternHappy = ":-)";
string patternSad = ":-(";

int main(int argc, char const *argv[])
{
	fgets(text + 1, 520, stdin);
	text[strlen(text + 1)] = '\0';
	// printf("text : %s\n",text + 1);
	string temp = string(text + 1);
	// cout << temp;

	int indexStart = 0;
	while(true)
	{
		indexStart = temp.find(patternHappy,indexStart);
		if(indexStart == string::npos)
			break;
		else{
			// something found
			// printf("happy Found\n");
			happy++;
			indexStart += patternHappy.size();
		}
	}

	indexStart = 0;
	while(true)
	{
		indexStart = temp.find(patternSad,indexStart);
		// printf("string npos : %d\n",string::npos);
		// printf("index Start : %d\n",indexStart);
		if(indexStart == string::npos)
			break;
		else{
			// something found
			// printf("sad Found\n");
			sad++;
			indexStart += patternSad.size();
		}
	}

	if(!happy && !sad)
		printf("none\n");
	else if (happy > sad)
		printf("happy\n");
	else if (happy < sad)
		printf("sad\n");
	else
		printf("unsure\n");

	return 0;
}

// 문제
// 승엽이는 자신의 감정을 표현하기 위해서 종종 문자 메시지에 이모티콘을 넣어 보내곤 한다. 승엽이가 보내는 이모티콘은 세 개의 문자가 붙어있는 구조로 이루어져 있으며, 행복한 얼굴을 나타내는 :-) 와 슬픈 얼굴을 나타내는 :-( 가 있다.

// 혜성이는 승엽이의 이모티콘을 귀여운 척이라고 생각해 매우 싫어하므로, 승엽이의 문자가 오면 전체적인 분위기만 판단해서 알려주는 프로그램을 작성하고 싶다.

// 입력
// 첫 줄에 최소 1개에서 최대 255개의 문자들이 입력된다.

// 출력
// 출력은 다음 규칙에 따라 정해진다.

// 어떤 이모티콘도 포함되어 있지 않으면, none 을 출력한다.
// 행복한 이모티콘과 슬픈 이모티콘의 수가 동일하게 포함되어 있으면, unsure 를 출력한다.
// 행복한 이모티콘이 슬픈 이모티콘보다 많이 포함되어 있으면, happy 를 출력한다.
// 슬픈 이모티콘이 행복한 이모티콘보다 많이 포함되어 있으면, sad 를 출력한다.
// 예제 입력 1 
// How are you :-) doing :-( today :-)?
// 예제 출력 1 
// happy
// 예제 입력 2 
// :)
// 예제 출력 2 
// none
// 예제 입력 3 
// This:-(is str:-(:-(ange te:-)xt.
// 예제 출력 3 
// sad
