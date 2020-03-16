#include <stdio.h>
#include <iostream>

using namespace std;

int min(int x, int y){ return x<y?x:y;}
int max(int x, int y){ return x>y?x:y;}

int save[110];

int main(int argc, char const *argv[])
{
	int N; scanf("%d",&N);
	for (int i=0;i<N;i++){
		scanf("%d",&save[i+1]);
	}

	int s = 0;
	int e = 0;

	for (int i=0;i<N;i++){
		int temp; scanf("%d",&temp);
		if(temp==save[i+1])
			continue;
		else if (temp<save[i+1])
			s++;
		else
			e++;
	}

	//printf("s : %d e : %d\n",s,e);
	if(s==0){
		printf("-1\n");
		return 0;
	}else if(e%s){
		printf("%d\n",e/s+1);
	}else{
		printf("%d\n",e/s+1);
	}
	/* code */
	return 0;
}