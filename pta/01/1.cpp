#include<iostream>
using namespace std;
int main(){
    int a,b,i,j,x;
    int *p,*pnew;
    cin >> a;
    cin >> b;
    p = new int[a];
    pnew = new int[a];
    for(i=0;i<a;i++){
        cin >> p[i];
    }
    x = a;
    while(x<b){
        x+=a;
    }
    for(i=0,j=x-b;i<a;i++){
        pnew[i]=p[j%a];
        j++;
    }
    cout << pnew[0];
    for(i = 1;i<a;i++){
        cout << " "<<pnew[i];
    }
    return 0;
}