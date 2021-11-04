#include<iostream>
using namespace std;
int main(){
    int l,v;
    cin >> l >> v;
    int a=24+7,b = 50+60;
    int x = l/v;
    if(x!=l/v * v) x++;
    int y = x/60;
    a = a-y;
    b = b-(x-y*60);
    if(b<60) a--;
    cout << a%24 << ":" << b%60;
}