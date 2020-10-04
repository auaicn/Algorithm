#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF (1987654321)

int max(int x, int y){
	return x>y?x:y;
}

vector<pair<int,int> > v;

int result;

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		int left,right; scanf("%d %d",&left,&right);
		v.push_back({left,right});
	}
	sort(v.begin(),v.end());
	int right_max = -INF;
	int initial_left = -INF;
	for (int i=0;i<N;i++){
		pair<int,int> lookup = v[i];
		int left = lookup.first;
		int right = lookup.second;
		if(left > right_max){
			// maybe seperated
			if(initial_left != -INF)
				result += right_max - initial_left;
			initial_left = left;
			right_max = right;
		}else{
			right_max = max(right_max, right);
		}
	}
	result += right_max - initial_left;
	printf("%d\n",result);
	return 0;
}


// 매우 큰 도화지에 자를 대고 선을 그으려고 한다. 선을 그을 때에는 자의 한 점에서 다른 한 점까지 긋게 된다. 선을 그을 때에는 이미 선이 있는 위치에 겹쳐서 그릴 수도 있는데, 여러 번 그은 곳과 한 번 그은 곳의 차이를 구별할 수 없다고 하자.

// 이와 같은 식으로 선을 그었을 때, 그려진 선(들)의 총 길이를 구하는 프로그램을 작성하시오. 선이 여러 번 그려진 곳은 한 번씩만 계산한다.

// 입력
// 첫째 줄에 선을 그은 횟수 N(1≤N≤1,000,000)이 주어진다. 다음 N개의 줄에는 선을 그을 때 선택한 두 점이 주어진다. 선택한 지점은 -1,000,000,000 이상 1,000,000,000 이하의 정수이다.

// 출력
// 첫째 줄에 그은 선의 총 길이를 출력한다.

// 예제 입력 1 
// 4
// 1 3
// 2 5
// 3 5
// 6 7
// 예제 출력 1 
// 5