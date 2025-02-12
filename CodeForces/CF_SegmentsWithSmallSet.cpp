#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0;
    ll result = 0;
    unordered_map<int, int> mp;
    for (int r = 0; r < n; r++) {
        mp[a[r]]++;
        while (mp.size() > k) {
            mp[a[l]]--;
            if (mp[a[l]] == 0) mp.erase(a[l]);
            l++;
        }
        result += r - l + 1;
    }
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--)
        solve();
    return 0;
}