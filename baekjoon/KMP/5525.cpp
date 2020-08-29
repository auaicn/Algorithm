#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>

#define MAX_TEXT_LENGTH (1000010)

using namespace std;

char arrayText[MAX_TEXT_LENGTH];
char arrayPattern[MAX_TEXT_LENGTH];
string text;
string pattern;
int textLength;
int patternLength;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	int M; scanf("%d",&M);
	for (int i=0;i<M;i++)
		scanf(" %c",&arrayText[i]);
	text = string(arrayText + 1);
	textLength = text.size();

	for (int i=0;i<N;i++)
		pattern += "IO";
	pattern += "I";
	patternLength = 2 * N + 1;
	// cout << "pattern" << " : " << pattern << endl;
	// cout << "patternLength" << " : " << patternLength << endl;
	// cout << "text" << " : " << text << endl;

	int result = 0;
	int indexStart = 0;
	while(true)
	{
		indexStart = text.find(pattern,indexStart);
		if(indexStart == string::npos)
			break;
		else
		{
			result++;
			indexStart += patternLength;
			while(indexStart + 2 <= textLength && text[indexStart] == 'O' && text[indexStart + 1] == 'I'){
				result++;
				indexStart += 2;
			}
		}
	}
	printf("%d\n",result);
	/* code */
	return 0;
}