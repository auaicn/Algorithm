#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<pair<int,int>, pair<int,int> > > v;

int result;

int main(int argc, char const *argv[])
{
	int N; N = 4;
	for (int i=0;i<N;i++){
		// 왼쪽 아래, 오른쪽 위
		int leftX, leftY, rightX, rightY;
		scanf("%d %d %d %d",&leftX,&leftY,&rightX,&rightY);
		v.push_back({{leftX,leftY},{rightX,rightY}});
	}

	for (int i=0;i<100;i++){
		for (int j=0;j<100;j++){
			// left Under i,j
			// right Upper i+1,j+1
			// is it included?
			for (int k=0;k<4;k++){
				pair<pair<int,int>, pair<int,int> > box = v[k];
				pair<int,int> leftUnder = box.first;
				pair<int,int> rightUpper = box.second;
				int xLeftUnder = leftUnder.first;
				int yLeftUnder = leftUnder.second;
				int xRightUpper = rightUpper.first;
				int yRightUpper = rightUpper.second;
				if(xLeftUnder <= i && i + 1 <= xRightUpper && yLeftUnder <= j && j + 1 <= yRightUpper){
					result++;
					break;
				}
			}
		}
	}
	printf("%d\n",result);
	return 0;
}


