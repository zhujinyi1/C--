// 
/*
    Trie树用于字符串快速查找，在多个字符串中查找某个字符串
*/
// 

#include<bits/stdc++.h>
using namespace std;

const int N = 10010;

int n;

int son[N][26],cnt[N],idx = 0;
char str1[N];

void Insert(char str[]){
    int p = 0;
    for(int i =0;str[i];i++){
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

bool Query(char str[]){
    int p = 0;
    for(int i = 0;str[i];i++){
        int u = str[i] - 'a';
        if(!son[p][u])  return 0;
        p = son[p][u];
    }

    return cnt[p];
}

int main(){
    cin >> n;
    while(n--){
        char op;
        cin >> op >> str1;
        switch(op){
            case 'I':
            Insert(str1);
            break;
            case 'Q':
            cout << Query(str1) << endl;
            break;
        }
    }

}