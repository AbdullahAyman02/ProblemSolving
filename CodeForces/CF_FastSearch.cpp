#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back

void solve() {
    int n, k; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cin >> k;
    int query_l, query_r;;
    for (int i = 0; i < k; i++) {
        cin >> query_l >> query_r;
        int l1 = -1, r1 = n;
        while (r1 > l1 + 1) {
            int m = (l1 + r1) / 2;
            if (a[m] < query_l) l1 = m;
            else r1 = m;
        }
        int l2 = -1, r2 = n;
        while (r2 > l2 + 1) {
            int m = (l2 + r2) / 2;
            if (a[m] <= query_r) l2 = m;
            else r2 = m;
        }
        cout << r2 - r1 << " ";
    }
    cout << endl;
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