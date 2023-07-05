typedef struct TrieNode {
  char letter;
  int endOfWord;
  struct TrieNode *first_child;
  struct TrieNode *next_sibling;
}TrieNode;

typedef struct Trie{
  struct TrieNode *root;
}Trie;

struct TrieNode *newNode(char);
//void trieInit(struct Trie *);
Trie* trieInit();
int trieSearch(struct Trie *, char *); 
void trieInsert(struct Trie *,  char *);
void listAll(struct Trie *);
void listAllHelper(struct TrieNode *, char *, int);
