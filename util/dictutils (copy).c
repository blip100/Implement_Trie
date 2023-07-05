//DICTUTILS.C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dictutils.h>

char * addbefore(dict * D,char str[])
{
    int len = strlen(str);
    char Str[len+1];
    int i;
    for(i=0;i<=len;i++)
    {
        Str[i+1] = str[i];
    }
    int hashmap[26],cnt=0;
    for(i=0;i<26;i++)
    {
        Str[0] = 'a'+i;
        if(trieSearch(D,Str))
        {
            hashmap[i]=1;
            cnt+=1;
        }
        else hashmap[i]=0;
    }
    char * letter = (char*)malloc(cnt+1);
    cnt = 0;
    for(i=0;i<26;i++)
    {
        if(hashmap[i]==1)
        {
            letter[cnt] = 'a'+i;
            cnt+=1;
        }
    }
    letter[cnt]='\0';
    return letter;
}

char * addafter(dict * D,char str[])
{
    int i;
    int len = strlen(str);
    char Str[len+1];
    Str[len+1] = 0;
    for(i=0;i<len;i++) Str[i]=str[i];
    int check[26],count=0;
    for(i=0;i<26;i++)
    {
        Str[len] = 'a'+i;
        if(trieSearch(D,Str))
        {
            check[i]=1;
            count++;
        }
        else check[i]=0;
    }
    char * letter = (char*)malloc(count+1);
    count = 0;
    for(i=0;i<26;i++)
    {
        if(check[i]==1)
        {
            letter[count] = 'a'+i;
            count++;
        }
    }
    letter[count]='\0';
    return letter;
}

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
int fact[100];

void allocate(char **ans,int x){
  int i;
  for (i = 0; i < fact[50]; i++){
        ans[i] = (char*)malloc((x)* sizeof(char));
    }
}

char** permute(dict* D,char *a, int l, int r,char**ans){
  static int filler=0;
    int i;
    if(l==r && trieSearch(D,a)){
        int j=0,ok=1;
        for(j=0;j<=filler;j++){
          if(ans[j]==a){
            ok=0;
          }
        }
        if(ok)ans[filler++]=a;
        ans[filler]=NULL;
    }
    else{
      for (i =l; i <= r; i++){
          swap((a+l),(a+i));
          permute(D,a, l + 1, r,ans);
          swap((a+l),(a+i));
      }
      return ans;
    }
}

char** anagrams(dict* D,char* str){
  int i;
  for(i=0;i<1e10;i++){
    if(i==0)fact[i]=1;
    else fact[i]*=(i*fact[i-1]);
  }
  char**ans=(char**)malloc(100000*sizeof(char*));
  allocate(ans,strlen(str));
  return permute(D,str,0,strlen(str),ans);
}




