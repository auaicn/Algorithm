#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string s;
string pattern;
string sub_pattern;

brute_force(int s_index,p_index){
	if (s[]==sub_pattern)
}

bool visit[410];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){

		cin >>s;
		cin>> pattern;

		for (int i=0;i<pattern.size();i++){
			sub_pattern = pattern.substr(0,i+1);
			brute_force(0,0);
		}

	}

	return 0;
}