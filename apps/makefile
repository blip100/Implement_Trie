maxchain : 
	gcc -L../trie -L../util -I../trie -I../util maxchain.c -lwordutils -ltrie
	export LD_LIBRARY_PATH="../trie;../util" ; ./a.out
	
subwords :
	gcc -L../trie -L../util -I../trie -I../util subwords.c -lwordutils -ltrie
	export LD_LIBRARY_PATH="../trie;../util" ; ./a.out
	
clean :
	rm a.out