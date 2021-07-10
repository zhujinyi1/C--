#include <iostream>
using namespace std;

typedef struct tree
{
    int elem;
    struct tree *l, *r;
} * T, Node;

void Display1(T& tr){
    if(!tr)
        return ;
    printf(" %d",tr->elem);
    Display1(tr->l);
    Display1(tr->r);
}

void BT(T& tr,int a[],int b[],int a1,int a2,int& i){
    int j;
    for(j = a1;j<=a2;j++){
        if(b[i]==a[j])
            break;
    }
    if(j>a2){
        tr = NULL;
        return ;
    }
    
    tr = new Node;
    tr->elem = b[i];
    i--;
    BT(tr->r,a,b,j+1,a2,i);
    BT(tr->l,a,b,a1,j-1,i);
}

int main()
{
    T head;
    int n, i,j;
    int a[31], b[31];
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }
    j = n-1;
    BT(head,b,a,0,n-1,j);
    printf("Preorder:");
    Display1(head);
    return 0;
}