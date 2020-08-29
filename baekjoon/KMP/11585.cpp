#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_TEXT_LENTGH (2000010)

char text[MAX_TEXT_LENTGH];
char pattern[MAX_TEXT_LENTGH];
int failure[MAX_TEXT_LENTGH];

int lengthText;
int lengthPattern;

int gcd(int x, int y){
	if(y == 0)
		return x;
	else
		return gcd(y,x%y);
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf(" %c",&text[i+1]);
	for (int i=0;i<N;i++)
		scanf(" %c",&pattern[i+1]);
	for (int i=0;i<N-1;i++)
		text[i+1+N] = text[i+1];
	// printf("Text : %s\n",text + 1);
	// printf("Pattern : %s\n",pattern + 1);

	lengthText = strlen(text + 1);
	lengthPattern = strlen(pattern + 1);
	// printf("lengthText : %d\n",lengthText);
	// printf("lengthPattern : %d\n",lengthPattern);

	int i = 0;
	failure[1] = 0;
	for (int idx = 2; idx <= lengthPattern; idx++){
		while(i && pattern[idx] != pattern[i+1]) i = failure[i];
		if(pattern[idx] == pattern[i+1]) i++;
		failure[idx] = i;
	}

	// KMP
	i = 0;
	int result = 0;
	for (int idx = 1; idx <= lengthText; idx ++)
	{
		while(i && text[idx] != text[i+1]) i = failure[i];
		if(text[idx] == text[i+1]) i++;
		if(i == lengthPattern)
		{
			result++;
			i = failure[i];
		}
	}
	// printf("result : %d\n",result);
	int greatest_common_divider = gcd(result,lengthPattern);
	// printf("%d\n",greatest_common_divider);
	printf("%d/%d\n",result/greatest_common_divider,lengthPattern/greatest_common_divider);
	return 0;
}

// 문제
// 수원이와 친구들은 저녁 메뉴를 잘 선택하지 못한다. 배가 고픈 수원이가 보다 못해 메뉴를 정하곤 하는데 이마저도 반대에 부딪히는 경우에는 수원이가 원형 룰렛을 돌려 결정하곤 한다. 이 원형 룰렛으로 메뉴를 선택하는 방법은 매우 독특한데, 원형 룰렛을 돌린 뒤 12시부터 시계방향으로 읽어서 나오는 모양으로 저녁 메뉴를 결정한다. 원형 룰렛에는 정확히 N개로 나누어진 칸이 존재하고, 각 칸에는 알파벳 대문자 하나가 써져있다. 또한 원형 룰렛의 12시 방향에 존재하는 화살표는 칸 사이에 걸치는 일이 없이 항상 하나의 특정한 칸을 가리키게 되며, 원형 룰렛을 돌렸을 때, N개의 칸이 12시에 존재하게 될 확률은 모두 같다.



// 오늘도 저녁 메뉴를 고르지 못한 수원이와 친구들은 고기를 먹자는 수원이의 의견을 반대하여 결국 원형 룰렛을 돌리게 되었다. 원형 룰렛을 돌려 수원이가 오늘 고기를 먹게 될 확률을 계산하는 프로그램을 작성하자.

// 입력
// 첫 번째 줄에는 원형 룰렛의 칸 수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 두 번째 줄에는 저녁 메뉴로 고기를 선택하게 되는 원형 룰렛의 모양이 12시 방향부터 시계방향으로 공백을 구분으로 한 글자씩 N개 주어진다. 세 번째 줄에는 현재의 원형 룰렛 모양이 12시 방향으로부터 시계방향으로 공백을 구분으로 한 글자씩 N개 주어진다.

// 출력
// 원형 룰렛을 돌렸을 때 오늘 저녁으로 고기를 선택하게 되는 확률을 기약분수 형태로 출력한다. 기약분수란 분자와 분모가 더 이상 약분이 안 되는 형태를 의미한다. 만약 룰렛이 어떤 곳에 멈춰도 고기를 먹을 수 있다면 1/1 을 출력한다. 원형 룰렛을 돌려 고기를 먹을 수 있는 경우의 수는 적어도 한 가지 이상 있기 때문에 분자가 0이 되는 경우는 없다.

// 예제 입력 1 
// 9
// I W A N T M E A T
// E A T I W A N T M
// 예제 출력 1 
// 1/9
// 예제 입력 2 
// 6
// A A B A A B
// B A A B A A
// 예제 출력 2 
// 1/3
