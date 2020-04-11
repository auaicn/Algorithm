#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

char temp[110];
int save[110];

bool auaicn[110];

int _left[110];
int _right[110];

int max(int x, int y){
	return x>y?x:y;
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	for (int t=0;t<T;t++){
		scanf(" %s",temp+1); int len = strlen(temp+1);

		int max_ = -1;
		for (int i=0;i<len;i++){
			save[i+1] = temp[i+1]-'0';
			max_ = max(max_,save[i+1]);

			//initialize
			_left[i+1] = 0;
			_right[i+1] = 0;
		}

		for (int k=0;k<max_;k++){
			//0-1 problem 9 thimes. // max_ times.
			for (int i=0;i<len;i++)
				auaicn[i+1] = save[i+1] ? true : false;

			// may not be needed but
			auaicn[0] = false;
			auaicn[len+1] = false;

			bool sw = false;
			int left_track;
			int right_track;

			for (int i=0;i<len;i++){
				if(auaicn[i+1]){
					if(!sw){
						sw = true;
						left_track = i+1;
					}else
						continue;
				}else{
					// false 
					if(sw){
						sw = false;
						right_track = i+1-1;
						_left[left_track]++;
						_right[right_track]++;
					}else
						continue;
				}
			}


			if(sw&&auaicn[len]){
				_left[left_track]++;
				_right[len]++;
			}

			for (int i=0;i<len;i++)
				if(save[i+1])
					save[i+1]--;
		}


		printf("Case #%d: ",t+1);
		for (int i=0;i<len;i++){
			for (int j=0;j<_left[i+1];j++)
				printf("(");
			printf("%c",temp[i+1]);
			for (int j=0;j<_right[i+1];j++)
				printf(")");
		}
		printf("\n");
	}
	return 0;
}