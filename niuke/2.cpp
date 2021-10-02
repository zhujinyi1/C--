#include<bits/stdc++.h>
using namespace std;

string str = "cocacola";
string s;
string s1,s2;
int a[10];
int Mlen = 0x7fffffff;

void Search(int index,int l){
    while(s1[index]==s2[index]) index++;
    if(index>=s1.length()-1){
        if(l<Mlen) Mlen = l;
    }
    for(int i = index+1;i<s2.length();i++){
        if(s2[i]==s1[index]&&!a[i]){
            char t = s2[i];
            s2[i] = s2[index];
            s2[index] = t;
            a[i] = 1;
        }
        Search(index+1,l+1);
        if(a[i] == 1){
            char t = s2[i];
            s2[i] = s2[index];
            s2[index] = t;
        }
        a[i] = 0;

    }
}

int main(){
    string s;
    int t = 0;
    cin >> s;
    for(int i = 0;i<8;i++){
        if(str[i]!=s[i]){
            s1+=str[i];
            s2+=s[i];
        }
    }

    Search(0,0);

    cout << Mlen;

    return 0;
}