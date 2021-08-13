#include<iostream>
using namespace std;
int main(){
    int i=1,n,h,m;
    cin >> n;
    while(i<=n){
        scanf("%d %d",&h,&m);
        cout << 60*(23-h)+60-m << endl;
        i++;
    }
    return 0;
}