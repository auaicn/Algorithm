#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

struct node{
	node* child[10];
	bool leaf;
};

void recurseive_delete(node* now){
	for (int i=0;i<10;i++)
		if(now->child[i])
			recurseive_delete(now->child[i]);
	free(now);
}

bool Trie_insert(char* str, struct node* now){

	if (now -> leaf)
		return false;

	if(str[0]=='\0'){
		bool fin = true;
		for (int i=0;i<10;i++)
			if(now->child[i]!=NULL)
				fin = false;

		if(!fin)
			return false;
		else{
			now->leaf = true;
			return true;
		}
	}

	else{
		if(now->child[str[0]-'0'] != NULL)
			return Trie_insert(str+1,now->child[str[0]-'0']);
		else{
			struct node* new_node = (node*) malloc(sizeof(struct node));
			memset(new_node,0,sizeof(struct node));
			now-> child[str[0]-'0'] = new_node;
			return Trie_insert(str+1,now->child[str[0]-'0']);
		}
	}
}

char save[20];

int main(int argc, char const *argv[])
{
	int T; scanf("%d",&T);
	while(T--){

		struct node* new_node = (node*) malloc(sizeof(struct node));
		memset(new_node,0,sizeof(struct node));
		struct node* root = new_node;

		bool sw = true;
		int N; scanf("%d",&N);

		for (int i=0;i<N;i++){
			scanf(" %s",save + 1);
			sw = sw && Trie_insert(save+1, root);
		}

		if (sw)
			printf("YES\n");
		else
			printf("NO\n");

		recurseive_delete(root);

	}

	return 0;
}