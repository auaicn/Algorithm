#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,float> m;
map<string,float>::iterator it;
map<string,float>::iterator temp;

string str;
int cnt_;

char save[30];

int main(int argc, char const *argv[])
{
	while(true){
		getline(cin, str);
		if(!cin)
		{
			if(cin.eof()){
			    //cout << "EOF\n";
			    break;
			}
			else
			    cout << "other failure\n";
		}

		temp = m.find(str);
		cnt_++;
		if(temp==m.end())
			m[str] = 1.0;
		else
			(temp->second)++;
	}

	for (it = m.begin();it!=m.end();it++){
		str = it->first;
		for (int i=0;i<str.size();i++)
			save[i] = str[i];
		save[str.size()]='\0';
		printf("%s %.4f\n",save,(it->second/cnt_)*100);
	}

	return 0;
}
