#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool jamie[1010];
bool jamie_available; int jamie_be_available;
bool cameron_available; int cameron_be_available;

vector<pair<pair<int,int>,int> > v;

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	for (int t = 0;t<T;t++){
		//jamie
		for (int i=0;i<1010;i++)
			jamie[i] = false;
		jamie_available = true; jamie_be_available = 0;
		cameron_available = true; cameron_be_available = 0;
		v.clear();

		int N; scanf("%d",&N);
		for (int i=0;i<N;i++){
			int left,right; scanf("%d %d",&left,&right);
			v.push_back({{left,right},i+1});
		}

		bool sw = false;
		sort(v.begin(),v.end());

		for (int i=0;i<N;i++){
			pair<pair<int,int>,int> pos = v[i];
			int index_ = pos.second;
			int time_start = pos.first.first;

			if(time_start>=jamie_be_available)
				jamie_available = true;
			if (time_start>=cameron_be_available)
				cameron_available = true;

			int time_end = pos.first.second;
			if(jamie_available&&cameron_available){
				// both can then jamie do it sorry
				jamie_available = false;
				jamie_be_available = time_end;
				jamie[index_] = true;

			}else if(jamie_available){
				//jamie do it
				jamie_available = false;
				jamie_be_available = time_end;
				jamie[index_] = true;

			}else{
				// jamie not available
				if(!cameron_available){
					sw = true;
					break;
				}else{
					// cam do it
					cameron_available = false;
					cameron_be_available = time_end;
					jamie[index_] = false;
				}

			}

		}

		printf("Case #%d: ",t+1);
		if(sw)
			printf("IMPOSSIBLE\n");
		else{
			for (int i=0;i<N;i++)
				if(jamie[i+1])
					printf("J");
				else
					printf("C");
			printf("\n");
		}

	}
	return 0;
}