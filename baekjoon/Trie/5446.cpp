#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define NUM_CHILD (130)

bool usable;

struct node{

	bool wildcard_usable;
	bool visited;
	struct node* child[NUM_CHILD];

};

struct node* root;

void Trie_insert(char* str, struct node* now){

	now->wildcard_usable = usable;

	if(str[0]=='\0')
		return;

	if(now->child[str[0]] == NULL){
		struct node* new_node = (struct node*) malloc(sizeof (struct node));
		memset(new_node,0,sizeof(struct node));
		now->child[str[0]] = new_node;
	}
	Trie_insert(str+1,now->child[str[0]]);
}

int res;

char* str;

vector<char*> v;

void recursive_free(struct node* now){
	for(int i=0;i<NUM_CHILD;i++)
		if(now->child[i])
			recursive_free(now->child[i]);
	free(now);
}

void Trie_traversal(char* str, struct node* now){

	if(now->visited)
		return;

	if(now->wildcard_usable){
		res++;
		now->visited = true;
		return;
	}

	if(str[0]=='\0'){
		res++;
		return;
	}

	Trie_traversal(str+1,now->child[str[0]]);

}


int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){

		root = (struct node*) malloc(sizeof (struct node));
		memset(root,0,sizeof(struct node));

		int N; scanf("%d",&N); usable = true;
		for (int i=0;i<N;i++){
			str = (char*) malloc(30);
			scanf(" %s",str);
			Trie_insert(str,root);
			v.push_back(str);
		}

		int M; scanf("%d",&M); usable = false;
		for (int i=0;i<M;i++){
			char temp[30];
			scanf(" %s",temp);
			Trie_insert(temp,root);
		}

		for (int i=0;i<N;i++)
			Trie_traversal(v[i],root);

		printf("%d\n",res);
		recursive_free(root);
		for (int i=0;i<v.size();i++)
			free(v[i]);
		v.clear();
		res = 0;
	}

	return 0;
}





