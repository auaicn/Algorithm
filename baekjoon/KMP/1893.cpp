#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

#define ORDER_MAX_LENGTH (110)
#define PATTERN_MAX_LENGTH (50010)
#define TEXT_MAX_LENGTH (500010)

char order[ORDER_MAX_LENGTH];
char pattern[PATTERN_MAX_LENGTH];
char text[TEXT_MAX_LENGTH];

char current_order[ORDER_MAX_LENGTH];

int lengthOrder;
int lengthPattern;
int lengthText;

int failure[PATTERN_MAX_LENGTH];

char transition[512];

vector<int> result;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	char temp; scanf("%c",&temp);
	while(T--)
	{
		result.clear();
		memset(order, '\0', ORDER_MAX_LENGTH);
		memset(pattern, '\0', PATTERN_MAX_LENGTH);
		memset(text, '\0', TEXT_MAX_LENGTH);
		memset(transition, '\0', 512);

		fgets(order + 1, ORDER_MAX_LENGTH, stdin);
		fgets(pattern + 1, PATTERN_MAX_LENGTH, stdin);
		fgets(text + 1, TEXT_MAX_LENGTH, stdin);

		lengthOrder = strlen(order + 1);
		lengthPattern = strlen(pattern + 1);
		lengthText = strlen(text + 1);

		order[lengthOrder] = '\0'; lengthOrder--;
		pattern[lengthPattern] = '\0'; lengthPattern--;
		text[lengthText] = '\0'; lengthText--;

		// make transition
		for (int i=0; i<lengthOrder-1;i++)
			transition[(int)order[i+1]] = order[i+2];
		transition[(int)order[lengthOrder]] = order[1];

		// lengthOrder 가 3이면, 2, 1, 0 만큼 shifting 하면서 찾을것이다.
		for (int shamt = 0; shamt < lengthOrder; shamt++)
		{
			// printf("Current Pattern : %s\n", pattern + 1);
			// get failure
			failure[1] = 0;
			int i = 0;
			for (int idx = 2; idx <= lengthPattern; idx++)
			{
				failure[idx] = 0; // reset here.
				while(i && pattern[i + 1] != pattern[idx]) i = failure[i];
				if(pattern[i + 1] == pattern[idx]) i++;
				failure[idx] = i; // i already incremented
			}

			i = 0;
			bool found = false;
			bool found_twice = false;
			for (int idx = 1; idx <= lengthText; idx++)
			{
				while(i && text[idx] != pattern[i+1]) i = failure[i];
				if(text[idx] == pattern[i + 1]) i++;
				if (i == lengthPattern){
					// printf("one found\n");
					if(found)
						found_twice = true;
					else
						found = true;
					i = failure[i];
				}
			}
			if(found && !found_twice)
				result.push_back(shamt);

			// change pattern
			// shift by 1
			for (int i=0;i<lengthPattern;i++)
				pattern[i+1] = transition[pattern[i+1]];
			
		}
		if(result.empty())
		{
			printf("no solution\n");
		}
		else
		{
			// found
			if (result.size() > 1)
			{
				printf("ambiguous: ");
				for (int i=0;i<result.size();i++)
					printf("%d ",result[i]);
				printf("\n");
			}else
			{
				printf("unique: %d\n",result[0]);
			}
		}
	}
	return 0;
}