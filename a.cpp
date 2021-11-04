#include<bits/stdc++.h>
using namespace std;

const int N = 10000;
int n,k1,k2;
int a[N],b[N];
int m = -200000000;
int c[N];

int main(){
    cin >> n >> k1 >> k2;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
    for(int i = 0;i<n;i++){
        cin >> b[i];
        c[i] = fabs(b[i]-a[i]);
    }
    int t;
    int k = k1+k2;
    for(int i =0;i<k;i++){
        m = -200000000;
        for(int j = 0;j<n;j++){
            if(m<c[j]){
                t = j;
                m = c[j];
            }
        }
        c[t]--;
    }
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans+=c[i]*c[i];
    }
    cout << ans;
    return 0;
}