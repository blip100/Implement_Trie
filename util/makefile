library : dictload.o dictutils.o
	gcc -shared -o libwordutils.so dictload.o dictutils.o

dictload.o : dictload.c dictload.h
	gcc -c -I. -I../trie  -o dictload.o dictload.c

dictutils.o : dictutils.c dictutils.h
	gcc -c -I. -I../trie  -o dictutils.o dictutils.c

clean :
	rm dictload.o dictutils.o libwordutils.so
