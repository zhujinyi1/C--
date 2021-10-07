#include<bits/stdc++.h>
using namespace std;

const int N = 10000;
int n;
string str;

int main(){
    cin >> n;
    while(n--){
        bool b = true;
        cin >> str;
        for(int i = 0;i<str.length()-1;i++){
            if((str[i]=='0'&&str[i+1]=='0')||(str[i]=='1'&&str[i+1]=='1')){
                b = false;
                break;
            } 
        }
        if(b) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}