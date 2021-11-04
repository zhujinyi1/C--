#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double ml;
    int n;
    cin >> ml >> n;
    printf("%.3lf",ml/n);
    cout << endl << n*2;
}