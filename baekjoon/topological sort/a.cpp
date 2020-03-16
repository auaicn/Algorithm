#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		vector<int> a;
		vector<int> b;
		int N; scanf("%d",&N);
		for (int i=0;i<N;i++){
			int temp; scanf("%d",&temp);
			a.push_back(temp);
		}

		for (int i=0;i<N;i++){
			int temp; scanf("%d",&temp);
			b.push_back(temp);
		}

		sort(a.begin(),a.end());
		sort(b.begin(),b.end());

		for (int i=0;i<N;i++)
			printf("%d ",a[i]);
		printf("\n");

		for (int i=0;i<N;i++)
			printf("%d ",b[i]);
		printf("\n");

	}
	return 0;
}