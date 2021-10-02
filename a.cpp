#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[10],q[10];
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;i++) scanf("%d",&a[i]);

    int hh = 0,tt=-1;
    for(int i = 0;i<n;i++){
        if(hh<=tt && i-k+1 >q[hh]) hh++;

        while(hh <=tt && a[q[tt]] >=a[i]) tt--;
        
        q[++tt] = i;
        // if(i>=k-1) printf("%d ",a[q[hh]]);
        for(int i = 0;i<=tt;i++){
            cout << a[q[i]] << " ";
        }
        cout << endl;
        
    }
    return 0;
}
