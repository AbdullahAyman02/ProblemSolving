#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int query;
    for (int i = 0; i < k; i++) {
        cin >> query;
        int l = 0, r = n - 1;
        while(r >= l) {
            int m = (l + r) / 2;
            if (a[m] == query) {
                cout << "YES" << endl;
                break;
            } else if (a[m] < query) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (r < l) cout << "NO" << endl;
    }
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