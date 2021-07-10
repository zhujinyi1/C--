#include<iostream>
using namespace std;
int main(){
    char a[81],ch;
    int i = 0;
    while((ch=getchar())!='\n'){
        a[i++] = ch;
    }
    a[i] = '\0';
    while(i>0){
        cout << a[--i];
    }
    return 0;
}