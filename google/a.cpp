#include <stdio.h>
#include <iostream>

using namespace std;

bool visit[110];
int save[110][110];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	for (int t=0;t<T;t++){
		int N; scanf("%d",&N);
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				scanf("%d",&save[i+1][j+1]);
			}
		}

		int res = 0;
		for (int i=0;i<N;i++)
			res+= save[i+1][i+1];

		int r = 0;
		int c = 0;

		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++)
				visit[j+1] = false;

			for (int j=0;j<N;j++){
				if(!visit[save[i+1][j+1]])
					visit[save[i+1][j+1]] = true;
				else{
					r++;
					break;
				}
			}
		}

		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++)
				visit[j+1] = false;

			for (int j=0;j<N;j++){
				if(!visit[save[j+1][i+1]])
					visit[save[j+1][i+1]] = true;
				else{
					c++;
					break;
				}
			}
		}

		printf("Case #%d: %d %d %d\n",t+1,res,r,c);
	}
	return 0;
}