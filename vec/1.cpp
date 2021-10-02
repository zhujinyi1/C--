#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    for(int i = 0;i<10;i++){
        v.push_back(i);
    }

    v.push_back(4);
    vector<int>::reverse_iterator ite;
    for(ite = v.rbegin();ite<v.rend();ite++){
        int &a = *ite;
        cout << a;
    }
    return 0;
}