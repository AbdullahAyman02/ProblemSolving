class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int length = queries.size();
        vector<int> result(length);
        unordered_map<int, int> colors, balls;

        for (int i = 0; i < length; i++) {
            int ball = queries[i][0], color = queries[i][1];

            if (balls.find(ball) != balls.end()) {
                colors[balls[ball]]--;

                if (colors[balls[ball]] == 0)
                    colors.erase(balls[ball]);
            }
            balls[ball] = color;
            colors[color]++;
            result[i] = colors.size();
        }
        return result;
    }
};