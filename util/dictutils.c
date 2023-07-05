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

void swap(char *a, int x1,int x2) {
    char temp = a[x1];
    a[x1] = a[x2];
    a[x2] = temp;
}

void permute(dict* D,char *a, int l, int r,char**ans,int filler[]){
//printf("entered\n");
    int i;
    if(l==r && trieSearch(D,a)){
	    //printf("hi\n");
	    //printf("entered****\n");
		int j=0,ok=1;
		for(j=0;j<filler[0];j++){
		  if(strcmp(ans[j],a)==0){
		    ok=0;
		  }
		}
		if(ok){
			ans[filler[0]]=(char*)malloc(50);
			strcpy(ans[filler[0]],a);
			printf("%s\n",a);
			filler[0]+=1;
			ans[filler[0]]=NULL;
		}
    }
    else{
      for (i =l; i < r; i++){
      	  swap(a,l,i);
          //swap((a+l),(a+i));
          //printf("h\n");
          permute(D,a, l + 1, r,ans,filler);
          swap(a,l,i);
      }
    }
}

char** anagrams(dict* D,char* str){
	//printf("anag called for %s\n",str);
  char**ans=(char**)malloc(100000*sizeof(char*));
  int filler[1];filler[0]=0;
  permute(D,str,0,strlen(str),ans,filler);
  return ans;
}

/*int main(){
        dict* D;
        D=trieInit();
        trieInsert(D,"eat");
        trieInsert(D,"rat");
        trieInsert(D,"cat");
        trieInsert(D,"tea");
        printf("%s\n",addbefore(D,"at"));
        //trieInsert(D,"at");
        //char * str = (char*)malloc(100);
        //strcpy(str,"tae");
        //anagrams(D,str);
}*/



