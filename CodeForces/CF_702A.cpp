#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back

int main()
{
    int t = 1;
    //cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<ll> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        ll max = -1, len = 1;
        for(int i = 1; i < n; i++)
        {
            if(v[i] > v[i - 1])
                len++;
            else
            {
                if(len > max)
                    max = len;
                len = 1;
            }
        }
        if(len > max)
            max = len;
        cout << max;
    }
    return 0;
}