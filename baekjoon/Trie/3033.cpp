#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define DENOMINATOR (1000003)

char str[200010];

vector<int> v[DENOMINATOR];
// bool visit[1000010];

int mod(int x){

	if(x >= 0)
		return x%DENOMINATOR;
	else
		if(x%DENOMINATOR)
			return x%DENOMINATOR+DENOMINATOR;
		else
			return 0;
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	scanf(" %s",str+1);

	int low = 0; // possible
	int high = N; // impossible

	while(high != low+1){

		int mid = (high + low) / 2;
		// let string length be mid
		// printf("[%d:%d] mid[%d]\n",low,high,mid);


		bool found = false;
		int hash_i = 0;
		int adjust = 1;
		for (int i=0; i<mid-1; i++)
			adjust = mod(adjust * 2);
		// printf("adjust [%d]\n",adjust);

		// let's find 'one' that has same pattern with substr(i,mid)
		for(int i = 1; i + mid - 1 <= N; i++){
			// starting index would be i
			// last char index would be i + mid - 1 it shouldn't exceed N

			if(i == 1)
				for (int j=0;j<mid;j++){
					// i+j
					// char lookup = str[i+j];
					// Nope right to left

					// char lookup = str[i + mid - 1 - j];
					char lookup = str[i+j];
					hash_i = mod(hash_i * 2 + lookup);
				}
			else{

				// previous hash reused
				hash_i = mod( (2 * (hash_i - str[i-1] * adjust) ) + str[i + mid - 1] );
			}
			// printf("hash value: %d\n",hash_i);

			if(v[hash_i].empty())
				v[hash_i].push_back(i);
			else{
				// now i

				// get index of first char on str with same hash value
				// but real str could be different
				// the case is scarsely

				for (int j=0;j<v[hash_i].size();j++){
					int index = v[hash_i][j];
					bool same = true;
					for (int len = 0; len < mid; len ++){
						if (str[i+len]!=str[index+len]){
							same = false;
							break;
						}
					}
					if(same)
						found = true;
					break;
				}

				// anyway push needed
				v[hash_i].push_back(i);
				if (found)
					break;

			}

			// compare with starting index [j+1:i+mid-1]
			// brute force but hash makes it fast
			// nope. need not.
			// we just need find if duplictae hash exists.

			if(found)
				break;

		}

		if(found)
			// try longer
			low = mid;
		else
			high = mid;

		for (int i=0;i<DENOMINATOR;i++)
			v[i].clear();

		// clear visit
		// for (int i=0;i<DENOMINATOR;i++)
			//visit[i] = false;

	} 
	printf("%d\n",low);
	return 0;
}

/*
문제
상근이는 꿈에서 길이가 L인 문자열을 외웠다.

꿈에서 깬 상근이는 이 문자열을 종이에 적었다. 종이를 적던 중에 어떤 문자열은 두 번 이상 등장하는 것 같은 느낌을 받았다.

문자열이 주어졌을 때, 두 번 이상 등장한 부분 문자열 중 가장 길이가 긴 것을 찾는 프로그램을 작성하시오. (부분문자열은 겹쳐서 등장할 수도 있다)

입력
첫째 줄에 L이 주어진다. (1 ≤ L ≤ 200,000) 다음 줄에는 길이가 L이면서 알파벳 소문자로 이루어진 문자열이 주어진다.

출력
첫째 줄에 두 번 이상 등장하는 부분 문자열 중 길이가 가장 긴 것의 길이를 출력한다. 만약 그러한 문자열이 없을 때는 0을 출력한다.

예제 입력 1 
11
sabcabcfabc
예제 출력 1 
3
*/