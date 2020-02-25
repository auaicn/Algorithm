#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int score[100010];
bool visit[100010];

vector<int> library_books[100010];
pair<int,int> library_info[100010];

//implement 4 
//avg * shup per day

int library_score[100010];

bool cmp(int x, int y){
	return score[x]>score[y];
}


int main(int argc, char const *argv[])
{

	FILE* fp = fopen("f_libraries_of_the_world.txt","r");
	FILE* fp_out = fopen("f_result.txt","w+");

	if(fp==NULL||fp_out==NULL){
		exit(-1);		
	}
	//init

	//implement 4
	priority_queue<pair<int,int> > pq;

	// scan
	int B,L,D; fscanf(fp,"%d %d %d",&B,&L,&D);

	for (int i=0;i<B;i++)
		fscanf(fp,"%d",&score[i]);

	for (int i=0;i<L;i++)
		library_books[i].reserve(1010);

	for (int i=0;i<L;i++){
		int num_books, sign_up_date, ship_per_day; fscanf(fp,"%d %d %d",&num_books,&sign_up_date,&ship_per_day);
		library_info[i] = {sign_up_date,ship_per_day};
		for (int j=0;j<num_books;j++){
			int temp; fscanf(fp,"%d",&temp);
			library_books[i].push_back(temp);
		}

		//implement 4
		int sum_ = 0;
		for (int j=0;j<num_books;j++)
			sum_ += score[library_books[i][j]];
		int library_score = (sum_ * ship_per_day)*100000 / (num_books * (sign_up_date + num_books/ship_per_day));
		pq.push({library_score,i});

	}


	// check
	/*
	for (int i=0;i<B;i++)
		fprintf(fp_out,"%3d",score[i]);
	fprintf(fp_out,"\n");

	for (int i=0;i<L;i++){
		for (int j=0;j<library_books[i].size();j++)
			fprintf(fp_out,"%3d",library_books[i][j]);
		fprintf(fp_out,"\n");
	}
	*/


	for (int i=0;i<L;i++)
		sort(library_books[i].begin(),library_books[i].end(),cmp);

	fprintf(fp_out,"%d\n",L);
	// implement 4

	int result = 0;

	while(!pq.empty()){

		pair<int,int> pos = pq.top(); pq.pop();

		// 사실 필요한건 Library의 책점수 평균 * 하루량 은 이제 필요없고 
		// library 번호만 필요하지.

		int lib_index = pos.second;
		int ship_per_day = library_info[lib_index].second;
		int sign_up_date = library_info[lib_index].first;

		if(D-sign_up_date-((library_books[lib_index].size()/ship_per_day)+1 >= 0)){

			// we can use.
			D-=sign_up_date;
			fprintf(fp_out,"%d %d\n",lib_index,(int)library_books[lib_index].size());
			for (int i=0;i<library_books[lib_index].size();i++)
				fprintf(fp_out,"%d ",library_books[lib_index][i]);
			fprintf(fp_out,"\n");
			result++;

		}

	}

	//rewind(fp_out);
	//fprintf(fp_out,"%d\n",result);

	fclose(fp);
	fclose(fp_out);

	return 0;
}