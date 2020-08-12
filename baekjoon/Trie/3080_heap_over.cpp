#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define NUM_CHILD (26)
#define DENOMINATOR (1000000007)

vector<struct node*> v;

long long fact[50];

struct node{
	int leaf;
	int num_child;
	struct node* child[NUM_CHILD];
};

long long res = 1;
struct node* root;

char str[3010];

void Trie_insert(char* str, struct node* now){

	if(str[0]=='\0'){
		now->leaf = 1;
		return;
	}

	if(now->child[str[0]-'A'] == NULL){
		struct node* new_node = (struct node*) malloc(sizeof(struct node));
		memset(new_node,0,sizeof(struct node));
		now->child[str[0]-'A'] = new_node;
		now->num_child++;
		v.push_back(new_node);
	}

	Trie_insert(str+1,now->child[str[0]-'A']);
}

void recursive_visit(struct node* now){

	if(now -> num_child + now -> leaf >= 2){
		res *= fact[now -> num_child + now -> leaf];
		res %= DENOMINATOR;
	}

	for (int i=0;i<NUM_CHILD;i++)
		if(now->child[i])
			recursive_visit(now->child[i]);

}

int main(int argc, char const *argv[])
{

	root = (struct node*) malloc(sizeof (struct node));
	memset(root,0,sizeof(struct node));
	v.push_back(root);

	int N; scanf("%d",&N);

	fact[0] = 1;
	fact[1] = 1;
	for (int i = 1; i <= 30; i++)
		fact[i+1] = (i+1) * fact[i];

	for (int i=0;i<N;i++){
		scanf(" %s",str);
		Trie_insert(str,root);
	}

	// recursive_visit(root);
	for (int i=0;i<v.size();i++){
		struct node* now = v[i];
		res *= fact[now -> num_child + now -> leaf];
		res %= DENOMINATOR;
	}

	printf("%lld\n",res);
	return 0;
}