/*
    ACWing，滑动窗口
    优先队列
    维护一个具有单调性的队列
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

int a[N];
int n,k;
int q[N];

int main(){
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> k;
    
    for(int i = 0;i<n ;i++){
        cin >> a[i];
    }
    
    int hh = 0,tt = -1;   //hh队头元素，tt队尾
    for(int i = 0;i<n;i++){
        if(hh<=tt&&q[hh]<i-k+1) hh++;   //如果队列长度超过k，将hh++
        while(hh<=tt&&a[q[tt]]>=a[i]) tt--;  //当队尾元素大于待入队元素的时候出队，
        q[++tt] = i;                         //队尾入队
        if(i>=k-1) cout << a[q[hh]] << " ";  //输出队头元素
    }
    
    cout << endl;
    
    hh = 0,tt = -1;
    for(int i = 0;i<n;i++){
        if(hh<=tt&&q[hh]<i-k+1) hh++;
        while(hh<=tt&&a[q[tt]]<=a[i]) tt--;
        q[++tt] = i;
        if(i>=k-1) cout << a[q[hh]] << " ";
    }
    
    return 0;
    
}