#include <stdio.h>
#include <stdlib.h>
char num[15];
int answer[15];
int main()
{

    char ch;
    int i=0;
    int n=0;
    int sum=0;
    scanf("%c",&num[n]);
    ch=getchar();

    while(((int)ch-48<10 && (int)ch-48>=0)||ch=='-'||ch=='X')

    {
        if(ch!='-')
        {
            n++;

            num[n]=ch;

        }
        ch = getchar();
    }



    for(n=0;n<10;n++)
    {
        answer[n]=num[n]-48;
        if(n==9&&num[n]=='X')
        {
            answer[n]=10;
        }

    }

    for(n=0;n<9;n++)
    {

        i++;
        sum+=answer[n]*i;

    }
    if(sum%11==answer[9])
        printf("Right");
    else
    {

        for(n=0;n<9;n++)
        {
            printf("%d",answer[n]);
            if(n==0)
                printf("-");
            if(n==3)
                printf("-");
            if(n==8)
                printf("-");
        }
        if (sum%11!=10)printf("%d",sum%11);
        else printf("%c",'X');
    }
    return 0;
}
