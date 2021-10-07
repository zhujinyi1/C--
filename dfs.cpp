#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int res = 0;
int arr[N];
int t = 0;
int n;
int p[93][10];
bool hang[8], lie[8], shunhang[16], nihang[16];

void dfs(int n)
{
    if (n == 8)
    {
        res++;
        if(res)
            for(int i = 0;i<8;i++){
                p[res][i] = p[res-1][i];
            }
        return;
    }

    for (int i = 1; i <= 8; i++)
    {
        if (!hang[n] && !lie[i] && !shunhang[i + n] && !nihang[8 + i - n])
        {
            hang[n] = lie[i] = shunhang[i + n] = nihang[8 + i - n] = true;
            p[res][n] = i;
            dfs(n + 1);
            hang[n] = lie[i] = shunhang[i + n] = nihang[8 + i - n] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dfs(0);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<8;j++){
            cout << p[arr[i]-1][j];
        }
        cout << endl;
    }
    return 0;
}