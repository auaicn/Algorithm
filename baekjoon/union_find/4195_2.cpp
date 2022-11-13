#define SIZE (30)

#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

char one[SIZE];
char another[SIZE];

string oneString, anotherString;

int group[200010];

int find(int x){
	if (x==group[x]) return x;
	else return group[x] = find(group[x]);
}

int main(){
	int T; scanf("%d", &T);

	map<string, int> index;
	map<int,int> groupSize;

	while(T--){
		int F; scanf("%d", &F);

		index.clear();
		groupSize.clear();

		while(F--){
			memset(one, '\0', SIZE);
			memset(another, '\0', SIZE);

			scanf(" %s", one);
			scanf(" %s", another);

			oneString = one;
			anotherString = another;

			int oneIndex, anotherIndex;

			if (index.find(oneString) == index.end()){
				index[oneString] = oneIndex = index.size() + 1;
				groupSize[oneIndex] = 1;
				group[oneIndex] = oneIndex;
			}else {
				oneIndex = index[oneString];
			}

			if (index.find(anotherString) == index.end()){
				index[anotherString] = anotherIndex = index.size() + 1;
				group[anotherIndex] = anotherIndex;
				groupSize[anotherIndex] = 1;
			}else {
				anotherIndex = index[anotherString];
			}

			int oneAncestor = find(oneIndex);
			int anotherAncestor = find(anotherIndex);

			if (oneAncestor != anotherAncestor){
				group[oneAncestor] = anotherAncestor;
				groupSize[anotherAncestor] += groupSize[oneAncestor];
			}

			printf("%d\n", groupSize[anotherAncestor]);
		}
	}
}