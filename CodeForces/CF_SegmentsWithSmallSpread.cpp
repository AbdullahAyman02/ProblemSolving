#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eb emplace_back

ll k;
struct myStack {
    stack<ll> s, sMin, sMax;
    myStack() {
        sMin.push(LLONG_MAX);
        sMax.push(LLONG_MIN);
    }
    void push(ll x) {
        s.push(x);
        sMin.push(::min(sMin.top(), x));
        sMax.push(::max(sMax.top(), x));
    }
    ll pop() {
        ll x = s.top(); s.pop();
        sMin.pop(); sMax.pop();
        return x;
    }
    bool empty() {
        return s.empty();
    }
    ll min() {
        return sMin.top();
    }
    ll max() {
        return sMax.top();
    }
};

myStack s1, s2;

void add(ll x) {
    s2.push(x);
}

void remove() {
    if (s1.empty()) {
        while (!s2.empty()) {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

bool good() {
    return max(s1.max(), s2.max()) - min(s1.min(), s2.min()) <= k;
}

void solve() {
    int n; cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0;
    ll result = 0;
    for (int r = 0; r < n; r++) {
        add(a[r]);
        while (!good()) {
            remove();
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