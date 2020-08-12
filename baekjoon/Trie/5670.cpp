#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<char*> v;

struct node* root;

struct node{
	int num_child;
	bool leaf;
	struct node* child[26];
};

void Trie_insert(char* str, struct node* now){

	if(str[0]=='\0'){
		now->leaf = true;
		return;
	}

	if(now->child[str[0]-'a'] == NULL){
		// create
		struct node* new_child = (node*)malloc(sizeof(struct node));
		memset(new_child,0,sizeof(struct node));
		now->child[str[0]-'a'] = new_child;
		now->num_child++;
		Trie_insert(str+1,new_child);

	}else
		Trie_insert(str+1,now->child[str[0]-'a']);

	return;
}

float Trie_traversal(char* str, struct node* now){

	if(str[0]=='\0')
		return 1;
	
	if((now->leaf || now->num_child >= 2) && now!=root )
		return Trie_traversal(str+1,now->child[str[0]-'a']) + 1;
	else
		// not leaf and no child or one child.
		return Trie_traversal(str+1,now->child[str[0]-'a']);
	
}

void recurseive_delete(node* now){
	for (int i=0;i<10;i++)
		if(now->child[i])
			recurseive_delete(now->child[i]);
	free(now);
	return;
}

int main(int argc, char const *argv[])
{
	while(true){
		int N; scanf("%d",&N);
		if(feof(stdin))
			break;

		root = (node*) malloc(sizeof(struct node));
		memset(root,0,sizeof(struct node));

		for (int i=0;i<N;i++){
			char* save = (char*) malloc(110);
			scanf(" %s",save);
			Trie_insert(save,root);
			v.push_back(save);
		}

		float float_sum = 0;
		for (int i=0;i<v.size();i++){
			float_sum += Trie_traversal(v[i],root);
		}

		printf("%.2f\n",float_sum / v.size());

		for (int i=0;i<v.size();i++)
			free(v[i]);
		v.clear();
		recurseive_delete(root);
	}
	return 0;
}