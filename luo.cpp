#include<stdio.h>
#include<string.h>
int main()
{
    char wd[12]={},st_wd[30]={};
    unsigned int js=0,wz=0,loc=0,flag=0;
    scanf("%s",wd);
    for(unsigned int i=0;i<strlen(wd);i++){
        if(wd[i]<'a') wd[i]+='a'-'A';
    }
    while(scanf("%s",st_wd)!=EOF){
      //printf("%d",strlen(st_wd));
      for(unsigned int i=0;i<strlen(st_wd);i++){
          if(st_wd[i]<'a') st_wd[i]+='a'-'A';
      }
      if(strcmp(wd,st_wd)==0) js++;
      if(js==1&&flag==0) wz=loc,flag=1;
      loc+=strlen(st_wd)+1;
    }
    if(js!=0) printf("%d %d",js,wz);
    else printf("-1");
    return 0;
}
