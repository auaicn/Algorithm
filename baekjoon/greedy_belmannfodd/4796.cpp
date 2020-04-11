#include <stdio.h>
#include <iostream>

using namespace std;

int min(int x, int y){
	return x<y?x:y;
}

int main(int argc, char const *argv[])
{
	int cnt_ = 0;
	while(true){
		cnt_++;
		int L,V,P; scanf("%d %d %d",&L,&V,&P);

		if(!(L*V*P))
			break;
		printf("Case %d: %d\n",cnt_,(P/V)*L+min(P%V,L));
	}
	return 0;
}