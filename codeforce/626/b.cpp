#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <stack>

using namespace std;

int save[40010];
int save2[40010];

int sub[40010];
int sub2[40010];

long long total[40010];
long long total2[40010];

int main(int argc, char const *argv[])
{
	int N,M,K; scanf("%d %d %d",&N,&M,&K);

	for (int i=0;i<N;i++)
		scanf("%d",&save[i+1]);
	for (int i=0;i<M;i++)
		scanf("%d",&save2[i+1]);

	int cnt_ = 0;
	int cnt_2 = 0;

	/*
	for (int i=0;i<N;i++)
		printf("%3d",save[i+1]);
	printf("\n");
	*/

	for (int i=0;i<N;i++){
		//printf("%d %d\n",cnt_,cnt_2);
		if(save[i+1])
			cnt_++;
		else{
			sub[cnt_]++;
			cnt_=0;
		}
	}

	for (int i=0;i<M;i++){
		if(save2[i+1])
			cnt_2++;
		else{
			sub2[cnt_2]++;
			cnt_2=0;
		}
	}

	sub[cnt_]++;
	sub2[cnt_2]++;

	stack<pair<int,int> > s;

	for (int i=0;i<N;i++)
		if(sub[i+1])
			s.push({i+1,sub[i+1]});

	while(!s.empty()){
		pair<int,int> pos = s.top(); s.pop();
		int index = pos.first;
		int num = pos.second;
		for (int i=index;i>0;i--)
			total[i]+=(index-i+1)*num;
	}

	/*
	printf("sub  :");
	for (int i=0;i<N;i++)
		printf("%3d",sub[i+1]);
	printf("\n");

	printf("sub2 :");
	for (int i=0;i<M;i++)
		printf("%3d",sub2[i+1]);
	printf("\n");
	*/

	stack<pair<int,int> > s2;

	for (int i=0;i<M;i++)
		if(sub2[i+1])
			s2.push({i+1,sub2[i+1]});

	while(!s2.empty()){
		pair<int,int> pos = s2.top(); s2.pop();
		int index = pos.first;
		int num = pos.second;
		for (int i=index;i>0;i--)
			total2[i]+=(index-i+1)*num;
	}

	/*
	//check
	printf("total  :");
	for (int i=0;i<N;i++)
		printf("%3d",total[i+1]);
	printf("\n");
ㅋㅋ
	printf("total2 :");
	for (int i=0;i<M;i++)
		printf("%3d",total2[i+1]);
	printf("\n");
	// sub 문제인데 0따리가 1붙어서 올라오는것도 있고
	// 중복의 문제가 가장 심한거같은데
	*/

	// 이 뒤로 건드리지마 
	vector<pair<int,int> > v;
	int bound = 0;
	for (int i=0;i<40010;i++){
		if(i*i>K)
			break;
		else bound = i;
	}

	// K를 소인수분해
	for (int i=1;i<=bound;i++)
		if(K%i)
			continue;
		else{
			if(i*i==K)
				continue;
			v.push_back({i,K/i});
		}


	int fixed_size = v.size();
	for (int i=0;i<fixed_size;i++){
		pair<int,int> look = v[i];
		int x = v[i].first;
		int y = v[i].second;
		v.push_back({y,x});
	}

	if(bound*bound==K)
		v.push_back({bound,bound});

	/*
	for (int i=0;i<v.size();i++)
		printf("%d %d ? ",v[i].first,v[i].second);
	printf("\n");
	*/

	long long res = 0;
	for (int i=0;i<v.size();i++){
		int x = v[i].first;
		int y = v[i].second;
		if(x>N||y>M)
			continue;
		//printf("x and y : %d %d\n",x,y);
		res+=total[x]*total2[y];
	}

	printf("%lld\n",res);

	return 0;
}