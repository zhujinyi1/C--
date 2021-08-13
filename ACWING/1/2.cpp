#include<iostream>
using namespace std;
int main()
{
    int i=0,j=0,n,t,k,p=1,q=1,r=0,x=1;
    cin >> n;
    while(i<n){
        cin >> t >> k;
        while(q<k){
            r=p;
            p=q;
            q=p+r;
            x++;
        }
        if(q==k&&k<=3)
            x--;
        for(j=0;j<=t-1;j++){
            if((((k!=1)&&(j==t-x-1||j==t-(k-p)))||((k==1)&&(j==t-x-1||j==t-(k-p)-1)))&&q!=k)
                cout << 'b';
            else if(q==k&&(j==t-x-1||j==t-1)){
                cout << 'b';
            }
            else
                cout << 'a';
        }
        cout << endl;
        i++;
    }
    return 0;
}