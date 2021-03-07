#include<iostream>
using namespace std;
int main()
{
    int num = 50;
    int &ref = num ;
    ref = ref + 10;
    num = num + 40 ;
    cout<<ref<<endl;
    return 0;
}