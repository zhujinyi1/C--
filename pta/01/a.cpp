#include<stdio.h>
#include<string.h>
int main()
{
    char a[5][81];
    char b[81];
    int i=0,j=0,index=0;
    for(i=0;i<5;i++)
    scanf("%s",a[i]);
    for(i=0;i<4;i++)
    {
        index=i;
        for(j=i+1;j<5;j++)
        if(strcmp(a[index],a[j])>0)
            index=j;
        strcpy(b,a[i]);
        strcpy(a[i],a[index]);
        strcpy(a[index],b);
    }
    printf("After sorted:");
    for(i=0;i<5;i++)
    {
        printf("\n%s",a[i]);
    }
    return 0;
}