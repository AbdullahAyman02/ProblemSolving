#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;

void run()
{
    for(int i = 1; i <= 26; i++)
        mp['a' + i - 1] = i;
}

int main()
{
    int t;
    cin >> t;
    run();
    while(t--)
    {
        int n; cin >> n;
        string str; cin >> str;
        sort(str.begin(), str.end(), greater<> ());
        cout << mp[str[0]] << '\n';
    }
    return 0;
}