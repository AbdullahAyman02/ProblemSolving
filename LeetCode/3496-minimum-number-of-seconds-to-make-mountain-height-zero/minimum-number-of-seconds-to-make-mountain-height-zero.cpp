class Solution {
public:
    typedef long long ll;

    bool solve(ll height, vector<int>& time, ll T) {
        ll heightCanBeBroken = 0;
        for (auto t : time) {
            ll h = (-1 + sqrt(1 + (8 * T) / t)) / 2;
            heightCanBeBroken += h;

            if (heightCanBeBroken >= height) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll low = 0, high = 1e18, result = 1e18;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (solve(1ll * mountainHeight, workerTimes, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};