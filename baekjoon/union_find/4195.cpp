#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int p[100010];
int s[100010];

int find(int x){
	if(x==p[x])
		return x;
	else
		return p[x] = find(p[x]);
}

int union_(int x, int y){
	int parent_x = find(x);
	int parent_y = find(y);
	if(parent_x==parent_y)
		return s[parent_y];
	else{
		p[parent_x] = parent_y;
		s[parent_y]+=s[parent_x];
		return s[parent_y];
	}
}

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){
		
		int N; scanf("%d",&N);
		map<string,int> m;

		for (int i=0;i<N+1;i++){
			p[i+1] = i+1;
			s[i+1] = 1;
		}

		while(N--){
			char left[30],right[30]; scanf(" %s %s",left,right);
			string A(left),B(right);

			if(m.find(A)==m.end()){
				m[A] = m.size()+1;
				//cout << A << " "<<m[A]<<endl;
			}

			if(m.find(B)==m.end()){
				m[B] = m.size()+1;
				//cout << B << " "<<m[B]<<endl;
			}
			
			printf("%d\n",union_(m[A],m[B]));
			
			/* check
			for (int i=0;i<m.size();i++)
				printf("%2d",p[i+1]);
			printf("\n");*/

		}
	}
	return 0;
}