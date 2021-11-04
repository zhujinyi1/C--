
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int a[N],b[N],g[N],k[N];
int x,y;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }
    cin >> x >> y;
    int ans = -1;
    for(int i = 0;i<n;i++){
        if(a[i]<=x&&a[i]+g[i]>=x&&b[i]<=y&&b[i]+k[i]>=y){
            ans = i+1;
        }
    }
    cout << ans;
    return 0;
}