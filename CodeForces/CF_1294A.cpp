#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        vector<long long> v(3);
        cin >> v[0] >> v[1] >> v[2] >> n;
        sort(v.begin(), v.end(), greater<long long>());
        n -= (v[0] - v[1] + v[0] - v[2]);
        if(!(n % 3) && n >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}