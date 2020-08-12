#include <stdio.h>
#include <iostream>

using namespace std;

char original[20];
char save[20][20];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		int N,M; scanf("%d %d",&N,&M);
		for (int i=0;i<N;i++)
			scanf("%s",save[i+1]+1);

		for (int i=0;i<M;i++)
			original[i+1] = save[1][i+1];
		
		bool sw;
		// transform i+1 th element
		for (int i=0;i<M;i++){

			//restore
			for (int j=0;j<M;j++)
				save[1][j+1] = original[j+1];

			// transform
			for (int j=0;j<26;j++){

				save[1][i+1] = 'a'+j;
				//compare the other
				sw = true;

				// save[1][i+1] transformed.
				for (int k=1;k<N;k++){

					// compare with k+1 th string
					int diff = 0;

					// by length
					for (int l=0;l<M;l++){
						if(save[1][l+1] != save[k+1][l+1])
							diff++;
					}

					if(diff >= 2){
						sw = false;
						break;
					}
				}
				if(sw)
					//found
					break;
			}
			if(sw)
				//found
				break;
		}
		if(sw)
			printf("%s\n",save[1]+1);
		else
			printf("-1\n");

	}
	return 0;
}