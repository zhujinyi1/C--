#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[100]={0};
    string str="";
    int n, k;
    long long s;
    int index;
    cin >> n >> k >> s;
    for (int i = 0; i < k; i++)
    {
        cin >> index;
        a[index-1]++;
    }
    while (s)
    {
        str += s % 2 + '0';
        s = s / 2;
    }

    if (str.length() > n)
    {
        cout << "NO";
        return 0;
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (a[i] && str[i]-'0' == 1)
            {
                cout << "NO";
                return 0;
            }
        }
        cout << "YES";
    }

    return 0;
}