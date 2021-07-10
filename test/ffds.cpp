#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a[5]={1,5,2,6,4};
    sort(a,a+5);
    
    reverse(a,a+5);
    for(int i = 0;i<5;i++){
        cout << a[i] << " ";
    }
    return 0;
}