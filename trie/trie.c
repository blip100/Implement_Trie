#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<trie.h>

TrieNode* create_node(char letter) {
    TrieNode* new_node = (TrieNode*) malloc(sizeof(TrieNode));
    new_node->letter = letter;
    new_node->endOfWord = 0;
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;
    return new_node;
}

Trie* trieInit() {
    Trie* new_trie = (Trie*) malloc(sizeof(Trie));
    new_trie->root = create_node('-');
    return new_trie;
}

int trieSearch(Trie* t,char* s){
    TrieNode* curr_node=t->root;
    while(*s != '\0'){
        TrieNode* child = curr_node->first_child;
        while(child != NULL){
            if(child->letter==*s){
                curr_node = child;
                s++;
                break;
            }
            child = child->next_sibling;
        }
        if(child==NULL){
            return 0;
        }
    }
    return curr_node->endOfWord;
}

void trieInsert(Trie* t,char* s){
	//printf("%s\n",s);
    TrieNode* curr_node = t->root;
    TrieNode* prev_node = NULL;
    //strcat(s,"i");
    while(*s != '\0'){
        TrieNode* child = curr_node->first_child;
        prev_node = NULL;
        while(child != NULL){
            if (child->letter == *s){
                curr_node = child;
                s++;
                break;
            }
            if(child->letter > *s){
                TrieNode* new_node = create_node(*s);
                new_node->next_sibling = child;
                if(prev_node == NULL){
                    curr_node->first_child = new_node;
                }else{
                    prev_node->next_sibling = new_node;
                    new_node->next_sibling=child;
                }
                curr_node = new_node;
                s++;
                break;
            }
            prev_node = child;
            child = child->next_sibling;
        }
        if(child == NULL){
            TrieNode* new_node = create_node(*s);
            if(prev_node == NULL){
                curr_node->first_child = new_node;
            }else{
                prev_node->next_sibling = new_node;
            }
            curr_node = new_node;
            s++;
        }
    }
    curr_node->endOfWord = 1;
}

void listAllHelper(struct TrieNode *node, char *str, int level){
  if (node == NULL){
    return;
  }
  if(node->endOfWord){
    str[level]=node->letter;
    str[level+1] = '\0';
    printf("%s\n", str+1);
  }
  str[level] = node->letter;
  struct TrieNode *child = node->first_child;
  while (child != NULL){
    listAllHelper(child, str, level + 1);
    child = child->next_sibling;
  }
}

void listAll(struct Trie *trie)
{
	char*str;
	str=(char*)malloc(50);
	listAllHelper(trie->root,str,0);
}
/*
int main(){
        Trie* D;
        D=trieInit();
        trieInsert(D,"eat");
        trieInsert(D,"beat");
        trieInsert(D,"beats");
        trieInsert(D,"abt");
        trieInsert(D,"at");
        trieInsert(D,"bat");
	trieInsert(D,"eat");
	trieInsert(D,"ate");
	trieInsert(D,"bet");
        printf("%d %d",trieSearch(D,"ate"),trieSearch(D,"bat"));
        
}*/

