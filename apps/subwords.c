//SUBWORDS.C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<wordutils.h>

struct map{
    char letter;
    int count;
};

void subwords(dict* D){
    char* str=(char*)malloc(100);
    printf("Enter a lower case string: ");
    scanf("%s",str);
    printf("Subwords : \n");
    int n=strlen(str);
    struct map mp[n];
    int i,j=0,k=0;
    for(i=0;i<n;i++){
        int found=0;
        for(k=0;k<j;k++){
            if(mp[k].letter==str[i]){
                mp[k].count++;
                found=1;
                break;
            }
        }
        if(found==0){
            mp[j].letter=str[i];
            mp[j].count++;
            j++;
        }
    }
    for(k=0;k<j;k++){
        char* temp=(char*)malloc(100);
        strcpy(temp,str);
        for(i=0;i<n;i++){
            if(temp[i]==mp[k].letter){
            temp[i]='\0';
                char *res=(char*)malloc(100);
                strcpy(res,temp);
                strcat(res,temp+i+1);
                //printf("result : %s\n",res);
                anagrams(D,res);
                //strcpy(temp,str);
                break;
            }
        }
    }
}

int main()
{
    dict * D = loaddfltdict();
    subwords(D);
    //printf("loaded\n");
    /*dict* D;
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
        //printf("%d\n",trieSearch(D,"at"));
        //printf("%d\n",trieSearch(D,"a"));
        //trieInsert(D,"");
	subwords(D);
	/*char *res=(char*)malloc(100);
	strcpy(res,"ate");
	anagrams(D,res);
        strcpy(res,"bat");
	anagrams(D,res);*/
    //listAll(D);
    //printf("%d",mp);*/
}

