#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    string str; cin >> str;
    pair<int, int> pos = {0, 0};
    for(auto& c : str)
    {
        if(c == 'U')
            pos.second++;
        else if(c == 'D')
            pos.second--;
        else if(c == 'R')
            pos.first++;
        else
            pos.first--;
        if(pos == make_pair(1, 1))
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}