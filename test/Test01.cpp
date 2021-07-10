#include<iostream>
using namespace std;
typedef int Elemtype;
typedef struct Queue{
    Elemtype *elem;
    int Maxsize;
    int font,rear;
}Que;

bool DeQ(Que Q,Elemtype &){

}


int main()
{
    Que Q;
    int i,j = 0;
    char c;
    string a = {'#'};
    cin >> i;
    Q.Maxsize = i+1;
    Q.elem = new Elemtype[i+1];
    Q.font = Q.rear = 0;
    c = getchar();
    while(c!='#'){
        if(c=='I'){
        while((c=getchar()!=' ')||(c=getchar()!='\n'));
        if((rear+1)%Q.Maxsize==Q.font){
            cout << Q.
        }
        cin >> Q.elem[Q.rear++];
        }
        if(c=='C'){
        while((c=getchar()!=' ')||(c=getchar()!='\n'));
        cin >> Q.elem[Q.rear++];
        }
    }
}