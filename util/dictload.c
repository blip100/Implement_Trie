#include <stdio.h>
#include<stdlib.h>
#include <dictutils.h>

dict *loaddfltdict()
{
    FILE *fp = fopen("../dict/words.txt", "r");
    char *string = (char*)malloc(100);
    dict *dictionary = trieInit(dictionary);
    while(!feof(fp))
    {
        fscanf(fp, "%s", string);
        trieInsert(dictionary, string);
    }
    // printf("list completed\n");
    free(string);
    fclose(fp);
    return dictionary;
}

dict *loaddict(char * path)
{
    FILE *fp = fopen(path, "r");
    char *string = (char*)malloc(100);
    dict *dictionary = trieInit(dictionary);
    while(!feof(fp))
    {
        fscanf(fp, "%s", string);
        trieInsert(dictionary, string);
    }
    free(string);
    fclose(fp);
    return dictionary;
}	


int main()
{
    dict * D = loaddfltdict();
}
