#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

#define MAX_TEXT_LENGTH (1000010)

char text[MAX_TEXT_LENGTH];
int failure[MAX_TEXT_LENGTH];

int main(int argc, char const *argv[])
{
	int textLength; scanf("%d",&textLength);
	for (int i=0;i<textLength;i++)
		scanf(" %c",&text[i+1]);

	// initial failure function
	int i = 0;
	failure[1] = 0;
	for (int idx=2;idx<=textLength;idx++)
	{
		while(i && text[idx] != text[i+1]) i = failure[i];
		if(text[idx] == text[i+1]) i++;
		failure[idx] = i;
	}

	if(failure[textLength] == 0)
		printf("%d\n",textLength);
	else
		printf("%d\n",textLength - failure[textLength]);
	return 0;

	// for (int i=0;i<textLength;i++)
		// printf("%d ",failure[i+1]);
	// printf("\n");

	int idx = textLength;
	while(failure[idx] * 2 > textLength)
	{
		idx = failure[idx];
	}

	// anyway we got some value
	// cut off left side
	int lengthToCut = failure[idx];
	textLength = textLength - lengthToCut;
	// printf("new text Length : %d\n",textLength);
	for (int i=0;i<textLength;i++)
		text[i+1] = text[i+1+lengthToCut];
	text[textLength + 1] = '\0';

	// get failure agagin
	i = 0;
	failure[1] = 0;
	for (int idx=2;idx<=textLength;idx++)
	{
		failure[idx] = 0;
		while(i && text[idx] != text[i+1]) i = failure[i];
		if(text[idx] == text[i+1]) i++;
		failure[idx] = i;
	}

	// cut off right side
	// as possible

	// for (int i=0;i<textLength;i++)
		// printf("%d ",failure[i+1]);
	// printf("\n");

	idx = textLength;
	while(failure[idx] * 2 > textLength)
	{
		idx = failure[idx];
	}

	// 이것만으로 cut된다고 할 수 있다.
	textLength -= failure[idx];
	// printf("new text Length : %d\n",textLength);

	// for (int i=0;i<textLength;i++)
		// printf("%c ",text[i+1]);
	// printf("\n");

	// check whether it's form A^N
	int lengthRepeat = textLength - failure[textLength];
	if(textLength%lengthRepeat || textLength == lengthRepeat)
	{
		// not repeating or failure value of last idx is 0 (no suffix prefix same).
		printf("%d\n",textLength);
		return 0;
	}
	else{
		int resultIfReallyRepeating = lengthRepeat;
		// printf("result if repeating %d\n",resultIfReallyRepeating);
		// check if it really being repeated.

		bool reallyRepeating = true;

		for (int i = 0; i < textLength - lengthRepeat; i++){
			// printf("LEFT : %c / RIGHT : %c\n",text[i+1],text[(i+1)%lengthRepeat + 1]);
			int augmented_idx = (i+1)%lengthRepeat;
			if(augmented_idx);
			else
				augmented_idx = lengthRepeat;

			if(text[i+1] != text[augmented_idx]){
				// printf("i+1[%d] here, became false\n",i+1);
				reallyRepeating = false;
			}
		}

		if(reallyRepeating)
			printf("%d\n",resultIfReallyRepeating);
		else
			printf("%d\n",textLength);

	}

	return 0;
}







































