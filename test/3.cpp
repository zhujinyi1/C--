#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct tree{
    char elem;
    struct tree *l,*r;
}Node,*T;

void BT(T& tr){
    char ch;
    ch = getchar();
    if(ch=='#'){
        tr = NULL;
    }
    else{
        tr = (T)malloc(sizeof(Node));
        tr->elem = ch;
        BT(tr->l);
        BT(tr->r);
    }
    
}

void Display1(T& tr){
    if(!tr)
        return ;
    Display1(tr->l);
    printf("%c",tr->elem);
    Display1(tr->r);
}
void Display2(T tr){
    T p;
    if(!tr)
        return ;
    p = tr->l;
    tr->l = tr->r;
    tr->r = p;
    Display2(tr->l);
    Display2(tr->r);
}

int main(){
    T head;
    BT(head);
    Display1(head);
    printf("\n");
    Display2(head);
    Display1(head);

    return 0;
}