#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int min(int x,int y){
	return x<y?x:y;
}

int main(int argc, char const *argv[])
{
	string str; cin >> str;
	vector<pair<string,int> > v;
	for (int i=0;i<str.size();i++)
		v.push_back({str.substr(i,str.size()-i),i+1});

	sort(v.begin(),v.end());

	for (int i=0;i<v.size();i++)
		cout << v[i].second << " ";
	cout <<endl;

	for (int i=0;i<v.size();i++)
		cout << v[i].first << endl;

	cout << "x" << " ";
	for (int i=0;i<v.size()-1;i++)
	{	
		int cnt_ = 0;
		for (int j=0;j<min(v[i].first.size(),v[i+1].first.size());j++){
			if (v[i].first[j]==v[i+1].first[j])
				cnt_++;
			else
				break;
		}
		cout << cnt_ << " ";
	}
	cout <<endl;

	return 0;
}