#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <trie.h>

int main()
{
	Trie * T;
	printf("CHecking test\n");
	T = trieInit();
	trieInsert(T,"hello");
	trieInsert(T,"h");
	trieInsert(T,"hell");
	trieInsert(T,"parthiv");
	trieInsert(T,"cup");
	trieInsert(T,"desk");
	trieInsert(T,"des");
	///*printf("%d",trieSearch(T,"parthi"));
	//printf("%d\n",trieSearch(T,"hello"));
	printf("%d\n",trieSearch(T,"desk"));
	printf("%d\n",trieSearch(T,"parthiv"));
	printf("%d\n",trieSearch(T,"cu"));
	//printf("%d",trieSearch(T,"bell"));//*/
	listAll(T);
	//printf("%c",T->root->first_child->first_child->letter);
	return 0;
}

