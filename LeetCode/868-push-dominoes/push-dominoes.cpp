class Solution {
public:
    string pushDominoes(string dominoes) {
        int length = dominoes.length();
        vector<int> forces(length);

        int force = 0;
        for (int i = 0; i < length; i++) {
            if (dominoes[i] == 'R') force = length;
            else if (dominoes[i] == 'L') force = 0;
            else force = max(force - 1, 0);

            forces[i] += force;
        }

        force = 0;
        for (int i = length - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') force = length;
            else if (dominoes[i] == 'R') force = 0;
            else force = max(force - 1, 0);

            forces[i] -= force;
        }

        string result;
        for (int force : forces)
            result += force > 0 ? 'R' : force < 0 ? 'L' : '.';

        return result;
    }
};