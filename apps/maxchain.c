//MAXCHAIN.C
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <wordutils.h>

int print(dict* D,char *str){
//printf("%s**%d\n",str,trieSearch(D,str));
    if(strlen(str)==1){
    	printf("%s\n",str);
    	return 1;
    }
    if(trieSearch(D,str+1) && print(D,str+1)){
	printf("%s\n",str);
        return 1;
    }
    else{
    //printf("-1\n");
        char*temp=(char*)malloc(200);
        strcpy(temp,str);
        temp[strlen(str)-1]='\0';
        if(trieSearch(D,temp) && print(D,temp)){
            printf("%s\n",str);
            return 1;
        }
        else{
        //printf("-1...\n");
            return 0;
        }
    }
}

int mp=0;
char* maxchain(dict* D,char* str){
mp++;
    //printf("hi1\n");
    int val=0;
    char *S1=(char*)malloc(200);
    S1=addbefore(D,str);
    char *S2=(char*)malloc(200);
    S2=addafter(D,str);
    char*res=(char*)malloc(200);
    char*temp=(char*)malloc(200);
    int i;
    strcpy(res,str);
    if(strlen(S1)==0 && strlen(S2)==0){
        return str;
    }
    strcpy(&temp[1],str);
    for(i=0;i<strlen(S1);i++){
    	temp[0]=S1[i];
        if(strlen(res)<strlen(maxchain(D,temp))){
            strcpy(res,maxchain(D,temp));
        }
        //strcpy(temp,str);
    }
    strcpy(temp,str);
    for(i=0;i<strlen(S2);i++){
    	int templen = strlen(temp);
    	temp[templen]=S2[i]; temp[templen+1]='\0';
    	if(strlen(res)<strlen(maxchain(D,temp))){
            strcpy(res,maxchain(D,temp));
        }
        strcpy(temp,str);
        //if(strlen(res)<strlen(maxchain(D,strcpy(temp,S2[i])))){
        //    strcpy(res,maxchain(D,temp));
        //}
        //temp=str;
    }
    //printf("res=%s\n",res);
    return res;
}

int main()
{
    dict * X = loaddfltdict();
    /*printf("loaded\n");
    dict* D;
        D=trieInit();
        trieInsert(D,"eat");
        trieInsert(D,"beat");
        trieInsert(D,"beats");
        trieInsert(D,"ibeats");
        trieInsert(D,"at");
        trieInsert(D,"a");
        trieInsert(D,"fat");
        trieInsert(D,"fast");
        trieInsert(D,"fate");
        trieInsert(D,"fates");
        printf("%d\n",trieSearch(D,"at"));
        printf("%d\n",trieSearch(D,"a"));
        //trieInsert(D,"");*/
    char * str = malloc(200);
    strcpy(str,"");
    ///printf("%s\n",maxchain(X,str));
    printf("Maxchain : \n");
    print(X,maxchain(X,str));
    //listAll(D);
    //printf("%d",mp);
}

